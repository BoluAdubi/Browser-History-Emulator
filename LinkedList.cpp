template <typename T>
LinkedList<T>::LinkedList()
{
	m_front = nullptr;
	m_length = 0;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
	clear();
}

template <typename T>
void LinkedList<T>::insert(int index, T entry)
{
	Node<T>* insertion = new Node<T>(entry);
	
	if(!(index > 0 && index <= m_length + 1))
	{
		throw(std::runtime_error("Invalid index"));
	}
	else if(index == 1) // if inserting at the front of the list
	{
		insertion -> setNext(m_front);
		m_front = insertion;
		m_length++;
	}
	else if(index == m_length + 1) // if inserting at the end of the list
	{
		Node<T>* endPtr = m_front;
		while(endPtr -> getNext() != nullptr)
		{
			endPtr = endPtr -> getNext();
		}
		endPtr -> setNext(insertion);
		m_length++;
	}
	else
	{
		Node<T>* beforePtr = m_front;
		Node<T>* afterPtr = m_front;
		
		// parse to node before given index
		for(int i = 1; i < index - 1; i++)
		{
			beforePtr = beforePtr -> getNext();
		}
		
		// parse to node after given index
		for(int i = 1; i <= index - 1; i++)
		{
			afterPtr = afterPtr -> getNext();
		}
		
		// insert node at given index
		beforePtr -> setNext(insertion);
		insertion -> setNext(afterPtr);
		m_length++;
	}
}

template <typename T>
void LinkedList<T>::remove(int index)
{
	if(m_length == 0)
	{
		throw(std::runtime_error("List is empty"));
	}
	else if(!(index > 0 && index <= m_length + 1))
	{
		throw(std::runtime_error("Invalid index"));
	}
	else if(index == 1)
	{
		Node<T>* temp = m_front;
		m_front = m_front -> getNext();
		delete temp;
		m_length--;
	}
	else if(index >= 2 &&  index <= m_length)
	{
		Node<T>* before = m_front;
		
		for(int i = 1; i < index - 1; i++)
		{
			before = before -> getNext();
		}
		
		Node<T>* target = before -> getNext();
		Node<T>* after = target -> getNext();
		
		delete target;
		before -> setNext(after);
		m_length--;
	}
}

template <typename T>
T LinkedList<T>::getEntry(int index) const
{
	Node<T>* temp = m_front;
	
	if(m_length == 0)
	{
		throw(std::runtime_error("List is empty"));
	}
	else if(index > m_length || index < 0)
	{
		throw(std::runtime_error("invalid index"));
	}
	else
	{
		for(int i = 1; i < index; i++)
		{
			temp = temp -> getNext();
		}
	}
	
	return(temp -> getEntry());
}

template <typename T>
int LinkedList<T>::length() const
{
	return(m_length);
}

template <typename T>
void LinkedList<T>::clear()
{
	while(m_length != 0)
	{
		remove(1);
	}
}

template <typename T>
void LinkedList<T>::setEntry(int index, T entry)
{
	Node<T>* temp = m_front;
	
	if(m_length == 0)
	{
		throw(std::runtime_error("List is empty"));
	}
	else if(index > m_length || index < 0)
	{
		throw(std::runtime_error("invalid index"));
	}
	else
	{
		for(int i = 1; i < index; i++)
		{
			temp = temp -> getNext();
		}
	}
	
	temp -> setEntry(entry);
}