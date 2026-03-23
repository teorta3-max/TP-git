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

		//1) Non
		//2) Qu'elle est fausse
		//3) A la base ça ne marchais pas, j'ai du modifier le 0 afin que le chiffre soit pair a la fin de la fonction estPair pour que ça marche. C'est corrigée

		TEST_METHOD(TestMax1)
		{
			Assert::AreEqual(max2(5,3), 5);
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


		//1) c'est le 3eme test qui ne marche pas parce que c'est plus flagrant que le 1er et le 2eme test.
		//2) C'est corrigée, j'ai return soit l'un soit l'autre nombre selon lequel est le plus grand, même si les deux sont négatifs, ça marche aussi pour les positifs et les égaux.

		TEST_METHOD(TestFactorielle1)
		{
			Assert::AreEqual(factorielle(0), 1);	
		}

		TEST_METHOD(TestFactorielle2)
		{
			Assert::AreEqual(factorielle(1), 1);
		}

		TEST_METHOD(TestFactorielle3)
		{
			Assert::AreEqual(factorielle(4), 24);
		}

		TEST_METHOD(TestFactorielle4)
		{
			Assert::AreEqual(factorielle(5), 120);
		}

		//On ne peut pas faire la factorielle d'un nombre négatif.
		//1)Non car mathématiquement c'est impossible.
		//2) Il faudrai vérifier si n est bien superrieur ou égal a 0 avant de faire la boucle

		TEST_METHOD(contientMajuscule1)
		{
			Assert::AreEqual(contientMajuscule("bonjour"), 0);
		}

		TEST_METHOD(contientMajuscule2)
		{
			Assert::AreEqual(contientMajuscule("BonJour"), 1);
		}

		TEST_METHOD(contientMajuscule3)
		{
			Assert::AreEqual(contientMajuscule("ABC"), 1);
		}

		TEST_METHOD(contientMajuscule4)
		{
			Assert::AreEqual(contientMajuscule(""), 0);
		}

		//Si le pointeur egal NULL est passé en paramètre, la fonction ne marche pas et peut causer une erreur de segmentation.

		TEST_METHOD(contientMajuscule5)
		{
			Assert::AreEqual(contientMajuscule(NULL), 0);
		}

		TEST_METHOD(divisionExacte1)
		{
		Assert::AreEqual(divisionExacte(10,2), 1);
		}

		TEST_METHOD(divisionExacte2)
		{
			Assert::AreEqual(divisionExacte(10, 3), 0);
		}

		TEST_METHOD(divisionExacte3)
		{
			Assert::AreEqual(divisionExacte(0, 5), 1);
		}

		//1) parce que l'on ne peut pas diviser un nombre par 0, il faudrait vérifier que b n'est pas égal à 0 avant de faire le calcul.
		//2) Non, c'est corrigée, j'ai ajouté une condition pour vérifier que b n'est pas égal à 0 avant de faire le calcul.

		TEST_METHOD(divisionExacte4)
		{
			Assert::AreEqual(divisionExacte(10,0), 0);
		}

	};
}
