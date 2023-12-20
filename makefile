CC = g++

default: main.o
	$(CC) main.o -o project-creator.exe

main.o: main.cpp
	$(CC) main.cpp -Wall -c -o main.o

clean:
	del *.o *.exe