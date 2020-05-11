#include <iostream>
#include <string>


using std::cout;
using std::cin;
using std::endl;
using std::string;


bool czyWiekszy(string a, string b)
{
	// Calculate lengths of both string
	int n1 = a.length(), n2 = b.length();

	if (n1 > n2)
		return true;
	if (n2 > n1)
		return false;

	// If lengths are same
	for (int i = 0; i < n1; i++)
	{
		if (a[i] > b[i])
			return true;
		if (a[i] < b[i])
			return false;
	}
	return false;
}

void QuickSort(string* tablica, int first, int last)
{
	int temp1 = first;
	int temp2 = last;

	string x = tablica[(first + last) / 2];

	do
	{
		while (czyWiekszy(x, tablica[temp1]))
		{
			temp1++;
		}
		while (czyWiekszy(tablica[temp2], x))
		{
			temp2--;
		}
		if (temp1 <= temp2)
		{
			swap(tablica[temp1], tablica[temp2]);

			temp1++;
			temp2--;
		}
	} while (temp1 <= temp2);

	if (first < temp2) QuickSort(tablica, first, temp2);
	if (last > temp1) QuickSort(tablica, temp1, last);
}

int main()
{
	int x;
	cin >> x;

	string* tablica = new string[x];
	for (int i = 0; i < x; i++)
	{
		cin >> tablica[i];
	}

	QuickSort(tablica, 0, x - 1);

	for (int i = 0; i < x; i++)
	{
		cout << tablica[i] << endl;
	}

	delete[] tablica;

	cin.ignore();
	cin.ignore();
}