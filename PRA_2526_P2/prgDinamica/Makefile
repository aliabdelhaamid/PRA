mochila.o: mochila.cpp
	g++ -std=c++17 -c mochila.cpp -o mochila.o
 
bin/testMochila: mochila.o
	mkdir -p bin
	g++ -std=c++17 mochila.o -o bin/testMochila

monedas.o: monedas.cpp
	g++ -std=c++17 -c monedas.cpp -o monedas.o

bin/testMonedas: monedas.o
	mkdir -p bin
	g++ -std=c++17 monedas.o -o bin/testMonedas

clean:
	rm -r *.o *.gch bin
