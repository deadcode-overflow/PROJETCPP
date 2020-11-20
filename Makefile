DEBUG=no
CXX=g++
ifeq ($(DEBUG),yes)
	CXXFLAGS= -O0 -g
	LDFLAGS= -Wall -Wextra -O0 -g
else
	CXXFLAGS= -O2
	LDFLAGS= -Wall -Wextra -O2
endif
EXEC= main
SRC= main.cpp Sommet.cpp ArbreB.cpp
OBJ= $(SRC:.cpp=.o)


ifeq ($(DEBUG),yes)
run : $(EXEC)
	echo "--mode debug--\n" & gdb $< 
else
run : $(EXEC)
	echo "--mode release--\n" & ./$<
endif

main : $(OBJ)
	$(CXX) -o $@ $(LDFLAGS) $^

main.o : Sommet.h

Sommet.o : Sommet.h

ArbreB.o : ArbreB.h

%.o : %.cpp
	$(CXX) -c $< $(CXXFLAGS)

.PHONY : clean

clean :
	rm -f *.o
	rm -f $(EXEC)
	clear