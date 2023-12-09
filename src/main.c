#include <stdio.h>
#include "operations.h"

int main(int argc, char const *argv[])
{
    int rowsA, columnsA, rowsB, columnsB;
    
    int** matrixA = createMatrix(&rowsA, &columnsA,'A');
    printMatrix(matrixA, &rowsA, &columnsA);

    int** matrixB = createMatrix(&rowsB, &columnsB, 'B');
    printMatrix(matrixB, &rowsB, &columnsB);

    if(areTheSameSize(&rowsA, &rowsB, &columnsA, &columnsB))
    {
        int** additionMatrix = addMatrices(matrixA, matrixB, &rowsA, &rowsB);
        printMatrix(additionMatrix, &rowsA, &rowsB);
    }
    
    if(isMultiplicationValid(&rowsA, &rowsB, &columnsA, &columnsB))
    {
        int** multiplicationMatrix = multiplyMatrices(matrixA, matrixB, &rowsA, &columnsA);
        printMatrix(multiplicationMatrix, &rowsA, &columnsB) ;
    }
    
    if(isSquare(&rowsA, &columnsA))
    {
        printf("\nMatrix A - Reversed : \n\n");
        printMatrix(reverseMatrix(matrixA, &rowsA, &columnsA), &rowsA, &columnsA);
    }

    if(isSquare(&rowsB, &columnsB))
    {
        printf("\nMatrix B - Reversed : \n\n");
        printMatrix(reverseMatrix(matrixB, &rowsB, &columnsB), &rowsB, &columnsB);
    }
    
    return 0;
}
