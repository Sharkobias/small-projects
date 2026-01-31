#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "journal_backend.hpp"
#define password "test123"
#define notcancel(x) x != ""
using namespace std;
enum MENU_ACTION {new_entry = 1, read_entry};
string login() 
{
	system("CLS");
	string input;
	cout << "                                   " << endl;
	cout << "*____________ LOG  IN ____________*" << endl;
	cout << "                                   " << endl;
	cout << "       PASSWORD: ";
	cin >> input;
	return input;
}

MENU_ACTION menu()
{
	int input;
	system("CLS");
	cout << "                                   " << endl;
	cout << "*____________ JOURNAL ____________*" << endl;
	cout << "|                                 |" << endl;
	cout << "|          [1]NEW ENTRY           |" << endl;
	cout << "|          [2]READ ENTRY          |" << endl;
	cin >> input;
	return static_cast<MENU_ACTION>(input);
}

string getUserInputWithCancel(string userPrompt) {
	//writing into entry and key
	system("CLS");
	string line;
	cout << "to cancel, enter" << endl;
	cout << userPrompt << endl;
	getline(cin, line);
	return line;
}

string getEntryText() 
{
	return getUserInputWithCancel("begin your entry:");
}

string getEntryTitle()
{
	cin.ignore();
	return getUserInputWithCancel("Create a title for the new entry");
}
void printTitles(vector<string> title_list) 
{
	system("CLS");
	cout << "Your previous entries:" << endl;
	for (string title : title_list)
		cout << title << endl;
}
void printEntry(const string title, const string entry) 
{
	system("CLS");
	string input;
	cout << title << endl;
	cout << entry << endl;
	getline(cin, input);
}
void createNewEntry() 
{
	string title = getEntryTitle();
	if (notcancel(title))
	{
		string note = getEntryText();
		if (notcancel(note))
			writeNewEntryIntoFile(title, note);
	}
}
void readEntry() 
{
	string user_choice;
	printTitles(getTitles());
	cout << "enter entry name to read" << endl;
	cin.ignore();
	getline(cin, user_choice);
	auto [title, entry] = getFullEntry(user_choice);
	printEntry(title, entry);
}
void handleMenuActions(MENU_ACTION choice) 
{	
	if (choice == new_entry)
	{
		createNewEntry();
	}
	else if (choice == read_entry)
	{
		readEntry();
	}
}
int main()
{
	string passcode;
	while (passcode != password)
	{
		passcode = login();
	}
	while (true)
	{
		handleMenuActions(menu()); 
	}
}