#include <iostream>

long long Fibonacci(int n)
{
	if (n <= 1)
	{
		return n;
	}
	else
	{
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}

int main()
{
	for (int i = 1; i <= 10; i++)
	{
		std::cout << Fibonacci(i) << " ";
	}
	std::cout << std::endl;

	return 0;
}