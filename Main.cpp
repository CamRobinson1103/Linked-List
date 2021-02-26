#include <iostream>
#include "List.h";



int main()
{
	std::cout << "Making a Link List: " << std::endl;
	List<int>* list = new List<int>();

	std::cout << "Printing: " << std::endl;
	list->print();

	system("pause");

	std::cout << "Adding 2 nodes: " << std::endl;
	list->insert(5, 1);
	list->insert(4, 2);

	std::cout << "Printing: " << std::endl;
	list->print();

	system("pause");

	return 0;
}
