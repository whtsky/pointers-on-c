#include <stdio.h>

void reverse_string(char *string) {
	char *start, *end, t;
	start = string;
	while(*string++) {
		;
	}
	end = string - 2;
	while(start < end) {
		t = *start;
		*start = *end;
		*end = t;
		start += 1;
		end -= 1;
	}
}

int main() {
	char s[] = "Hello";
	reverse_string(s);
	puts(s);
	return 0;
}
