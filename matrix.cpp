#include <cstdio>
#include <iostream>
#include "matrix.h"

Matrix::Matrix(int rows, int cols)
{
    numberOfCols = cols;
    numberOfRows = rows;
    allocate_array();
    fill_array();
}

Matrix::~Matrix()
{
    for( int i = 0; i < numberOfRows; i++ )
    {
        free(arr[i]);
    }
    free(arr);
}

void Matrix::allocate_array(void)
{
    arr = (int**)malloc(numberOfRows * sizeof(int*));
    for (int i = 0; i < numberOfRows; i++)
        arr[i] = (int*)malloc(numberOfCols * sizeof(int));
}

void Matrix::fill_array(void)
{
    int t = 0;
    for (int y = 0; y < numberOfRows; y++)
    {
        for (int x = 0; x < numberOfCols; x++)
            arr[y][x] = ++t;
    }
}

std::string Matrix::get_array_string(void)
{
    return arr_string;
}

void Matrix::generate_spiral_string(void)
{
    arr_string = "";
    int number_of_elements = numberOfRows * numberOfCols;
    int t = 0;
    int leftBorder = 0;
    int rightBorder = numberOfCols-1;
    int topBorder = 0;
    int bottomBorder = numberOfRows-1;
    while ( number_of_elements > 0 )
    {
        for (t = leftBorder; t <= rightBorder && number_of_elements-- > 0; t++)
        {
            arr_string = arr_string + std::to_string(arr[topBorder][t]) + " ";
        }
        for (t = topBorder+1; t <= bottomBorder && number_of_elements-- > 0; t++)
        {
            arr_string = arr_string + std::to_string(arr[t][rightBorder]) + " ";
        }
        for (t = rightBorder-1; t >= leftBorder && number_of_elements-- > 0; t--)
        {
            arr_string = arr_string + std::to_string(arr[bottomBorder][t]) + " ";
        }
        for (t = bottomBorder-1; t > topBorder && number_of_elements-- > 0; t--)
        {
            arr_string = arr_string + std::to_string(arr[t][leftBorder]) + " ";
        }
        topBorder += 1;
        rightBorder -= 1;
        leftBorder += 1;
        bottomBorder -= 1;
    }
}
