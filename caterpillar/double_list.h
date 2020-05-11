#pragma once
#include <cstdio>
#include <cstdlib>
#include <iostream>

struct node
{
	char letter;
	node* next;
	node* prev;
};

struct double_list
{
	double_list();
	void push_front(char value);
	void push_back(char value);
	void pop_front();
	void pop_back();
	void display();
	bool empty();
private:
	node* head;
	node* last;
};

void print_an_array(char** arr, int n, int m);
void move_the_caterpillar(char direction, int* x, int* y, int n, int m);