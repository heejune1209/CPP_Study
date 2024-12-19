#include <iostream>
using namespace std;
// 로또 번호 생성기

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

// { 1, 42,3,15,5,6 } => {1, 3, 5, 6, 15, 42}
void Sort(int numbers[], int count)
{
	for (int i = 0; i < count; i++)
	{
		// i번째 값이 제일 좋다고 가정
		int best = i;

		// 다른 후보와 비교를 통해 제일 좋은 후보를 찾아나선다.
		for (int j = i + 1; j < count; j++)
		{
			if (numbers[j] < numbers[best])
			{
				best = j;
			}
		}

		// 제일 좋은 후보와 교체
		if (i != best)
		{
			Swap(numbers[i], numbers[best]);
		}

	}
}
// 3) 로또 번호 생성
void ChooseLotto(int number[])
{
	srand((unsigned)time(0)); // 랜덤 시드 설정

	int count = 0;
	while (count != 6)
	{
		int randvalue = 1 + (rand() % 45); // 1~45

		// 이미 찾은 값인지?
		bool found = false;
		for (int i = 0; i < count; i++)
		{
			// 이미 찾은 값
			if (number[i] == randvalue)
			{
				found = true;
				break;
			}
		}

		// 못찾았으면 추가!
		if (found == false)
		{
			number[count] = randvalue;
			count++;
		}
	}

	Sort(number, 6);

	// Todo: 랜덤으로 1~45 사이의 숫자 6개를 골라라!
	// 정렬 기능도 같이 넣어야함.
	// 단, 중복이 없어야함
}



int main()
{
	// 1) Swap 함수 만들기
	int a = 1;
	int b = 2;
	Swap(a, b);
	// a = 2, b = 1

	cout << a << "," << b << endl;

	// 2) 정렬 함수 만들기 (작은 숫자가 먼저 오도록 정렬)
	int numbers[6] = { 1, 42,3,15,5,6 };

	int size1 = sizeof(numbers); // 6*4 =24
	int size2 = sizeof(int); // 4
	Sort(numbers, sizeof(numbers) / sizeof(int));
	// {1, 3, 5, 6, 15, 42}

	// 3) 로또 번호 생성기
	// 여기서 굳이 카운트를 이렇게 안 넣어준 이유는 애당초 로또가 한국 로또는 6개짜리니까 여기 넘겨주는 배열이 
	// 일단은 크기가 6이라고 가정을 하고 그냥 진행을 하도록 할게요
	ChooseLotto(numbers);

	for (int i = 0; i < 6; i++)
	{
		cout << numbers[i] << endl;
	}

	return 0;
}