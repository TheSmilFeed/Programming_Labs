#include <iostream>
#include "array.h"
//#include "Lab5.1.cpp"

int matrixmult(double* matr1, int col1, int rows1, double* matr2, int col2, int rows2) {
	if (col1 == rows2) {
		col = col1; rows = rows2;
		matr = new double[rows * col];
		for (int i = 0; i < rows1; i++)
			for (int j = 0; j < col2; j++)
			{
				matr[i * col2 + j] = 0;
				for (int k = 0; k < col1; k++)
					matr[i * col2 + j] += matr1[i * col1 + k] * matr2[k * col2 + j];
			}
	}
}