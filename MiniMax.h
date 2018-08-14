#pragma once


int Max(int(*Q)[15], int deep, int alpha, int beta);
int Min(int(*Q)[15], int deep, int alpha, int beta);
void maxmin(int(*Q)[15], int deep, int *bestX, int *bestY);