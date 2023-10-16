#include <iostream>
#include <stack>

using namespace std;

bool ParenCheck(const string& S)
{
	stack<char> Stk;

	for (const auto& c : S)
	{
		if (c == '(' || c == '{' || c == '[')
		{
			Stk.push(c);
		}
		else
		{
			if (Stk.empty() ||
				(Stk.top() == '(' && c != ')') ||
				(Stk.top() == '{' && c != '}') ||
				(Stk.top() == '[' && c != ']'))
			{
				return false;
			}

			Stk.pop();
		}
	}

	return Stk.empty();
}

int main()
{
	// 올바른 괄호
	cout << ParenCheck("(){}[]") << endl;
	cout << ParenCheck("((((()))))") << endl;
	cout << ParenCheck("(){[()]}") << endl;

	// 올바르지 않은 괄호
	cout << ParenCheck("((({}))") << endl;
	cout << ParenCheck(")(") << endl;
	cout << ParenCheck("({)}") << endl;

	return 0;
}