#include <iostream>

int buff[256];

void Merge(int data[], int left, int mid, int right)
{
	int i = left, j = mid + 1, k = left;

	while (i <= mid && j <= right)
	{
		if (data[i] <= data[j])
		{
			buff[k++] = data[i++];
		}
		else
		{
			buff[k++] = data[j++];
		}
	}

	while (i <= mid)
	{
		buff[k++] = data[i++];
	}

	while (j <= right)
	{
		buff[k++] = data[j++];
	}

	for (int x = left; x <= right; x++)
	{
		data[x] = buff[x];
	}
}

void MergeSort(int data[], int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		MergeSort(data, left, mid);
		MergeSort(data, mid + 1, right);
		Merge(data, left, mid, right);
	}
}

int main()
{
	int data[] = {2, 6, 7, 4, 1, 8, 5, 3};
	MergeSort(data, 0, 7);

	for (const auto n : data)
	{
		std::cout << n << " ";
	}
	std::cout << std::endl;

	return 0;
}