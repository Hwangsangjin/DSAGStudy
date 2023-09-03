#include <iostream>

using namespace std;

int main()
{
	int Scores[5] = { 50, 60, 70, 80, 90 };
	int Size = sizeof(Scores) / sizeof(Scores[0]);
	int Sum = 0;

	for (int i = 0; i < Size; i++)
	{
		Sum += Scores[i];
	}

	float Mean = (float)Sum / Size;
	cout << "Mean score: " << Mean << endl;

	return 0;
}