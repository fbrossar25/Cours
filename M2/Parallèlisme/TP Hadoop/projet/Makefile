JAVACC=javac
JAR=jar
DIR_CLASSES=wordcount_classes  # a dir to store classes and not mix too many files with sources
INPUT_FILES=VG_Global_Sales.csv VG_Sales_And_Ranking.csv
OUTPUT_DIR=output
PROJECT=Projet
JAR_NAME=$(PROJECT).jar

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