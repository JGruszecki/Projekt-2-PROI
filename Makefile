program: main.o userType.o test.o
	g++ main.o userType.o test.o -o program

main.o: main.cpp Dictionary.h test.h
	g++ -Wall -c main.cpp -o main.o

userType.o: userType.cpp userType.h
	g++ -Wall -c userType.cpp -o userType.o

test.o: test.cpp Dictionary.h
	g++ -Wall -c test.cpp -o test.o

.PHONY: clean

clean:
	rm -f main.o  test.o userType.o program
run:
	./program