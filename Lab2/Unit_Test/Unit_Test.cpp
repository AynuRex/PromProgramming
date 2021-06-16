#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab2/Header.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(X_One_solution)
		{
			double X = getX_case2(15,8,9,2,85,37);
			Assert::AreEqual(3.0, X);
		}
		TEST_METHOD(Y_One_solution)
		{
			double Y = getY_case2(15, 8, 9, 2, 85, 37);
			Assert::AreEqual(5.0, Y);
		}
		TEST_METHOD(y_when_x_is_any_case1)
		{
			double Y = getY_case4_1(0, 0, 0, 5, 0, 5);
			Assert::AreEqual(1.0, Y);
		}
		TEST_METHOD(y_when_x_is_any_case2)
		{
			double Y = getY_case4_1(0, 5, 0, 0, 30, 0);
			Assert::AreEqual(6.0, Y);
		}
		TEST_METHOD(y_when_x_is_any_case3)
		{
			double Y = getY_case4_2(0, 3, 0, 5, 0, 0);
			Assert::AreEqual(0.0, Y);
		}
		TEST_METHOD(y_when_x_is_any_case4)
		{
			double Y = getY_case4_2(0, 9, 0, 5, 27, 15);
			Assert::AreEqual(3.0, Y);
		}
		TEST_METHOD(x_when_y_is_any_case1)
		{
			double X = getX_case3_1(0, 0, 10, 0, 0, 95);
			Assert::AreEqual(9.5, X);
		}
		TEST_METHOD(x_when_y_is_any_case2)
		{
			double X = getX_case3_1(2, 0, 0, 0, 28, 0);
			Assert::AreEqual(14.0, X);
		}
		TEST_METHOD(x_when_y_is_any_case3)
		{
			double X = getX_case3_2(3, 0, 5, 0, 0, 0);
			Assert::AreEqual(0.0, X);
		}
		TEST_METHOD(x_when_y_is_any_case4)
		{
			double X = getX_case3_2(9, 0, 5, 0, 27, 15);
			Assert::AreEqual(3.0, X);
		}
		TEST_METHOD(k_case1)
		{
			double k, n;
			case1(0, 0, 18, 2, 0, 66, k, n);
			Assert::AreEqual(-9.0, k);
		}
		TEST_METHOD(n_case1)
		{
			double k, n;
			case1(0, 0, 18, 2, 0, 66, k, n);
			Assert::AreEqual(33.0, n);
		}
		TEST_METHOD(k_case2)
		{
			double k, n;
			case1(81, 9, 0, 0, 54, 0, k, n);
			Assert::AreEqual(-9.0, k);
		}
		TEST_METHOD(n_case2)
		{
			double k, n;
			case1(81, 9, 0, 0, 54, 0, k, n);
			Assert::AreEqual(6.0, n);
		}
		TEST_METHOD(k_case3)
		{
			double k, n;
			case1(3, 6, 6, 12, 9, 18, k, n);
			Assert::AreEqual(-0.5, k);
		}
		TEST_METHOD(n_case3)
		{
			double k, n;
			case1(3, 6, 6, 12, 9, 18, k, n);
			Assert::AreEqual(1.5, n);
		}
	};
}
