#include "pch.h"
#include "CppUnitTest.h"

extern "C" {
#include "../TP4_TU/TP4_TU.h" 
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TP4TUtest
{
	TEST_CLASS(TP4TUtest)
	{
	public:
		TEST_METHOD(TestESTpair1)
		{
			Assert::AreEqual(estPair(4) , 1);
		}
		TEST_METHOD(TestESTpair2)
		{
			Assert::AreEqual(estPair(7), 0);
		}
		TEST_METHOD(TestESTpair3)
		{
			Assert::AreEqual(estPair(0), 1);
		}
		TEST_METHOD(TestESTpair4)
		{
			Assert::AreEqual(estPair(-2), 1);
		}
		TEST_METHOD(TestESTpair5)
		{
			Assert::AreEqual(estPair(-3), 0);
		}
		
	};
}
