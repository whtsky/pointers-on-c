#include <stdio.h>
#include <string.h>

void dollars(char *dest, char const *src) {
	unsigned long len = strlen(src);
	*dest++ = '$';
	if(len >= 3) {
		int i;
		for(i = len - 2; i > 0; i--) {
			if(i % 3 == 0) {
				*dest++ = ',';
			}
			*dest++ = *src++;
		}
	} else {
		*dest++ = '0';
	}
	*dest++ = '.';
	*dest++ = len < 2 ? '0' : *src++;
	*dest++ = len < 1 ? '0' : *src;
	*dest = '\0';
}

int main(int argc, char *argv[]) {
	char dest[20];
	char *src = "113213212";
	
	dollars(dest, src);
	puts(dest);
	return 0;
}