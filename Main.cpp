#include "Entry.hpp"
#include "AddressBook.hpp"
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <iostream>


void signalHandler(tgui::EditBox::Ptr box, tgui::Gui& gui, tgui::Theme& theme, tgui::ChatBox::Ptr chatbox, int i);
void signalHandler2(AddressBook* testBook, tgui::EditBox::Ptr box, tgui::Gui& gui, tgui::Theme& theme, tgui::ChatBox::Ptr chatbox, int i);


int main()
{

	//testBook->PrintAddressBook();
	////testBook->SaveBook();
	//testBook->LoadBook();
	//AddressBook* testBook = new AddressBook(box->getText().toAnsiString());

	//testBook->AddEntry("Joe", "123456789", "123 apple st.");
	//testBook->AddEntry("Joe2", "123456789", "123 apple st.");
	//testBook->AddEntry("Aoe3", "123456789", "123 apple st.");
	//testBook->AddEntry("Aod", "123456789", "123 apple st.");
	//testBook->EditEntry("Joe4", "Aod", "123456789", "123 apple st.");
	//testBook->PrintAddressBook();
	AddressBook* testBook = new AddressBook();

	sf::RenderWindow window(sf::VideoMode(1200, 600), "Address Book");
	window.setFramerateLimit(60);
	tgui::Gui gui(window);
	tgui::Theme theme{ "D:/TGUI-0.8/themes/Black.txt" };
	gui.add(tgui::Picture::create("D:/TGUI-0.8/water.jpg"));
	sf::Event event;
	int i = 0;
	
	/////////////////////////////////////////////////////////////
	tgui::EditBox::Ptr editbox = tgui::EditBox::create();
	tgui::ChatBox::Ptr chatbox = tgui::ChatBox::create();
	tgui::Label::Ptr label = tgui::Label::create();
	/////////////////////////////////////////////////////////////
	editbox->setSize(550,50);
	editbox->setPosition(350, 420);
	editbox->setTextSize(18);
	/////////////////////////////////////////////////////////////
	tgui::Button::Ptr CreAddIn = tgui::Button::create();
	CreAddIn->setSize(50, 20);
	CreAddIn->setPosition(10, 30);
	CreAddIn->setText("Info");
	CreAddIn->connect("pressed", signalHandler, editbox, std::ref(gui), std::ref(theme), std::ref(chatbox), 1);
	tgui::Button::Ptr CreAddEn= tgui::Button::create();
	CreAddEn->setSize(50, 20);
	CreAddEn->setPosition(70, 30);
	CreAddEn->setText("Enter");
	CreAddEn->connect("pressed", signalHandler2, testBook, editbox, std::ref(gui), std::ref(theme), std::ref(chatbox), 1);
	label->setRenderer(theme.getRenderer("Label"));
	label->setText("Create Address Book");
	label->setPosition(10, 10);
	label->setTextSize(14);
	label->getRenderer()->setBackgroundColor(sf::Color(100, 100, 100, 255));
	gui.add(label);
	//////////////////////////////////////////////////////////////
	tgui::Button::Ptr AddEntIn = tgui::Button::create();//add 50 to y
	AddEntIn->setSize(50, 20);
	AddEntIn->setPosition(10, 80);
	AddEntIn->setText("Info");
	//AddEntIn->connect("pressed", signalHandler, std::ref(gui), std::ref(theme), chatbox, i);
	tgui::Button::Ptr AddEntEn = tgui::Button::create();
	AddEntEn->setSize(50, 20);
	AddEntEn->setPosition(70, 80);
	AddEntEn->setText("Enter");
	AddEntEn->connect("pressed", signalHandler2, testBook, editbox, std::ref(gui), std::ref(theme), std::ref(chatbox), 2);
	label = tgui::Label::create();
	label->setRenderer(theme.getRenderer("Label"));
	label->setText("Add Entry");
	label->setPosition(10, 60);
	label->setTextSize(14);
	label->getRenderer()->setBackgroundColor(sf::Color(100, 100, 100, 255));
	gui.add(label);
	///////////////////////////////////////////////////////////////
	tgui::Button::Ptr DelEntIn = tgui::Button::create();
	DelEntIn->setSize(50, 20);
	DelEntIn->setPosition(10, 130);
	DelEntIn->setText("Info");
	//DelEntIn->connect("pressed", signalHandler, std::ref(gui), std::ref(theme), chatbox, i);
	tgui::Button::Ptr DelEntEn = tgui::Button::create();
	DelEntEn->setSize(50, 20);
	DelEntEn->setPosition(70, 130);
	DelEntEn->setText("Enter");
	label = tgui::Label::create();
	label->setRenderer(theme.getRenderer("Label"));
	label->setText("Delete Entry");
	label->setPosition(10, 110);
	label->setTextSize(14);
	label->getRenderer()->setBackgroundColor(sf::Color(100, 100, 100, 255));
	gui.add(label);
	/////////////////////////////////////////////////////////////////
	tgui::Button::Ptr EdEntIn = tgui::Button::create();
	EdEntIn->setSize(50, 20);
	EdEntIn->setPosition(10, 180);
	EdEntIn->setText("Info");
	//EdEntIn->connect("pressed", signalHandler, std::ref(gui), std::ref(theme), chatbox, i);
	tgui::Button::Ptr EdEntEn = tgui::Button::create();
	EdEntEn->setSize(50, 20);
	EdEntEn->setPosition(70, 180);
	EdEntEn->setText("Enter");
	label = tgui::Label::create();
	label->setRenderer(theme.getRenderer("Label"));
	label->setText("Edit Entry");
	label->setPosition(10, 160);
	label->setTextSize(14);
	label->getRenderer()->setBackgroundColor(sf::Color(100, 100, 100, 255));
	gui.add(label);
	/////////////////////////////////////////////////////////////////
	tgui::Button::Ptr SeaEntIn = tgui::Button::create();
	SeaEntIn->setSize(50, 20);
	SeaEntIn->setPosition(10, 230);
	SeaEntIn->setText("Info");
	tgui::Button::Ptr SeaEntEn = tgui::Button::create();
	SeaEntEn->setSize(50, 20);
	SeaEntEn->setPosition(70, 230);
	SeaEntEn->setText("Enter");
	label = tgui::Label::create();
	label->setRenderer(theme.getRenderer("Label"));
	label->setText("Search Entry");
	label->setPosition(10, 210);
	label->setTextSize(14);
	label->getRenderer()->setBackgroundColor(sf::Color(100, 100, 100, 255));
	gui.add(label);
	//////////////////////////////////////////////////////////////////
	tgui::Button::Ptr PriAddIn = tgui::Button::create();
	PriAddIn->setSize(50, 20);
	PriAddIn->setPosition(10, 280);
	PriAddIn->setText("Info");
	PriAddIn->connect("pressed", signalHandler, editbox, std::ref(gui), std::ref(theme), std::ref(chatbox), 6);
	tgui::Button::Ptr PriAddEn = tgui::Button::create();
	PriAddEn->setSize(50, 20);
	PriAddEn->setPosition(70, 280);
	PriAddEn->setText("Enter");
	PriAddEn->connect("pressed", signalHandler2, testBook, editbox, std::ref(gui), std::ref(theme), std::ref(chatbox), 6);
	label = tgui::Label::create();
	label->setRenderer(theme.getRenderer("Label"));
	label->setText("Print Address Book");
	label->setPosition(10, 260);
	label->setTextSize(14);
	label->getRenderer()->setBackgroundColor(sf::Color(100, 100, 100, 255));
	gui.add(label);
	//////////////////////////////////////////////////////////////////
	tgui::Button::Ptr SortIn = tgui::Button::create();
	SortIn->setSize(50, 20);
	SortIn->setPosition(10, 330);
	SortIn->setText("Info");
	tgui::Button::Ptr SortEn = tgui::Button::create();
	SortEn->setSize(50, 20);
	SortEn->setPosition(70, 330);
	SortEn->setText("Enter");
	SortEn->connect("pressed", signalHandler2, testBook, editbox, std::ref(gui), std::ref(theme), std::ref(chatbox), 7);
	label = tgui::Label::create();
	label->setRenderer(theme.getRenderer("Label"));
	label->setText("Sort Address Book");
	label->setPosition(10, 310);
	label->setTextSize(14);
	label->getRenderer()->setBackgroundColor(sf::Color(100, 100, 100, 255));
	gui.add(label);
	//////////////////////////////////////////////////////////////////
	
	tgui::Button::Ptr SaveIn = tgui::Button::create();
	SaveIn->setSize(50, 20);
	SaveIn->setPosition(10, 380);
	SaveIn->setText("Info");
	SaveIn->connect("pressed", signalHandler, editbox, std::ref(gui), std::ref(theme), std::ref(chatbox), 8);
	tgui::Button::Ptr SaveEn = tgui::Button::create();
	SaveEn->setSize(50, 20);
	SaveEn->setPosition(70, 380);
	SaveEn->setText("Enter");
	SaveEn->connect("pressed", signalHandler2, testBook, editbox, std::ref(gui), std::ref(theme), std::ref(chatbox), 8);
	label = tgui::Label::create();
	label->setRenderer(theme.getRenderer("Label"));
	label->setText("Save Address Book");
	label->setPosition(10, 360);
	label->setTextSize(14);
	label->getRenderer()->setBackgroundColor(sf::Color(100, 100, 100, 255));
	gui.add(label);
	/////////////////////////////////////////////////////////////////
	tgui::Button::Ptr LoadIn = tgui::Button::create();
	LoadIn->setSize(50, 20);
	LoadIn->setPosition(10, 430);
	LoadIn->setText("Info");
	LoadIn->connect("pressed", signalHandler, editbox, std::ref(gui), std::ref(theme), std::ref(chatbox), 9);
	tgui::Button::Ptr LoadEn = tgui::Button::create();
	LoadEn->setSize(50, 20);
	LoadEn->setPosition(70, 430);
	LoadEn->setText("Enter");
	LoadEn->connect("pressed", signalHandler2, testBook, editbox, std::ref(gui), std::ref(theme), std::ref(chatbox), 9);
	label = tgui::Label::create();
	label->setRenderer(theme.getRenderer("Label"));
	label->setText("Load Address Book");
	label->setPosition(10, 410);
	label->setTextSize(14);
	label->getRenderer()->setBackgroundColor(sf::Color(100, 100, 100, 255));
	gui.add(label);
	//////////////////////////////////////////////////////////////////
	chatbox->setRenderer(theme.getRenderer("ChatBox"));
	chatbox->setSize(550, 350);
	chatbox->setTextSize(18);
	chatbox->setPosition(350, 50);
	chatbox->setLinesStartFromTop();
	chatbox->addLine("-->Hey! Choose which function you desire to use. Hit Info to see format of input. Enter the requested information in the text box and hit the corresponding enter button for the desired function. ", sf::Color::White);
	/////////////////////////////////////////////////////////////////
	gui.add(chatbox);
	gui.add(label);
	gui.add(editbox, "textBox");
	gui.add(CreAddIn);
	gui.add(CreAddEn);
	gui.add(AddEntIn);
	gui.add(AddEntEn);
	gui.add(DelEntIn);
	gui.add(DelEntEn);
	gui.add(EdEntIn);
	gui.add(EdEntEn);
	gui.add(SeaEntIn);
	gui.add(SeaEntEn);
	gui.add(PriAddIn);
	gui.add(PriAddEn);
	gui.add(SortIn);
	gui.add(SortEn);
	gui.add(SaveIn);
	gui.add(SaveEn);
	gui.add(LoadIn);
	gui.add(LoadEn);
	
	//button->connect("pressed", signalHandler, editBox, std::ref(gui), std::ref(theme), chatbox);


	

	
	//gui.add(editBox, "textBox");




	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			gui.handleEvent(event);
		}

		window.clear(sf::Color::Black);

		gui.draw();

		window.display();
	}

	return 0;

}


void signalHandler(tgui::EditBox::Ptr box, tgui::Gui& gui, tgui::Theme& theme, tgui::ChatBox::Ptr chatbox, int i)
{ 
	if(i == 1)
		chatbox->addLine("-->Type what you want your address to be called and hit Enter under Create Address Book.", sf::Color::White);
	if (i == 2)
		chatbox->addLine("-->Type in the following format: name>=number>=address>=.", sf::Color::White);
	if (i == 3)
		chatbox->addLine("-->Type in name of address entry you would like to delete.", sf::Color::White);
	if (i == 4)
		chatbox->addLine("-->Type in the following format: name of file you would like to edit >=name>=number>=address>= of the edited address.", sf::Color::White);
	if (i == 5)
		chatbox->addLine("-->Type in name of address entry you would like to search for and print.", sf::Color::White);
	if (i == 6)
		chatbox->addLine("-->Prints the address book", sf::Color::White);
	if (i == 7)
		chatbox->addLine("-->Sorts the names of entries in alphabetical order.", sf::Color::White);
	if (i == 8)
		chatbox->addLine("-->Type in name of the file you would like to save the address to.", sf::Color::White);
	if (i == 9)
		chatbox->addLine("-->Type in the name of the file you would like to load the address from.", sf::Color::White);

	
	
}

void signalHandler2(AddressBook* testBook, tgui::EditBox::Ptr box, tgui::Gui& gui, tgui::Theme& theme, tgui::ChatBox::Ptr chatbox, int i)
{
	if (i == 1)
	{
		//testBook->AddEntry("Joe", "123456789", "123 apple st.");
		//testBook->AddEntry("Joe2", "123456789", "123 apple st.");
		//testBook->AddEntry("Aoe3", "123456789", "123 apple st.");
		//testBook->AddEntry("Aod", "123456789", "123 apple st.");
		testBook->EditEntry("Joe4", "Aod", "123456789", "123 apple st.");
		
	}
	if (i == 2)
	{
		

		testBook->AddEntry(box, gui, theme, chatbox);
	}
	if (i == 3)
	{
		testBook->DeleteEntry(box->getText().toAnsiString());
	}
	if (i == 4)
	{
		std::string s = box->getText().toAnsiString();
		std::string dl = ">=";
		int i = 0;
		std::string in[4] = { "","","",""};
		size_t pos = 0;
		std::string token;

		while ((pos = s.find(dl)) != std::string::npos)
		{
			token = s.substr(0, pos);

			in[i] = token;
			i++;
			s.erase(0, pos + dl.length());
		}

		testBook->EditEntry(in[0], in[1], in[2], in[3]);
	}
	if (i == 5)
	{
		testBook->SearchAddressBook(box->getText().toAnsiString());
	}
	if (i == 6)
	{
		testBook->PrintAddressBook(box, gui, theme, chatbox);
	}
	if (i == 7)
	{
		testBook->SortBy();
	}
	if (i == 8)
	{
		testBook->SaveBook(box->getText().toAnsiString(), box, gui, theme, chatbox);
	}
	if (i == 9)
	{
		testBook->LoadBook(box->getText().toAnsiString(), box, gui, theme, chatbox);
	}
	
	
	
		
}





