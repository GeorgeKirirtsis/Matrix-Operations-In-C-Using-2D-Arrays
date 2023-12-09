#pragma once

#ifndef OPERATIONS_H
#define OPERATIONS_H

void printMatrix(int** matrix, int* rows, int* columns);

int** reverseMatrix(int** matrix, int* rows, int* columns);

int** multiplyMatrices(int** matrixA, int** matrixB, int* rows, int* columns);

int** addMatrices(int** matrixA, int** matrixB, int* rows, int* columns);

int** createMatrix(int* rows, int* columns, char matrixName);

int isMultiplicationValid(int* rowsA, int* rowsB, int* columnsA, int* columnsB);

int areTheSameSize(int* rowsA, int* rowsB, int* columnsA, int* columnsB);

int isSquare(int* rows, int* columns);
#endif