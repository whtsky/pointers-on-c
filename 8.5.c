#include <stdio.h>

void matrix_multiply(int *m1, int *m2, int *r, int x, int y, int z) {
	int i, j, k;
	
	for(i=0; i<x; i++) {
		for(j=0; i<z; j++) {
			*r = 0;
			for(k=0; k<y; k++) {
				*r += (*(m1 + i*y + k) * *(m2 + j + k*z));
			}
			r++;
		}
	}
}