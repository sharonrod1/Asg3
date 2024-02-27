all:StrList

StrList: Main.o StrList.o
		gcc -Wall Main.o StrList.o -o StrList
Main.o: Main.c StrList.h
		gcc -Wall -c Main.c
StrList.o: StrList.c StrList.h
		gcc -Wall -c StrList.c

.PHONY: clean all

clean:
		rm *.o StrList