/* -----------------------------------------------------------------------------
 *
 * File Name:  Node.cpp
 * Author: Bolu Adubi
 * Assignment:   EECS-268 Lab 4
 * Description:  Excercise in node, stack, and queue implementation
 * Date: 09/27/2020
 *
 ---------------------------------------------------------------------------- */
 
template <typename T>
Node<T>::Node(T entry)
{
	m_entry = entry;
	m_next = nullptr;
}

template <typename T>
T Node<T>::getEntry() const
{
	return(m_entry);
}

template <typename T>
void Node<T>::setEntry(T entry)
{
	m_entry = entry;
}

template <typename T>
Node<T>* Node<T>::getNext() const
{
	return(m_next);
}

template <typename T>
void Node<T>::setNext(Node<T>* next)
{
	m_next = next;
}