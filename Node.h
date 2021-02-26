#pragma once
#include <iostream>
template <typename T>
struct Node
{
public:
	Node();
	Node(T value);
	Node<T>* next;
	Node<T>* previous;
	T data;
private:

};

//Default constructor for Node
template<typename T>
inline Node<T>::Node()
{

}

//Constructor for Node that takes in an argument "value"
template<typename T>
inline Node<T>::Node(T value)
{
	data = value;
}