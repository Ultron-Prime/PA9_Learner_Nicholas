/* -------------------------------------------------
FILE:		proj9.cpp
DESCRIPTION:	proj9 C++ file for Project 9 for Fall 2019 CS 202-1001 at UNR
COMPILER:	g++ compiler
NOTES:		

MODIFICATION HISTORY:
Author			Date		Version
----------------	--------	-------
Version 1		YYYY-MM-DD	x.x Description
Nick Learner		2019-11-20	1.0 Created this file
*/

#include "ArrayQueue.h"
#include "NodeQueue.h"

using namespace std;

int main()
{
	DataType data[10];
	
	cout << endl << "An array of DataType objects,\n" <<
		"used later in the program for the ArrayQueue and NodeQueue objects" << endl;
	
	for (size_t i = 0; i < 10; ++i)
	{
		data[i].setIntVal((int)i);
		data[i].setDoubleVal(-1.1 * (double)i);
		cout << data[i] << endl;
	}
	
	ArrayQueue a1;
	NodeQueue n1;
	ArrayQueue a2 = a1;
	NodeQueue n2(n1);
	ArrayQueue a3(4, data[4]);
	NodeQueue n3(6, data[2]);
	
	
	cout << "\n\n" << "Initializaton/output tests" << "\n\n";
	
	cout << "a1" << endl << a1 << endl;
	cout << "n1" << endl << n1 << endl;
	cout << "a2" << endl << a2 << endl;
	cout << "n2" << endl << n2 << endl;
	cout << "a3" << endl << a3 << endl;
	cout << "n3" << endl << n3 << endl;
	
	
	cout << endl << "ArrayQueue tests" << "\n\n";
	
	cout << "a1.push(value)" << endl;
	a1.push(data[1]);
	cout << "new a1" << endl << a1 << endl;
	
	cout << "a2" << endl << a2 << endl;
	
	cout << "a2.push(value)" << endl;
	a2.push(data[2]);
	cout << "new a2" << endl << a2;
	cout << "a2.size() = " << a2.size() << "\n\n";
	
	cout << "a3.push(value)" << endl;
	a3.push(data[3]);
	cout << "new a3" << endl << a3;
	cout << "a3.size() = " << a3.size() << "\n\n";
	
	cout << "a1.pop(value)" << endl;
	a1.pop();
	cout << "new a1" << endl << a1 << endl;
	
	cout << "a2.pop(value)" << endl;
	a2.pop();
	cout << "new a2" << endl << a2 << endl;
	
	cout << "a3.pop(value)" << endl;
	a3.pop();
	cout << "new a3" << endl << a3 << endl;
	
	cout << "Without checking whether the queues are empty or not:" << endl;
	cout << "a1.front() = " << a1.front() << endl;
	cout << "a3.front() = " << a3.front() << endl;
	
	cout << "a1.back() = " << a1.back() << endl;
	cout << "a3.back() = " << a3.back() << endl;
	
	cout << "a2.size() = " << a2.size() << endl;
	cout << "a3.size() = " << a3.size() << endl;
	
	cout << endl << "Assigment operator test: a2 = a3" << endl;
	a2 = a3;
	cout << "new a2" << endl << a2 << endl;
	
	cout << "empty() tests" << endl;
	cout << "a1.empty() = " << boolalpha << a1.empty() << endl;
	cout << "a2.empty() = " << boolalpha << a2.empty() << endl;
	cout << "a3.empty() = " << boolalpha << a3.empty() << "\n\n";
	
	cout << "full() tests" << endl;
	cout << "a1.full() = " << boolalpha << a1.full() << endl;
	cout << "a2.full() = " << boolalpha << a2.full() << endl;
	cout << "a3.full() = " << boolalpha << a3.full() << "\n\n";
	
	cout << "a3.clear()" << endl;
	a3.clear();
	cout << "new a3" << endl << a3 << endl;
	
	
	cout << endl << "NodeQueue tests" << "\n\n";
	
	cout << "n1.push(value)" << endl;
	n1.push(data[9]);
	cout << "new n1" << endl << n1 << endl;
	
	cout << "n2" << endl << n2 << endl;
	
	cout << "n2.push(value)" << endl;
	n2.push(data[8]);
	cout << "new n2" << endl << n2;
	cout << "n2.size() = " << n2.size() << "\n\n";
	
	cout << "n3.push(value)" << endl;
	n3.push(data[7]);
	cout << "new n3" << endl << n3;
	cout << "n3.size() = " << n3.size() << "\n\n";
	
	cout << "n1.pop(value)" << endl;
	n1.pop();
	cout << "new n1" << endl << n1 << endl;
	
	cout << "n2.pop(value)" << endl;
	n2.pop();
	cout << "new n2" << endl << n2 << endl;
	
	cout << "n3.pop(value)" << endl;
	n3.pop();
	cout << "new n3" << endl << n3 << endl;
	
	cout << "Without checking whether the queues are empty or not:" << endl;
	/*cout << "n1.front() = " << n1.front() << endl;
	cout << "n3.front() = " << n3.front() << endl;
	
	cout << "n1.back() = " << n1.back() << endl;
	cout << "n3.back() = " << n3.back() << endl;*/
	
	cout << "n2.size() = " << n2.size() << endl;
	cout << "n3.size() = " << n3.size() << endl;
	
	cout << endl << "Assigment operator test: n2 = n3" << endl;
	n2 = n3;
	cout << "new n2" << endl << n2 << endl;
	
	cout << "empty() tests" << endl;
	cout << "n1.empty() = " << boolalpha << n1.empty() << endl;
	cout << "n2.empty() = " << boolalpha << n2.empty() << endl;
	cout << "n3.empty() = " << boolalpha << n3.empty() << "\n\n";
	
	cout << "full() tests" << endl;
	cout << "n1.full() = " << boolalpha << n1.full() << endl;
	cout << "n2.full() = " << boolalpha << n2.full() << endl;
	cout << "n3.full() = " << boolalpha << n3.full() << "\n\n";
	
	cout << "n3.clear()" << endl;
	n3.clear();
	cout << "new n3" << endl << n3 << endl;
	
	cout << "Destructors:" << endl;
	
	return 0;
}

