#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void PrintVector(const std::vector<T>& vec)
{
	for (const auto e : vec)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;
}

void Permutation(std::vector<int>& vec, int k)
{
	if (k == vec.size() - 1)
	{
		PrintVector(vec);
		return;
	}

	for (int i = k; i < vec.size(); i++)
	{
		std::swap(vec[k], vec[i]);
		Permutation(vec, k + 1);
		std::swap(vec[k], vec[i]);
	}
}

int main()
{
	std::vector<int> vec{1, 2, 3, 4};
	Permutation(vec, 0);

	/*std::sort(vec.begin(), vec.end());

	do
	{
		PrintVector(vec);
	} while (std::next_permutation(vec.begin(), vec.end()));*/

	return 0;
}