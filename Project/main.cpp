#include <iostream>
#include <algorithm>

int Partition(int data[], int left, int right)
{
	int pivot = data[left];
	int i = left + 1, j = right;

	while (true)
	{
		while (data[i] <= pivot && i <= right)
		{
			i++;
		}

		while (data[j] > pivot && j > left)
		{
			j--;
		}
		
		if (i < j)
		{
			std::swap(data[i], data[j]);
		}
		else
		{
			break;
		}
	}

	std::swap(data[left], data[j]);
	return j;
}

void QuickSort(int data[], int left, int right)
{
	if (left < right)
	{
		int p = Partition(data, left, right);
		QuickSort(data, left, p - 1);
		QuickSort(data, p + 1, right);
	}
}

int main()
{
	int data[] = {5, 6, 7, 3, 1, 9, 2, 4, 8};
	QuickSort(data, 0, std::size(data) - 1);

	for (const auto n : data)
	{
		std::cout << n << " ";
	}
	std::cout << std::endl;

	return 0;
}