#include "AddressBook.hpp"
#include <fstream>
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
void AddressBook::SetAddName(std::string StringName)
{
	this->StringName = StringName;
}
void AddressBook::SortBy(tgui::ChatBox::Ptr chatbox)
{
	chatbox->addLine("--> " + this->StringName + " has been sorted alphabetically", sf::Color::White);
	for (std::list<Entry*>::iterator currentEntry = this->entries.begin(); currentEntry != this->entries.end(); ++currentEntry)
	{
		tempList.push_back((*currentEntry)->GetName());
	}
	tempList.sort();
	for (std::list<std::string>::iterator Iname = tempList.begin(); Iname != tempList.end(); ++Iname)
	{
		SearchAddressBook(*Iname, chatbox);
	}
	tempList.clear();
}
void AddressBook::Seperate(tgui::EditBox::Ptr box, tgui::Gui& gui, int x, tgui::ChatBox::Ptr chatbox, std::string string)//seperates input to add into addressbook
{
	std::string s = box->getText().toAnsiString();
	int i = 0;
	std::string dl = ">=";
	std::string in[4] = { "","","","" };
	size_t pos = 0;
	std::string token;
	while ((pos = s.find(dl)) != std::string::npos)
	{
		token = s.substr(0, pos);
		in[i] = token;
		i++;
		s.erase(0, pos + dl.length());
	}
	if (x == 2)
	{
		AddEntry(in[0], in[1], in[2]);
		chatbox->addLine("-->Entry Added.", sf::Color::White);
	}
	if (x == 4)
	{
		EditEntry(in[0], in[1], in[2], in[3]);
		chatbox->addLine("-->Entry Edited.", sf::Color::White);
	}
	
}
void AddressBook::DeleteEntry(std::string nameKey, tgui::ChatBox::Ptr chatbox)
{
	for (std::list<Entry*>::iterator currentEntry = this->entries.begin(); currentEntry != this->entries.end(); ++currentEntry)
	{
		if ((*currentEntry)->GetName().compare(nameKey) == 0)
		{
			chatbox->addLine("-->Entry " + (*currentEntry)->ToString() + " has been deleted.", sf::Color::White);
			this->entries.erase(currentEntry);
			break;
		}	
	}
}
void AddressBook::SearchAddressBook(std::string name, tgui::ChatBox::Ptr chatbox)
{
	for (std::list<Entry*>::iterator currentEntry = this->entries.begin(); currentEntry != this->entries.end(); ++currentEntry) 
	{
		if ((*currentEntry)->GetName().compare(name) == 0) 
		{
			chatbox->addLine((*currentEntry)->ToString(), sf::Color::White);
		}
	}
}
void AddressBook::EditEntry(std::string nameKey, std::string name, std::string phone, std::string address)
{
	for (std::list<Entry*>::iterator currentEntry = this->entries.begin(); currentEntry != this->entries.end(); ++currentEntry)
	{
		if ((*currentEntry)->GetName().compare(nameKey) == 0)
		{
			(*currentEntry)->SetName(name);
			(*currentEntry)->SetPhone(phone);
			(*currentEntry)->SetAddress(address);
		}
	}
}
void AddressBook::AddEntry(std::string name, std::string phone, std::string address)
{
	this->entries.push_back(new Entry(name, phone, address));
}
void AddressBook::PrintAddressBook(tgui::EditBox::Ptr box, tgui::Gui& gui, tgui::Theme& theme, tgui::ChatBox::Ptr chatbox)
{
	chatbox->addLine("-->" + this->StringName + " Address Book", sf::Color::White);
	for (std::list<Entry*>::iterator currentEntry = this->entries.begin(); currentEntry != this->entries.end(); ++currentEntry) 
	{
		chatbox->addLine((*currentEntry)->ToString() , sf::Color::White );
	}
}
void AddressBook::LoadBook(std::string string, tgui::EditBox::Ptr box, tgui::Gui& gui, tgui::Theme& theme, tgui::ChatBox::Ptr chatbox)
{
	infile.open(string + ".txt");
	chatbox->addLine("-->" + string + "Address Book loaded", sf::Color::White);
	while (!infile.eof()) // Read in all lines.
	{
		getline(infile, input); // Loads lines into string.
		chatbox->addLine(input, sf::Color::White);
	}
	infile.close();
}
void AddressBook::SaveBook(std::string string, tgui::EditBox::Ptr box, tgui::Gui& gui, tgui::Theme& theme, tgui::ChatBox::Ptr chatbox)
{
	outfile.open(string + ".txt");
	chatbox->addLine("-->" + this-> StringName + " Address Book Saved as " + string, sf::Color::White);
	for (std::list<Entry*>::iterator currentEntry = this->entries.begin(); currentEntry != this->entries.end(); ++currentEntry)
	{
		outfile << (*currentEntry)->ToString() << std::endl;
	}
	outfile.close();
}

