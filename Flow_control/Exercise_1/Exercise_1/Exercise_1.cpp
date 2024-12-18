#include <iostream>
using namespace std;

// 연습문제 1

int main()
{
	//int input;
	//cin >> input; // cin : cout과 반대로 입력을 받고 싶을때 사용한다.
	//cout << "hello world" << endl; // 이 부분에서 cout은 콘솔 아웃이라고 해서 어떤 숫자를 출력할수 있고, 
						   // 문자열도 출력할수 있다. << 이거는 화살표느낌
	// 그리고 여기서 cout을 할 때 한 줄을 띄고 싶으면은 여기다가 \n을 해도 되는데, 위에처럼 endl을 붙이면 
	// 한줄 아래로 내리는 기능을 한다.
	// cout << endl; 이렇게 나눠서 써도 되지만, 평소엔 저렇게 한줄로 한번에 쓴다.

	// 연습문제 : 별찍기
	// 유저들이 어떤 정수를 입력하면
	// n*n개의 별을 찍었으면 좋겠다.

	/*int input;
	cin >> input;
	for (int i = 0; i< input; i++)
	{
		for (int j = 0; j < input; j++)
		{
			cout << "*";
		}
		cout << endl;
	}*/

	// 별찍기 2탄
	// 1개부터 시작해서 순차적으로 줄마다 증가하게 수정해주세요
	// 내버전
	/*
	int input;
	cin >> input;
	int w = 1;
	for (int i = 0; i< input; i++) // 한줄 넘김
	{
		for (int j = 0; j < input; j++) // 별찍기
		{
			if (w == j)
			{
				w++;
				break;
			}
			cout << "*";
		}
		cout << endl;
	}
	*/
	/*
	// 강사 버전
	int input;
	cin >> input;
	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	*/

	// 별찍기 3탄
	// n개부터 시작해서 줄마다 1개씩 줄어드는 형태로!
	/*
	int input;
	cin >> input;
	for (int i = 0; i < input; i++)
	{
		for (int j = 0; j < (input - i); j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	*/
	// 의외로 코딩 시험에서도 그냥 아주 간단한 문제로 가끔 출제가 되기도 하니까 재미삼아서 
	// 몇개를 연습해보면 좋을거같다.

	// 구구단
	// 2단부터 9단까지 구구단 출력
	/*
	int res;
	for (int i = 2; i < 10; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			res = i * j;
			cout << i << "x"<< j << "=" << res << endl;
		}

	}
	*/
}