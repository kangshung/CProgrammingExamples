#include "Heap.h"

void swap(unsigned int *x, unsigned int *y)
{
	unsigned int temp = *x;
	*x = *y;
	*y = temp;
}

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

Heap::Heap() :capacity(60000), size_min(0), size_max(0)
{
	maxheap = new node[capacity];
	minheap = new node[capacity];
}

void Heap::push(unsigned int n, unsigned short i)
{
	// 0 nigdy nie jest w inpucie
	if (n != 1)
	{
		size_min++;
		// dodawanie do minheapa
		minheap[size_min - 1].value = n;
		minheap[size_min - 1].sequence_index = i;
		minheap[size_min - 1].min_index = size_min - 1;

		size_max++;
		// dodawanie do maxheapa
		maxheap[size_max - 1].value = n;
		maxheap[size_max - 1].sequence_index = i;
		maxheap[size_max - 1].max_index = size_max - 1;

		// crossing-over indexow
		minheap[size_min - 1].max_index = maxheap[size_max - 1].max_index;
		maxheap[size_max - 1].min_index = minheap[size_min - 1].min_index;



		//// nie dziala
		//
		//iele = size_min - 1;
		//if (((iele - 1) / 2) >= 0 && minheap[iele].value > minheap[(iele - 1) / 2].value) // to sie zamienia maxa
		//{
		//	while (maxheap[iele].max_index != 0 && maxheap[iele].value > maxheap[(iele - 1) / 2].value)
		//	{
		//		swap(&maxheap[iele].value, &maxheap[(iele - 1) / 2].value);
		//		swap(&maxheap[iele].sequence_index, &maxheap[(iele - 1) / 2].sequence_index);
		//		swap(&maxheap[iele].min_index, &maxheap[(iele - 1) / 2].min_index);

		//		minheap[size_max - 1].max_index = maxheap[(iele - 1) / 2].max_index;
		//		minheap[(iele - 1) / 2].max_index = maxheap[iele].max_index;

		//		iele = (iele - 1) / 2;
		//	}
		//}
		//else if (((iele - 1) / 2) >= 0 && minheap[iele].value < minheap[(iele - 1) / 2].value) // to sie zamienia mina
		//{
		//	while (minheap[iele].min_index != 0 && minheap[iele].value < minheap[(iele - 1) / 2].value)
		//	{
		//		swap(&minheap[iele].value, &minheap[(iele - 1) / 2].value);
		//		swap(&minheap[iele].sequence_index, &minheap[(iele - 1) / 2].sequence_index);
		//		swap(&minheap[iele].max_index, &minheap[(iele - 1) / 2].max_index);

		//		maxheap[size_max - 1].min_index = minheap[(iele - 1) / 2].min_index;
		//		maxheap[(iele - 1) / 2].min_index = minheap[iele].min_index;

		//		iele = (iele - 1) / 2;
		//	}
		//}
	}
}

void Heap::heapify_root_max(unsigned int root_index)
{
	// dziala
	new_index = root_index;

	// jezeli oba istnieja i oba sa wieksze od parenta
	if (2 * root_index + 2 < size_max
		&& maxheap[2 * root_index + 1].value > maxheap[root_index].value
		&& maxheap[2 * root_index + 2].value > maxheap[root_index].value)
	{
		if (maxheap[2 * root_index + 1].value < maxheap[2 * root_index + 2].value)
		{
			new_index = 2 * root_index + 2;
		}
		else if (maxheap[2 * root_index + 1].value > maxheap[2 * root_index + 2].value)
		{
			new_index = 2 * root_index + 1;
		}
		else if (maxheap[2 * root_index + 1].value == maxheap[2 * root_index + 2].value)
		{
			if (maxheap[2 * root_index + 1].sequence_index < maxheap[2 * root_index + 2].sequence_index)
			{
				new_index = 2 * root_index + 1;
			}
			else
			{
				new_index = 2 * root_index + 2;
			}
		}
	}

	// jezeli oba istnieja i tylko pierwszy jest wiekszy od parenta
	else if (2 * root_index + 2 < size_max
		&& maxheap[2 * root_index + 1].value > maxheap[root_index].value
		&& maxheap[2 * root_index + 2].value <= maxheap[root_index].value)
	{
		new_index = 2 * root_index + 1;
	}

	// jezeli oba istnieja i tylko drugi jest wiekszy od parenta
	else if (2 * root_index + 2 < size_max
		&& maxheap[2 * root_index + 2].value > maxheap[root_index].value
		&& maxheap[2 * root_index + 1].value <= maxheap[root_index].value)
	{
		new_index = 2 * root_index + 2;
	}

	// jezeli oba sa takie same i jakims cudem ktorys ma mniejszy sequence_index od parenta (jakby byly same 2)
	else if (2 * root_index + 2 < size_max
		&& maxheap[2 * root_index + 1].value == maxheap[root_index].value
		&& maxheap[2 * root_index + 2].value == maxheap[root_index].value)
	{
		if (maxheap[2 * root_index + 1].sequence_index < maxheap[2 * root_index + 2].sequence_index
			&& maxheap[2 * root_index + 1].sequence_index < maxheap[root_index].sequence_index)
		{
			new_index = 2 * root_index + 1;
		}
		else if (maxheap[2 * root_index + 1].sequence_index > maxheap[2 * root_index + 2].sequence_index
			&& maxheap[2 * root_index + 2].sequence_index < maxheap[root_index].sequence_index)
		{
			new_index = 2 * root_index + 2;
		}
	}

	// jezeli lewy byl taki sam jak parent i ma mniejszy sequence_index
	else if (2 * root_index + 2 < size_max
		&& maxheap[2 * root_index + 1].value == maxheap[root_index].value
		&& maxheap[2 * root_index + 2].value != maxheap[root_index].value)
	{
		if (maxheap[2 * root_index + 1].sequence_index < maxheap[root_index].sequence_index)
		{
			new_index = 2 * root_index + 1;
		}
	}

	// jezeli prawy byl taki sam jak parent i ma mniejszy sequence_index
	else if (2 * root_index + 2 < size_max
		&& maxheap[2 * root_index + 2].value == maxheap[root_index].value
		&& maxheap[2 * root_index + 1].value != maxheap[root_index].value)
	{
		if (maxheap[2 * root_index + 2].sequence_index < maxheap[root_index].sequence_index)
		{
			new_index = 2 * root_index + 2;
		}
	}

	// jezeli istnieje tylko lewy i jest wieszy od parenta
	else if (2 * root_index + 1 < size_max && 2 * root_index + 2 >= size_max && maxheap[2 * root_index + 1].value > maxheap[root_index].value)
	{
		new_index = 2 * root_index + 1;
	}

	// jezeli istnieje tylko lewy i jest rowny parentowi
	else if (2 * root_index + 1 < size_max && 2 * root_index + 2 >= size_max && maxheap[2 * root_index + 1].value == maxheap[root_index].value)
	{
		if (maxheap[2 * root_index + 1].sequence_index < maxheap[root_index].sequence_index)
		{
			new_index = 2 * root_index + 1;
		}
	}

	if (new_index != root_index)
	{
		swap(&maxheap[root_index].value, &maxheap[new_index].value);
		swap(&maxheap[root_index].sequence_index, &maxheap[new_index].sequence_index);
		swap(&maxheap[root_index].min_index, &maxheap[new_index].min_index);

		minheap[maxheap[new_index].min_index].max_index = maxheap[new_index].max_index;
		minheap[maxheap[root_index].min_index].max_index = maxheap[root_index].max_index;

		heapify_root_max(new_index);
	}
}

void Heap::heapify_root_min(unsigned int root_index)
{
	// dziala
	new_index = root_index;

	// jezeli oba istnieja i oba sa mniejsze od parenta
	if (2 * root_index + 2 < size_min
		&& minheap[2 * root_index + 1].value < minheap[root_index].value
		&& minheap[2 * root_index + 2].value < minheap[root_index].value)
	{
		if (minheap[2 * root_index + 1].value > minheap[2 * root_index + 2].value)
		{
			new_index = 2 * root_index + 2;
		}
		else if (minheap[2 * root_index + 1].value < minheap[2 * root_index + 2].value)
		{
			new_index = 2 * root_index + 1;
		}
		else if (minheap[2 * root_index + 1].value == minheap[2 * root_index + 2].value)
		{
			if (minheap[2 * root_index + 1].sequence_index < minheap[2 * root_index + 2].sequence_index)
			{
				new_index = 2 * root_index + 1;
			}
			else
			{
				new_index = 2 * root_index + 2;
			}
		}
	}

	// jezeli oba istnieja i tylko pierwszy jest mniejszy od parenta
	else if (2 * root_index + 2 < size_min
		&& minheap[2 * root_index + 1].value < minheap[root_index].value
		&& minheap[2 * root_index + 2].value >= minheap[root_index].value)
	{
		if (minheap[2 * root_index + 1].value == 1 || minheap[2 * root_index + 1].value == 0)
		{
			if (minheap[2 * root_index + 2].value == minheap[root_index].value
				&& minheap[2 * root_index + 2].sequence_index < minheap[root_index].sequence_index)
			{
				new_index = 2 * root_index + 2;
			}
		}
		else
		{
			new_index = 2 * root_index + 1;
		}
	}

	// jezeli oba istnieja i tylko drugi jest mniejszy od parenta
	else if (2 * root_index + 2 < size_min
		&& minheap[2 * root_index + 2].value < minheap[root_index].value
		&& minheap[2 * root_index + 1].value >= minheap[root_index].value
		)
	{
		if (minheap[2 * root_index + 2].value == 1 || minheap[2 * root_index + 2].value == 0)
		{
			if (minheap[2 * root_index + 1].value == minheap[root_index].value
				&& minheap[2 * root_index + 1].sequence_index < minheap[root_index].sequence_index)
			{
				new_index = 2 * root_index + 1;
			}
		}
		else
		{
			new_index = 2 * root_index + 2;
		}
	}

	// jezeli oba sa takie same i jakims cudem ktorys ma mniejszy sequence_index od parenta (jakby byly same 2)
	else if (2 * root_index + 2 < size_min
		&& minheap[2 * root_index + 1].value == minheap[root_index].value
		&& minheap[2 * root_index + 2].value == minheap[root_index].value)
	{
		if (minheap[2 * root_index + 1].sequence_index < minheap[2 * root_index + 2].sequence_index
			&& minheap[2 * root_index + 1].sequence_index < minheap[root_index].sequence_index)
		{
			new_index = 2 * root_index + 1;
		}
		else if (minheap[2 * root_index + 1].sequence_index > minheap[2 * root_index + 2].sequence_index
			&& minheap[2 * root_index + 2].sequence_index < minheap[root_index].sequence_index)
		{
			new_index = 2 * root_index + 2;
		}
	}

	// jezeli lewy byl taki sam jak parent i ma mniejszy sequence_index
	else if (2 * root_index + 2 < size_min
		&& minheap[2 * root_index + 1].value == minheap[root_index].value
		&& minheap[2 * root_index + 2].value != minheap[root_index].value)
	{
		if (minheap[2 * root_index + 1].sequence_index < minheap[root_index].sequence_index)
		{
			new_index = 2 * root_index + 1;
		}
	}

	// jezeli prawy byl taki sam jak parent i ma mniejszy sequence_index
	else if (2 * root_index + 2 < size_min
		&& minheap[2 * root_index + 2].value == minheap[root_index].value
		&& minheap[2 * root_index + 1].value != minheap[root_index].value)
	{
		if (minheap[2 * root_index + 2].sequence_index < minheap[root_index].sequence_index)
		{
			new_index = 2 * root_index + 2;
		}
	}

	// jezeli istnieje tylko lewy i jest mniejszy od parenta
	else if (2 * root_index + 1 < size_min && 2 * root_index + 2 >= size_min && minheap[2 * root_index + 1].value < minheap[root_index].value
		&& minheap[2 * root_index + 1].value != 0 && minheap[2 * root_index + 1].value != 1)
	{
		new_index = 2 * root_index + 1;
	}

	// jezeli istnieje tylko lewy i jest rowny parentowi
	else if (2 * root_index + 1 < size_min && 2 * root_index + 2 >= size_min && minheap[2 * root_index + 1].value == minheap[root_index].value)
	{
		if (minheap[2 * root_index + 1].sequence_index < minheap[root_index].sequence_index)
		{
			new_index = 2 * root_index + 1;
		}
	}

	if (new_index != root_index)
	{
		swap(&minheap[root_index].value, &minheap[new_index].value);
		swap(&minheap[root_index].sequence_index, &minheap[new_index].sequence_index);
		swap(&minheap[root_index].max_index, &minheap[new_index].max_index);

		maxheap[minheap[new_index].max_index].min_index = minheap[new_index].min_index;
		maxheap[minheap[root_index].max_index].min_index = minheap[root_index].min_index;

		heapify_root_min(new_index);
	}
}

void Heap::up_pusher_min_heap(unsigned short index)
{
	// dziala
	help_pop_min = index;

	while (minheap[help_pop_min].min_index != 0
		&& minheap[help_pop_min].value < minheap[(help_pop_min - 1) / 2].value

		|| (minheap[help_pop_min].value == minheap[(help_pop_min - 1) / 2].value
			&& minheap[help_pop_min].sequence_index < minheap[(help_pop_min - 1) / 2].sequence_index))
	{
		swap(&minheap[help_pop_min].value, &minheap[(help_pop_min - 1) / 2].value);
		swap(&minheap[help_pop_min].sequence_index, &minheap[(help_pop_min - 1) / 2].sequence_index);
		swap(&minheap[help_pop_min].max_index, &minheap[(help_pop_min - 1) / 2].max_index);

		maxheap[minheap[(help_pop_min - 1) / 2].max_index].min_index = minheap[(help_pop_min - 1) / 2].min_index;
		maxheap[minheap[help_pop_min].max_index].min_index = minheap[help_pop_min].min_index;

		help_pop_min = (help_pop_min - 1) / 2;
	}
}

void Heap::up_pusher_max_heap(unsigned short index)
{
	// dziala
	help_pop_min = index;

	while (maxheap[help_pop_min].max_index != 0
		&& (maxheap[help_pop_min].value > maxheap[(help_pop_min - 1) / 2].value

			|| (maxheap[help_pop_min].value == maxheap[(help_pop_min - 1) / 2].value
				&& maxheap[help_pop_min].sequence_index < maxheap[(help_pop_min - 1) / 2].sequence_index)))
	{
		swap(&maxheap[help_pop_min].value, &maxheap[(help_pop_min - 1) / 2].value);
		swap(&maxheap[help_pop_min].sequence_index, &maxheap[(help_pop_min - 1) / 2].sequence_index);
		swap(&maxheap[help_pop_min].min_index, &maxheap[(help_pop_min - 1) / 2].min_index);

		minheap[maxheap[(help_pop_min - 1) / 2].min_index].max_index = maxheap[(help_pop_min - 1) / 2].max_index;
		minheap[maxheap[help_pop_min].min_index].max_index = maxheap[help_pop_min].max_index;

		help_pop_min = (help_pop_min - 1) / 2;
	}
}

void Heap::pop_max()
{
	if (size_max == 1)
	{
		size_max--;
		size_min--;
	}
	else if (size_max > 1)
	{
		jakistam_kolejny_index = maxheap[0].min_index;
		if (maxheap[0].value == 1)
		{
			minheap[jakistam_kolejny_index].value = 1;
		}
		else if (maxheap[0].value == 0)
		{
			minheap[jakistam_kolejny_index].value = 0;
		}

		if (minheap[jakistam_kolejny_index].sequence_index != minheap[size_min - 1].sequence_index)
		{
			swap(&minheap[jakistam_kolejny_index].value, &minheap[size_min - 1].value);
			swap(&minheap[jakistam_kolejny_index].sequence_index, &minheap[size_min - 1].sequence_index);
			swap(&minheap[jakistam_kolejny_index].max_index, &minheap[size_min - 1].max_index);

			maxheap[minheap[jakistam_kolejny_index].max_index].min_index = minheap[jakistam_kolejny_index].min_index;

			size_min--;
			if (jakistam_kolejny_index != 0 && minheap[jakistam_kolejny_index].value < minheap[(jakistam_kolejny_index - 1) / 2].value)
			{
				up_pusher_min_heap(jakistam_kolejny_index);
			}
			else if (jakistam_kolejny_index != 0
				&& minheap[jakistam_kolejny_index].value == minheap[(jakistam_kolejny_index - 1) / 2].value
				&& minheap[jakistam_kolejny_index].sequence_index < minheap[(jakistam_kolejny_index - 1) / 2].sequence_index)
			{
				up_pusher_min_heap(jakistam_kolejny_index);
			}
			else if (jakistam_kolejny_index != 0
				&& minheap[jakistam_kolejny_index].value == minheap[(jakistam_kolejny_index - 1) / 2].value
				&& minheap[jakistam_kolejny_index].sequence_index > minheap[(jakistam_kolejny_index - 1) / 2].sequence_index)
			{
				heapify_root_min(jakistam_kolejny_index);
			}
			else if (jakistam_kolejny_index != 0 && minheap[jakistam_kolejny_index].value > minheap[(jakistam_kolejny_index - 1) / 2].value)
			{
				heapify_root_min(jakistam_kolejny_index);
			}
			else if (jakistam_kolejny_index == 0)
			{
				heapify_root_min(jakistam_kolejny_index);
			}
		}
		else
		{
			size_min--;
		}
		if (maxheap[0].sequence_index != maxheap[size_max - 1].sequence_index)
		{
			swap(&maxheap[0].value, &maxheap[size_max - 1].value);
			swap(&maxheap[0].sequence_index, &maxheap[size_max - 1].sequence_index);
			swap(&maxheap[0].min_index, &maxheap[size_max - 1].min_index);

			minheap[maxheap[0].min_index].max_index = 0;

			size_max--;
		}
		else
		{
			size_max--;
		}
		heapify_root_max(0);
	}
}

void Heap::pop_min()
{
	if (size_min == 1)
	{
		size_max--;
		size_min--;
	}
	else if (size_max > 1)
	{
		jakistam_kolejny_index = minheap[0].max_index;
		if (minheap[0].value == 1)
		{
			maxheap[jakistam_kolejny_index].value = 1;
		}
		else if (minheap[0].value == 0)
		{
			maxheap[jakistam_kolejny_index].value = 0;
		}

		if (maxheap[jakistam_kolejny_index].sequence_index != maxheap[size_max - 1].sequence_index)
		{
			swap(&maxheap[jakistam_kolejny_index].value, &maxheap[size_max - 1].value);
			swap(&maxheap[jakistam_kolejny_index].sequence_index, &maxheap[size_max - 1].sequence_index);
			swap(&maxheap[jakistam_kolejny_index].min_index, &maxheap[size_max - 1].min_index);

			minheap[maxheap[jakistam_kolejny_index].min_index].max_index = maxheap[jakistam_kolejny_index].max_index;

			size_max--;
			if (jakistam_kolejny_index != 0 && maxheap[jakistam_kolejny_index].value > maxheap[(jakistam_kolejny_index - 1) / 2].value)
			{
				up_pusher_max_heap(jakistam_kolejny_index);
			}
			else if (jakistam_kolejny_index != 0
				&& maxheap[jakistam_kolejny_index].value == maxheap[(jakistam_kolejny_index - 1) / 2].value
				&& maxheap[jakistam_kolejny_index].sequence_index < maxheap[(jakistam_kolejny_index - 1) / 2].sequence_index)
			{
				up_pusher_max_heap(jakistam_kolejny_index);
			}
			else if (jakistam_kolejny_index != 0
				&& maxheap[jakistam_kolejny_index].value == maxheap[(jakistam_kolejny_index - 1) / 2].value
				&& maxheap[jakistam_kolejny_index].sequence_index > maxheap[(jakistam_kolejny_index - 1) / 2].sequence_index)
			{
				heapify_root_max(jakistam_kolejny_index);
			}
			else if (jakistam_kolejny_index != 0 && maxheap[jakistam_kolejny_index].value < maxheap[(jakistam_kolejny_index - 1) / 2].value)
			{
				heapify_root_max(jakistam_kolejny_index);
			}
			else if (jakistam_kolejny_index == 0)
			{
				heapify_root_max(jakistam_kolejny_index);
			}
		}
		else
		{
			size_max--;
		}
		if (minheap[0].sequence_index != minheap[size_min - 1].sequence_index)
		{
			swap(&minheap[0].value, &minheap[size_min - 1].value);
			swap(&minheap[0].sequence_index, &minheap[size_min - 1].sequence_index);
			swap(&minheap[0].max_index, &minheap[size_min - 1].max_index);

			maxheap[minheap[0].max_index].min_index = 0;

			size_min--;
		}
		else
		{
			size_min--;
		}
		heapify_root_min(0);
	}
}