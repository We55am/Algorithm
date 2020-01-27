This is a repository to collect my C Algorithms.

Intro to Makefile:
The make utility automatically determines which pieces of a large program need to be recompiled. To prepare to use make, you must write a file called the makefile that describ s the relationships among files in your program and provides commands for upda ing each file.
Any Makefile consists of "rules" with the following shape:
    target ... : prerequisites ...
       	   recipe
       	   --
	   --
target: can be the generated file or action like "clean".
prerequisites: is the input files used to gerenate the trget.
recipe: actions "commands" needs to carry out.
'#' in a line of a makefile starts a comment.
"--file-name" tell make to read the file name as the makefile
Some Variables:
- .RECIPEPREFIX: A tab vairable.
- objects, OBJECTS, objs, OBJS, obj or OBJ (standard practice): vaiable contains all object files.


References:
1- GNU make manual https://www.gnu.org/software/make/manual/
2- Kyle Loudon. 1999. Mastering algorithms with c (1st. ed.). O’Reilly Media, Inc.