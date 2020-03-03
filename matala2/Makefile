CC=gcc
AR=ar 
OBJECTS_MAIN=main.o
OBJECTS_BANK=myBank.o
FLAGS= -Wall -g

all: myBankLib main	
main: $(OBJECTS_MAIN) libmyBank.a 
	$(CC) $(FLAGS) -o main $(OBJECTS_MAIN) ./libmyBank.a
myBankLib:$(OBJECTS_BANK)
	$(AR) -rcs libmyBank.a $(OBJECTS_BANK)	
myBank.o: myBank.c myBank.h
	$(CC) $(FLAGS) -c myBank.c
main.o: main.c myBank.h  
	$(CC) $(FLAGS) -c main.c 

.PHONY: clean all myBankLib main

clean:
	rm -f *.o *.a *.so main 
