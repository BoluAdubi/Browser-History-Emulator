#ifndef EXECUTIVE_H
#define EXECUTIVE_H

#include <iostream>
#include <fstream>
#include <stdexcept>
#include "LinkedList.h"
#include "browser.h"
#include "Node.h"

class executive
{
	private:
		std::string m_fileName;
	
	public:
		/** 
       * @pre None
       * @post Executive object is created
       * @param Input file name
       * @throw None
       **/
		executive(std::string file);
		
		/** 
       * @pre User must have provided a file
       * @post filename is returned
       * @param None
       * @throw None
       **/
		std::string getFileName();
		
		/** 
       * @pre User must have provided a file
       * @post returns true if file is open and false if it isnt
       * @param None
       * @throw std::runtime error if no file has been provided
       **/
		bool isFileOpen();
		
		/** 
       * @pre User must have provided a file
       * @post Data from file is read and processed
       * @param input file name
       * @throw None
       **/
		void readFile(std::string file);
		
		/** 
       * @pre None
       * @post executive is run
       * @param None
       * @throw None
       **/
		void run();
};
#endif