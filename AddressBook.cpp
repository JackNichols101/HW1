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
void AddressBook::SortBy()
{
	for (std::list<Entry*>::iterator currentEntry = this->entries.begin(); currentEntry != this->entries.end(); ++currentEntry)
	{
		this->tempList.push_back((*currentEntry)->GetName());
	}
	tempList.sort();
	for (std::list<std::string>::iterator Iname = this->tempList.begin(); Iname != this->tempList.end(); ++Iname)
	{
		SearchAddressBook(*Iname);
	}
}
void AddressBook::DeleteEntry(std::string name)
{
	for (std::list<Entry*>::iterator currentEntry = this->entries.begin(); currentEntry != this->entries.end(); ++currentEntry)
	{
		if ((*currentEntry)->GetName().compare(name) == 0)
		{
			delete((*currentEntry));
		}
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

void AddressBook::AddEntry(tgui::EditBox::Ptr box, tgui::Gui& gui, tgui::Theme& theme, tgui::ChatBox::Ptr chatbox)
{
	std::string s = box->getText().toAnsiString();
	std::string dl = ">=";
	int i = 0;
	std::string in[3] = { "","","" };
	size_t pos = 0;
	std::string token;

	while ((pos = s.find(dl)) != std::string::npos)
	{
		token = s.substr(0, pos);

		in[i] = token;
		i++;
		s.erase(0, pos + dl.length());

	}
	this->entries.push_back(new Entry(in[0], in[1], in[2]));
}

void AddressBook::PrintAddressBook(tgui::EditBox::Ptr box, tgui::Gui& gui, tgui::Theme& theme, tgui::ChatBox::Ptr chatbox)
{
	StringName = (box->getText().toAnsiString());
	chatbox->addLine("-->" + StringName + " Address Book", sf::Color::White);
	for (std::list<Entry*>::iterator currentEntry = this->entries.begin(); currentEntry != this->entries.end(); ++currentEntry) 
	{
		chatbox->addLine((*currentEntry)->ToString() , sf::Color::White );
	}
}

void AddressBook::LoadBook(std::string string, tgui::EditBox::Ptr box, tgui::Gui& gui, tgui::Theme& theme, tgui::ChatBox::Ptr chatbox)
{
	infile.open(string + ".txt");
	
	while (!infile.eof()) // Read in all lines.
	{
		getline(infile, input); // Saves the text in file.
		//std::cout << input << std::endl;
		//chatbox->addLine(input + " \n", sf::Color::White);// Prints file with newLine.

	}
	infile.close();
	//system("pause");
}

void AddressBook::SaveBook(std::string string, tgui::EditBox::Ptr box, tgui::Gui& gui, tgui::Theme& theme, tgui::ChatBox::Ptr chatbox)
{
	outfile.open(string + ".txt");
	outfile << StringName << std::endl;
	chatbox->addLine("-->" + StringName + " Address Book Saved", sf::Color::White);
	for (std::list<Entry*>::iterator currentEntry = this->entries.begin(); currentEntry != this->entries.end(); ++currentEntry)
	{
		outfile << (*currentEntry)->ToString() << std::endl;
	}
	outfile.close();
}

