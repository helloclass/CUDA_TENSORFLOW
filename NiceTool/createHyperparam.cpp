#include "initMat.h"
#include "calMain.h"
#include "structTempSet.h"
#include "Main_Session.h"
#include <stdlib.h>

d_arr* getWeight(int row, int col, double init_val) {
	d_arr *W;
	W = initMat(row, col, init_val);

	return W;
}

d_arr* getBias(int col, double init_val) {
	d_arr *b;
	b = initMat(1, col, init_val);

	return b;
}

d_arr*** getPerceptron(int* size, double init_val) {
	int step = 0;
	int layer = (_msize(size) / sizeof(int)) - 1;

	d_arr*** perceptron = (d_arr***)malloc(2 * sizeof(d_arr**));
	for(int i = 0; i<2; i++)
		perceptron[i] = (d_arr**)malloc((layer) * sizeof(d_arr*));

	while (step < layer)
	{
		perceptron[0][step] = getWeight(size[step], size[step + 1], init_val);
		perceptron[1][step] = getBias(size[step + 1], init_val);
		step++;
	}

	hangPerceptron(perceptron);
	return perceptron;
}