//this will be for the menu and user input

#define _CRT_SECURE_NO_WARNINGS
#define EXIT_VALUE -1
#define MATRIX_SIZE 3

#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"

void FindTransposeMatrixUI();
void FindDeterminantOfMatrixUI();
void FindMinorMatrixUI();

int main(void) {

	

	int userInput = 0;

	while (userInput != EXIT_VALUE) {

		printf("\n\n\nWelcome to the matrix calculator!\n");
		printf("Press '1' if you want to find the transpose of a matrix\n");
		printf("Press '2' if you want to find the determinant of the matrix\n");
		printf("Press '3' if you want to find the minor matrix\n");
		printf("Press '-1' if you'd like to exit\n");
		printf("Input: ");

		scanf("%d", &userInput);

		switch (userInput) {
		case 1:
			//find the transpose of a matrix
			FindTransposeMatrixUI();
			break;

		case 2:
			//find the determinant of the matrix
			FindDeterminantOfMatrixUI();
			break;

		case 3:
			//find the matrix of minors
			FindMinorMatrixUI();
			break;

		case -1:
			//the user wants to exit
			printf("Thank you for using the matrix calculator.\n");
			printf("Goodbye!");
			exit(EXIT_SUCCESS);
			break;

		}


	}

	

	return 0;
}

void FindMinorMatrixUI() {
	int localUserInput = 0;

	int userMatrix[MATRIX_SIZE][MATRIX_SIZE] = { {0,0,0}, {0,0,0}, {0,0,0} };

	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int k = 0; k < MATRIX_SIZE; k++) {

			printf("\n\nPlease enter the number for the %d,%d spot\n", i + 1, k + 1);
			printf("input: ");

			scanf("%d", &localUserInput);
			userMatrix[i][k] = localUserInput;
		}
	}

	FindMinorMatrix(userMatrix);

	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int k = 0; k < MATRIX_SIZE; k++) {
			printf("%d, ", userMatrix[i][k]);
		}
		printf("\n");
	}

}

void FindDeterminantOfMatrixUI() {
	int localUserInput = 0;

	int userMatrix[MATRIX_SIZE][MATRIX_SIZE] = { {0,0,0}, {0,0,0}, {0,0,0} };

	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int k = 0; k < MATRIX_SIZE; k++) {

			printf("\n\nPlease enter the number for the %d,%d spot\n", i + 1, k + 1);
			printf("input: ");

			scanf("%d", &localUserInput);
			userMatrix[i][k] = localUserInput;
		}
	}

	int determinant = FindDeterminant(userMatrix);
	printf("\n\nThe determinant of the given matrix is: %d", determinant);

}

void FindTransposeMatrixUI() {
	int localUserInput = 0;

	int userMatrix[MATRIX_SIZE][MATRIX_SIZE] = { {0,0,0}, {0,0,0}, {0,0,0} };

	for (int i = 0; i < MATRIX_SIZE; i++) {
		for (int k = 0; k < MATRIX_SIZE; k++) {

			printf("\n\nPlease enter the number for the %d,%d spot\n", i + 1, k + 1);
			printf("input: ");

			scanf("%d", &localUserInput);
			userMatrix[i][k] = localUserInput;
		}
	}

	FindTransposeMatrix(userMatrix);

	
}