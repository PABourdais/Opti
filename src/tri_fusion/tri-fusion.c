#include "tri-fusion.h"


/** fusion **/

void fusion(double t[], double t1[], uint64_t n, uint64_t n1, double tmp[]){
	int i = 0;
	int i1 = 0;
	int k = 0;

	while(i != n && i1 != n1) {
		if(t[i] < t1[i1]) {
			tmp[k] = t[i];
			i++;
		} else {
			tmp[k] = t1[i1];
			i1++;
		}
		k++;
	}
	if(i != n) {
		while(i != n) {
			tmp[k] = t[i];
			k++;
			i++; 
		}
	} else {
		while(i1 != n1) {
			tmp[k] = t1[i1];
			k++;
			i1++; 
		}
	}
}



/** diviser_monothread **/
/** n taille du tableau **/
void mergesort_monothread(double t[], uint64_t n, double tmp[]){
		int i; //itérateur du tableau final
		if(n<2){
			return;
		} else {

			mergesort_monothread(t, n/2, tmp); // Tri de la partie gauche
			mergesort_monothread(t+(n/2),n-(n/2), tmp); // Tri de la partie droite
			fusion(t, t+(n/2), n/2, n-(n/2), tmp); // Fusion des deux sous tableaux trié
			for(i=0; i<n; i++){ // t = tmp on recopie notre tableau
				t[i] = tmp[i];
			}
		}
}	

/**mergesort_multithread**/
void mergesort_multithread(double t[], uint64_t n, double tmp[], uint64_t compt) {
	if(n<2){
		return;
	} else {
		int i;
		if(compt < omp_get_thread_num()) {
			#pragma omp task firstprivate(t, n, tmp)
			mergesort_multithread(t, n/2, tmp, compt+1);
			#pragma omp task firstprivate(t, n, tmp)
			mergesort_multithread(t+(n/2), n-(n/2), tmp, compt+1);
		} else {
			mergesort_monothread(t, n/2, tmp);
			mergesort_monothread(t+(n/2), n-(n/2), tmp);
		}
		#pragma omp taskwait
		fusion(t, t+(n/2), n/2, n-(n/2), tmp);

		for(i = 0; i<n; i++) {
			t[i] = tmp[i];
		}
	}
}


