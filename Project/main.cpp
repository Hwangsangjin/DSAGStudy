#include <iostream>

long long Factorial(int n)
{
	if (n == 0)
	{
		return 1;
	}
	else
	{
		return n * Factorial(n - 1);
	}
}

int main()
{
	std::cout << Factorial(5) << std::endl;
	std::cout << Factorial(10) << std::endl;
	std::cout << Factorial(20) << std::endl;

	return 0;
}