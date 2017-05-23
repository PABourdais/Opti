#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "rdtsc-timer.h"
#include "tri-fusion.h"

int main(int argc, char *argv[]) {
	uint64_t N_MAX = (uint64_t)(240*1024L*1024L)/(uint64_t)sizeof(double); // 240 MiB
	double * tab = (double *) malloc(N_MAX*sizeof(double)); // malloc alloue en octet
	double * tmp = (double *) malloc(N_MAX*sizeof(double));
	double time_0;
	double time_1;
	double avg;
	double average;
	double tpscalcul;
	uint64_t n;
	uint64_t j;
	uint64_t k;
	int nTest;

	nTest = atoi(argv[1]); // Nbre de test		
	
	for(n=N_MAX/100;n<N_MAX;n+=N_MAX/100){ // on fait un incrément de 1/100 qui permet d'augmenter la taille du tableau
			avg = 0.0;
			for(j=0; j<nTest;j++){
				/*Initialisation*/
				srand48(n);
				for(k = 0; k < n; k++){ // on initialise le tableau jusqu'à ns
					tab[k] = drand48()*64;
				}
				printf("tableau initialisé pour n = %ld\n", n);

				TIME_START2(time_0);
				mergesort_monothread(tab, n, tmp); 
				TIME_STOP2(time_1);

				tpscalcul = ((double)(time_1-time_0));
				avg = avg + tpscalcul;
				printf("n : %ld temps exécution : %f\n",n, tpscalcul);
			}
			average = avg/nTest;
			FILE* fichier = NULL;
		  fichier = fopen("tri-fusion-complexite.txt", "a+");
		  if (fichier != NULL){
					fprintf(fichier, "%ld\t%e\n",n,average);
		      fclose(fichier);
		  }
	}

	free(tab);
	free(tmp);
	return 0;
}
