#include <iostream>
#include <fstream>
#include <string>
#define password "test123"
#define dontcancel(x) x != "x" && x != "X"
using namespace std;

fstream entry("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal\\journal\\entries.txt", fstream::app);
fstream editing("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal\\journal\\entries.txt");
fstream key("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal\\journal\\entry_key.txt", fstream::app);
string hold_title = "";
string hold_note = "";
string login() 
{
	system("CLS");
	string enter = "";
	cout << "                                   " << endl;
	cout << "*____________ LOG  IN ____________*" << endl;
	cout << "                                   " << endl;
	cout << "       PASSWORD: ";
	cin >> enter;
	return enter;
}
int menu()
{
	system("CLS");
	int user_choice = 0;
	cout << "                                   " << endl;
	cout << "*____________ JOURNAL ____________*" << endl;
	cout << "|                                 |" << endl;
	cout << "|          [1]NEW ENTRY           |" << endl;
	cout << "|          [2]READ ENTRY          |" << endl;
	cin >> user_choice;
	return user_choice;
}
string new_entry_title()
{
	system("CLS");
	string write;
	cout << "to cancel enter X" << endl;
	cout << "Create a title for the new entry" << endl;
	getline(cin, write);
	return write;
}
string entry_note() 
{
	system("CLS");
	string note;
	cout << "to cancel enter X" << endl;
	cout << "begin your entry:" << endl;
	getline(cin, note);
	return note;
}
void helper() 
{
	int choice = menu();
	if (choice == 1)
	{
		cin.ignore();
		string title = new_entry_title();
		if (dontcancel(title))
		{
			hold_title = title;
			string note = entry_note();
			if (dontcancel(note))
			{
				hold_note = note;
			}
			else
			{
				helper();
			}
		}
		else
		{
			helper();
		}
		if (dontcancel(hold_note) && dontcancel(hold_title))
		{
			entry << " " << endl;
			entry << hold_title << endl;
			key << hold_title << endl;
			entry << hold_note << endl;
		}
		hold_note.clear();
		hold_title.clear();
	}
}
int main()
{
	string passcode;
	while (passcode != password)
	{
		passcode = login();
	}
	helper();
}