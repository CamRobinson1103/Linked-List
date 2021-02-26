#include "List.h"
#include <iostream>

int main()
{
	List<int>* List2 = new List<int>();
	List2->initialize();

	List2->pushFront(2);
	List2->pushFront(4);
	List2->pushBack(6);
	List2->pushFront(8);
	List2->pushBack(10);
	List2->print();
	std::cout << std::endl;

	List2->sort();
	List2->print();

	system("pause");
	return 0;
};