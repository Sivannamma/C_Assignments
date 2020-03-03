CC=gcc
AR=ar
OBJECTS_MAIN2=main2.o
OBJECTS_BANK2=txtfind.o
OBJECTS_MAIN=main.o
OBJECTS_BANK=isort.o
FLAGS= -Wall -g

all: isort txtfind	

txtfind: txtfind.o main2.o
	$(CC) $(FLAGS) -o txtfind main2.o txtfind.o

main2.o: main2.c txtfind.h  
	$(CC) $(FLAGS) -c main2.c 


txtfind.o: txtfind.c txtfind.h
	$(CC) $(FLAGS) -c txtfind.c

isort: isort.o main.o
	$(CC) $(FLAGS) -o isort main.o isort.o

main.o: main.c isort.h  
	$(CC) $(FLAGS) -c main.c 

isort.o:isort.c isort.h  
	$(CC) $(FLAGS) -c isort.c 


.PHONY: isort clean all txtfind

clean:
	rm -f *.o *.a *.so isort txtfind 
