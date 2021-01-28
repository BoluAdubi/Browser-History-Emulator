/* -----------------------------------------------------------------------------
 *
 * File Name:  Node.h
 * Author: Bolu Adubi
 * Assignment:   EECS-268 Lab 4
 * Description:  Excercise in node, stack, and queue implementation
 * Date: 09/27/2020
 *
 ---------------------------------------------------------------------------- */

#ifndef NODE_H
#define NODE_H

template <typename T>
class Node
{
	private:
		T m_entry;
		Node<T>* m_next;
	
	public:
	
		Node(T entry);
		
		/** 
		* @pre None
		* @post entry is returned
		* @param None
		* @throw None
		**/
		T getEntry() const;
		
		/** 
		* @pre None
		* @post Node value is set to entry
		* @param entry, the element to be assigned to the node
		* @throw None
		**/
		void setEntry(T entry);
		
		/** 
		* @pre None
		* @post m_next is returned
		* @param None
		* @throw None
		**/
		Node<T>* getNext() const;
		
		/** 
		* @pre None
		* @post next is assigned to m_next
		* @param next, the element to be assigned to m_next
		* @throw None
		**/
		void setNext(Node<T>* next);

};

#include "Node.cpp"
#endif