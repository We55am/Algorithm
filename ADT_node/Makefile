CC = gcc
CFLAGS = -std=gnu99 -pedantic -Wall -Werror

main: main.c node.o
	$(CC) $(CFLAGS) -o main main.c node.o

node.o: node.c
	$(CC) $(CFLAGS) -c node.c

.Phony = clean

clean:
	rm node *.o *~
