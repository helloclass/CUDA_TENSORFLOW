#include <stdlib.h>
#include "sturctTempSet.h"
#include "Main_Session.h"

d_arr* initMat(int row, int col, double val) {
	double* arr = (double*)malloc(sizeof(double) * row * col);
	for (int i = 0; i < row * col; i++)
		arr[i] = val;

	d_arr* res = (d_arr*)malloc(sizeof(d_arr));
	res->arr = arr;
	res->col = col;
	res->raw = row;

	hangMat(res);
	return res;
}

i_arr* initIntMat(int row, int col, int val) {
	int* arr = (int*)malloc(sizeof(double) * row * col);
	for (int i = 0; i < row * col; i++)
		arr[i] = val;

	i_arr* res = (i_arr*)malloc(sizeof(i_arr));
	res->arr = arr;
	res->col = col;
	res->raw = row;

	return res;
}