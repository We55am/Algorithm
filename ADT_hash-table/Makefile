CC = gcc
CfLAGS = -Wall -Werror -pedantic -std=gnu99
linkPATH = ../ADT_linked-list/linked-list.c

test: main.c hash.c
	$(CC) $(CFLAGS) -o test main.c hash.c $(linkPATH)

hash.o: hash.c
	$(CC) $(CFLAGS) -c hash.c
