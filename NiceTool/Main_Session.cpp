#include<stdlib.h>
#include "sturctTempSet.h"

static d_arr** MAT_SESS = (d_arr**)malloc(sizeof(d_arr*) * 100);
static int MAT_SESS_NUM = 0;

void hangMat(d_arr* mat) {
	MAT_SESS[MAT_SESS_NUM] = mat;
	MAT_SESS_NUM++;
}

void freeMat() {
	for (int i = 0; i < MAT_SESS_NUM; i++)
		free(MAT_SESS[i]);
	free(MAT_SESS);
}