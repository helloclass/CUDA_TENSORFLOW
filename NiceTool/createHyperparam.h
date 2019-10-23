#pragma once
#ifndef CREATEHYPERPRAM_H
#define CREATEHYPERPRAM_H

#include "structTempSet.h"

d_arr* getWeight(int row, int col, double init_val);
d_arr* getBias(int col, double init_val);
d_arr*** getPerceptron(int* size, double init_val);
#endif