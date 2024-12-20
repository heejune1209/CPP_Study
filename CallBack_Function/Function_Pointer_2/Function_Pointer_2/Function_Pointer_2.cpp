#include <iostream> // C++ 라이브러리

using namespace std;

// 함수 포인터

// typedef의 진실
// typedef 왼쪽값, 오른쪽값 -> 오른쪽값은 (캐스팅 타입 정의)
// 정확히는 왼쪽/오른쪽 기준이 아니라,
// [선언 문법] 에서 typedef을 앞에다 붙이는 쪽
class Knight
{
public:
	// 정적 함수
	static void HelloKnight()
	{
		cout << "HelloKnight()" << endl;
	}

	// 멤버 함수
	int GetHp(int, int)
	{
		cout << "GetHp()" << endl;
		return _hp;
	}
public:
	int _hp = 100;
};

typedef int integer;
typedef int* pointer;
//typedef int FUNC(int, int); // 얘는 func라는 이름의 함수가 등장한다는 의미가 아니라 이제부터 func라는 타입 자체가 어떤 함수 타입을 의미할건데 
// 그 함수 타입이 인자는 아무것도 안받고 출력는 int를 반환하는 함수 타입을 이제 func라고 부르겠다라고 선언을 한셈이다
typedef int ARRAY[20];

typedef int (*PFUNC)(int, int); // 웬만하면 이렇게 한번에 표현하는 버전을 기억 , 함수 포인터

typedef int (Knight::* PMEMFUNC)(int, int); // 멤버 함수 포인터
// 나이트 클래스의 멤버 함수로 사용한다고 했으니 다른 클래스로 위 코드를 이용하지 못한다
int Test(int a, int b)
{
	cout << "Test" << endl;
	return a + b;
}

int t(int a, int b)
{
	cout << "T" << endl;
	return a + b;
}



int main()
{
	// 함수 포인터
	// 1) 포인터        *
	// 2) 변수의 이름   fn
	// 3) 타입         함수(인자로 int 2개를 받고, int 1개를 반환)

	//int (*fn)(int, int); // 이렇게 한번에 사용하는 경우가 더 많으니까 익숙해지기

	PFUNC fn;
	// 위에서 *PFUNC 이렇게 typedef했었다
	// 이 함수 타입 자체는 일반적인 그런 int라거나 아니면 클래스 타입과는 다르게 뭔가 메모리에 올라가는 개념이 아니라고 설명하고 있다.
	// 그래서 FUNC t; 이 코드는 저런 함수라는 게 존재 하는데 함수를 타고가면 그 구현부가 있을것이다 라는거를 선언하는거에 불과하다


	//typedef int(FUNC_TYPE)(int, int);

	fn = Test;
	// 일반 함수 포인터는 &를 생략할 수 있다.(배열처럼 함수이름이 함수의 시작 주소).
	fn(1, 2);
	(*fn)(1, 2); // 둘다 똑같은 기능

	// 위 함수 포인터 선언 문법으로 [전역 함수 / 정적 함수]만 담을수 있다 (호출 규약이 동일한 애들)
	//fn = &Knight::GetHp; // error
	Test(1, 2);

	Knight k1;
	k1.GetHp(1, 1);

	PMEMFUNC mfn;
	mfn = &Knight::GetHp;
	// 일반 함수 포인터는& 를 생략할 수 있지만 멤버 함수 포인터의 경우, & 를 반드시 붙여줘야한다.고로 웬만하면 모두& 를 붙이는 게 좋다.

	(k1.*mfn)(1, 1);
	// 혹여나 함수 포인터와 같은 이름의 멤버 변수나 멤버 함수가 존재할 수 있기 때문에 
	// 그러한 중복 문제를 방지하기 위해 멤버 함수 포인터의 앞엔 접근 연산자 *을 붙인다.

	Knight* k2 = new Knight();
	// 같은 의미
	((*k2).*mfn)(1, 1);
	(k2->*mfn)(1, 1);
	delete k2;

	return 0;
}