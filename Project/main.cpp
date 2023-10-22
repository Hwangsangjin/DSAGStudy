#include <iostream>
#include <list>

using namespace std;

template <typename T>
class Queue
{
public:
	Queue() {}

	void enqueue(const T& e) { list.push_back(e); }
	void dequeue() { list.pop_front(); }
	const T& front() const { return list.front(); }

	bool empty() const { return list.empty(); }
	int size() const { return list.size(); }

private:
	std::list<T> list;
};

int main()
{
	Queue<int> Q;
	Q.enqueue(10);
	Q.enqueue(20);
	Q.enqueue(30);
	Q.dequeue();

	cout << Q.front() << endl;
	Q.enqueue(40);

	while (!Q.empty())
	{
		const auto& e = Q.front();
		cout << e << " ";
		Q.dequeue();
	}

	return 0;
}