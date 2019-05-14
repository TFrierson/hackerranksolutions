// decimaltobinary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <bitset>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n = 439;
	int ones = 1;
	int max = 1;

	string dectobin = bitset<64>(n).to_string();
	//erase leading zeros
	dectobin.erase(0, min(dectobin.find_first_not_of('0'), dectobin.size() - 1));

	cout << dectobin << endl;

	//the first entry will always be 1, since we erased the leading zeros
	//consones.push_back(1);

	for (int i = 1; i < dectobin.length(); i++)
	{
		if (dectobin[i] == '0')
		{
			ones = 0;
		}

		else
		{
			ones++;
		}	

		if (max < ones)
		{
			max = ones;
		}
	}

	cout << max;

	return 0;
}