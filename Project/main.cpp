#include <iostream>

using namespace std;

template <typename T>
class DynamicArray
{
public:
	DynamicArray(int N)
		: Size(N)
	{
		Ptr = new T[Size] {};
	};

	~DynamicArray()
	{
		delete[] Ptr;
		Ptr = nullptr;
	}

	unsigned int size() { return Size; }
	T& operator[] (const int i) { return Ptr[i]; }
	const T& operator[] (const int i) const { return Ptr[i]; }

private:
	unsigned int Size;
	int* Ptr;
};

int main()
{
	DynamicArray<int> DA(5);
	DA[0] = 10;
	DA[1] = 20;
	DA[2] = 30;

	for (int i = 0; i < DA.size(); i++)
	{
		cout << DA[i] << " ";
	}
	cout << endl;

	return 0;
}