#include <stdio.h>
#include <stdbool.h>

#define N 1000

#define n_to_num(n) ((n*2) + 3)
#define num_to_n(num) ((num - 3) / 2)

int main() {
	bool nums[N];
	int i, current, max=n_to_num(N);
	for(i=0; i<N; i++) {
		*(nums+i) = true;
	}
	
	for(i=0; i<N; i++) {
		if(!*(nums+i)) {
			continue;
		}
		current = n_to_num(i);
		while (current += n_to_num(i), current <= max) {
			if(current % 2 == 0) {
				continue;
			}
			*(nums+num_to_n(current)) = false;
		}
	}
	
	printf("2 ");
	for(i=0; i<N; i++) {
		if(*(nums+i)) {
			printf("%d ", n_to_num(i));
		}
	}
}
