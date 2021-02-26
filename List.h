#pragma once
#include "Iterator.h"
#include <iostream>
template <typename T>
class List
{
public:
	List() {};
	List(List<T>& otherList);

	/// Returns an Iterator pointing to the first Node in the List
	Iterator<T> begin() const;

	/// Returns the next item after the last Node in the List
	Iterator<T> end() const;

	/// Deletes all nodes in the List
	void destroy();

	/// Adds a new Node to the beginning of the List
	void pushFront(const T& value);

	/// Adds a new Node to the end of the List
	void pushBack(const T& value);

	/// Adds a new Node to the List at the given index
	bool insert(const T& value, int index);

	/// Removes all Nodes with the given value
	bool remove(const T& value);

	void sort();

	/// Prints the values of all the Nodes
	void print() const;

	void initialize();

	/// Checks to see if the given item is in the List
	bool contains(const T& object);

	/// Returns an empty list
	bool isEmpty() const;

	/// Gets data at thr given index
	bool getData(Iterator<T>& iter, int index);

	/// Returns the amount of Nodes in the List
	int getLength() const;

	void operator =(const List<T>& otherList);

private:
	Node<T>* m_first, m_head = Node<T>();
	Node<T>* m_last, m_tail = Node<T>();
	int m_nodeCount = 0;
};

template<typename T>
inline List<T>::List(List<T>& otherList)
{
	this = otherList;
}

template<typename T>
inline Iterator<T> List<T>::begin() const
{
	return Iterator<T>(m_first);
}

template<typename T>
inline Iterator<T> List<T>::end() const
{
	return Iterator<T>(m_last);
}

template<typename T>
inline void List<T>::destroy()
{
	for (Iterator<T> iter = begin(); iter != end(); ++iter)
	{
		remove(iter.m_current);
	}
}

template<typename T>
inline void List<T>::pushFront(const T& value)
{
	Node<T>* newNode = new Node<T>(value);
	m_first->previous = newNode;
	newNode->next = m_first;

	newNode->previous = nullptr;
	m_first = newNode;

	m_nodeCount++;

	if (m_nodeCount == 1)
		m_last = newNode;
	else if (m_nodeCount == 2)
		m_last = newNode->next;
}

template<typename T>
inline void List<T>::pushBack(const T& value)
{
	Node<T>* newNode = new Node<T>(value);
	m_last->next = newNode;
	newNode->previous = m_last;
	newNode->next = nullptr;
	m_last = newNode;

	m_nodeCount++;

	if (m_nodeCount == 1)
		m_first = newNode;
	else if (m_nodeCount == 2)
		m_first = newNode->previous;
}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	Iterator<T> iter = begin();
	for (int i = 0; i < index; i++)
		iter++;

	Node<T> newNode = new Node<T>(value);

	newNode.previous = iter.m_current.previous;
	newNode.next = iter.m_current;

	iter.m_current.previous->next = newNode;
	iter.m_current.previous = newNode;

	newNode.previous = newNode;

	if (iter.m_current == m_first)
		m_first = newNode;

	if (iter.m_current == m_last)
		m_last = newNode;

	m_nodeCount++;
	return true;

}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	Iterator<T> iter = Iterator<T>();
	for (Iterator<T> iter = begin(); iter != end(); ++iter)
		if (contains(value))
		{
			if (iter == m_first)
				m_first = iter--;

			iter.m_current.next.previous = iter.m_current.previous;
			iter.m_current.next = iter.m_current.next;

			delete(iter.m_current);
			m_nodeCount--;
			return true;
		}
	return false;
}

template<typename T>
inline void List<T>::sort()
{
	Iterator<T> iter = begin();
	Iterator<T> jter = end();
	for (int i = 0; i < getLength(); i++)
	{
		for (int j = getLength() - 1; j > i; j--)
		{
			getData(iter, j - 1);
			getData(jter, j);
			if (*jter < *iter)
			{
				Iterator<T> temp;
				temp = jter;
				jter = iter;
				iter = temp;
			}
		}
	}
}

template<typename T>
inline void List<T>::print() const
{
	for (Iterator<T> iter = begin(); iter != end(); iter = iter++)
		std::cout << *iter << " ";
	std::cout << std::endl;
}

template<typename T>
inline void List<T>::initialize()
{
	m_first = new Node<T>();
	m_last = new Node<T>();
	m_nodeCount = 0;
}

template<typename T>
inline bool List<T>::contains(const T& object)
{
	for (int i = 0; i < getLength(); i++)
		if (i == object)
			return true;
	return false;
}

template<typename T>
inline bool List<T>::isEmpty() const
{
	return (!m_first);
}

template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{
	iter = begin();

	for (int i = 0; i < index; i++)
	{
		iter = iter++;
	}

	return false;
}

template<typename T>
inline int List<T>::getLength() const
{
	return m_nodeCount;
}

template<typename T>
inline void List<T>::operator=(const List<T>& otherList)
{
	Iterator<T> tempIter = new Iterator<T>(begin());
	Iterator<T> tempIterOther = new Iterator<T>(otherList->m_first);
	while (tempIter.m_current != otherList.m_last)
	{
		for (int i = 0; i < otherList->getLength(); i++)
		{
			tempIter->m_current = tempIterOther->m_current;
		}
	};
}

