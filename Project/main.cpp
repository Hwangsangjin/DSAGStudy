#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
	forward_list<int> FL{ 10, 20, 30, 40 };
	FL.push_front(40);
	FL.push_front(30);

	for (const auto& i : FL)
	{
		cout << i << " ";
	}
	cout << endl;

	int Cnt = distance(FL.begin(), FL.end());
	cout << Cnt << endl;

	FL.remove(40);
	FL.remove_if([](int N) { return N > 20; });

	for (const auto& i : FL)
	{
		cout << i << " ";
	}
	cout << endl;

	Cnt = distance(FL.begin(), FL.end());
	cout << Cnt << endl;

	return 0;
}