// Course:  CS213 - Programming II  - 2018
// Title:   Assignment I - Task 1 - Problem 0
// Program: CS213-2018-A1-T1-P0
// Purpose: Skeleton code for the student to start working
// Author:  Dr. Mohammad El-Ramly
// Date:    10 August 2018
// Version: 1.0
#include <bits/stdc++.h>
#include <iostream>
#include <iomanip>
//#include <cassert>

using namespace std;

// A structure to store a matrix
struct matrix
{
    int** data;       // Pointer to 2-D array that will simulate matrix
    int row, col;
};
//---------------------------------------------


// Already implemented
void createMatrix (int row, int col, int num[], matrix& mat);

// Student #1 with the smallest ID (e.g., 20170080)
// All these operations return a new matrix with the calculation result
matrix operator+  (matrix mat1, matrix mat2); // Add if same dimensions
matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar

// Student #2 with the middle ID (e.g., 20170082)
// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
// new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
// matrix with difference
matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);   	// Add 1 to each element ++mat
void   operator-- (matrix& mat);    	// Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);
// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
// and return istream to allow cascading input

//Student #3 with the biggest ID (e.g., 20170089)
ostream& operator<< (ostream& out, matrix mat);
// Print matrix  as follows (2 x 3)			4	 6 	  8
// and return ostream to cascade printing	9	12  	123
bool   operator== (matrix mat1, matrix mat2);	// True if identical
bool   operator!= (matrix mat1, matrix mat2); 	// True if not same
bool   isSquare   (matrix mat);  // True if square matrix
bool   isSymetric (matrix mat);  // True if square and symmetric
bool   isIdentity (matrix mat);  // True if square and identity
matrix transpose(matrix mat);    // Return new matrix with the transpose

//__________________________________________

int main()
{
    int data1 [] = {1,2,3,4,5,6,7,8};
    int data2 [] = {13,233,3,4,5,6};
    int data3 [] = {10,100,10,100,10,100,10,100};

    matrix mat1, mat2, mat3;
    createMatrix (4, 2, data1, mat1);
    createMatrix (2, 3, data2, mat2);
    createMatrix (4, 2, data3, mat3);
cout <<"enter the matrix \n";
matrix matt1,matt2;
cin >> matt1;
matt1 += matt2;
cout << matt1;
    /* The next code will not work until you write the functions
      cout << mat1 << endl;
      cout << mat2 << endl;
      cout << mat3 << endl;

      cout << (mat1 + mat3) << endl << endl;
      cout << (mat3 + mat3) << endl << endl;

      ++mat1;
      cout << mat1 << endl;

      mat1+= mat3 += mat3;
      cout << mat1 << endl;
      cout << mat2 << endl;
      cout << mat3 << endl;
      // Add more examples of using matrix
      // .......
    */
    return 0;
}

//__________________________________________
// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix (int row, int col, int num[], matrix& mat)
{
    mat.row = row;
    mat.col = col;
    mat.data = new int* [row];

    for (int i = 0; i < row; i++)
        mat.data[i] = new int [col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            mat.data[i][j] = num[i * col + j];
}
//------------------------------------------------
matrix operator+= (matrix& mat1, matrix mat2)
{
    for ( int i = 0 ; i<mat1.row ; i++)
    {
        for (int j =0 ; j<mat1.col ; j++)
        {

            mat1.data[i][j]= mat1.data[i][j] + mat2.data[i][j];

        }
    }
    return mat1;


}
//----------------------------------------------
matrix operator-= (matrix& mat1, matrix mat2)
{
    for ( int i = 0 ; i<mat1.row ; i++)
    {
        for (int j =0 ; j<mat1.col ; j++)
        {

            mat1.data[i][j]= mat1.data[i][j] - mat2.data[i][j];
        }

    }
    return mat1;


}
//------------------------------------------------
matrix operator+= (matrix& mat1, int scalar)
{

    for (int i = 0 ; i<mat1.row ; i++)
    {
        for (int j=0 ; j< mat1.col ; j++)
        {
            mat1.data[i][j]=(mat1.data[i][j]+scalar);

        }
    }
    return mat1;

}
//---------------------------------------------------
matrix operator-= (matrix& mat1, int scalar)
{

    for (int i = 0 ; i<mat1.row ; i++)
    {
        for (int j=0 ; j< mat1.col ; j++)
        {
            mat1.data[i][j]=(mat1.data[i][j]-scalar);

        }
    }
    return mat1;

}

//--------------------------------------------------------------
void operator++ (matrix& mat1 )
{
    for (int i = 0 ; i<mat1.row ; i++)
    {
        for (int j=0 ; j< mat1.col ; j++)
        {
            mat1.data[i][j]=(mat1.data[i][j]+1);

        }
    }


}
//----------------------------------------------------------
void operator-- (matrix& mat1 )
{
    for (int i = 0 ; i<mat1.row ; i++)
    {
        for (int j=0 ; j< mat1.col ; j++)
        {
            mat1.data[i][j]=(mat1.data[i][j]-1);

        }
    }


}
//------------------------------------------------------------
istream& operator>> (istream& in, matrix& mat)
{
for (int i = 0 ;i <mat.row ; i++)
{
 for (int j=0 ; j<mat.col ; j++)
    {

    in >> mat.data[i][j];
    }
}
    return in;
}

ostream& operator<< (ostream& out, matrix mat)
{
    for (int i=0;i<mat.col * mat.row ;i++)
        {
    out << mat.data[i];
        }
    return out;

}
