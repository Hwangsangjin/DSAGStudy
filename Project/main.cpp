#include <iostream>

int Sum(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return n + Sum(n - 1);
	}
}

int main()
{
	int result = Sum(5);
	std::cout << result << std::endl;

	return 0;
}