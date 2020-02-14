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
		std::string input;
		std::ifstream infile;
		std::ofstream outfile;
	public:
		AddressBook();
		~AddressBook();
		std::list<std::string> tempList;
		void SetAddName(std::string StringName);
		void Seperate(tgui::EditBox::Ptr box, tgui::Gui& gui, int i, tgui::ChatBox::Ptr chatbox, std::string string);
		void SortBy(tgui::ChatBox::Ptr chatbox);
		void SearchAddressBook(std::string name, tgui::ChatBox::Ptr chatbox);
		void DeleteEntry(std::string name, tgui::ChatBox::Ptr chatbox);
		void AddEntry(std::string name, std::string phone, std::string address);
		void EditEntry(std::string nameKey, std::string name, std::string phone, std::string address);
		void PrintAddressBook(tgui::EditBox::Ptr box, tgui::Gui& gui, tgui::Theme& theme, tgui::ChatBox::Ptr chatbox);
		void LoadBook(std::string string, tgui::EditBox::Ptr box, tgui::Gui& gui, tgui::Theme& theme, tgui::ChatBox::Ptr chatbox);
		void SaveBook(std::string string, tgui::EditBox::Ptr box, tgui::Gui& gui, tgui::Theme& theme, tgui::ChatBox::Ptr chatbox);
};

