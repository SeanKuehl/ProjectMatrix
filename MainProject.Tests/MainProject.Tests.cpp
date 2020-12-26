#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C" {
#include "Functions.h"
}

namespace MainProjectTests
{
	TEST_CLASS(FindMinorTests)
	{
	public:
		//these and determinant test cases from:
		//https://www.symbolab.com/solver/matrix-determinant-calculator/%5Cdet%20%5Cbegin%7Bpmatrix%7D1%20%26%202%20%26%203%20%5C%5C4%20%26%205%20%26%206%20%5C%5C7%20%26%208%20%26%209%5Cend%7Bpmatrix%7D?or=ex
		TEST_METHOD(FindMinor__0_0_____1_2_3_4_5_6_7_8_9____negative3)
		{
			int matrixToPass[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
			int x = 0;
			int y = 0;
			int expected = -3;
			int actual = FindMinor(x, y, matrixToPass);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FindMinor__0_1_____1_2_3_4_5_6_7_8_9____negative12)
		{
			int matrixToPass[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
			int x = 0;
			int y = 1;
			int expected = -12;
			int actual = FindMinor(x, y, matrixToPass);

			Assert::AreEqual(expected, actual);
		}


		TEST_METHOD(FindMinor__0_2_____1_2_3_4_5_6_7_8_9____negative9)
		{
			int matrixToPass[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
			int x = 0;
			int y = 2;
			int expected = -9;
			int actual = FindMinor(x, y, matrixToPass);

			Assert::AreEqual(expected, actual);
		}
	};


	TEST_CLASS(FindDeterminantTests)
	{
	public:
		//determinant test cases from:
		//https://www.symbolab.com/solver/matrix-determinant-calculator/%5Cdet%20%5Cbegin%7Bpmatrix%7D1%20%26%202%20%26%203%20%5C%5C4%20%26%205%20%26%206%20%5C%5C7%20%26%208%20%26%209%5Cend%7Bpmatrix%7D?or=ex
		TEST_METHOD(FindDeterminant_______1_2_3_4_5_6_7_8_9____0)
		{
			int matrixToPass[3][3] = { {1,2,3}, {4,5,6}, {7,8,9} };
			
			int expected = 0;
			int actual = FindDeterminant(matrixToPass);

			Assert::AreEqual(expected, actual);
		}


		
	};
}
