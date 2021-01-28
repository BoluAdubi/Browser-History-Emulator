#ifndef BROWSER_H
#define BROWSER_H

#include <string>

#include "LinkedList.h"
#include "BrowserHistoryInterface.h"

class browser : public BrowserHistoryInterface
{
	private:
		LinkedList<std::string> m_list;
		int m_index;
	
	public:
	
		 /**
		  * @post browser object is created
		  */
		browser();
	
		/**
		* @post All memory allocated by the implementing class should be freed. 
		*       This, as with all virtual destructors, is an empty definition since we
		*       have no knowledge of specific implementation details.
		*/
		~browser();

		/**
		* @pre none
		* @post the browser navigate to the given url
		* @param url, a string representing a URL
		*/
		void navigateTo(std::string url);

		/**
		* @pre none
		* @post if possible, the browser navigates forward in the history otherwise it keeps focus
		*         on the current URL
		*/
		void forward();

		/**
		* @pre none
		* @post if possible, the browser navigates backwards in the history otherwise it keeps focus
		*         on the current URL 
		*/
		void back();

		/**
		* @return the current URL 
		*/
		std::string current() const;

		/**
		* @pre None
		* @post The list is cleared out, then the current browser history is copied into the given list  
		* @param destination, an empty list of strings
		*/
		void copyCurrentHistory(ListInterface<std::string>& destination);
		
		/**
		* @pre None
		* @post Prints browser history 
		* @param None
		* @throw None
		*/
		void print();
};
#endif