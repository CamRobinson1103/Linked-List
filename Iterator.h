#pragma once
#include "Node.h"

template <typename T>
class Iterator
{
public:
	Iterator<T>();
	Iterator<T>(Node<T>* node);
	Iterator<T> operator ++();
	Iterator<T> operator --();
	const bool operator ==(const Iterator<T>& iter);
	const bool operator !=(const Iterator<T>& iter);
	T operator *();

private:
	Node<T>* current;
};

//Default constructor for Iterator
template<typename T>
inline Iterator<T>::Iterator()
{
	//Sets the variable current to nullptr
	current = nullptr;
}

//Constructor for Iterator that takes in a Mode as an argument
template<typename T>
inline Iterator<T>::Iterator(Node<T>* node)
{
	//Sets the variable current to node
	current = node;
}

//Operator overload for increment
template<typename T>
inline Iterator<T> Iterator<T>::operator++()
{
	//Checks to see if current's next is not nullptr
	if (current->next != nullptr)
	{
		//If so, sets current to be currents next and returns
		current = current->next;
		return *this;
	}
	return nullptr;
}

//Operator overload for decrement
template<typename T>
inline Iterator<T> Iterator<T>::operator--()
{
	//Checks to see if current's next is not nullptr
	if (current->next != nullptr)
	{
		//If so sets current to be current's next and returns
		current = current->next;
		return *this;
	}
	return nullptr;
}

//Operator overload for equal to
template<typename T>
inline const bool Iterator<T>::operator==(const Iterator<T>& iter)
{
	if (current != nullptr && iter.current != nullptr && current->data == &iter.current->data)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Operator overload for not equal to
template<typename T>
inline const bool Iterator<T>::operator!=(const Iterator<T>& iter)
{
	if (current == nullptr || iter.current == nullptr)
	{
		return false;
	}

	if (&current->data != &iter.current->data)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Operator overload for multiply
template<typename T>
inline T Iterator<T>::operator*()
{
	//Returns current's data
	return current->data;
}