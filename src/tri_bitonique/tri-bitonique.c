#include "tri-bitonique.h"


void bitonic_sort(double t[], uint64_t start, uint64_t n, int direction){
	if(n<2){

	} else {
		bitonic_sort(t, start, n/2, 1);
		bitonic_sort(t, start+(n/2), n/2, 0);
		bitonic_merge(t, start, n, direction);
	}
}

void bitonic_merge(double t[], uint64_t start, uint64_t n, int direction){
	if(n>1){
		bitonic_compare(t, start, n, direction);
		bitonic_merge(t, start, n/2, direction);
		bitonic_merge(t, start+(n/2), n/2, direction);
	}
}

void bitonic_compare(double t[], uint64_t start, uint64_t n, int direction){
	int i;

	for(i=start; i < start+(n/2); i++){
		if(direction == (t[i]>t[i+(n/2)])){
			int tmp = t[i];
			t[i] = t[i+(n/2)];
			t[i+(n/2)] = tmp;
		}
	}
}
