CXX=g++
CXXFLAGS=-Wall -Wextra -O2
LDFLAGS=
OFLAGS=-I inc
EXEC=main.exe
SRC=main.cpp huffman.cpp Sommet.cpp ArbreB.cpp
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

all: project

# Compile le projet
project: checkdirs $(EXEC)

# Vérifie si les répertoires sont créer,si ce n'est pas le cas, les créés.
checkdirs: $(BUILD_DIR)

$(BUILD_DIR):
	@mkdir -pv $@

main.exe: $(OBJ)
	$(CXX) $(LDFLAGS) -o $(DIR_EXEC)/$@  $(addprefix $(DIR_OBJ)/,$^)
	@echo "\ncompilation success"

main.o: huffman.h

huffman.o: huffman.h

Sommet.o: Sommet.h

ArbreB.o: ArbreB.h Sommet.h

%.o: %.cpp
	$(CXX) $(OFLAGS) $(CXXFLAGS) -c $< -o $(DIR_OBJ)/$@

.PHONY: clean

# Supprime les dossiers générés et leur contenu
clean:
	@rm -fv resultat_cryptage.txt
	@rm -fv resultat_decryptage.txt
	@rm -rfv $(DIR_EXEC)/*
	@rm -dfv $(DIR_EXEC)
	@rm -rfv $(DIR_OBJ)/*
	@rm -dfv $(DIR_OBJ)
	@echo "\nproject clean"