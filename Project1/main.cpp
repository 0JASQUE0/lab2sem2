#include <iostream>
#include "RBTree.h"
#include "list.h"
#include "queue.h"
#include <string>
#include "Shannon-Fano.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	string str = "in vino veritas in aqua sanitas";

	cout << str << endl;

	string encodedString;
	string decodedString;

	result(str, encodedString, decodedString);

	return 0;
}