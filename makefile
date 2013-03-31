# tha 2/2012

CC = gcc
CF = -Wall -g

build:	main.o enc.o globals.o maindec.o dec.o
	$(CC) $(CF) main.o enc.o globals.o -o lz77_enc.e
	$(CC) $(CF) maindec.o dec.o globals.o -o lz77_dec.e

.c.o:
	$(CC) $(CF) -c $<

.cc.o:
	$(CC) $(CF) -c $<

clean:
	rm -f *.o *.e

all:
	@make -s clean
	make 
