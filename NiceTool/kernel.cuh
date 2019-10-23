#ifndef KERNEL_CUH
#define KERNEL_CUH

#include<omp.h>
#include<cuda.h>

__host__ __device__
int get_raw(int idx, int K_n);

__host__ __device__
int get_col(int idx, int K_k);

__host__ __device__
void get_mul(double* res, double* a, double* b, int idx, int K_m, int K_n, int K_k);

__global__
void mmul(double*, double*, double*, int, int, int);

//__host__ __device__
//void get_mul(double* res, double* a, double* b, int idx, int m, int n, int k);
//
//__global__
//void mmul(double* a, double* b, double* res, int m, int n, int k);

#endif