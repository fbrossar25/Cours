JAVACC=javac
JAR=jar
INPUT_FILE=matrices.in.dat
# INPUT_FILE=test.csv
# INPUT_FILE=input
OUTPUT=res.out.dat
PROJECT=Mm
JAR_NAME=$(PROJECT).jar
DIR_CLASSES=$(PROJECT)_classes  # a dir to store classes and not mix too many files with sources

all: $(JAR_NAME)

$(JAR_NAME): $(PROJECT).class
	$(JAR) -cvf $@ -C $(DIR_CLASSES) .
	@echo "* JAR READY *"
	@echo "-> run with 'hadoop jar $@ $(PROJECT) $(INPUT_FILE) $(OUTPUT)'"

$(PROJECT).class: $(DIR_CLASSES) $(PROJECT).java
	hadoop com.sun.tools.javac.Main -d $(DIR_CLASSES) $(PROJECT).java 

$(DIR_CLASSES):
	mkdir -p $(DIR_CLASSES)

run:
	rm -rf $(OUTPUT)
	hadoop jar $(JAR_NAME) $(PROJECT) $(INPUT_FILE) $(OUTPUT)

clean:
	rm -rf $(OUTPUT) $(OUTPUT)-final

clean_classes:
	rm -rf $(DIR_CLASSES)

mrproper: clean clean_classes
	rm -rf $(JAR_NAME)