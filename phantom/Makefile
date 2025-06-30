flags=-O2 -Wall -std=c11

.PHONY: all clean

all: clean phantom.exe

phantom.exe: phantom.o
        gcc $(flags) $^ -o $@ $(ldflags)

phantom.o: phantom.c phantom.h
        gcc $(flags) -c $<

clean:
        rm -f *.o phantom.exe