#include <iostream>
#include <fstream>
#include <string>
#define password "test123"
using namespace std;

fstream entry("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal\\journal\\entries.txt", fstream::app);
fstream editing("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal\\journal\\entries.txt");
fstream key("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal\\journal\\entry_key.txt", fstream::app);
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
		if (title != "x" && title != "X")
		{
			key << title << endl;
			entry << title << endl;
			string note = entry_note();
			if (note != "x" && note != "X")
			{
				entry << note << endl;
				entry << " " << endl;
			}
			else
				helper();
		}
		else
			helper();
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