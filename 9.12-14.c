#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

bool prepare_key(char *key) {
	char *keyp, *write_p, *read_p, ch;
	if(*key == '\0') {
		return false;
	}

	for(keyp = key; (ch = *keyp) != '\0'; keyp++) {
		if(!isalpha(ch)) {
			return false;
		}
		*keyp = toupper(ch);
	}
	
	for(keyp = key; (ch = *keyp) != '\0'; ) {
		for(write_p = read_p = ++keyp; *read_p != '\0'; read_p++) {
			if(*read_p != ch) {
				*write_p++ = *read_p;
			}			
		}
		*write_p = '\0';
	}

	for(ch = 'A'; ch < 'Z'; ch++) {
		if(strchr(key, ch) == NULL) {
			*write_p = ch;
			*++write_p = '\0';
		}
	}

	return true;	
}

void encrypt(char *data, char const *key) {
	for(;*data != '\0'; data++) {
		if(isupper(*data)) {
			*data = key[*data - 'A'];
		} else if (islower(*data)) {
			*data = tolower(key[*data - 'a']);
		}
	}
}

void decrypt(char *data, char const *key) {
	bool is_lower;
	char ch;
	for(;(ch = *data) != '\0'; data++) {
		if(isalpha(ch)) {
			if (islower(ch)) {
				is_lower = true;
				ch = toupper(ch);
			}
			ch = 'A' + (strchr(key, ch) - key);
			if(is_lower) {
				ch = tolower(ch);
			}
			*data = ch;
		}
	}
}

int main(int argc, char *argv[]) {
	char keys[27] = "TRAILBLAZERS";
	char data[] = "abcdefg";
	prepare_key(keys);
	puts(keys);
	
	encrypt(data, keys);
	puts(data);
	
	decrypt(data, keys);
	puts(data);	
	return 0;	
}