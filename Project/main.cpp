#include <iostream>
#include <array>

using namespace std;

int main()
{
	array<int, 5> Scores{ 50, 60, 70, 80, 90 };
	int Sum = 0;

	for (int i = 0; i < Scores.size(); i++)
	{
		Sum += Scores[i];
	}

	float Mean = static_cast<float>(Sum) / Scores.size();
	cout << "Mean score: " << Mean << endl;

	return 0;
}