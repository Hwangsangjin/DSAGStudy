#include <iostream>

using namespace std;

struct Node
{
	int Data;
	Node* Next;
};

class LinkedList
{
public:
	LinkedList() : Head(nullptr) {};
	~LinkedList()
	{
		while (!empty())
		{
			pop_front();
		}
	}

	void push_front(int Value)
	{
		Node* NewNode = new Node{ Value, Head };

		if (Head)
		{
			NewNode->Next = Head;
		}

		Head = NewNode;
	}

	void pop_front()
	{
		if (!Head)
		{
			return;
		}

		Node* First = Head;
		Head = Head->Next;
		delete First;
	}

	bool empty() const
	{
		return Head == nullptr;
	}

	void print_all() const
	{
		Node* Curr = Head;

		while (Curr)
		{
			cout << Curr->Data << " ";
			Curr = Curr->Next;
		}

		cout << endl;
	}

private:
	Node* Head;
};

int main()
{
	LinkedList LL;
	LL.push_front(10);
	LL.push_front(20);
	LL.push_front(30);
	LL.print_all();

	LL.pop_front();
	LL.print_all();

	LL.push_front(40);
	LL.print_all();

	return 0;
}