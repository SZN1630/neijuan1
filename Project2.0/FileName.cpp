#include "szn.h"
void List::inputFront()
{
	LinkNode* newNode;
	int val;
	cin >> val;
	int end = NULL;
	cout << "Please input number" << endl;
	while (val != end)
	{
		newNode = new LinkNode(val);
		if (newNode == NULL) { cout << "error"; exit(1); }
		newNode->link = first->link;
		first->link = newNode;
		cin >> val;
	}
}
bool List::Insert(int i, int& x)
{
	if (first == NULL || i == 0)
	{
		LinkNode* newNode = new LinkNode(x);
		if (newNode == NULL) { cout << "error"; exit(1); }
		newNode->link = first;
		first = newNode;
	}
	else
	{
		LinkNode* current = first;
		for (int k = 1; k < i; k++)
			if (current == NULL) break;
			else current = current->link;
		if (current == NULL) { cout << "error"; return false; }
		else
		{
			LinkNode* newNode = new LinkNode(x);
			if (newNode == NULL) { cout << "error"; exit(1); }
			newNode->link = current->link;
			current->link = newNode;
		}
	}
	return true;
}
//bool List::Remove(int i, int& x)

void List::Output()
{
	LinkNode* current = first->link;
	while (current != NULL) {
		cout << current->data << " ";
		current = current->link;
	}
	cout << endl;
}
