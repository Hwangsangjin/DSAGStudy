#include <iostream>

using namespace std;

int main()
{
	// 동적 배열 할당 및 초기화
	int* Ptr = new int[3] {};
	Ptr[0] = 10;
	Ptr[1] = 20;

	// 포인터를 배열처럼 사용
	for (int i = 0; i < 3; i++)
	{
		std::cout << Ptr[i] << std::endl;
	}

	// 동적 배열 해제
	delete[] Ptr;
	Ptr = nullptr;

	return 0;
}