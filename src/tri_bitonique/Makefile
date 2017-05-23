CC = gcc 
CFLAGS = 

.PRECIOUS: %.s

.SUFFIXES:

all: tri-bitonique-calcul tri-bitonique-sequence tri-bitonique-complexite

tri-bitonique: tri-bitonique-calcul.c tri-bitonique.c
	${CC} ${CFLAGS}  $^ -o bin/$@ 

tri-seq-bitoniquee: tri-bitonique-sequence.c tri-bitonique.c
	${CC} ${CFLAGS}  $^ -o bin/$@
	
tri-bitonique-complexite: tri-bitonique-complexite.c tri-bitonique.c
	${CC} ${CFLAGS}  $^ -o bin/$@ 
	
clean:
	rm -f bin/*
	
