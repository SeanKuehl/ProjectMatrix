//this is for the logic functions

#include <stdio.h>
#define smallerMatrixWidthAndHieght 2
#define matrixWidthAndHieght 3

int FindMinor(int x, int y, int matrix[matrixWidthAndHieght][matrixWidthAndHieght]) {
	//I have to define it in order to pass it in

	//given an x and a y, find a(ei-hf) in matrix(this is the case if both x and y are 1)
	
	//a b c
	//d e f
	//g h i

	int maxXOrYValue = 3;
	int aValue = matrix[x][y];
	int smallerMatrix[smallerMatrixWidthAndHieght][smallerMatrixWidthAndHieght];
	int smallerMatrixRow = 0;
	int smallerMatrixColumn = 0;

	//now make a new array of just e,i,h,f by 
	//taking on those things in neither the row nor the column of a
	for (int i = 0; i < maxXOrYValue; i++) {
		for (int j = 0; j < maxXOrYValue;  j++) {
			//i is the row, j is the column
			if (i != x && j != y) {
				smallerMatrix[smallerMatrixRow][smallerMatrixColumn] = matrix[i][j];
				smallerMatrixRow++;
				if (smallerMatrixRow == smallerMatrixWidthAndHieght) {
					smallerMatrixRow = 0;
					smallerMatrixColumn++;
				}
			}
		}
	}

	//now put everything into the formula from above
	int result = aValue * (smallerMatrix[0][0] * smallerMatrix[1][1] - (smallerMatrix[0][1] * smallerMatrix[1][0]));
	return result;
	

}

int FindDeterminant(int matrix[matrixWidthAndHieght][matrixWidthAndHieght]) {
	//given the following the determinant is: minor(a) - minor(b) + minor(c)
	//a b c
	//d e f
	//g h i

	int aValueX = 0;
	int aValueY = 0;

	int bValueX = 0;
	int bValueY = 1;

	int cValueX = 0;
	int cValueY = 2;

	int minorA = FindMinor(aValueX, aValueY, matrix);
	int minorB = FindMinor(bValueX, bValueY, matrix);
	int minorC = FindMinor(cValueX, cValueY, matrix);

	int determinant = minorA - minorB + minorC;

	return determinant;


}