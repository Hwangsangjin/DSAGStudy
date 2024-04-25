#include <iostream>
#include <algorithm>
#include <functional>
#include <string>
#include <vector>

class Person
{
public:
	std::string name;
	int age;

	bool operator<(const Person& p) const
	{
		return age < p.age;
	}

	void Print() const
	{
		std::cout << name << ", " << age << std::endl;
	}
};

bool abs_cmp(const int& a, const int& b)
{
	return std::abs(a) < std::abs(b);
}

int main()
{
	// 배열의 정렬
	int arr[5] = {4, 2, 3, 5, 1};
	std::sort(arr, arr + 5); // 오름 차순, [1, 2, 3, 4, 5]
	//std::sort(std::begin(arr), std::end(arr)); // std::begin(), std::end()
	//std::sort(std::begin(arr), std::end(arr), std::greater<>()); // 내림 차순, [5, 4, 3, 2, 1]

	for (const auto& e : arr)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	// 벡터의 정렬
	std::vector<std::string> vec = {"orange", "banana", "apple", "lemon"};
	std::sort(vec.begin(), vec.end(), std::greater<>());
	//std::sort(vec.begin(), vec.end(), std::less<>()); // ["apple", "banana", "lemon", "orange"]
	//std::sort(vec.begin(), vec.end(), std::greater<>()); // ["orange", "lemon", "banana", apple"]
	//std::sort(begin(vec), end(vec));

	for (const auto& e : vec)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	// 비교 방법 지정
	struct AbsCmp
	{
		inline bool operator()(int a, int b) const
		{
			return std::abs(a) < std::abs(b);
		}
	};

	std::vector<int> nums = {10, 2, -3, 5, 7};
	std::sort(nums.begin(), nums.end(), AbsCmp()); // [2, -3, 5, 7, 10]
	std::sort(nums.begin(), nums.end(), abs_cmp); // [2, -3, 5, 7, 10]
	std::sort(nums.begin(), nums.end(), [](int a, int b) { return std::abs(a) < std::abs(b); }); // [2, -3, 5, 7, 10]

	for (const auto& e : nums)
	{
		std::cout << e << " ";
	}
	std::cout << std::endl;

	// 비교 연산자를 오버로딩한 클래스 객체의 정렬
	std::vector<Person> people;
	people.push_back({"Amelia", 29});
	people.push_back({"Noah", 25});
	people.push_back({"Olivia", 31});
	people.push_back({"Sophia", 40});
	people.push_back({"George", 35});

	std::sort(people.begin(), people.end());

	for (const auto& person : people)
	{
		person.Print();
	}

	return 0;
}