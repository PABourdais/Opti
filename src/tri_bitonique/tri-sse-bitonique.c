#include <x86intrin.h>
#include <emmintrin.h> 

void bitonic_sort_sse_16d(double table[]){
	int k;
	int temporaire;
	__m128d * tableau[8];
	double * tab_taille_2[2];
	//Insertion des valeurs du tab dans lse registres
	for(k=0; k<8; k++){
		//Avant l'insertion, on onrdonne 2 à 2
		if(table[2k]>tableau[2k+1]){
			temporaire = table[2k];
			table[2k] = table[2i+1];
			table[2k+1] = temporaire;	
		}
		tab_taille_2[0] = table[2k];
		tab_taille_2[1] = table[2k+1];
		tableau[k] = _mm_loadu_pd(tab_taille_2);
	}
	//Debut des opérations on suit le schéma du reaseau de tri bitonnique à 8 entrées
	for(k=0; k<4; k++){
		_mm_min_pd(tableau[2k], tableau[2k+1]);
	}
	_mm_min_pd(tableau[0], tableau[3]);
	_mm_min_pd(tableau[4], tableau[7]);
	_mm_min_pd(tableau[1], tableau[2]);
	_mm_min_pd(tableau[5], tableau[6]);
	for(k=0; k<4; k++){
		_mm_min_pd(tableau[2k], tableau[2k+1]);
	}
	for(k=0; k<4; k++){
		_mm_min_pd(tableau[k], tableau[7-k]);
	}
	_mm_min_pd(tableau[0], tableau[2]);
	_mm_min_pd(tableau[1], tableau[3]);
	_mm_min_pd(tableau[4], tableau[6]);
	_mm_min_pd(tableau[5], tableau[7]);
	for(k=0; k<4; k++){
		_mm_min_pd(tableau[2k], tableau[2k+1]);
	}
	//On sort les valeurs
}
