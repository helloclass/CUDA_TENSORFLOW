#include<stdlib.h>
#include "structTempSet.h"

static int PERCEP_MAX_HANG_SIZE = 5;
static int MAT_MAX_HANG_SIZE = 5;

static d_arr**** PERCEP_SESS = (d_arr****)malloc(sizeof(d_arr***) * PERCEP_MAX_HANG_SIZE);
static d_arr** MAT_SESS = (d_arr**)malloc(sizeof(d_arr*) * MAT_MAX_HANG_SIZE);

static int PERCEP_SESS_NUM = 0;
static int MAT_SESS_NUM = 0;

void hangPerceptron(d_arr*** mat) {
	if (PERCEP_SESS_NUM == PERCEP_MAX_HANG_SIZE - 1) {
		PERCEP_MAX_HANG_SIZE *= 2;
		PERCEP_SESS = (d_arr****)realloc(PERCEP_SESS, sizeof(d_arr***) * PERCEP_MAX_HANG_SIZE);
	}
	PERCEP_SESS[PERCEP_SESS_NUM] = mat;
	PERCEP_SESS_NUM++;
}

void hangMat(d_arr* mat) {
	if (MAT_SESS_NUM == MAT_MAX_HANG_SIZE - 1) {
		MAT_MAX_HANG_SIZE *= 2;
		MAT_SESS = (d_arr**)realloc(MAT_SESS, sizeof(d_arr*) * MAT_MAX_HANG_SIZE);
	}
	MAT_SESS[MAT_SESS_NUM] = mat;
	MAT_SESS_NUM++;
}

void close() {
	for (int i = 0; i < MAT_SESS_NUM; i++) {
		free(MAT_SESS[i]->arr);
		free(MAT_SESS[i]);
	}

	for (int i = 0; i < PERCEP_SESS_NUM; i++) {
		/*MAT_SESS[What perceptron][0: W, 1: b][num_layer of perceptron][(if Weight)W_size1 or W_size2]*/
		free(PERCEP_SESS[i][0]);
		free(PERCEP_SESS[i][1]);
		free(PERCEP_SESS[i]);
	}

	free(MAT_SESS);
	free(PERCEP_SESS);
}
