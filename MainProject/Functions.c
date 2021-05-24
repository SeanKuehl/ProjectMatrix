//this is for the logic functions

#include <stdio.h>
#define smallerMatrixWidthAndHieght 2
#define matrixWidthAndHieght 3


//when it's multiplied with the a value it's not actually the minor,
//it's when it's not multiplied with the a value that it's the minor
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

int FindMinorWithoutMultiplicationByA(int x, int y, int matrix[matrixWidthAndHieght][matrixWidthAndHieght]) {
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
		for (int j = 0; j < maxXOrYValue; j++) {
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
	int result = (smallerMatrix[0][0] * smallerMatrix[1][1] - (smallerMatrix[0][1] * smallerMatrix[1][0]));
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

void FindMinorMatrix(int matrix[matrixWidthAndHieght][matrixWidthAndHieght]) {
	//create a matrix where each element is the minor of the 
	//one in the matrix passed to this function

	int minorMatrix[matrixWidthAndHieght][matrixWidthAndHieght];
	int maxXOrYValue = 3;

	int minorMatrixX = 0;
	int minorMatrixY = 0;
	int minorOfThisSpot = 0;

	for (int i = 0; i < maxXOrYValue; i++) {
		for (int j = 0; j < maxXOrYValue; j++) {
			minorOfThisSpot = FindMinorWithoutMultiplicationByA(i, j, matrix);
			

			minorMatrix[minorMatrixY][minorMatrixX] = minorOfThisSpot;
			
			minorMatrixX++;
			if (minorMatrixX == maxXOrYValue) {
				minorMatrixX = 0;
				minorMatrixY++;
			}
		}
	}

	for (int i = 0; i < maxXOrYValue; i++) {
		for (int j = 0; j < maxXOrYValue; j++) {
			matrix[i][j] = minorMatrix[i][j];
		}
		
	}

	


}

void FindFlippedMatrix(int matrix[matrixWidthAndHieght][matrixWidthAndHieght]) {

	//flip the numbers accross the diagonal(top left to bottom right diagonal)
	int firstSwapX = 1;
	int firstSwapY = 0;

	int secondSwapX = 2;
	int secondSwapY = 0;

	int thirdSwapX = 2;
	int thirdSwapY = 1;

	int valueAt = 0;
	int temp = 0;

	//these flippings are crude but I don't believe there's any good formula
	//for finding them

	valueAt = matrix[firstSwapY][firstSwapX];
	temp = matrix[firstSwapX][firstSwapY];
	matrix[firstSwapY][firstSwapX] = temp;
	matrix[firstSwapX][firstSwapY] = valueAt;

	valueAt = matrix[secondSwapY][secondSwapX];
	temp = matrix[secondSwapX][secondSwapY];
	matrix[secondSwapY][secondSwapX] = temp;
	matrix[secondSwapX][secondSwapY] = valueAt;

	valueAt = matrix[thirdSwapY][thirdSwapX];
	temp = matrix[thirdSwapX][thirdSwapY];
	matrix[thirdSwapY][thirdSwapX] = temp;
	matrix[thirdSwapX][thirdSwapY] = valueAt;

	

}

void FindNegativeMatrix(int matrix[matrixWidthAndHieght][matrixWidthAndHieght]) {
	int everyOtherCounter = 0;
	int numberToMakeNegativeOn = 1;
	int resetEveryOtherValue = 2;
	int maxXOrYValue = 3;

	for (int i = 0; i < maxXOrYValue; i++) {
		for (int j = 0; j < maxXOrYValue; j++) {
			if (everyOtherCounter == numberToMakeNegativeOn) {
				matrix[j][i] = matrix[j][i] * -1;
			}
			everyOtherCounter++;
			if (everyOtherCounter == resetEveryOtherValue) {
				everyOtherCounter = 0;
			}
		}
	}

	
}

//will need to do multi-layered approach to deal with 0 determinant case
void FindTransposeMatrix(int matrix[matrixWidthAndHieght][matrixWidthAndHieght]) {
	int maxXOrYValue = 3;

	double determinant = FindDeterminant(matrix);	//made this double to fix problem where inversed determinant is always zero
	
	if (FindDeterminant(matrix) == 0) {
		//using findDeterminant again because doubles are harder to check without using a tolerance
		printf("Matrix is singular, there is no corresponding transpose matrix.\n");
	}
	else {
		double inversedDeterminant = 1 / determinant;




		FindMinorMatrix(matrix);



		FindFlippedMatrix(matrix);




		FindNegativeMatrix(matrix);





		double transposeMatrix[matrixWidthAndHieght][matrixWidthAndHieght];


		//could get around just decimals by displaying matrix[i][j] / inversedDeterminant
		for (int i = 0; i < maxXOrYValue; i++) {
			for (int j = 0; j < maxXOrYValue; j++) {
				transposeMatrix[i][j] = inversedDeterminant * matrix[i][j];
				printf("%f, ", transposeMatrix[i][j]);
			}
			printf("\n\n");
		}
	}

	

}