// vectorofvectors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

int main()
{
	int n;
	int q;
	string input1, input2, input3;
	vector<vector<int>> uvecs;
	vector<int> resultvec;
	
	getline(cin, input1);

	int pos = input1.find(" ");
	string string1, string2;
	string1 = input1.substr(0, pos);
	string2 = input1.substr(pos + 1);
	n = stoi(string1);
	q = stoi(string2);

	for (int i = 0; i < n; i++)
	{
		getline(cin, input2);
		stringstream ss(input2);
		vector<int>uservec;
		string string3;
		int number;
		{
			//Go thrugh ss and get each number, turn it into i, then put it into the vector
			while (getline(ss, string3, ' '))
			{
				number = stoi(string3);
				uservec.push_back(number);
			}
		}

		uvecs.push_back(uservec);
		uservec.clear();
	}

	for (int j = 0; j < q; j++)
	{
		getline(cin, input3);
		int pos = input3.find(" ");
		string string3 = input3.substr(0, pos);
		string string4 = input3.substr(pos + 1);
		int q1 = stoi(string3);
		int q2 = stoi(string4);

		int result1 = uvecs[q1][q2];
		resultvec.push_back(result1);
	}

	for (int r = 0; r < resultvec.size(); r++)
	{
		cout << resultvec[r] << endl;
	}

	return 0;
}