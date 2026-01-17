#include <iostream>
#include <fstream>
#include <string>
#define password "test123"
#define notcancel(x) x != ""
using namespace std;

fstream entry("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal\\journal\\entries.txt", fstream::app);

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
string entry_part(int decide) 
{
	system("CLS");
	string note;
	cout << "to cancel, enter" << endl;
	if(decide == 2)
		cout << "begin your entry:" << endl;
	else if(decide == 1)
		cout << "Create a title for the new entry" << endl;
	getline(cin, note);
	return note;
}
string read(int part, string look) 
{
	system("CLS");
	string lines = "";
	if (part == 1)
	{
		fstream key_read("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal\\journal\\entry_key.txt");
		cout << "Your previous entries:" << endl;
		for (string line; getline(key_read, line); )
			cout << line << endl;
	}
	else 
	{
		fstream editing("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal\\journal\\entries.txt");
		string out;
		int parts = 0;
		while (getline(editing, lines))
		{
			if (lines == look)
			{
				cout << "to return, enter" << endl;
				cout << lines << endl;
				parts++;
			}
			else if (parts == 1)
			{
				parts = 0;
				cout << lines << endl;
				cin.ignore();
				getline(cin, out);
				if (out == "")
					return out;
				else
					return out;
			}
		}
	}
	return "";
}
void helper() 
{
	int choice = menu();
	system("CLS");
	if (choice == 1)
	{
		cin.ignore();
		string title = entry_part(1);
		if(notcancel(title))
		{
			string note = entry_part(2);
			if (notcancel(note))
			{
				entry << title << endl;
				key << title << endl;
				entry << note << endl;
			}
			note.clear();
		}
		title.clear();
	}
	else if (choice == 2) 
	{
		string user_choice;
		read(1, user_choice);
		cout << "enter entry name to read" << endl;
		cin >> user_choice;
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