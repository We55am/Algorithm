CC = gcc
OBJS = list.o sort.o test.c
CFLAGS = -std=gnu99 -Wall -Werror -pedantic
.RECIPEPREFIX = >

test : $(OBJS)
> $(CC) $(CFLAGS) -o test $(OBJS)

test.o : test.c
> > $(CC) $(CFLAGS) -c test.c -lm

list.o : list.c
> $(CC) $(CFLAGS) -c list.c -lm

sort.o : sort.c
> $(CC) $(CFLAGS) -c sort.c -lm

clean:
> rm -rf *.o *~ .#* *#

