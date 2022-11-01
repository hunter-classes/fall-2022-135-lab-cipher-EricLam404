main: main.o caesar.o vigenere.o decrypt.o solve.o
	g++ -o main main.o caesar.o vigenere.o decrypt.o solve.o

test-ascii: test-ascii.o
	g++ -o test-ascii test-ascii.o

tests: tests.o caesar.o vigenere.o decrypt.o
	g++ -o tests tests.o caesar.o vigenere.o decrypt.o

solve: solve.o caesar.o
	g++ -o solve solve.o caesar.o

test-ascii.o: test-ascii.cpp 

caesar.o: caesar.cpp caesar.h

vigenere.o: vigenere.cpp vigenere.h

decrypt.o: decrypt.cpp decrypt.h

main.o: main.cpp caesar.h vigenere.h

solve.o: solve.cpp solve.h
	g++ -c -std=c++11 solve.cpp

tests.o: tests.cpp doctest.h caesar.h vigenere.h decrypt.h
	g++ -c -std=c++11 tests.cpp

clean:
	rm -f *.o test-ascii.o main caesar vigenere decrypt tests test-ascii solve
