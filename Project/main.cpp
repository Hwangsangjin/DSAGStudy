#include <iostream>
#include <stack>
#include <vector>

using namespace std;

template <typename T>
void Reverse(vector<T>& Vec)
{
	stack<T, vector<T>> Stk(Vec);

	/*stack<T> Stk;
	for (const auto& e : Vec)
	{
		Stk.push(e);
	}*/

	for (int i = 0; i < Vec.size(); i++)
	{
		Vec[i] = Stk.top();
		Stk.pop();
	}
}

int main()
{
	//vector<int> Vec{ 10, 20, 30, 40, 50 };
	vector<string> Vec{ "John", "loves", "Jane" };

	//Reverse<int>(Vec);
	Reverse<string>(Vec);

	for (const auto& e : Vec)
	{
		cout << e << " ";
	}

	return 0;
}