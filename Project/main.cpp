#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> Q;
	Q.push(10);
	Q.push(20);
	Q.push(30);
	Q.pop();

	cout << Q.front() << endl;
	Q.push(40);

	while (!Q.empty())
	{
		const auto& e = Q.front();
		cout << e << " ";
		Q.pop();
	}

	return 0;
}