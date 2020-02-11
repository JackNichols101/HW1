#include "Entry.hpp"
#include "AddressBook.hpp"
#include <iostream>

int main() {
	AddressBook* testBook = new AddressBook();

	testBook->AddEntry("Joe", "123456789", "123 apple st.");
	testBook->AddEntry("Joe2", "123456789", "123 apple st.");
	testBook->AddEntry("Joe3", "123456789", "123 apple st.");
	testBook->AddEntry("Joe4", "123456789", "123 apple st.");
	testBook->EditEntry("Joe4");
	testBook->PrintAddressBook();

	delete(testBook);

	int a;
	std::cin >> a;
}
	
