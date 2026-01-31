#pragma once

#include <vector>
#include <string>

using namespace std;

vector<string> getTitles();
pair<string, string> getFullEntry(string entry_title);
void writeNewEntryIntoFile(const string& title, const string& note);