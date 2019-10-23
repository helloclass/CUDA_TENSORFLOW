#pragma once
#ifndef PRINTMAT_H
#define PRINTMAT_H
#include "structTempSet.h"

void printMat(double* arr, int row, int col);
void printMat(int* arr, int row, int col);
void printMat(d_arr* arr);
void printMat(i_arr* arr);
void shape(d_arr* arr);
void shape(i_arr* arr);

#endif // !PRINTMAT_H