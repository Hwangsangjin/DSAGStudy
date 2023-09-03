#include <iostream>
#include <algorithm>

using namespace std;

// N 값에 관계없이 1회 연산 실행: 𝑂(1)
int Middle(int Data[], int N)
{
	return Data[N / 2];
}

// for 반복문 내부 문장이 𝑛번 실행: 𝑂(𝑛)
int Summation(int Data[], int N)
{
	int Sum = 0;

	for (int i = 0; i < N; i++)
	{
		Sum += Data[i];
	}

	return Sum;
}

// for 반복문 내부 문장이 2𝑛번 실행: 𝑂(𝑛)
int Variance(int Data[], int N)
{
	int Sum = 0;

	for (int i = 0; i < N; i++)
	{
		Sum += Data[i];
	}

	double Mean = static_cast<double>(Sum) / N;
	double Var = 0.0;

	for (int i = 0; i < N; i++)
	{
		Var += (Data[i] - Mean) * (Data[i] - Mean);
	}

	return (Var / N);
}

// 최선의 경우 for 반복문 안의 비교 연산이 1회, 최악의 경우 𝑛번 실행: 𝑂(𝑛)
int Find(int Data[], int N, int Target)
{
	for (int i = 0; i < N; i++)
	{
		if (Data[i] == Target)
		{
			return i;
		}
	}
}

// 이중 for 반복문 내부 문장이 1/2𝑛(𝑛-1)번 실행: 𝑂(𝑛2)
void BubbleSort(int Data[], int N)
{
	for (int i = N - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (Data[i] > Data[j + 1])
			{
				swap(Data[j], Data[j + 1]);
			}
		}
	}
}

// 재귀 함수가 𝑛번 호출되고, 함수 내부에 단일 연산만 있음: 𝑂(𝑛)
int Sum(int N)
{
	if (N == 1)
	{
		return 1;
	}

	return N + Sum(N - 1);
}

// 재귀 함수가 매번 2번의 새로운 호출을 수행함. Func(N)이 1번 호출되면, Func(N-1)은 2번 호출되고, Func(N-2)는 4번, Func(N-3)은 8번 등등으로 호출됨: 𝑂(2𝑛)
void Func(int N)
{
	if (N == 1)
	{
		return;
	}

	Func(N - 1);
	Func(N - 1);
}

int main()
{
	return 0;
}