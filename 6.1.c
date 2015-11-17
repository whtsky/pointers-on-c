#include <stdio.h>

char *find_char(char const *source, char const *chars) {
	char *t;
	if (source == NULL || chars == NULL) {
		return NULL;
	}
	
	for(; *source != '\0'; source++) {
		for(t=chars; *t != '\0'; t++) {
			if (*source == *t)
				return *source;
		}
	}

	return source;
}
