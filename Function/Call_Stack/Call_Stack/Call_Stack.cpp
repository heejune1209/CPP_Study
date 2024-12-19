#include <iostream>
using namespace std;

// 제 5장 : 호출 스택

// 함수 선언
void Func1();
void Func2(int a, int b); // 여기서 선언한 매개변수의 이름과, 아래에서 선언할 매개변수의 이름은 같지 않아도 된다.
// 이거는 말 그대로 함수의 시그니처, 함수의 모양만 알려주면 되기 때문에 이렇게 일단은
// 만들어 두면 된다고 볼수 있다.
void Func3(float a);
// 이렇게 함수 선언을 먼저 해줘야 된다 C++에선. (C#에선 그렇게 안해도 된다.)
// 이렇게 함수 선언을 할 줄 알아야, 이리저리 함수를 서로 호출하는 걸 편하게 만들 수 있다.
// 디버그 하면 호출 스택을 볼수 있는데, 호출 스택으로 스택 프레임에 대해 알수 있다. 
// 호출 스택을 볼줄 아는것이 상당히 중요.
// 지금 내가 어떻게 맞는지를 손쉽게 찾을 수 있는 그런 방법을 제공해 준다가 일단 오늘의 결론이 된다.

void Func1()
{
	cout << "func1" << endl;
	Func2(1, 2);

}
void Func2(int a, int b)
{
	cout << "func2" << endl;
	Func3(10);
}

void Func3(float a)
{
	cout << "func3" << endl;

}

int main()
{
	cout << "main" << endl;
	Func1();


	return 0;
}
