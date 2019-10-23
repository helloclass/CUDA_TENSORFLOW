#pragma once
#ifndef MAIN_SESSION_H
#define MAIN_SESSION_H

static int PERCEP_MAX_HANG_SIZE;
static int MAT_MAX_HANG_SIZE;

static d_arr**** PERCEP_SESS;
static d_arr** MAT_SESS;

static int PERCEP_SESS_NUM;
static int MAT_SESS_NUM;

void hangPerceptron(d_arr*** mat);
void hangMat(d_arr* mat);
void close();

#endif // !MAIN_SESSION_H
