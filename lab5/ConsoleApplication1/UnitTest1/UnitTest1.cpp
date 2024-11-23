#include "pch.h"
#include "CppUnitTest.h"
#include "C:\university\oipz\5 лб\lab5\ConsoleApplication1\ConsoleApplication1\ConsoleApplication1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		

		TEST_METHOD(TestIsValidInput_ValidData)
		{
			try
			{
				
				Assert::IsTrue(isValidInput(3, 1));  
			}
			catch (const std::exception& e)
			{
				Assert::Fail(L"Unexpected exception thrown.");
			}
		}

		TEST_METHOD(TestIsValidInput_InvalidData)
		{
			try
			{
				
				Assert::IsFalse(isValidInput(0, -1));  
			}
			catch (const std::exception& e)
			{
				Assert::Fail(L"Unexpected exception thrown.");
			}
		}

		TEST_METHOD(TestCalculateY_PositiveX)
		{
			try
			{
				
				double x = 3;
				int n = 3;
				double expected = 4.5;  
				double actual = calculateY(x, n);
				Assert::AreEqual(expected, actual, 0.001);
			}
			catch (const std::exception& e)
			{
				Assert::Fail(L"Unexpected exception thrown.");
			}
		}

		TEST_METHOD(TestCalculateY_ZeroX)
		{
			try
			{
				
				double x = 0;
				int n = 3;
				double expected = 0;  
				double actual = calculateY(x, n);
				Assert::AreEqual(expected, actual, 0.001);
			}
			catch (const std::exception& e)
			{
				Assert::Fail(L"Unexpected exception thrown.");
			}
		}
	};
}
