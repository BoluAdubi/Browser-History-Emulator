#include "executive.h"

executive::executive(std::string file)
{
	m_fileName = file;
}

std::string executive::getFileName()
{
	return(m_fileName);
}

bool executive::isFileOpen()
{
	std::string file = getFileName();
	
	std::ifstream myInFile;
	myInFile.open(file);
	
	if (myInFile.is_open())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void executive::readFile(std::string file)
{
	std::ifstream myInFile;
	myInFile.open(file);
	
	bool fileStatus = isFileOpen();
	
	std::string tempCommand = " ";
	std::string tempURL = " ";
	LinkedList<std::string> execList;
	browser execBrowser;
	
	if(fileStatus == true)
	{
		while(myInFile >> tempCommand)
		{
			if(tempCommand == "NAVIGATE")
			{
				myInFile >> tempURL;
				execBrowser.navigateTo(tempURL);
			}
			else if(tempCommand == "BACK")
			{
				try
				{
					execBrowser.back();
				}
				catch(std::runtime_error& rte)
				{
					std::cout << " ";
				}
			}
			else if(tempCommand == "FORWARD")
			{
				try
				{
					execBrowser.forward();
				}
				catch(std::runtime_error& rte)
				{
					std::cout << " ";
				}
			}
			else if(tempCommand == "HISTORY")
			{
				execBrowser.print();
			}
		}
	}
	else
	{
		std::cout << "Invalid file given \n";
	}
}

void executive::run()
{
	readFile(m_fileName);
}