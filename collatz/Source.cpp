#include "Heap.h"

using std::cin;
using std::cout;
using std::endl;

unsigned long long collatz(unsigned int* x)
{
	unsigned long long temp = *x;
	if (temp % 2 == 0)
	{
		return (temp / 2);
	}
	else if (temp % 2 == 1)
	{
		return (temp * 3 + 1);
	}
}

int main()
{
	Heap heap;
	unsigned short n;
	unsigned long long return_largest, return_smallest;
	short a_number_of_repeats_of_a_number_of_loops_and_a_letter_of_function_to_use, number_of_loops;
	char letter_of_function_to_use;
	cin >> n;
	unsigned int* sequence = new unsigned int[n];

	for (unsigned short i = 0; i < n; i++)
	{
		cin >> sequence[i];
	}

	for (unsigned short i = 0; i < n; i++)
	{
		heap.push(sequence[i], i);
	}

	unsigned short x = (heap.size_max / 2) - 1;
	unsigned short y = (heap.size_min / 2) - 1;
	if (heap.size_max > 1)
	{
		for (int i = x; i >= 0; i--)
		{
			heap.heapify_root_max(heap.maxheap[i].max_index);
		}
	}
	if (heap.size_min > 1)
	{
		for (int i = y; i >= 0; i--)
		{
			heap.heapify_root_min(heap.minheap[i].min_index);
		}
	}

	cin >> a_number_of_repeats_of_a_number_of_loops_and_a_letter_of_function_to_use;
	for (int i = 0; i < a_number_of_repeats_of_a_number_of_loops_and_a_letter_of_function_to_use; i++)
	{
		cin >> number_of_loops;
		cin >> letter_of_function_to_use;
		for (int i = 0; i < number_of_loops; i++)
		{
			if (heap.size_max != 0)
			{
				if (letter_of_function_to_use == 'l')
				{
					return_largest = collatz(&heap.maxheap[0].value);
					if (return_largest > 1 && return_largest <= 4294967295)
					{
						sequence[heap.maxheap[0].sequence_index] = heap.minheap[heap.maxheap[0].min_index].value = heap.maxheap[0].value = return_largest;

						if (((heap.maxheap[0].min_index - 1) / 2) >= 0 && heap.minheap[heap.maxheap[0].min_index].value < heap.minheap[(heap.maxheap[0].min_index - 1) / 2].value)
						{
							heap.up_pusher_min_heap(heap.maxheap[0].min_index);
						}
						else
						{
							heap.heapify_root_min(heap.minheap[heap.maxheap[0].min_index].min_index);
						}
						heap.heapify_root_max(0);
					}
					else if (return_largest == 1)
					{
						heap.maxheap[0].value = 1;
						sequence[heap.maxheap[0].sequence_index] = 1;
						heap.pop_max();
					}
					else if (return_largest > 4294967295)
					{
						heap.maxheap[0].value = 0;
						sequence[heap.maxheap[0].sequence_index] = 0;
						heap.pop_max();
					}
				}
				else if (letter_of_function_to_use == 's')
				{
					return_smallest = collatz(&heap.minheap[0].value);
					if (return_smallest != 1 && return_smallest <= 4294967295)
					{
						sequence[heap.minheap[0].sequence_index] = heap.maxheap[heap.minheap[0].max_index].value = heap.minheap[0].value = return_smallest;

						if (((heap.minheap[0].max_index - 1) / 2) >= 0 && heap.maxheap[heap.minheap[0].max_index].value > heap.maxheap[(heap.minheap[0].max_index - 1) / 2].value)
						{
							heap.up_pusher_max_heap(heap.minheap[0].max_index);
						}
						else
						{
							heap.heapify_root_max(heap.maxheap[heap.minheap[0].max_index].max_index);
						}
						heap.heapify_root_min(0);
					}
					else if (return_smallest == 1)
					{
						heap.minheap[0].value = 1;
						sequence[heap.minheap[0].sequence_index] = 1;
						heap.pop_min();
					}
					else if (return_smallest > 4294967295)
					{
						heap.minheap[0].value = 0;
						sequence[heap.minheap[0].sequence_index] = 0;
						heap.pop_min();
					}
				}
			}
		}
	}

	for (unsigned short i = 0; i < n; i++)
	{
		if (sequence[i] != 0)
		{
			cout << sequence[i] << ' ';
		}
		else
		{
			cout << "m ";
		}
	}

	cin.ignore();
	cin.ignore();
}