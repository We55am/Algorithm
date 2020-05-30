CC = gcc
OBJS = image.o image.c
CFLAGS = -std=gnu99 -Wall -Werror -pedantic
.RECIPEPREFIX = >

test : $(OBJS)
> $(CC)	$(CFLAGS) -o $@ $^
> @echo ""$@" Compiled successfully!"

image.o : image.c
> $(CC) $(CFLAGS) -c image.c

clean:
> rm -rf *.o *~ .#* *#
