#pragma once
#include <list>
#include <iostream>
#include "Entry.hpp"

class AddressBook
{
	private:
		std::list<Entry*> entries;
	public:
		AddressBook();
		~AddressBook();
		void SearchAddressBook(std::string name);
		void AddEntry(std::string name, std::string phone, std::string address);
		void EditEntry(std::string name);
		void PrintAddressBook();
};

