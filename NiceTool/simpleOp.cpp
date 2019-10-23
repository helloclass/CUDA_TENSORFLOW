#include <stdio.h>
#include <math.h>
#include "structTempSet.h"
#include "initMat.h"
#include "math_constants.h"


void* copyMat(d_arr* a, d_arr* b) {
	d_arr* res;

	if ((a->raw - b->col) || (a->col - b->col)) {
		printf("You must match size of a, b dims\n");
		return NULL;
	}
	int size = a->raw * a->col;
	while (size)
		a->arr[size] = b->arr[size];
}

d_arr* addMat(d_arr* a, d_arr* b) {
	d_arr* res;

	if ((a->raw - b->col) || (a->col - b->col)){
		printf("You must match size of a, b dims\n");
		return NULL;
	}
	res = initMat(a->raw, a->col, 0);

	int size = a->raw * a->col;
	while (size)
		res->arr[--size] = a->arr[size] + b->arr[size];

	return res;
}

d_arr* subMat(d_arr* a, d_arr* b) {
	d_arr* res;

	if ((a->raw - b->col) || (a->col - b->col)) {
		printf("You must match size of a, b dims\n");
		return NULL;
	}
	res = initMat(a->raw, a->col, 0);

	int size = a->raw * a->col;
	while (size)
		res->arr[--size] = a->arr[size] - b->arr[size];

	return res;
}

d_arr* mulMat(d_arr* a, d_arr* b) {
	d_arr* res;

	if ((a->raw - b->col) || (a->col - b->col)) {
		printf("You must match size of a, b dims\n");
		return NULL;
	}
	res = initMat(a->raw, a->col, 0);

	int size = a->raw * a->col;
	while (size)
		res->arr[--size] = a->arr[size] * b->arr[size];

	return res;
}

d_arr* divMat(d_arr* a, d_arr* b) {
	d_arr* res;

	if ((a->raw - b->col) || (a->col - b->col)) {
		printf("You must match size of a, b dims\n");
		return NULL;
	}

	int size = a->raw * a->col;
	while (size)
		res->arr[--size] = a->arr[size] / b->arr[size];

	return res;
}

void add(d_arr* a, double x) {
	int size = a->raw * a->col;
	while (size)
		a->arr[--size] = a->arr[size] + x;
}

void sub(d_arr* a, double x) {
	int size = a->raw * a->col;
	while (size)
		a->arr[--size] = a->arr[size] - x;
}

void mul(d_arr* a, double x) {
	int size = a->raw * a->col;
	while (size)
		a->arr[--size] = a->arr[size] * x;
}

void div(d_arr* a, double x, int rev) {
	int size = a->raw * a->col;
	while (size) {
		if (!rev) a->arr[--size] = a->arr[size] / x;
		else a->arr[--size] = x / a->arr[size];
	}
}

void expMat(d_arr* a, double rev) {
	int size = a->raw * a->col;
	if (rev) rev *= -1;
	while (size)
		a->arr[--size] = exp(a->arr[size] * (rev));
}

double meanMat(d_arr* a) {
	double res = 0;
	for (int size = 0; size < (a->raw * a->col); size++)
		res += a->arr[size];
	res /= (a->raw * a->col);

	return res;
}

d_arr* rootMat(d_arr* a) {
	d_arr* res = initMat(a->raw, a->col, 0);
	for (int size = 0; size < (a->raw * a->col); size++)
		res->arr[size] += sqrt(a->arr[size]);

	return res;
}

d_arr* powMat(d_arr* a, int pow_num) {
	d_arr* res = initMat(a->raw, a->col, 0);
	for (int size = 0; size < (a->raw * a->col); size++)
		res->arr[size] += pow(a->arr[size], pow_num);

	return res;
}