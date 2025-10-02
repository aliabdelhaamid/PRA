.SUFFIXES: .cpp .h .o
.cpp.o: ; g++ -c $*.cpp

all: main

testDyV.o: testDyV.cpp DyV.h
	g++ -c testDyV.cpp

main: testDyV.o
	g++ -o main testDyV.o

clean: 
	rm -f *.o main

test: all
	./main
