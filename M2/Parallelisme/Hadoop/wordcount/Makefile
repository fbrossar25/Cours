JAVACC=javac
JAR=jar
DIR_CLASSES=wordcount_classes  # a dir to store classes and not mix too many files with sources
INPUT_FILE=objets-trouves-gares.csv
# INPUT_FILE=test.csv
# INPUT_FILE=input
OUTPUT_DIR=output
JAR_NAME=wordcount.jar
PROJECT=WordCount

all: $(JAR_NAME)

$(JAR_NAME): $(PROJECT).class
	$(JAR) -cvf $@ -C $(DIR_CLASSES) .
	@echo "* JAR READY *"
	@echo "-> run with 'hadoop jar $@ $(PROJECT) $(INPUT_FILE) $(OUTPUT_DIR)'"

$(PROJECT).class: $(DIR_CLASSES) $(PROJECT).java
	hadoop com.sun.tools.javac.Main -d $(DIR_CLASSES) $(PROJECT).java 

$(DIR_CLASSES):
	mkdir -p $(DIR_CLASSES)

run:
	rm -rf $(OUTPUT_DIR)
	hadoop jar $(JAR_NAME) $(PROJECT) $(INPUT_FILE) $(OUTPUT_DIR)

clean:
	rm -rf $(OUTPUT_DIR) $(OUTPUT_DIR)-final

clean_classes:
	rm -rf $(DIR_CLASSES)

mrproper: clean clean_classes
	rm -rf $(JAR_NAME)