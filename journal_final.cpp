#include <iostream>
#include <fstream>
#include <string>
#include "journal_work.h"
#define password "test123"
#define notcancel(x) x != ""
using namespace std;

fstream entry("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal_final\\journal_final\\entries.txt", fstream::app);
fstream key("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal_final\\journal_final\\entry_key.txt", fstream::app);
string login() 
{
	system("CLS");
	cout << "                                   " << endl;
	cout << "*____________ LOG  IN ____________*" << endl;
	cout << "                                   " << endl;
	cout << "       PASSWORD: ";
	return getChoice();
}
string menu()
{
	system("CLS");
	cout << "                                   " << endl;
	cout << "*____________ JOURNAL ____________*" << endl;
	cout << "|                                 |" << endl;
	cout << "|          [1]NEW ENTRY           |" << endl;
	cout << "|          [2]READ ENTRY          |" << endl;
	return getChoice();
}
string entry_write(int decide) 
{
	//writing into entry and key
	system("CLS");
	cout << "to cancel, enter" << endl;
	if(decide == 1)
		cout << "begin your entry:" << endl;
	else
		cout << "Create a title for the new entry" << endl;
	return write();
}
void read(int part, string look) 
{
	system("CLS");
	string lines = "";
	if (part == 1)
	{
		//read all titles
		fstream key_read("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal_final\\journal_final\\entry_key.txt");
		cout << "Your previous entries:" << endl;
		for (string line; getline(key_read, line); )
			cout << line << endl;
	}
	else 
	{
		//read from entries
		fstream editing("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal_final\\journal_final\\entries.txt");
		string out;
		int parts = 0;
		while (getline(editing, lines))
		{
			if (lines == look)
			{
				//reading title from entry
				cout << "to return, enter" << endl;
				cout << lines << endl;
				parts++;
			}
			else if (parts == 1)
			{
				//reading the note part
				parts = 0;
				cout << lines << endl;
				getline(cin, out);
			}
		}
	}
}
void helper() 
{
	string choice = menu();
	system("CLS");
	if (choice == "1")
	{
		cin.ignore();
		string title = entry_write(1);
		if(notcancel(title))
		{
			//reading title if its not empty
			string note = entry_write(2);
			if (notcancel(note))
			{
				//if note and title arent empty, write them into files
				entry << title << endl;
				key << title << endl;
				entry << note << endl;
			}
			note.clear();
		}
		title.clear();
	}
	else if (choice == "2")
	{
		string user_choice;
		read(1, user_choice);
		cout << "enter entry name to read" << endl;
		cin.ignore();
		getline(cin, user_choice);
		read(2, user_choice);
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
		helper(); 
	}
}