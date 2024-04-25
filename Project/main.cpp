#include <iostream>
#include <algorithm>

bool linear_search(int data[], int n, int target)
{
	for (int i = 0; i < n; i++)
	{
		if (data[i] == target)
		{
			return true;
		}
	}

	return false;
}

bool binary_search(int data[], int n, int target)
{
	int lower = 0;
	int upper = n - 1;

	if (data[lower] > target || data[upper] < target)
	{
		return false;
	}

	while (lower <= upper)
	{
		int mid = (lower + upper) / 2;
		
		if (data[mid] == target)
		{
			return true;
		}
		else if (data[mid] < target)
		{
			lower = mid + 1;
		}
		else
		{
			upper = mid - 1;
		}
	}

	return false;
}

int main()
{
	int data[] = {1, 2, 3, 5, 7, 10, 13, 15, 18, 23, 25, 27, 28, 30, 33};
	int target = 23;

	bool res1 = linear_search(data, std::size(data), target);
	bool res2 = binary_search(data, std::size(data), target);
	bool res3 = std::binary_search(std::begin(data), std::end(data), target);

	std::cout << res1 << std::endl;
	std::cout << res2 << std::endl;
	std::cout << res3 << std::endl;

	return 0;
}