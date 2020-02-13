#pragma once
#include <list>
#include <iostream>
#include "Entry.hpp"
#include <fstream>




class AddressBook
{
	private:
		std::string StringName;
		std::string string;
		std::list<Entry*> entries;
		std::list<std::string> tempList;
		std::string input;
		std::ifstream infile;
		std::ofstream outfile;
	public:
		AddressBook();
		~AddressBook();
		void SortBy();
		void SearchAddressBook(std::string name);
		void DeleteEntry(std::string name);
		void AddEntry(tgui::EditBox::Ptr box, tgui::Gui& gui, tgui::Theme& theme, tgui::ChatBox::Ptr chatbox);
		void EditEntry(std::string nameKey, std::string name, std::string phone, std::string address);
		void PrintAddressBook(tgui::EditBox::Ptr box, tgui::Gui& gui, tgui::Theme& theme, tgui::ChatBox::Ptr chatbox);
		void LoadBook(std::string string, tgui::EditBox::Ptr box, tgui::Gui& gui, tgui::Theme& theme, tgui::ChatBox::Ptr chatbox);
		void SaveBook(std::string string, tgui::EditBox::Ptr box, tgui::Gui& gui, tgui::Theme& theme, tgui::ChatBox::Ptr chatbox);
};

