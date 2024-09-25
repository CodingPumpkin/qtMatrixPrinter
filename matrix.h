#ifndef MATRIX_H
#define MATRIX_H

#include "string"
#include "print"
#include "stdlib.h"
//#include "stdio.h"

class Matrix
{
private:
    void allocate_array(void);
    int **arr;
    std::string arr_string;
    int numberOfRows, numberOfCols;

public:
    Matrix(int rows, int cols);
    ~Matrix();
    std::string get_array_string(void);
    void generate_spiral_string(void);
    void fill_array(void);
};

#endif // MATRIX_H
