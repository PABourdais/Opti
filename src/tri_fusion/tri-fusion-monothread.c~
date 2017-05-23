#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "rdtsc-timer.h"
#include <stdio.h>
#include "tri-fusion.h"
#define N_TABLEAU (int)pow(2,30)/(int)sizeof(double) // nombre de case pour un tableau de double de 1 GiB

/** Main **/
/*
*/
int main (int argc, char *argv[]){

	double * tab = (double *) malloc(N_TABLEAU * sizeof(double)); //Tableau de 1GiB à trier
	double * tmp = (double *) malloc(N_TABLEAU * sizeof(double)); //tableau temporaire pour le mergesort
	double time_0, time_1; // valeur pour le calcul du temps
	double avg, average; // moyenne 
	double tpscalcul;
	int k; // itérateur
	int nTest;
	int j;

	nTest = atoi(argv[1]); // Nbre de test
	avg = 0.0;
		
	for(k=0;k<nTest;k++){
		srand48(time(NULL));			
		fprintf(stdout,"Initialisation du tableau numéro %d\n",k);	
		for(j = 0; j < N_TABLEAU; j++){
			tab[j] = drand48()*64; // on génére un nombre entre [0;64]
		}
		TIME_START2(time_0);
		mergesort_monothread(tab, N_TABLEAU, tmp);
		TIME_STOP2(time_1); 
		tpscalcul = ((double)(time_1-time_0)); //calcul du temps du temps de calcul du tri
		fprintf(stdout,"Fin du test numéro %d en %lf s\n", k, tpscalcul);
		avg = avg + tpscalcul;
	}
	average = avg/nTest;
	fprintf(stdout,"Valeur moyenne du temps de calcul %lf s\n",average);
	free(tab); // libération de l'espace mémoire
	free(tmp);
	return EXIT_SUCCESS;
}
