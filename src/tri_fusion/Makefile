CC = gcc 
CFLAGS = 

.PRECIOUS: %.s

.SUFFIXES:

all: tri-fusion-monothread tri-fusion-complexite tri-fusion-multithread tri-fusion-multithread-variable

tri-fusion-monothread: tri-fusion-monothread.c tri-fusion.c
	${CC} ${CFLAGS}  $^ -o bin/$@ 

tri-fusion-complexite: tri-fusion-complexite.c tri-fusion.c
	${CC} ${CFLAGS}  $^ -o bin/$@
	
tri-fusion-multithread: tri-fusion-multithread.c tri-fusion.c
	${CC} ${CFLAGS}  $^ -o bin/$@ -fopenmp
	
clean:
	rm -f bin/*
	
