#include <stdio.h>

static char *digits[] = {
	"", "ONE ", "TWO ", "THREE ", "FOUR ", "FIVE ", "SIX ", "SEVEN ",
	"EIGHT ", "NINE ", "TEN ", "ELEVEN ", "TWELVE ", "THIRTEEN ",
	"FOURTEEN ", "FIFTEEN ", "SIXTEEN ", "SEVENTEEN ", "EIGHTEEN ",
	"NINETEEN "
};

static char *tens[] = {
	"TWENTY ", "THIRTY ", "FORTY ", "FIFTY ", "SIXTY ", "SEVENTY ",
	"EIGHTY ", "NINETY "
};
static char *magnitudes[] = {
	"", "THOUSAND ", "MILLION ", "BILLION "
};

void write_three(unsigned int amount, char *buffer, char **mag) {
	if(amount >= 1000) {
		write_three(amount / 1000, buffer, mag+1);
		amount %= 1000;
	}
	if (amount >= 100) {
		strcat(buffer, digits[amount/100]);
		strcat(buffer, "HUNDRED ");
		amount %= 100;
	}
	if (amount >= 20) {
		strcat(buffer, tens[amount/10]);
		strcat(buffer, digits[amount%10]);
	} else {
		strcat(buffer, digits[amount]);
	}
	strcat(buffer, *mag);
}

void written_amount(unsigned int amount, char *buffer) {
	write_three(amount, buffer, &magnitudes);
}

int main(int argc, char *argv[]) {
	char buffer[1000] = "";
	written_amount(16312, buffer);
	puts(buffer);
	return 0;
}