CC = gcc
CFLAGS = -std=gnu99 -Wall -Werror -pedantic

hello: hello.c
	$(CC) $(CFLAGS) -o hello hello.c -lm

