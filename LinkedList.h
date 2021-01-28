#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdexcept>
#include <iostream>

#include "Node.h"
#include "ListInterface.h"

template <typename T>
class LinkedList : public ListInterface<T>
{
	private:
		Node<T>* m_front;
		int m_length;
		
	public:
	
		 /**
		  * @post LinkedList object is created
		  */
		LinkedList();
		
		 /**
		  * @post All memory allocated by the implementing class should be freed. 
		  *       This, as with all virtual destructors, is an empty definition since we
		  *       have no knowledge of specific implementation details.
		  */
		~LinkedList();
		
		/**
		* @pre The index is valid
		* @post The entry is added to the list at the index, increasing length by 1
		* @param index, position to insert at (1 to length+1)
		* @param entry, value/object to add to the list
		* @throw std::runtime_error if the index is invalid
		*/
		void insert(int index, T entry); 
		
		/**
		* @pre The index is valid
		* @post The entry at given position is removed, reducing length by 1 
		* @param index, position to insert at (1 to length)
		* @throw std::runtime_error if the index is invalid
		*/
		void remove(int index);
		
		/**
		* @pre The index is valid
		* @post None 
		* @param index, position to insert at (1 to length)
		* @throw std::runtime_error if the index is invalid
		*/
			T getEntry(int index) const;
		
		/**
		* @pre None
		* @post None 
		* @throw None
		*/
		int length() const;
		
		/**
		* @pre None
		* @post List is empty
		* @throw None
		*/
		void clear();
		
		/**
		* @pre The index is valid (must already exist)
		* @post Given entry overrides the entry at the given index 
		* @param index, position to override at (1 to length)
		* @param entry, value/object to place at given index
		* @throw std::runtime_error if the index is invalid
		*/
		void setEntry(int index, T entry);
};
#include "LinkedList.cpp"
#endif