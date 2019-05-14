// mergesort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <array>
#include <vector>

using namespace std;

void merge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1;
	int n2 = r - m;

	vector<int> left(n1);
	vector<int> right(n2);

	//Copy the first half of the array into left
	for (int i = 0; i < n1; i++)
	{
		left[i] = arr[l + i];
	}

	//Copy the second half of the array into right
	for (int j = 0; j < n2; j++)
	{
		right[j] = arr[m + 1 + j];
	}

	int a = 0;
	int b = 0;
	int d = l;

	while (a < n1 && b < n2)
	{
		if (left[a] <= right[b])
		{
			arr[d] = left[a];
			a++;
		}

		else
		{
			arr[d] = right[b];
			b++;
		}

		d++;
	}

	while (a < n1)
	{
		arr[d] = left[a];
		a++;
		d++;
	}

	while (b < n2)
	{
		arr[d] = right[b];
		b++;
		d++;
	}
}

void mergesort(int arr[], int l, int r)
{
	if(l < r)
	{
		int mid = (l + r) / 2;

		mergesort(arr, l, mid);
		mergesort(arr, mid + 1, r);

		merge(arr, l, mid, r);
	}

	//skips when l = r
}

int main()
{
	int arraytosort[]{ 3, 7, 1, 10, 2, 5, 4 };

	//sizeof(array) gives the total bits assigned to the array. Divide it by an element of the array to find the number of elements
	int arraysize = sizeof(arraytosort) / sizeof(arraytosort[0]);

	cout << "Original array is: " << endl;

	for (int i = 0; i < arraysize; i++)
	{
		cout << arraytosort[i] << " ";
	}

	mergesort(arraytosort, 0, arraysize - 1);

	cout << "\n" << "Sorted array is: " << endl;

	for (int j = 0; j < arraysize; j++)
	{
		cout << arraytosort[j] << " ";
	}

	return 0;
}