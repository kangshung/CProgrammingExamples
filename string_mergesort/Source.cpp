#include<iostream>
#include<string>

using std::string;

bool is_bigger(string a, string b)
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

void merge(string* array, int low, int mid, int high, int elements)
{
	int i, j, k;
	string* c = new string[elements];
	i = low;
	k = low;
	j = mid + 1;
	while (i <= mid && j <= high)
	{
		if (is_bigger(array[i], array[j]) == false)
		{
			c[k] = array[i];
			k++;
			i++;
		}
		else
		{
			c[k] = array[j];
			k++;
			j++;
		}
	}
	while (i <= mid)
	{
		c[k] = array[i];
		k++;
		i++;
	}
	while (j <= high)
	{
		c[k] = array[j];
		k++;
		j++;
	}

	for (int i = low; i < k; i++)
	{
		array[i] = c[i];
	}

	delete[] c;
}

void merge_sort(string* array, int low, int high, int elements)
{
	if (low < high)
	{
		int mid = (low + high) / 2;

		merge_sort(array, low, mid, elements);
		merge_sort(array, mid + 1, high, elements);

		merge(array, low, mid, high, elements);
	}
}

void main()
{
	int a_size_of_an_array;
	std::cin >> a_size_of_an_array;

	//int* array = new int[a_size_of_an_array];
	string* array = new string[a_size_of_an_array];

	for (int i = 0; i < a_size_of_an_array; i++)
	{
		std::cin >> array[i];
	}

	int low = 0;
	int high = a_size_of_an_array - 1;

	merge_sort(array, low, high, a_size_of_an_array);

	for (int i = 0; i < a_size_of_an_array; i++)
	{
		std::cout << array[i] << std::endl;
	}

	delete[] array;

	std::cin.ignore();
	std::cin.ignore();
}