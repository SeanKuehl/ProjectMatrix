#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

extern "C" {
#include "Functions.h"
}

namespace MainProjectTests
{
	TEST_CLASS(MainProjectTests)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int matrixToPass[3][3] = { {0,0,0}, {0,0,0}, {0,0,0} };
			int x = 0;
			int y = 0;
			int expected = 0;
			int actual = FindMinor(x, y, matrixToPass);

			Assert::AreEqual(expected, actual);
		}
	};
}
