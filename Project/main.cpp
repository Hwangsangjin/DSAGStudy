#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class Stack
{
public:
	Stack() {}

	void push(const T& e) { List.push_back(e); }
	void pop() { List.pop_back(); }
	const T& top() const { return List.back(); }

	bool empty() const { return List.empty(); }
	int size() const { return List.size(); }

private:
	vector<T> List;
};


int main()
{
	Stack<int> STK;
	STK.push(10);
	STK.push(20);
	STK.push(30);
	STK.pop();

	cout << STK.top() << endl;
	STK.push(40);

	while (!STK.empty())
	{
		auto& e = STK.top();
		cout << e << " ";
		STK.pop();
	}
	cout << endl;

	return 0;
}