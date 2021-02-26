#include <iostream>
#include "Iterator.h";
#include "Node.h";

template<typename T>
class List
{
public:
	//List()

	List<T>();
	List(List<T>& list);
	~List<T>();

	void destroy();

	const Iterator<T> begin();
	const Iterator<T> end();


	bool contains(const T& object);

	const void pushFront(const T& object);
	void pushBack(const T& object);

	bool insert(const T& value, int index);
	bool remove(const T& value);


	void print();
	void initialize();
	bool isEmpty();
	bool getData(Iterator<T>& iter, int index);
	const int getLength();


	const List<T>& operator= (const List<T>& otherList);

	void sort();

private:
	Node<T>* m_first;
	Node<T>* m_last;
	int m_nodeCount = 0;
};

template<typename T>
inline List<T>::List()
{
}

template<typename T>
inline List<T>::~List()
{
	delete List<T>;
}

template<typename T>
inline List<T>::List(List<T>& list)
{
	this = list;
}

template<typename T>
inline void List<T>::initialize()
{
	m_first = nullptr;
	m_last = nullptr;
	m_first->previous = nullptr;
	m_last->next = nullptr;
}


template<typename T>
inline bool List<T>::isEmpty()
{
	bool isItEmpty = false;


}

//sets the given iterator to the point to a node at the given index
template<typename T>
inline bool List<T>::getData(Iterator<T>& iter, int index)
{
	bool gotData = false;
	auto iter = List->begin();

	while (iter != List->end())
	{
		iter++;

		if (iter = index)
		{
			gotData = true;
			iter++;
		}
	}

	return gotData;
}

template<typename T>
inline const int List<T>::getLength()
{
	int length = 0;
	for (Iterator i = m_first; i < m_last; i++)
	{
		length++;
	}
	return length;
}

template<typename T>
inline const List<T>& List<T>::operator=(const List<T>& otherList)
{
	Iterator<T> tempIter = new Iterator(begin());
	Iterator<T> tempIterOther = new Iterator(otherList->m_first);
	while (tempIter != otherList->m_last);
	{
		for (int i = 0; i < otherList->getLength(); i++)
		{
			tempIter.m_current = tempIterOther->m_current;
		}
	}

}

template<typename T>
inline void List<T>::sort()
{
	for (int i = 0; i < m_nodeCount; i++)
	{
		for (int j = m_nodeCount - 1; j > i; j--)
		{
			if (Iterator<T>.m_current < Iterator<T>.next)
			{
				T temp = Iterator<T>.m_current;
				Iterator* m_current = this.next;
				this.next = temp;
			}

		}
	}
}

template<typename T>
inline void List<T>::destroy()
{
	for (Iterator<T> iter = begin(); iter != end(); ++iter)
		remove(iter.m_current);
}

template<typename T>
inline const Iterator<T> List<T>::begin()
{
	return Iterator<T>(m_first);
}

template<typename T>
inline const Iterator<T> List<T>::end()
{
	return Iterator<T>(m_last);
}

//this prints the values for all the nodes
template<typename T>
inline void List<T>::print()
{
	for (Iterator<int> iter = begin(); iter != end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
}

//checks to see if the given items is in the list
template<typename T>
inline bool List<T>::contains(const T& object)
{
	bool isThere = false;
	Iterator iter = begin();

	while (iter != end())
	{
		iter++;

		if (iter == object)//this will check if the object is actually there and if it is, it will say isThere is true
		{
			isThere = true;
		}
	}

	return isThere;
}

template<typename T>
inline const void List<T>::pushFront(const T& object)
{
	Node<T> newFirst = new Node<T>;

	newFirst->m_nodeCount = object;

	newFirst->next() = (*m_first);
	newFirst->previous() = nullptr;

	//this is when he previous head is the new Node
	if ((*m_first) != nullptr)
		(*m_first)->previous = newFirst;

	//the head points to the new node
	(*m_first) = newFirst;
	return void();
}

template<typename T>
inline void List<T>::pushBack(const T& object)
{
	Node<T>* newNode = new Node<T>(object);

	Node<T>* last = *m_first;
	//was originially m_last

	newNode->data = object;

	newNode->next = nullptr;

	if (*m_first == nullptr)
	{
		newNode->previous = nullptr;
		*m_first = newNode;
		return;
	}

	while (m_last->next != nullptr)
	{
		last = m_last->next;
		last->previous = last;

		newNode->previous = last;
		return;
	}

}

template<typename T>
inline bool List<T>::insert(const T& value, int index)
{
	bool isInserted = false;
	Node<T>* temp = &Node<T>(value);
	Iterator<T> iter = begin();

	temp->next = m_first;
	m_first->previous = temp;
	isInserted = true;

	return isInserted;
}

template<typename T>
inline bool List<T>::remove(const T& value)
{
	bool isRemoved = false;

	if (value != nullptr)
	{
		value = value.previous;
		delete value;
		isRemoved = true;
	}

	return isRemoved;
}

