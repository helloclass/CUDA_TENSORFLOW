#include <stdio.h>
#include <stdlib.h>
#include "kernel.cuh"
#include "sturctTempSet.h"

d_arr* matmul(d_arr* op1, d_arr* op2)
{
	int m, n, k;
	m = op1->raw;
	n = op1->col;
	k = op2->col;

	double *res, *d_a, *d_b, *d_res;

	res = (double*)malloc(sizeof(double) * m * k);
	cudaMalloc(&d_a, sizeof(double) * m * n);
	cudaMalloc(&d_b, sizeof(double) * n * k);
	cudaMalloc(&d_res, sizeof(double) * m * k);

	for (int i = 0; i < m*k; i++)
		res[i] = 0.0;

	cudaMemcpy(d_a, op1->arr, sizeof(double) * m * n, cudaMemcpyHostToDevice);
	cudaMemcpy(d_b, op2->arr, sizeof(double) * n * k, cudaMemcpyHostToDevice);
	cudaMemcpy(d_res, res, sizeof(double) * m * k, cudaMemcpyHostToDevice);

	mmul<<<1, (m * k)>>>(d_a, d_b, d_res, m, n, k);

	cudaMemcpy(res, d_res, sizeof(double) * m * k, cudaMemcpyDeviceToHost);
	
	cudaFree(d_a);
	cudaFree(d_b);
	cudaFree(d_res);

	d_arr* res_arr = (d_arr*)malloc(sizeof(double) * m * k);
	res_arr->arr = res;
	res_arr->raw = m;
	res_arr->col = k;

	return res_arr;
}
