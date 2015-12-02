#include <stdio.h>
#include <stdbool.h>

int solutions_count = 0;
int board[8][8] = {0};

void print_board(void) {
	printf("Solution: No.%d\n", ++solutions_count);
	int x, y;
	for(x=0; x<8; x++) {
		for(y=0; y<8; y++) {
			if(board[x][y]) {
				putchar('Q');
			} else {
				putchar('.');
			}
			putchar(' ');
		}
		putchar('\n');
	}
	printf("------------\n");
}

bool can_place(int row, int column) {
	int i, x, y;

	for(i=0; i<row; i++) {
		if(board[i][column]) {
			return false;
		}
	}
	
	for(i=0; i<column; i++) {
		if(board[row][i]) {
			return false;
		}
	}
	
	x = row;
	y = column;
	
	while(x >=0 && y >= 0) {
		if(board[x--][y--]) {
			return false;
		}
	}
	
	x = row;
	y = column;
	
	while(x >=0 && y < 8) {
		if(board[x--][y++]) {
			return false;
		}
	}
	
	return true;

}

void place_queen(int row) {
	int column;
	for(column=0; column<8; column++) {
		if(can_place(row, column)) {
			board[row][column] = true;
			if(row < 7) {
				place_queen(row+1);
			} else {
				print_board();
			}
			board[row][column] = false;
		}
	}
}

int main(int argc, char *argv[]) {
	place_queen(0);
}