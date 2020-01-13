CC = gcc
CFLAGS = -std=gnu99 -Wall -Werror -pedantic
linkPATH = ../ADT_linked-list/linked-list.c

test: main.c queue.o
	$(CC) $(CFLAGS) -o test main.c queue.o $(linkPATH)
queue.o: queue.c
	$(CC) $(CFLAGS) -c queue.c $(linkPATH)

