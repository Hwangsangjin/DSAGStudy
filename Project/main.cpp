#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> STK;
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