CC = gcc
CFLAGS = -g -O1 -Wall

arrayList: arrayList.o main.o

arrayList.o: arrayList.h

main.o: arrayList.h

clean:
	rm -f *.o

