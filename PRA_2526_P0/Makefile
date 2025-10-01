.SUFFIXES: .cpp .h .o
.cpp.o: ; g++ -c $*.cpp

all: main

BrazoRobotico.o: BrazoRobotico.cpp BrazoRobotico.h
	g++ -c BrazoRobotico.cpp
maiBrazoRobotico.o: mainBrazoRobotico.cpp BrazoRobotico.h
	g++ -c mainBrazoRobotico.cpp

main: mainBrazoRobotico.o BrazoRobotico.o
	g++ -o main mainBrazoRobotico.o BrazoRobotico.o

clean: 
	rm -f *.o main

test: all
	./main
