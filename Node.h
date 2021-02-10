#pragma once
#include <iostream>
template<typename T>
class Node
{
public:
	Node<T>();
	Node<T>* next;
	Node <T>* previous;
	T data;

private:

};

template<typename T>
inline Node<T>::Node()
{
}
