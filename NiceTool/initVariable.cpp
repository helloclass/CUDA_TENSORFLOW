#include<stdlib.h>
#include<math.h>
#include"structTempSet.h"
#include"math_constants.h"
#include"simpleOp.h"

void random_normal(d_arr* data, double mean, double sd) {
	int size = data->raw * data->col;
	double const_num = 1 / (sd * sqrt(2.0 * CUDART_PI));
	double pow_2sd = (2 * pow(sd, 2));

	for (int i = 0; i < size; i++)
		data->arr[i] = const_num * exp(-(pow(i - mean, 2) / pow_2sd));
}

void truncated_normal(d_arr* data, double mean, double sd, double stddev) {
	int size = data->raw * data->col;
	double const_num = 1 / (sd * sqrt(2.0 * CUDART_PI));
	double pow_2sd = (2 * pow(sd, 2));

	for (int i = 0; i < size; i++) {
		data->arr[i] = exp(-(pow(i - mean, 2) / pow_2sd));
		data->arr[i] = (data->arr[i] > stddev) ? data->arr[i] : 0;
	}
}

void get_whitning(d_arr* data) {

}
