#pragma once
#pragma warning(disable:4715)
#pragma warning(disable:4244)
#include <iostream>

struct Heap
{
	struct node
	{
		unsigned int value;
		int sequence_index;
		int max_index;
		int min_index;
	}*minheap, *maxheap;

	unsigned short capacity, size_min, size_max, iele, root_index, new_index, help_pop_min, jakistam_kolejny_index;

	Heap();
	void push(unsigned int n, unsigned short i);

	void heapify_root_max(unsigned int root_index);
	void heapify_root_min(unsigned int root_index);

	void up_pusher_max_heap(unsigned short index);
	void up_pusher_min_heap(unsigned short index);

	void pop_max();
	void pop_min();
};