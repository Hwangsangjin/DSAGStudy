#include <iostream>

using namespace std;

class DynamicArray
{
public:
	DynamicArray(int N)
		: Size(N)
	{
		Ptr = new int[Size] {};
	};

	~DynamicArray()
	{
		delete[] Ptr;
		Ptr = nullptr;
	}

	unsigned int size() { return Size; }
	int& operator[] (const int i) { return Ptr[i]; }
	const int& operator[] (const int i) const { return Ptr[i]; }

private:
	unsigned int Size;
	int* Ptr;
};

int main()
{
	DynamicArray DA(5);
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