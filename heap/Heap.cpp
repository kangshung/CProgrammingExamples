#include "Heap.h"

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

Heap::Heap() :size(0), root(0), allocation(2)
{
	arr = (int*)malloc(allocation * sizeof(int));
}

Heap::~Heap()
{
	free(arr);
}

void Heap::push(int value)
{
	size++;

	int i = size - 1;
	arr[i] = value;

	// fixing the heap property
	while (i != 0 && arr[(i - 1) / 2] < arr[i])
	{
		swap(&arr[(i - 1) / 2], &arr[i]);
		i = (i - 1) / 2;
	}

	if (size == allocation)
	{
		allocation *= 2;
		arr = (int*)realloc(arr, allocation * sizeof(int));
	}
}

void Heap::heapify(int n)
{
	// dla MAX
	int l = n;

	// jezeli oba istnieja i oba sa wieksze od parenta
	if (2 * n + 2 < size && arr[2 * n + 1] > arr[n] && arr[2 * n + 2] > arr[n])
	{
		if (arr[2 * n + 1] < arr[2 * n + 2])
		{
			l = 2 * n + 2;
		}
		else if (arr[2 * n + 1] >= arr[2 * n + 2])
		{
			l = 2 * n + 1;
		}
	}

	// jezeli oba istnieja i tylko pierwszy jest wiekszy od parenta
	else if (2 * n + 2 < size && arr[2 * n + 1] > arr[n] && arr[2 * n + 2] <= arr[n])
	{
		l = 2 * n + 1;
	}

	// jezeli oba istnieja i tylko drugi jest wiekszy od parenta
	else if (2 * n + 2 < size && arr[2 * n + 2] > arr[n] && arr[2 * n + 1] <= arr[n])
	{
		l = 2 * n + 2;
	}

	// jezeli istnieje tylko lewy i jest wieszy od parenta
	else if (2 * n + 1 < size && 2 * n + 2 >= size && arr[2 * n + 1] > arr[n])
	{
		l = 2 * n + 1;
	}

	// jezeli istnieje tylko lewy i jest rowny badz mniejszy od parenta
	// lub
	// parent nie ma zadnego dziecka (ani lewego ani prawego)
	// lub
	// parent ma 2 dzieci ale zaden nie jest wiekszy od niego
	// to
	// l sie nie zmienia, i swap, i rekurencja sie nie wywoluja i funkcja sie konczy
	if (l != n)
	{
		swap(&arr[n], &arr[l]);
		heapify(l);
	}
}

void Heap::increase_value(int old_value, int new_value)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == old_value)
		{
			arr[i] = new_value;
			return;
		}
	}
	std::cout << "na" << std::endl;
}

int Heap::pop()
{
	if (size == 1)
	{
		size--;
		return arr[0];
	}
	else
	{
		root = arr[0];
		arr[0] = arr[size - 1];
		size--;
		heapify(0);

		return root;
	}
}