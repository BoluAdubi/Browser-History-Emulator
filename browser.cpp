#include "browser.h"

browser::browser()
{
	m_index = 0;
}

browser::~browser()
{
	m_list.clear();
}

void browser::navigateTo(std::string url)
{
	if(m_index == m_list.length())
	{
		m_list.insert(m_index + 1, url);
		m_index++;
	}
	else
	{
		m_list.insert(m_index + 1, url);
		m_index++;

		int length = m_list.length();
		
		for(int i = m_index + 1; i <= length; i++)
		{
			m_list.remove(m_index + 1);
		}
	}
}

void browser::forward()
{
	if(m_index == m_list.length())
	{
		throw(std::runtime_error("no URL next"));
	}
	else if(m_index < m_list.length())
	{
		m_index++;
	}	
}

void browser::back()
{
	if(m_index == 0)
	{
		throw(std::runtime_error("no URL before"));
	}
	else if(m_index > 1)
	{
		m_index--;
	}
}

std::string browser::current() const
{
	return(m_list.getEntry(m_index));
}

void browser::copyCurrentHistory(ListInterface<std::string>& destination)
{
	destination.clear();
	for(int i = 1; i <= m_list.length(); i++)
	{
		destination.insert(i, m_list.getEntry(i));
	}
}

void browser::print()
{
	std::cout << "\n";
	std::cout << "Oldest\n";
	std::cout << "===========\n";				
	
	for(int i = 1; i <= m_list.length(); i++)
	{
		std::cout << m_list.getEntry(i);
		if(i == m_index)
		{
			std::cout << "    <==current\n";
		}
		else
		{
			std::cout << "\n";
		}
	}
	
	std::cout << "===========\n";
	std::cout << "Newest\n";
	std::cout << "\n";
}