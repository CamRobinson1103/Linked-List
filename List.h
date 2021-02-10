template<typename T>
class List
{
public:
	List<T>() { initialize(); };
	List<T> (const List<T>& other) { copyList(other); };
	~List<T>() { destroy(); };
	List<T>& operator= (List<T>& rhs);
	void initialize();
	bool isEmpty();
	void print();
	int getLength();
	void destroy();
	T front() const;
	T back() const;
	bool contains(const T& object) const;
	void pushFront(const T& object);
	void pushBack(const T& object);
	void deleteNode(const T& object);
	Iterator<T> begin();
	Iterator<T> end();

private:
	Node<T> m_first = nullptr;
	Node<T> m_last = nullptr;
	int m_nodeCount = 0;
};

template<typename T>
inline List<T>& List<T>::operator=(List<T>& rhs)
{
	// TODO: insert return statement here
}

template<typename T>
inline void List<T>::initialize()
{

}

template<typename T>
inline bool List<T>::isEmpty()
{
	return false;
}

template<typename T>
inline void List<T>::print()
{
	for (Iterator<int> iter = begin(); iter != end(); ++iter)
	{
		std::cout << *iter << std::endl;
	}
}

template<typename T>
inline int List<T>::getLength()
{
	return 0;
}

template<typename T>
inline void List<T>::destroy()
{
}

template<typename T>
inline T List<T>::front() const
{
	return T();
}

template<typename T>
inline T List<T>::back() const
{
	return T();
}

template<typename T>
inline bool List<T>::contains(const T& object) const
{
	return false;
}

template<typename T>
inline void List<T>::pushFront(const T& object)
{
}

template<typename T>
inline void List<T>::pushBack(const T& object)
{
}

template<typename T>
inline void List<T>::deleteNode(const T& object)
{
}

template<typename T>
inline Iterator<T> List<T>::begin()
{
	return Iterator<T>();
}

template<typename T>
inline Iterator<T> List<T>::end()
{
	return Iterator<T>();
}
