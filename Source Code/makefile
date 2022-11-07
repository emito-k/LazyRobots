main: *.o
	g++ -g -static *.o -o main

*.o: *.cpp
	g++ -g -c -static *.cpp

run: main
	./main

clean:
	rm -f *.o main
