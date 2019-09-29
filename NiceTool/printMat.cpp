#include <stdio.h>
#include "sturctTempSet.h"

void printMat(double* arr, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%.2lf ", arr[i * col + j]);
		}
		printf("\n");
	}
	printf("\n");
}

void printMat(int* arr, int row, int col) {
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			printf("%d ", arr[i * col + j]);
		}
		printf("\n");
	}
	printf("\n");
}

void printMat(d_arr* arr) {
	for (int i = 0; i < arr->raw; i++) {
		for (int j = 0; j < arr->col; j++) {
			printf("%.2lf ", arr->arr[i * arr->col + j]);
		}
		printf("\n");
	}
	printf("\n");
}

void printMat(i_arr* arr) {
	for (int i = 0; i < arr->raw; i++) {
		for (int j = 0; j < arr->col; j++) {
			printf("%d ", arr->arr[i * arr->col + j]);
		}
		printf("\n");
	}
	printf("\n");
}