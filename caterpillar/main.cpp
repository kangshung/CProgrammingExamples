#include "double_list.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	int n, m, c, x, y, d;
	cin >> m;
	cin >> n;
	cin >> c;
	cin >> x;
	cin >> y;
	cin >> d;
	char* inside = new char[d];
	cin >> inside;

	char** arr = new char*[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = new char[m];
	}

	char temp[2];
	for (int i = 0; i < n; i++)
	{
		fgets(temp, 2, stdin);
		fgets(arr[i], m + 1, stdin);
	}

	double_list list;
	for (int i = 0; i < d; i++)
	{
		list.push_back(inside[i]);
	}

	char direction = '4';
	for (int i = 0; i < c; i++)
	{
		if (arr[y - 1][x - 1] == '1')
		{
			if (i == c - 1) break;
			direction = '1';
			move_the_caterpillar(direction, &y, &x, n, m);
		}
		else if (arr[y - 1][x - 1] == '2')
		{
			if (i == c - 1) break;
			direction = '2';
			move_the_caterpillar(direction, &y, &x, n, m);
		}
		else if (arr[y - 1][x - 1] == '3')
		{
			if (i == c - 1) break;
			direction = '3';
			move_the_caterpillar(direction, &y, &x, n, m);
		}
		else if (arr[y - 1][x - 1] == '4')
		{
			if (i == c - 1) break;
			direction = '4';
			move_the_caterpillar(direction, &y, &x, n, m);
		}
		else if (arr[y - 1][x - 1] >= 'A' && arr[y - 1][x - 1] <= 'Z')
		{
			if (arr[y - 1][x - 1] == 'A')
			{
				list.push_back(arr[y - 1][x - 1] + 32);
				arr[y - 1][x - 1] = '&';
			}
			else
			{
				list.push_back(arr[y - 1][x - 1] + 32);
				int temp = arr[y - 1][x - 1];
				arr[y - 1][x - 1] = --temp;
			}
			if (i == c - 1) break;
			move_the_caterpillar(direction, &y, &x, n, m);
		}
		else if (arr[y - 1][x - 1] >= 'a' && arr[y - 1][x - 1] <= 'z')
		{
			if (arr[y - 1][x - 1] == 'a')
			{
				list.push_front(arr[y - 1][x - 1]);
				arr[y - 1][x - 1] = '*';
			}
			else
			{
				list.push_front(arr[y - 1][x - 1]);
				int temp = arr[y - 1][x - 1];
				arr[y - 1][x - 1] = --temp;
			}
			if (i == c - 1) break;
			move_the_caterpillar(direction, &y, &x, n, m);
		}
		else if (arr[y - 1][x - 1] == '&')
		{
			if (!list.empty()) list.pop_back();
			if (i == c - 1 || list.empty()) break;
			move_the_caterpillar(direction, &y, &x, n, m);
		}
		else if (arr[y - 1][x - 1] == '*')
		{
			if (!list.empty()) list.pop_front();
			if (i == c - 1 || list.empty()) break;
			move_the_caterpillar(direction, &y, &x, n, m);
		}
		else if (arr[y - 1][x - 1] == '#')
		{
			if (i == c - 1) break;
			move_the_caterpillar(direction, &y, &x, n, m);
		}
	}

	cout << x << " " << y << " ";
	list.display();
	cout << endl;
	print_an_array(arr, n, m);
	//delete[] inside;
	/*for (int i = 0; i < n; i++)
	{
		delete[] arr[i];
	}*/
	delete[] arr;


	/*
	W trakcie pisania projektu, przed wrzuceniem finalnej wersji kodu na STOS, zostało zreuploadowanych wiele roznych implementacji listy,
	pisanych przeze mnie na podstawie ogromnej ilosci pseudokodow z przeroznych stron internetowych.
	
	Przykladowe strony, z ktorych bralem informacje:
	https://www.geeksforgeeks.org/doubly-linked-list/
	https://www.geeksforgeeks.org/delete-a-node-in-a-doubly-linked-list/
	https://www.tutorialspoint.com/data_structures_algorithms/doubly_linked_list_program_in_c.htm
	https://gist.github.com/master5o1/1330051
	https://www.sanfoundry.com/cpp-program-implement-doubly-linked-list/
	https://stackoverflow.com/questions/19326017/deleting-the-back-element-in-a-linked-list

	Jednakze finalna wersje listy napisalem calkowicie sam, debugujac kazdy jej fragment i piszac ja w swoim stylu, gdy juz zrozumialem jak ona dziala
	i jak nalezy ja zaimplementowac, aby przeszla na STOSie. Okazuje sie, ze jej struktura jest znacznie inna od tych, ktore sa zamieszczone
	w wyzej wymienionych linkach, jednak jakies podobienstwa moga byc, gdyz jest to czesto uzywana struktura danych.
	*/
}