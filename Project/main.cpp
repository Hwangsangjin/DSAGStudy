#include <iostream>

using namespace std;

template <typename T>
struct Node
{
	T Data;
	Node* Prev;
	Node* Next;
};

template <typename T>
class DoublyLinkedList
{
public:
	class iterator
	{
	public:
		iterator() : Ptr(nullptr) {}
		iterator(Node<T>* p) : Ptr(p) {}

		T& operator*() { return Ptr->Data; }

		iterator& operator++()
		{
			Ptr = Ptr->Next;
			return *this;
		}

		iterator& operator--()
		{
			Ptr = Ptr->Prev;
			return *this;
		}

		bool operator==(const iterator& iter) const
		{
			return Ptr == iter.Ptr;
		}

		bool operator!=(const iterator& iter) const
		{
			return Ptr != iter.Ptr;
		}

		friend class DoublyLinkedList;

	private:
		Node<T>* Ptr;
	};

	DoublyLinkedList()
		: Count(0)
	{
		Header = new Node<T>{ T(), nullptr, nullptr};
		Trailer = new Node<T>{ T(), nullptr, nullptr};

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

	iterator begin() const
	{
		return iterator(Header->Next);
	}

	iterator end() const
	{
		return iterator(Trailer);
	}

	void insert(const iterator& iter, const T& value)
	{
		Node<T>* Ptr = iter.Ptr;
		Node<T>* NewNode = new Node<T>{ value, Ptr->Prev, Ptr };
		NewNode->Prev->Next = NewNode;
		NewNode->Next->Prev = NewNode;
		Count++;
	}

	void push_front(const T& value)
	{
		insert(begin(), value);
	}

	void push_back(const T& value)
	{
		insert(end(), value);
	}

	void erase(const iterator& iter)
	{
		Node<T>* Ptr = iter.Ptr;
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
			erase(begin());
		}
	}

	void pop_back()
	{
		if (!empty())
		{
			erase(--end());
		}
	}

	iterator find(const T& value)
	{
		Node<T>* Curr = Header->Next;
		while (Curr->Data != value && Curr != Trailer)
		{
			Curr = Curr->Next;
		}

		return iterator(Curr);
	}

	bool empty() const
	{
		return Count == 0;
	}

	int size() const
	{
		return Count;
	}

private:
	int Count;
	Node<T>* Header;
	Node<T>* Trailer;
};

int main()
{
	DoublyLinkedList<int> DLL;
	DLL.push_back(10);
	DLL.push_back(20);
	DLL.push_back(30);

	auto Iter = DLL.find(20);
	if (Iter != DLL.end())
	{
		DLL.insert(Iter, 50);
	}

	for (const auto& i : DLL)
	{
		cout << i << " ";
	}
	cout << endl;

	return 0;
}