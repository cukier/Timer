CC=ccsc
CFLAGS=+FH +LN -T -A -M -Z +DF +Y=9 +STDOUT

all: Timer

Timer: timer.c
	$(CC) $(CFLAGS) timer.c

clean:
	rm *.cof *.err *.esym *.hex *.lst *.DBK