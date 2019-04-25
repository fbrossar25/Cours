data = sc.textFile("wordcount-small.txt")
# Exercise 1.1
# 	Array of line of the file wordcount-small.txt

# Exercise 1.2
# creates a Array[Array[String]] from the file
list = data.map(lambda line: line.split(" "))

# show value of the 3rd column
list.foreach(lambda x : print(x[2])) 

#Array[ pair (mot, nb)]
# Exercise 1.3
mappedList = list.map(lambda x : (x[0], int(x[2])))
mappedList.first()

# Exercise 1.4
# combine values by key
reducedList  = mappedList.reduceByKey( lambda a,b : a + b)
reducedList.collect()

# Exercise 1.5
#Array[ pair (prefixe, nb)]
mappedPrefixedList = list.map( lambda x : (x[0].split(".")[0],int(x[2])))

#Combine values by prefixed key
reducedPrefixedList = mappedPrefixedList.reduceByKey( lambda a,b : a + b)

reducedPrefixedList.collect()

# Exercise 2.1
# Get file int RDD[String]
f1 = sc.textFile("ratings.dat")
f2 = sc.textFile("users.dat")

# Exercise 2.2
# Split into Array[String]
c1 = f1.map(lambda el : el.split("::"))
c2 = f2.map(lambda el : el.split("::"))

c1.count()
c1.take(10)
c2.count()
c2.take(10)

# Exercise 2.3
#SQL select distinct(UserID), count(*) from Ratings
cnt = c1.map(lambda x : (x[0],1)).reduceByKey( lambda a,b : a + b)
cnt.collect()

# Exercise 2.4
cnt.takeOrdered(3,key = lambda x : -x[1])


# Exercise 3
# Join Exemple

cnt2 = c2.map(lambda x : (x[0], (x[1], x[2], x[3], x[4])))

j = cnt.join(cnt2)

joinedArray = j.map( lambda x : (x[0], x[1][0], x[1][1]))

#show the top three users that have voted
joinedArray.sortBy(lambda x : x[1], ascending= False).take(3)

# The join operation is by key
# To made other joint, you may have to change the key, and to filter the data