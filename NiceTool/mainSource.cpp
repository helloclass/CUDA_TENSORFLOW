#include <stdio.h>
#include <stdlib.h>
#include "calMain.h"
#include "printMat.h"
#include "sturctTempSet.h"
#include "Main_Session.h"
#include "initMat.h"

int main() {
	d_arr *op1, *op2, *res;
	int m, n, k;
	m = 4;
	n = 3;
	k = 5;

	op1 = initMat(m, n, 1);
	op2 = initMat(n, k, 2);

	res = matmul(op1, op2);

	printMat(res);

	freeMat();
	return 0;
}