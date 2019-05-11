import pyspark


#get file int RDD[String]
f1 = sc.textFile("ratings.dat", 4)

#get file int RDD[String]
f2 = sc.textFile("users.dat", 4)

storageLevel = pyspark.StorageLevel.MEMORY_AND_DISK_SER

f1.persist(storageLevel)

# Exercise 4.1.a
# transform in Array[String]
c1 = f1.map(lambda el : el.split("::"))
c1.persist(storageLevel)

# Exercise 4.1.b
# Transform in Array[Tuplets]
c2 = c1.map(lambda x : (x[0], x[1], x[2], x[3]))
c2.persist(storageLevel)
c2.count()


# What we can observe is that one task is executed undependently on every partition part of the file;
# The tasks are not executed consequitively, but on every partition the time for execution is different;
# The execution time is faster when file is stored -> thus in the case of many requests there is an interest of storing the file (persisting)

# Exercie 4.1.c
#Count the number of films for chaque user
#  we can modify the last number to change the level of parallelism  
#  (BY DEFAULT : the level of parallelism in the output depends on the number of partitions of the parent RDD)

c3 = c2.map(lambda x : (x[0],1)).reduceByKey( lambda a,b : a + b, 4)

# user with most films
user1 = c3.sortBy(lambda x : -x[1])
user1.take(1)

# Exercise 4.2.a
f2.persist(storageLevel)

# Transform in Array[String]
d1 = f2.map(lambda el : el.split("::"))
d1.persist(storageLevel)

# Transform in Array[Tuplets]
d2 = d1.map( lambda x : (x[0], x[1], x[2], x[3], x[4]))
d2.persist(storageLevel)

j1 = c2.map( lambda x : (x[0], (x[1], x[2], x[3])))
j2 = d2.map( lambda x : (x[0], (x[1], x[2], x[3], x[4])))

naturalJoin = j1.join(j2)
naturalJoin.take(10)

# n-uplets (FilmID, Age)
filmAge = naturalJoin.map( lambda x : (x[1][0][0], int(x[1][1][0])))
filmAge.take(10)

# Exercise 4.2.b
# n-uplets (UserID, Age)
userAge = d2.map( lambda x : (x[0], x[1]))
userAge.take(10)

# n-uplets (UserID, Note)
note = c1.map( lambda x : (x[0], int(x[2])))
note.take(10)

# Exercise 4.2.c
joinUser = userAge.join(note)
joinUser.distinct().collect()