// maps.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;

int main()
{
	int number;
	string inputstring;
	vector<string> inputStrings;
	map<string, long int> phoneBook;

	getline(cin, inputstring);
	istringstream iss(inputstring);
	number = stoi(inputstring);
	iss.clear();


	while (getline(cin, inputstring) && inputstring.size() != 0)
	{
		inputStrings.push_back(inputstring);
	}

	for (int a = 0; a < inputStrings.size(); a++)
	{
		string string1 = inputStrings[a];

		for (int b = 0; b < string1.size(); b++)
		{
			if (isspace(string1[b]))
			{
				string string2 = string1.substr(b + 1, 8);
				string1.erase(string1.find(" "));

				long int phoneNumber = stol(string2);

				//save time by putting the string splitting results directly into the map
				phoneBook.insert(pair<string, long int>(string1, phoneNumber));
			}
		}
	}

	for (int j = number; j < inputStrings.size(); j++)
	{
		string searchString;
		searchString = inputStrings[j];

		map<string, long int>::iterator itr = phoneBook.find(searchString);

		if (itr != phoneBook.end())
		{
			cout << itr->first << " = " << itr->second << endl;
		}

		else
		{
			cout << "Not found" << endl;
		}
	}

	return 0;
}
