#include "structTempSet.h"
#include "math_constants.h"
#include "initMat.h"
#include "simpleOp.h"

void relu(d_arr* data) {
	int size = data->raw * data->col;
	while (size)
		data->arr[size] = (data->arr[--size] > 0) * data->arr[size];
}

void sigmoid(d_arr* data) {
	expMat(data, 1);
	add(data, 1);
	div(data, 1.0, 1);
}