#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <stdio.h>
#include <stdlib.h>

void printMatrix(int** matrix, int* rows, int* columns)
{
    for(int i = 0; i < *rows; ++i)
    {
        for(int j = 0; j < *columns; ++j)
        {
            printf("\t%d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int** reverseMatrix(int** matrix, int* rows, int* columns)
{
    int* tempArr = (int*)malloc(sizeof(int) * *rows);
    
    int k = 0;
    for(int i = 0; i < *rows; i++)
    {
        for(int j = 0; j < *columns; j++)
        {
          
            tempArr[k] = matrix[i][j];
            k++;
            
        }
    }
    
    int counter = 0;
    for(int i = 0; i < *rows; ++i)
    {
        for(int j = 0; j < *columns; ++j)
        {
            matrix[i][j] = tempArr[*rows * *columns - counter -1];
            counter++;
        }
    }

    free(tempArr);
    return matrix;
    free(matrix);
}

int** multiplyMatrices(int** matrixA, int** matrixB, int* rows, int* columns)
{
    int** matrix = (int**)malloc(*rows * sizeof(int*));
    for(int i = 0; i < *rows; ++i)
        matrix[i] = (int*)malloc(*columns * sizeof(int));

    for(int i = 0; i < *rows; ++i)
    {
        for(int j = 0; j < *columns; ++ j)
        {
            matrix[i][j] = 0;
            for(int k = 0 ; k < *columns; ++k)
            {
                matrix[i][j] += matrixA[i][k] * matrixB[k][j];              
            }
        }
    }

    printf("\nMultiplication Matrix: \n\n");

    return matrix;
    free(matrix);
}

int** addMatrices(int** matrixA, int** matrixB, int* rows, int* columns)
{
    int** matrix = (int**)malloc(*rows * sizeof(int*));
    for(int i = 0; i < *rows; ++i)
        matrix[i] = (int*)malloc(*columns * sizeof(int));

    for(int i = 0; i < *rows; ++i)
    {
        for(int j = 0; j < *columns; ++j)
        {
            matrix[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }

    printf("\nMatrix A + Matrix B: \n\n");

    
    return matrix;
    free(matrix);
}

int** createMatrix(int* rows, int* columns, char matrixName)
{
    printf("Please Enter The Rows Of Matrix %c: ", matrixName);
    scanf("%d", &*rows);

    printf("Please Enter The Columns Of Matrix %c: ", matrixName);
    scanf("%d", &*columns);

    int** matrix = (int**)malloc(*rows * sizeof(int*));
    for(int i = 0; i < *rows; i++)
        matrix[i] = (int*)malloc(*columns * sizeof(int*));

    for(int i = 0; i < *rows; i++)
    {
        for(int j = 0; j < *columns; j++)
        {
            printf("Please Enter The Value Of mXn[%d][%d]: ", i+1, j+1);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nMatrix %c: \n\n", matrixName);

    return matrix;
    free(matrix);
}

int areTheSameSize(int* rowsA, int* rowsB, int* columnsA, int* columnsB)
{
    return(*rowsA == *rowsB && *columnsA == *columnsB);
}

int isMultiplicationValid(int* rowsA, int* rowsB, int* columnsA, int* columnsB)
{
    return((*rowsA == *columnsB && *columnsA == *rowsB));
}

int isSquare(int* rows, int* columns)
{
    return(*rows == *columns);
}
#endif