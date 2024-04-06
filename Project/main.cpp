#include <iostream>
#include <numeric>

int GCD(int a, int b)
{
	if (b == 0)
	{
		return a;
	}
	else
	{
		return GCD(b, a % b);
	}
}

int LCM(int a, int b)
{
	return a * b / GCD(a, b);
}

int main()
{
	int gcd1 = GCD(10, 15);
	int lcm1 = LCM(10, 15);

	constexpr int gcd2 = std::gcd(10, 15);
	constexpr int lcm2 = std::lcm(10, 15);

	std::cout << gcd1 << ", " << gcd2 << std::endl;
	std::cout << lcm1 << ", " << lcm2 << std::endl;

	return 0;
}