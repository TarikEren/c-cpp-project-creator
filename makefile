CC = g++
h_dir = ./headers/
s_dir = ./src/


default: main.o prompts.o file_creation.o
	$(CC) main.o prompts.o file_creation.o -o project-creator.exe

main.o: main.cpp 
	$(CC) main.cpp -Wall -c

prompts.o: $(s_dir)prompts.cpp $(h_dir)prompts.h $(h_dir)file_creation.h
	$(CC) $(s_dir)prompts.cpp -c 

file_creation.o: $(s_dir)file_creation.cpp $(h_dir)prompts.h $(h_dir)file_creation.h
	$(CC) $(s_dir)file_creation.cpp -c

clean:
	del *.o *.exe