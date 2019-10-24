#pragma once
#ifndef INITVARIABLE_H
#define INITVARIABLE_H
#include"structTempSet.h"

void random_normal(d_arr* data, double mean, double sd);
void truncated_normal(d_arr* data, double mean, double sd, double stddev);
void get_whitning(d_arr* data);

#endif