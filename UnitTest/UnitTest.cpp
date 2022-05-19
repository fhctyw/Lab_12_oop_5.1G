#include "pch.h"
#include "CppUnitTest.h"
#include "..\Lab_12_oop_5.1G\MyException.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			MyException e("some error");
			Assert::AreEqual(e.What(), "some error");
		}
	};
}
