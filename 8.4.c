#include <stdio.h>
#include <stdbool.h>

bool identity_matrix(int *matrix, int size) {
	int x, y;
	for(x = 0; x < size; x++) {
		for(y = 0; y < size; y++) {
			if (*matrix++ != (x == y)) {
				return false;
			}
		}
	}
	return true;
}
