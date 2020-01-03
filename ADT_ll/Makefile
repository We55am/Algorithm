CC = gcc
CFLAGS = -std=gnu99 -pedantic -Wall -Werror

node: node.o
	$(CC) $(CFLAGS) -o node.o

node.o: node.c
	$(CC) $(CFLAGS) -c node.c

.Phony = clean

clean:
	rm node *.o *~
