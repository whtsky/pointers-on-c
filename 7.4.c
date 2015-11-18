#include <stdio.h>
#include <stdarg.h>

int max_list(int a, ...) {
	va_list var_arg;
	int max = a, now;
	va_start(var_arg, a);
	while ((now = va_arg(var_arg, int)) > 0) {
		if (now > max)
			max = now;
	}
	va_end(var_arg);
	return max;
}

int main(int argc, char *argv[]) {
	printf("%d", max_list(1, 2, 5, 4, 3, 7, 9, -1));
	return 0;
}