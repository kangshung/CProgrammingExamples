#pragma once
#include<iostream>

struct Heap
{
	int size, root, allocation;
	int* arr;

	Heap();
	~Heap();
	void push(int);
	int pop();
	void heapify(int);
	void increase_value(int, int);
};