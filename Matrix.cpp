// Matrix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	//Declaring variables
	int i, j, k;
	int rowCount, colCount;

	//Telling the users to input the Matrix dimesions
	cout << "Enter number of rows:";
	cin >> rowCount;
	cout << "Enter number of columns: ";
	cin >> colCount;

	//Dynamically allocating the rows of both matrix by pointing to a pointer and creating a new float pointer
	float **input_matrix = new float*[rowCount];
	float **trans_mat = new float*[colCount];

	//creating the columns of the matrix
	for (i = 0; i < rowCount; ++i)
		input_matrix[i] = new float[colCount];

	for (i = 0; i < colCount; ++i)
		trans_mat[i] = new float[rowCount];

	//Inputing values of the matrix and transposing them
	for (j = 0; j < rowCount; j++) {
		for (k = 0; k < colCount; k++) {
			cout << "Enter the value of array[" << j + 1 << "][" << k + 1 << "]: ";
			cin >> input_matrix[j][k];
			trans_mat[k][j] = input_matrix[j][k];
		}
		cout << "\n";
	}
	
	//printing input matrix and its transpose

	cout << "Your inputted matrix is a " <<rowCount <<" X " <<colCount <<" matrix displayed below: \n";

	for (j = 0; j < rowCount; j++) {
		for (k = 0; k < colCount; k++) {
			cout << input_matrix[j][k];
		}
		cout << "\n";
	}
	cout<<"\n It's transpose is a " <<colCount <<" X " <<rowCount <<" matrix displayed below : \n";

	for (j = 0; j < colCount; j++) {
		for (k = 0; k < rowCount; k++) {
			cout << trans_mat[j][k];
		}
		cout << "\n";
	}
	for (i = 0; i < rowCount; ++i) //deletes cooCount of input_matrix from hardware memory
		delete[] input_matrix[i];

	delete[] input_matrix; //deletes rowCount of input_matrix from hardware memory

	for (i = 0; i < colCount; ++i) //deletes column of trans_mat from hardware memory
		delete[] trans_mat[i];

	delete[] trans_mat; //deletes row of trans_mat from hardware memory
	return 0;
}
