CC = gcc
CFALGS = -c -Wall

all: example

example: main.o functions.o 
	$(CC) main.o functions.o -o example

main.o: main.c
	$(CC) $(CFALGS) main.c

functions.o: functions.c
	$(CC) $(CFALGS) functions.c

clean:
	rm -rf *.o example

.PHONY: all clean