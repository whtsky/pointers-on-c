#include <stdio.h>

int ascii_to_integer(char *string) {
	int current = 0;
	while(*string != '\0') {
		if (*string < '0' || *string > '9')
			return 0;
		current = current * 10 + (*string++ - '0');
	}
	return current;
}

int main(int argc, char *argv[]) {
	printf("%d", ascii_to_integer("233"));
}
