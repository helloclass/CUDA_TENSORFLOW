#pragma once
#ifndef SIMPLEOP_H
#define SIMPLEOP_H
#include "structTempSet.h"

void* copyMat(d_arr*, d_arr*);

d_arr* addMat(d_arr*, d_arr*);
d_arr* subMat(d_arr*, d_arr*);
d_arr* mulMat(d_arr*, d_arr*);
d_arr* divMat(d_arr*, d_arr*);

void add(d_arr*, double);
void sub(d_arr*, double);
void mul(d_arr*, double);
void div(d_arr*, double, int);
void expMat(d_arr*, double);

double meanMat(d_arr* a);
d_arr* rootMat(d_arr* a);
d_arr* powMat(d_arr* a, int pow_num);

#endif // !SIMPLEOP_H
