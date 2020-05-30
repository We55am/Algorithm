CC = gcc
OBJS = image.c
CFLAGS = -std=gnu99 -Wall -Werror -pedantic
.RECIPEPREFIX = >

test : $(OBJS)
> $(CC)	$(CFLAGS) -o $@ $^
> @echo ""$@" Compiled successfully!"

clean:
> rm -rf test *.o *~ .#* *#
