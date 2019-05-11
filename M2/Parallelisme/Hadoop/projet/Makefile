JAVACC=javac
JAR=jar
CLASSES_DIR=classes  # a dir to store classes and not mix too many files with sources
SRC_DIR=src
INPUT_FILE=VG_Sales_And_Rankings.csv
OUTPUT_DIR=output
PROJECT=Projet
JAR_NAME=$(PROJECT).jar

all: $(JAR_NAME)

$(JAR_NAME): clean classes
	$(JAR) -cvf $@ -C $(CLASSES_DIR) .
	@echo "* JAR READY *"
	@echo "-> run with 'hadoop jar $@ $(PROJECT) $(INPUT_FILE) $(OUTPUT_DIR)'"

classes:
	rm -f $(CLASSES_DIR)
	mkdir -p $(CLASSES_DIR)
	hadoop com.sun.tools.javac.Main -d $(CLASSES_DIR) $(SRC_DIR)/*.java 

run: clean
	hadoop jar $(JAR_NAME) $(PROJECT) $(INPUT_FILE) $(OUTPUT_DIR)
	cp $(OUTPUT_DIR)/result/part-r-00000 .
	mv part-r-00000 result

clean: clean_classes
	rm -rf $(OUTPUT_DIR)

clean_classes:
	rm -rf $(CLASSES_DIR)

mrproper: clean clean_classes
	rm -rf $(JAR_NAME)