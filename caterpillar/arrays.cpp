#include "double_list.h"

void print_an_array(char** arr, int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (arr[i][j] == '&' || arr[i][j] == '*')
			{
				arr[i][j] = '@';
			}
			std::cout << arr[i][j];
		}
		std::cout << std::endl;
	}
}

void move_the_caterpillar(char direction, int* x, int* y, int n, int m)
{
	if (direction == '1' && *x == 1)
	{
		*x = n;
	}
	else if (direction == '1')
	{
		(*x)--;
	}
	if (direction == '2' && *x == n)
	{
		*x = 1;
	}
	else if (direction == '2')
	{
		(*x)++;
	}
	if (direction == '3' && *y == 1)
	{
		*y = m;
	}
	else if (direction == '3')
	{
		(*y)--;
	}
	if (direction == '4' && *y == m)
	{
		*y = 1;
	}
	else if (direction == '4')
	{
		(*y)++;
	}
}