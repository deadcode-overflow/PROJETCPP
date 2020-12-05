CXX=g++
CXXFLAGS=-Wall -Wextra -O2
LDFLAGS=
OFLAGS=-I inc

vpath %.exe bin
vpath %.o obj
vpath %.cpp src
vpath %.h inc

EXEC=main.exe
SRC=main.cpp Sommet.cpp ArbreB.cpp test.cpp
OBJ=$(SRC:.cpp=.o)

DIR_EXEC=bin
DIR_OBJ=obj
DIR_SRC=src
DIR_HEADERS=inc

BUILD_DIR=$(DIR_EXEC) $(DIR_OBJ)

all: checkdirs $(EXEC)

# Verify if directories are created, create them if not.
checkdirs: $(BUILD_DIR)

$(BUILD_DIR):
	@mkdir -pv $@

main.exe: $(OBJ)
	$(CXX) $(LDFLAGS) -o $(DIR_EXEC)/$@  $(addprefix $(DIR_OBJ)/,$^)
	@echo "compilation succes"

main.o: test.h

test.o: test.h Sommet.h ArbreB.h

Sommet.o: Sommet.h

ArbreB.o: ArbreB.h Sommet.h

%.o: %.cpp
	$(CXX) $(OFLAGS) $(CXXFLAGS) -c $< -o $(DIR_OBJ)/$@

.PHONY: clean clean_project clean_Qt_build

# Delete all
clean: clean_Qt_build clean_project

# Delete all local generated directories and their components
clean_project:
	@rm -fv *.o
	@rm -rfv $(DIR_EXEC)*
	@rm -rfv $(DIR_OBJ)*
	@rm -dfv $(DIR_EXEC)
	@rm -dfv $(DIR_OBJ)
	@echo "\nproject clean"
	@echo "--------------"

TARGET=build

# Build local Qt build in ./build/ directory
build:
	${MAKE} -C $(TARGET) all

# Delete local Qt build
clean_Qt_build:
	@mv $(TARGET)/README.md ./
	@rm -rfv $(TARGET)/*
	@echo "\nbuild clean"
	@mv README.md $(TARGET)
	@echo "------------"