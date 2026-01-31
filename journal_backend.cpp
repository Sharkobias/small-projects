#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
fstream entry_file("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal_final\\journal_final\\entries.txt", fstream::app);
fstream key("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal_final\\journal_final\\entry_key.txt", fstream::app);

vector<string> getTitles()
{
	vector<string> titles;
	fstream key_read("C:\\Users\\user\\Desktop\\PROJEKTY\\CPP\\journal_final\\journal_final\\entry_key.txt");
	for (string line; getline(key_read, line); )
		titles.push_back(line);
	return titles;
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
void writeNewEntryIntoFile(const string& title, const string& note) {
	entry_file << title << endl;
	key << title << endl;
	entry_file << note << endl;
}
