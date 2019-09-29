__host__ __device__
int get_raw(int idx, int K_k) {
	return idx / K_k;
}

__host__ __device__
int get_col(int idx, int K_k) {
	return idx % K_k;
}

__host__ __device__
void get_mul(double* res, double* a, double* b, int idx, int K_m, int K_n, int K_k ) {
	int m = get_raw(idx, K_k);
	int k = get_col(idx, K_k);

	for (int n = 0; n < K_n; n++)
		res[idx] = a[m * K_n + n] * b[n * K_k + k];
}

__global__
void mmul(double* a, double* b, double* res, int K_m, int K_n, int K_k) {
	int id = blockDim.x * blockIdx.x + threadIdx.x;

	if (id < K_m * K_k)
		get_mul(res, a, b, id, K_m, K_n, K_k);

}
