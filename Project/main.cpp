#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	vector<string> Msg{ "Hello", "C++", "World", "from", "Visual Studio" };

	for (const string& Word : Msg)
	{
		cout << Word << " ";
	}
	cout << endl;

	return 0;
}