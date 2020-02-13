#include "Entry.hpp"
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
Entry::Entry()
{
	this->name = "";
	this->phone = "";
	this->address = "";
}

Entry::Entry(std::string name, std::string phone, std::string address)
{
	this->name = name;
	this->phone = phone;
	this->address = address;
}
Entry::~Entry()
{
}
void Entry::SetName(std::string name)
{
	this->name = name;
}
void Entry::SetPhone(std::string phone)
{
	this->phone = phone;
}
void Entry::SetAddress(std::string address)
{
	this->address = address;
}
std::string Entry::GetName()
{
	return this->name;
}

std::string Entry::GetPhone()
{
	return this->phone;
}

std::string Entry::GetAddress()
{
	return this->address;
}

std::string Entry::ToString()
{
	return this->name + " " + this->phone + " " + this->address;
}

std::string Entry::MakeString()
{
	return this->name + ">=" + this->phone + ">=" + this->address + ">=";
}




