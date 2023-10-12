#include <iostream>
#include <stack>

using namespace std;

string Reverse(const string& Str)
{
	stack<char> Stk;
	for (char c : Str)
	{
		Stk.push(c);
	}

	string Result;
	while (!Stk.empty())
	{
		Result += Stk.top();
		Stk.pop();
	}

	return Result;
}

int main()
{
	string Str1 = "HELLO";
	string Str2 = "ALGORITHM";

	cout << Str1 << " -> " << Reverse(Str1) << endl;
	cout << Str2 << " -> " << Reverse(Str2) << endl;

	return 0;
}