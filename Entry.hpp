#pragma once
#include <string>
class Entry
{
	private:
		std::string name;
		std::string phone;
		std::string address;

	public:
		Entry();
		Entry(std::string name, std::string phone, std::string address);
		~Entry();
		std::string GetName();
		std::string GetPhone();
		std::string GetAddress();
		std::string ToString();
		void SetName(std::string name);
		void SetPhone(std::string phone);
		void SetAddress(std::string address);
	
};

