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

		TEST_METHOD(TestESTpair5)
		{
			Assert::AreEqual(estPair(-3), 0);
		}
		//1) Non
		//2) Qu'elle est fausse
		//3) A la base ça ne marchais pas, j'ai du modifier le 0 afin que le chiffre soit pair a la fin de la fonction estPair pour que ça marche. C'est corrigée

		TEST_METHOD(TestMax1)
		{
			Assert::AreEqual(max2(2,3), 5);
		}

		TEST_METHOD(TestMax21)
		{
			Assert::AreEqual(max2(3,5), 5);
		}

		TEST_METHOD(TestMax22)
		{
			Assert::AreEqual(max2(-1,-8), -1);
		}

		TEST_METHOD(TestMax23)
		{
			Assert::AreEqual(max2(4,4), 4);
		}

	};
}
