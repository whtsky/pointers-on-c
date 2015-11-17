#include <stdio.h>
#include <stdbool.h>

char *match(char *str, char const *match) {
	while(*match) {
		if(!(*match++ == *str++))
			return NULL;
	}
	return str;
}

int del_substr(char *str, char const *substr) {
	char *end;
	while(*str) {
		end = match(str, substr);
		if (end != NULL) {
			while((*str++ = *end++)) {
				;
			}
			return 1;
		}
		str++; 
	}
	return 0;
}

int main(int argc, char *argv[]) {
	char a[] = "heaheaaheheaa";
	char *b = "aa";
	del_substr(a, b);
	printf("%s", a);
	return 0;
}