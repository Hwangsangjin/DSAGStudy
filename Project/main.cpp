#include <iostream>

void Hanoi(int n, int from, int to, int by)
{
	if (n == 1)
	{
		std::cout << from << " -> " << to << std::endl;
	}
	else
	{
		Hanoi(n - 1, from, by, to);
		std::cout << from << " -> " << to << std::endl;
		Hanoi(n - 1, by, to, from);
	}
}

int main()
{
	//Hanoi(2, 1, 3, 2);
	Hanoi(3, 1, 3, 2);

	return 0;
}