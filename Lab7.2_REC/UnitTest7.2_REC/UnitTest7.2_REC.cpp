#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab7.2_REC/Lab7.2_REC.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest72REC
{
	TEST_CLASS(UnitTest72REC)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			const int k = 3;
			const int n = 3;
			int** a = new int* [k];
			for (int i = 0; i < k; i++)
				a[i] = new int[n];

			a[0][0] = 10; a[0][1] = 20; a[0][2] = 30;
			a[1][0] = 5;  a[1][1] = 50; a[1][2] = 60;
			a[2][0] = 40; a[2][1] = 1;  a[2][2] = 2;

			int expectedSum = 16;
			int actualSum = sum(a, k, n);

			Assert::AreEqual(expectedSum, actualSum);
		}
	};
}
