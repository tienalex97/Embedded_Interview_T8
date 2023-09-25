CC = g++
CFLAGS = -Wall

all: main.o MonAn.o Table.o
    $(CC) $(CFLAGS) -o main main.o MonAn.o Table.o

main.o: main.cpp MonAn.h Table.h
    $(CC) $(CFLAGS) -c main.cpp

Table.o: Table.cpp Table.h
    $(CC) $(CFLAGS) -c Table.cpp
    
MonAn.o: MonAn.cpp MonAn.h
    $(CC) $(CFLAGS) -c MonAn.cpp

clean:
    rm -f *.o main