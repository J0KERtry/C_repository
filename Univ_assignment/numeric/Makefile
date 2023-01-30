all:

CC = gcc
CFLAGS = -O3 -std=gnu11 -Wall

main: main.tex
	platex $@
	dvipdfmx -p a4 $@

bit: bit.o
	$(CC) $(CFLAGS) -o $@ $^ -lm

diff: diff.o
	$(CC) $(CFLAGS) -o $@ $^ -lm

newton: newton.o
	$(CC) $(CFLAGS) -o $@ $^ -lm

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f bit diff newton *.o main.{aux,dvi,log,pdf}
