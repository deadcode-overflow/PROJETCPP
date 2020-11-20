run : main
	./main

main : main.o Sommet.o ArbreB.o test.o
	g++ -Wall -Wextra -O2 -o main main.o Sommet.o ArbreB.o test.o

main.o : Sommet.h ArbreB.h test.h
	g++ -c main.cpp

test.o : test.h
	g++ -c test.cpp
	
Sommet.o : Sommet.h
	g++ -c Sommet.cpp

ArbreB.o : ArbreB.h Sommet.h
	g++ -c ArbreB.cpp

clean :
	rm -f *.o
	rm -f main
	clear