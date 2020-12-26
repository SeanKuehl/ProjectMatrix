//this will be for the menu and user input

#include <stdio.h>
#include "Functions.h"

int main(void) {

	int givenMatrix[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
	int** gottenMatrix = FindMinorMatrix(givenMatrix);

	//int** FindMinorMatrix(int[matrixWidthAndHieght][matrixWidthAndHieght]);

	return 0;
}