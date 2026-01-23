// journal_work.h
#include <iostream>
using namespace std;
string getChoice() 
{
	string input;
	cin >> input;
	return input;
}
string write() 
{
	string note;
	getline(cin, note);
	return note;
}