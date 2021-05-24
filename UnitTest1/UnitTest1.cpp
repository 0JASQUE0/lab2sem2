#include "pch.h"
#include "CppUnitTest.h"
#include "D:\Прога 4 сем лабы\лаба 2\Project1\Shannon-Fano.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(searchMiddleTest)
		{
			LinkedList<int>* test = new LinkedList<int>;
			for (int i = 0; i < 10; i++)
				test->push_front(i);
			int mid = searchMiddle(test, 0, 9);
			Assert::IsTrue(mid == 2);
		}

		TEST_METHOD(bubbleSortTest)
		{
			LinkedList<int>* A = new LinkedList<int>;
			LinkedList<char>* B = new LinkedList<char>;
			LinkedList<char>* check = new LinkedList<char>;
			for (int i = 0; i < 5; i++) {
				A->push_back(i);
			}
			B->push_back('e');
			B->push_back('d');
			B->push_back('c');
			B->push_back('b');
			B->push_back('a');

			check->push_back('a');
			check->push_back('b');
			check->push_back('c');
			check->push_back('d');
			check->push_back('e');

			bubbleSort(B, A, 5);

			for (int i = 0; i < 5; i++) {
				Assert::IsTrue(A->at(4 - i)->data == i);
				Assert::IsTrue(B->at(i)->data == check->at(i)->data);
			}
		}

		TEST_METHOD(frequencyCountingTest)
		{
			LinkedList<int>* A = new LinkedList<int>;
			LinkedList<char>* B = new LinkedList<char>;
			string testStr = "aaa  b";
			LinkedList<int>* checkA = new LinkedList<int>;
			LinkedList<char>* checkB = new LinkedList<char>;

			checkA->push_back(3);
			checkA->push_back(2);
			checkA->push_back(1);

			checkB->push_back('a');
			checkB->push_back(' ');
			checkB->push_back('b');

			frequencyCounting(B, A, testStr);

			for (int i = 0; i < 3; i++) {
				Assert::IsTrue(A->at(i)->data == checkA->at(i)->data);
				Assert::IsTrue(B->at(i)->data == checkB->at(i)->data);
			}
		}

		TEST_METHOD(ShannonFanoTest)
		{
			string str = "it is test string";
			string test = "101 11 100 101 01 100 11 001 01 11 100 01 11 0001 101 00001 00000";
			string encodedString, decodedString;
			result(str, encodedString, decodedString);
			for (int i = 0; i < encodedString.length() - 1; i++)
			{
				Assert::IsTrue(encodedString[i] == test[i]);
			}

			for (int i = 0; i < decodedString.length() - 1; i++)
			{
				Assert::IsTrue(decodedString[i] == str[i]);
			}
		}
	};
}
