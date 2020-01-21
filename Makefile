#this is a comment it is ignored.
#You can name this file Makefile, makefile or GNUmakefile. (standarads).
CC = gcc
CFLAGS = -std=gnu99 -Wall -Werror -pedantic
.RECIPEPREFIX = >	#This variable replace the tab
OBJS = hello.o

hello : $(OBJS)
> $(CC) $(CFLAGS) -o hello $(OBJS) -lm

hello.o : hello.c
> $(CC) $(CFLAGS) -c hello.c -lm

.PHONY : clean
clean :
> rm -f *.o
> rm hello
