# This is a repository to collect my C Algorithms

## Introduction to Makefile

The make utility automatically determines which pieces of a large program need to be recompiled. To prepare to use make, you must write a file called the makefile that describes the relationships among files in your program and provides commands for updating each file.

### Any Makefile consists of "rules" with the following shape:

```makefile
target: prerequisites
	recipse
	...
	...
```

**target**: can be the generated file or action like "clean"

**prerequisites**: is the input used to generate the target.

**recipe**: actions "commands" needs to carry out.

"#" in a line of a makefile starts a comment.

## References

1. GNU Make Manual [https://www.gnu.org/software/make/manual/] 
2. Kyle Loudon. 1999. Mastering Algorithms with C (1st. ed.). O'Reilly Media, Inc.