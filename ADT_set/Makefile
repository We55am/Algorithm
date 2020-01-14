CC = gcc
CFLAGS = -std=gnu99 -Wall -Werror -pedantic
linkPATH = ../ADT_linked-list/linked-list.c

test: main.c set.o
	$(CC) $(CFLAGS) -o test main.c set.c $(linkPATH)

set.o: set.c
	$(CC) $(CFLAGS) -c set.c $(linkPATH)
