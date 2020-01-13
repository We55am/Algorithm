CC = gcc
CFLAGS = -std=gnu99 -Wall -Werror -pedantic
linkedPATH = ../ADT_linked-list/linked-list.c

test: main.c stack.o
	$(CC) $(CFLAGS) -o test stack.o main.c $(linkedPATH)
stack.o: stack.c
	$(CC) $(CFLAGS) -c stack.c $(linkedPATH)
