# tha 2/2012

CC = gcc
CF = -Wall -g

build:	main.o enc.o globals.o
	$(CC) $(CF) main.o enc.o globals.o -o lz77_enc.e

.c.o:
	$(CC) $(CF) -c $<

.cc.o:
	$(CC) $(CF) -c $<

clean:
	rm -f *.o *.e

all:
	@make -s clean
	make 
