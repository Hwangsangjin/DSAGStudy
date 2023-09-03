#include <iostream>
#include <list>

using namespace std;

int main()
{
	list<int> L1;
	L1.push_back(10);
	L1.push_back(20);

	for (const auto& i : L1)
	{
		cout << i << " ";
	}
	cout << endl;

	list<int> L2{ 10, 20, 30, 40 };

	for (const auto& i : L2)
	{
		cout << i << " ";
	}
	cout << endl;

	L2.splice(L2.end(), L1);

	for (const auto& i : L1)
	{
		cout << i << " ";
	}
	cout << endl;

	for (const auto& i : L2)
	{
		cout << i << " ";
	}
	cout << endl;

	L2.sort();

	for (const auto& i : L2)
	{
		cout << i << " ";
	}
	cout << endl;

	L2.unique();

	for (const auto& i : L2)
	{
		cout << i << " ";
	}
	cout << endl;

	return 0;
}