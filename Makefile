CC=gcc
EXEC=checker

all:$(EXEC)

checker: checker.o
		$(CC) -o checker checker.o
checker.o:
		$(CC) -o checker.o -c checker.c -L
clean:
		rm -f *.o
