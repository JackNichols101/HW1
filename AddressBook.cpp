#include "AddressBook.hpp"
AddressBook::AddressBook()
{
}
AddressBook::~AddressBook()
{
	for (std::list<Entry*>::iterator currentEntry = this->entries.begin(); currentEntry != this->entries.end(); ++currentEntry) 
	{
		delete((*currentEntry));
	}
}
void AddressBook::SearchAddressBook(std::string name)
{
	for (std::list<Entry*>::iterator currentEntry = this->entries.begin(); currentEntry != this->entries.end(); ++currentEntry) 
	{
		if ((*currentEntry)->GetName().compare(name) == 0) 
		{
			std::cout<<(*currentEntry)->ToString()<<std::endl;
		}
	}
}
void AddressBook::EditEntry(std::string name)
{
	for (std::list<Entry*>::iterator currentEntry = this->entries.begin(); currentEntry != this->entries.end(); ++currentEntry)
	{
		if ((*currentEntry)->GetName().compare(name) == 0)
		{
			(*currentEntry)->SetName("jack");
			(*currentEntry)->SetPhone("666");
			(*currentEntry)->SetAddress("dick");
		}
	}
}
void AddressBook::AddEntry(std::string name, std::string phone, std::string address)
{
	this->entries.push_back(new Entry(name, phone, address));
}
void AddressBook::PrintAddressBook()
{
	for (std::list<Entry*>::iterator currentEntry = this->entries.begin(); currentEntry != this->entries.end(); ++currentEntry) 
	{
		std::cout<<(*currentEntry)->ToString()<<std::endl;
	}
}

