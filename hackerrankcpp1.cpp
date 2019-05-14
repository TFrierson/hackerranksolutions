// hackerrankcpp1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string stringtoParse = "20, 30, 40";
	char ch;
	vector<int> sstoint;
	stringstream ss(stringtoParse);
	int sttoint;

	while (ss)
	{
		ss >> sttoint >> ch;
		sstoint.push_back(sttoint);
	}

	for (int i = 0; i < sstoint.size(); i++)
	{
		cout << sstoint[i] << " ";
	}

	return 0;
}

