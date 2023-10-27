#include <iostream>
#include <queue>

using namespace std;

#define MAX_QUEUE 10

template <typename T>
class CircularQueue
{
public:
	CircularQueue(int size = MAX_QUEUE)
	{
		Array = new T[size];
		Capacity = size;
		Count = 0;
		FrontIndex = 0;
		RearIndex = -1;
	}
	~CircularQueue()
	{
		delete[] Array;
	}

	void enqueue(const T& e)
	{
		if (full())
		{
			cout << "Overflow error!" << endl;
			return;
		}

		RearIndex = (RearIndex + 1) % Capacity;
		Array[RearIndex] = e;
		Count++;
	}

	void dequeue()
	{
		if (empty())
		{
			cout << "Underflow error!" << endl;
			return;
		}

		FrontIndex = (FrontIndex + 1) % Capacity;
		Count--;
	}

	const T& front() const { return Array[FrontIndex]; }

	bool empty() const { return Count == 0; }
	int full() const { return Count == Capacity; }
	int size() const { return Count; }

private:
	T* Array;
	int FrontIndex;
	int RearIndex;
	int Count;
	int Capacity;
};

int main()
{
	CircularQueue<int> Q(5);

	Q.enqueue(10);
	Q.enqueue(20);
	Q.enqueue(30);
	Q.enqueue(40);
	Q.enqueue(50);

	Q.dequeue();
	Q.dequeue();

	Q.enqueue(60);
	Q.enqueue(70);
	Q.enqueue(80);

	while (!Q.empty())
	{
		auto& e = Q.front();
		cout << e << " ";
		Q.dequeue();
	}

	return 0;
}