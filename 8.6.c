#include <stdio.h>
#include <stdarg.h>

int array_offset(int arrayinfo[], ...) {
	va_list offsets;
	int rv = 0, ndim = *arrayinfo++;
	int offset, current, low, high;
	if(ndim < 1 || ndim > 10) {
		return -1;
	}
	va_start(offsets, arrayinfo);
	for(offset=0; offset<ndim; offset++) {
		current = va_arg(offsets, int);
		low = *arrayinfo++;
		high = *arrayinfo++;
		if(current < low || current > high) {
			va_end(offsets);
			return -1;
		}
		rv *= high - low + 1;
		rv += current - low;
	}
	va_end(offsets);
	return rv;
}

int main(int argc, char *argv[]) {
	// Copied from https://github.com/dielew/pts_on_c/blob/master/p8_8_6.c
	int arrayinfo[10] = {3, 4, 6, 1, 5, -3, 3};

	printf("%d\n", array_offset(arrayinfo, 4, 1, -3));
	printf("%d\n", array_offset(arrayinfo, 4, 1, -2));
	printf("%d\n", array_offset(arrayinfo, 4, 1, 3));
	printf("%d\n", array_offset(arrayinfo, 4, 2, -3));
	printf("%d\n", array_offset(arrayinfo, 5, 1, -3));
	printf("%d\n", array_offset(arrayinfo, 6, 3, 1));

	return 0;
}