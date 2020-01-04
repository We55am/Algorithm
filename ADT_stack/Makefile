CC = gcc
CFLAGS = -std=gnu99 -Wall -Werror -pedantic

stack: stack.o
	$(CC) $(CFLAGS) -o stack stack.o

stack.o: stack.c
	$(CC) $(CFLAGS) -c stack.c

.Phony = clean

clean:
	rm stack *.o *~
