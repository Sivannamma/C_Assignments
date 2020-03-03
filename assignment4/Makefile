CC=gcc
AR=ar

FLAGS= -Wall -g

all:  frequency	

 
frequency: TrieFunc.o main.o
	$(CC)  $(FLAGS) -o frequency main.o TrieFunc.o



main.o: main.c Trie.h  
	$(CC) $(FLAGS) -c main.c 



TrieFunc.o: TrieFunc.c Trie.h
	$(CC) $(FLAGS) -c TrieFunc.c



.PHONY: frequency  clean all 

clean:
	rm -f *.o *.a *.so  frequency 
