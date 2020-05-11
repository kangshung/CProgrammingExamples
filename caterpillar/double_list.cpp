#include "double_list.h"

double_list::double_list() :head(nullptr), last(nullptr)
{
}

void double_list::push_front(char value)
{
	//dziala na 100%
	node* n = (node*)malloc(sizeof(node));
	n->letter = value;
	n->prev = nullptr;
	n->next = head;
	head = n;
	if (n->next != nullptr)
	{
		n->next->prev = n;
	}
	else
	{
		last = n;
	}
}

void double_list::push_back(char value)
{
	//dziala na 100%
	node* n = (node*)malloc(sizeof(node));
	n->letter = value;
	n->next = nullptr;
	n->prev = last;
	last = n;
	if (n->prev != nullptr)
	{
		n->prev->next = n;
	}
	else
	{
		head = n;
	}
}

void double_list::pop_front()
{
	if (head == last)
	{
		delete head;
		head = nullptr;
	}
	else
	{
		node* n = head;
		head = head->next;
		delete n;
	}
}

void double_list::pop_back()
{
	if (head == last)
	{
		delete head;
		head = nullptr;
	}
	else
	{
		node* n = last;
		last = last->prev;
		last->next = nullptr;
		delete n;
	}
}

void double_list::display()
{
	node* temp = head;

	if (empty())
	{
		std::cout << "#";
	}
	else
	{
		while (temp != nullptr)
		{
			printf("%c", temp->letter);
			temp = temp->next;
		}
	}
}

bool double_list::empty()
{
	if (head == nullptr)
	{
		return true;
	}
	else return false;
}