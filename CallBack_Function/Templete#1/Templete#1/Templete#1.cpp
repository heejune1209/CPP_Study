#include <iostream> // C++ 라이브러리

using namespace std;

// 템플릿 기초

class Knight
{
public:

public:
	int _hp = 100;
};

template<typename T>
// typename도 class로 바꿔 사용할 수 있다.
void Print(T a)
{
	cout << a << endl;
}

// 템플릿 특수화
// 템플릿화 된 함수 템플릿 중, 예외를 처리할 때 사용하는 방식이다. 사용 방법은 아래와 같다.
// 템플릿 꺽쇠 안에 아무것도 입력하지 않으면 해당 함수가 입력받는 타입에 따라 유동적으로 예외 처리를 할 수 있게 된다.

template<>
void Print(Knight a)
{
	cout << "Knight !!!" << endl;
	cout << a._hp << endl;
}
// 대부분이 경우엔 void Print(T a) 이 함수 버전을 따르겠지만
// 나이트의 경우에만 void Print(Knight a) 이 버전이 호출될것이다

template<typename T>
T Add(T a, T b)
{
	return a + b;
}
// T를 조커카드처럼 생각.

// 여러개의 타입을 지정하고 싶으면 콤마(,)를 이용하여 지정해줄 수 있다.
template<typename T1, typename T2>
void Print(T1 a, T2 b)
{
	cout << a << " " << b << endl;
}


// 연산자 오버로딩(전역함수 버전)오버로딩을 해서 나이트 클래스도 이제 적용을 할 수 있게끔 한다
ostream& operator<<(ostream& os, const Knight& k)
{
	os << k._hp;
	return os;
}



int main()
{
	// 템플릿 : 함수나 클래스를 찍어내는 틀
	// 1) 함수 템플릿
	// 2) 클래스 템플릿

	// T는 템플릿의 이름이고 아무렇게나 입력할 수 있다. 위의 코드는 함수 Print를 오버로딩 하지 않고 사용할 수 있게 해준다. 
	// 지정하고자 하는 타입을 고정시켜 주고 싶은 경우 아래와 같이 사용한다.
	Print<int>(50);
	// 그래서 아무리 다른 인자를 정수가 아닌 실수로 만든다 하더라도 상관없이 무조건 int버전이 호출되게됨

	Print(50); // T = int
	Print(50.0f); // T = float
	Print(50.0); // T = double
	Print("Hello World!"); // T = const char*

	int result1 = Add(1, 2);
	float result2 = Add<float>(1.11f, 2.22f);

	Print("Hello ", 100);

	Knight k;
	Print(k);
	// 만약 템플릿 특수화가 아니었으면 void Print(T a) 이 함수가 호출되었을것이다

	return 0;
}