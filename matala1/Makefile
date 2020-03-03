CC=gcc
AR=ar 
OBJECTS_MAIN=main.o
OBJECTS_BASE=basicMath.o
OBJECTS_POW=power.o
FLAGS= -Wall -g

all: mymathd mymaths mains maind	
mains: $(OBJECTS_MAIN) libmyMath.a 
	$(CC) $(FLAGS) -o mains $(OBJECTS_MAIN) ./libmyMath.a
maind: $(OBJECTS_MAIN)
	$(CC) $(FLAGS) -o maind $(OBJECTS_MAIN) ./libmyMath.so
mymathd: $(OBJECTS_POW) $(OBJECTS_BASE)
	$(CC) -shared -o libmyMath.so $(OBJECTS_POW) $(OBJECTS_BASE)
mymaths:$(OBJECTS_POW) $(OBJECTS_BASE)
	$(AR) -rcs libmyMath.a $(OBJECTS_POW) $(OBJECTS_BASE)	
power.o: power.c myMath.h
	$(CC) $(FLAGS) -c power.c
basicMath.o: basicMath.c myMath.h
	$(CC) $(FLAGS) -c basicMath.c
main.o: main.c myMath.h  
	$(CC) $(FLAGS) -c main.c 

.PHONY: clean all mains maind mymaths mymathd

clean:
	rm -f *.o *.a *.so mymathd mymaths mains maind
