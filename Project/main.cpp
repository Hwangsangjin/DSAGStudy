#include <iostream>

using namespace std;

struct Node
{
	int Data;
	Node* Prev;
	Node* Next;
};

class DoublyLinkedList
{
public:
	DoublyLinkedList()
		: Count(0)
	{
		Header = new Node{ 0, nullptr, nullptr };
		Trailer = new Node{ 0, nullptr, nullptr };

		Header->Next = Trailer;
		Trailer->Prev = Header;
	}

	~DoublyLinkedList()
	{
		while (!empty())
		{
			pop_front();
		}

		delete Header;
		Header = nullptr;
		delete Trailer;
		Trailer = nullptr;
	}

	void insert(Node* Ptr, int Value)
	{
		Node* NewNode = new Node{ Value, Ptr->Prev, Ptr };
		NewNode->Prev->Next = NewNode;
		NewNode->Next->Prev = NewNode;
		Count++;
	}

	void push_front(int Value)
	{
		insert(Header->Next, Value);
	}

	void push_back(int Value)
	{
		insert(Trailer, Value);
	}

	void erase(Node* Ptr)
	{
		Ptr->Prev->Next = Ptr->Next;
		Ptr->Next->Prev = Ptr->Prev;
		delete Ptr;
		Ptr = nullptr;
		Count--;
	}

	void pop_front()
	{
		if (!empty())
		{
			erase(Header->Next);
		}
	}

	void pop_back()
	{
		if (!empty())
		{
			erase(Trailer->Prev);
		}
	}

	bool empty() const
	{
		return Count == 0;
	}

	int size() const
	{
		return Count;
	}

	void print_all() const
	{
		Node* Curr = Header->Next;
		while (Curr != Trailer)
		{
			cout << Curr->Data << " ";
			Curr = Curr->Next;
		}

		cout << endl;
	}

	void print_reverse() const
	{
		Node* Curr = Trailer->Prev;
		while (Curr != Header)
		{
			cout << Curr->Data << " ";
			Curr = Curr->Prev;
		}

		cout << endl;
	}

private:
	int Count;
	Node* Header;
	Node* Trailer;
};

int main()
{
	DoublyLinkedList DLL;
	DLL.push_back(10);
	DLL.push_back(20);
	DLL.push_back(30);
	DLL.print_all();
	DLL.print_reverse();

	DLL.pop_front();
	DLL.pop_back();
	DLL.print_all();

	DLL.push_front(100);
	DLL.push_back(400);
	DLL.print_all();

	return 0;
}