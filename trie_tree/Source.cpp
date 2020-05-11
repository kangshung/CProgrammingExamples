#include<iostream>
#include<string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

const int ALPHABET_SIZE = 26;

struct node
{
	node* children[ALPHABET_SIZE];
	string translation;
	bool end;
};

node* create_node()
{
	node* temp = new node;
	temp->end = false;

	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		temp->children[i] = nullptr;
	}
	return temp;
}

void insert(node* root, string word, string translation)
{
	node* temp = root;

	for (int i = 0; i < word.length(); i++)
	{
		int index = word[i] - 'a';

		if (!temp->children[index])
		{
			temp->children[index] = create_node();
		}
		temp = temp->children[index];
	}

	temp->end = true;
	temp->translation = translation;
}

void search(node* root, string word)
{
	node* temp = root;

	for (int i = 0; i < word.length(); i++)
	{
		int index = word[i] - 'a';

		if (!temp->children[index])
		{
			cout << '-' << endl;
			return;
		}
		temp = temp->children[index];
	}

	if (temp->end)
	{
		cout << temp->translation << endl;
	}
	else
	{
		cout << '-' << endl;
	}
}

void print_all_possibilities(node* node)
{
	if (node == nullptr)
	{
		return;
	}
	if (node->end)
	{
		cout << node->translation << endl;
	}

	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (node->children[i] != nullptr)
		{
			print_all_possibilities(node->children[i]);
		}
	}
}

void asterisk(node* root, string word)
{
	node* temp = root;

	for (int i = 0; i < word.length(); i++)
	{
		int index = word[i] - 'a';

		if (!temp->children[index])
		{
			cout << '-' << endl;
			return;
		}
		temp = temp->children[index];
	}

	print_all_possibilities(temp);
}

int main()
{
	char letter;
	string word, translation;
	node* root = create_node();
	while (cin >> letter)
	{
		if (letter == '+')
		{
			cin >> word >> translation;
			insert(root, word, translation);
		}
		else if (letter == '?')
		{
			cin >> word;
			search(root, word);
		}
		else if (letter == '*')
		{
			cin >> word;
			asterisk(root, word);
		}
	}
	cin.ignore();
	cin.ignore();
}