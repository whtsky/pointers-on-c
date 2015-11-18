#include <stdio.h>
#include <stdarg.h>

int print_integer(int d) {
	return printf("%d", d);
}

int print_float(double f) {
	return printf("%f", f);
}

int print_string(char *s) {
	int count = 0;
	while(*s) {
		putchar(*s++);
		count++;
	}
	return count;
}

int printf_s(char *format, ...) {
	va_list var_arg;
	int count = 0;
	va_start(var_arg, format);
	while(*format != '\0') {
		if(*format != '%') {
			putchar(*format++);
			continue;
		}
		switch(*++format) {
			case 'd':
				count += print_integer(va_arg(var_arg, int));
				break;
			case 'f':
				count += print_float(va_arg(var_arg, double));
				break;
			case 's':
				count += print_string(va_arg(var_arg, char *));
				break;
			case 'c':
				putchar(va_arg(var_arg, int));
				count += 1;
				break;
			default:
				fprintf(stderr, "烫烫烫");
		}
		format++;
	}
	va_end(var_arg);
	return count;

}

int main(int argc, char *argv[]) {
	printf_s("233%d %s %c", 23, "www", '6');
	return 0;
}