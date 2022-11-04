main: main.o caesar.o decrypt.o solve.o
	g++ -o main main.o caesar.o decrypt.o solve.o

tests: tests.o caesar.o decrypt.o solve.o
	g++ -o tests tests.o caesar.o decrypt.o solve.o

test-ascii.o: test-ascii.cpp 

caesar.o: caesar.cpp caesar.h

decrypt.o: decrypt.cpp decrypt.h

main.o: main.cpp caesar.h solve.h

solve.o: solve.cpp solve.h
	g++ -c -std=c++11 solve.cpp

tests.o: tests.cpp doctest.h caesar.h decrypt.h
	g++ -c -std=c++11 tests.cpp

clean:
	rm -f *.o main caesar decrypt tests solve
