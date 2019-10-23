#include <stdio.h>
#include <stdlib.h>
#include <crtdbg.h>
#include "Header.h"
#define Percep d_arr***
#define BLANK printf("\n");

void printPercep(Percep p);

int main() {
	d_arr *op1;
	op1 = initMat(10, 11, -1);
	relu(op1);

	printMat(op1);

	close();
	_CrtDumpMemoryLeaks();
	return 0;
}

void printPercep(Percep p) {
	int size = _msize(p[0]) / (sizeof(int) * 2); //W의 주소와 b의 주소를 가지기에 sizeof(int)에 X2

	printf("===================\n");
	for (int i = 0; i < size; i++) {
		shape(p[0][i]);
		BLANK;
		printf("W%d: \n", i + 1);
		printMat(p[0][i]);

		shape(p[1][i]);
		BLANK;
		printf("b%d: \n", i + 1);
		printMat(p[1][i]);

		printf("===================\n");
	}
}