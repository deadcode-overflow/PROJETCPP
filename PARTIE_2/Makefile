CXX=g++
CXXFLAGS=-Wall -Wextra -O2
LDFLAGS=
OFLAGS=-I inc

EXEC=main.exe
SRC=main.cpp huffman.cpp
OBJ=$(SRC:.cpp=.o)

DIR_EXEC=bin
DIR_OBJ=obj
DIR_SRC=src
DIR_HEADERS=inc

BUILD_DIR=$(DIR_EXEC) $(DIR_OBJ)
BUILD_QT=build
CONFIG=build_config.txt

vpath %.exe bin
vpath %.o obj
vpath %.cpp src
vpath %.h inc

# Generate
all: project qt_build

# Compile the basic project
project: checkdirs $(EXEC)

# Verify if directories are created, create them if not.
checkdirs: $(BUILD_DIR)

$(BUILD_DIR):
	@mkdir -pv $@

# Create local Qt build 
qt_build: checkconfig
	@$(MAKE) -C $(BUILD_QT) qt_build

# Verify if Makefile in local Qt build already exist, create him if not.
checkconfig:
	@touch $(BUILD_QT)/Makefile
	@cp -v $(CONFIG) $(BUILD_QT)/Makefile

main.exe: $(OBJ)
	$(CXX) $(LDFLAGS) -o $(DIR_EXEC)/$@  $(addprefix $(DIR_OBJ)/,$^)
	@echo "\ncompilation success"
	@echo "----------------"

main.o: huffman.h

huffman.o: huffman.h

%.o: %.cpp
	$(CXX) $(OFLAGS) $(CXXFLAGS) -c $< -o $(DIR_OBJ)/$@

.PHONY: clean clean_project clean_qt_build checkconfig

# Delete all
clean: clean_qt_build clean_project

# Delete local generated directories and their components
clean_project:
	@rm -fv *.o
	@rm -rfv $(DIR_EXEC)/*
	@rm -rfv $(DIR_OBJ)/*
	@rm -dfv $(DIR_EXEC)
	@rm -dfv $(DIR_OBJ)
	@echo "\nproject clean"
	@echo "------------"

# Delete local Qt build
clean_qt_build:
	@mv $(BUILD_QT)/README.md ../
	@rm -fv $(BUILD_QT)/Main
	@rm -fv $(BUILD_QT)/Makefile
	@rm -fv $(BUILD_QT)/CMakeLists.txt
	@rm -rf $(BUILD_QT)/*
	@echo "\nbuild clean"
	@mv ../README.md $(BUILD_QT)
	@echo "----------"