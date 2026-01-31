#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#define password "test123"
#define notcancel(x) x != ""
using namespace std;

enum MENU_ACTION {new_entry = 1, read_entry};
fstream entry_file("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal_final\\journal_final\\entries.txt", fstream::app);
fstream key("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal_final\\journal_final\\entry_key.txt", fstream::app);
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
vector<string> getTitles() 
{
	vector<string> titles;
	fstream key_read("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal_final\\journal_final\\entry_key.txt");
	for (string line; getline(key_read, line); )
		titles.push_back(line);
	return titles;
}
void printTitles(vector<string> title_list) 
{
	system("CLS");
	cout << "Your previous entries:" << endl;
	for (string title : title_list)
		cout << title << endl;
}
pair<string, string> getFullEntry(string entry_title) 
{
	string lines;
	string title;
	string entry;
	fstream editing("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal_final\\journal_final\\entries.txt");
	int parts = 0;
	while (getline(editing, lines))
	{
		if (lines == entry_title)
		{
			parts++;
			title = lines;
		}
		else if (parts == 1)
		{
			parts = 0;
			entry = lines;
			break;
		}
	}
	return make_pair(title, entry);
}
void printEntry(const string title, const string entry) 
{
	system("CLS");
	string input;
	cout << title << endl;
	cout << entry << endl;
	getline(cin, input);
}
void writeNewEntryIntoFile(const string& title, const string& note) {
	entry_file << title << endl;
	key << title << endl;
	entry_file << note << endl;
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