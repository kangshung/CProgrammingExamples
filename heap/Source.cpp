#include "Heap.h"

using std::cout;
using std::cin;
using std::endl;

int main()
{
	Heap heap[1000];
	char letter;
	int n = 0, group = 0, group2 = 0, value = 0, old_value = 0, new_value = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> letter;
		if (letter == 'a')
		{
			cin >> group >> value;
			heap[group].push(value);
		}
		else if (letter == 'e')
		{
			cin >> group;
			if (heap[group].size == 0)
			{
				cout << "na" << endl;
			}
			else
			{
				cout << heap[group].pop() << endl;
			}
		}
		else if (letter == 'm')
		{
			cin >> group >> group2;
			for (int i = 0; i < heap[group2].size; i++)
			{
				int temp = heap[group2].pop();
				heap[group].push(temp);
			}
		}
		else if (letter == 'i')
		{
			cin >> group >> old_value >> new_value;
			heap[group].increase_value(old_value, new_value);
		}
	}
	cin.ignore();
	cin.ignore();
}