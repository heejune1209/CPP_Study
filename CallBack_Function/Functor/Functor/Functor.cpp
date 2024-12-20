#include <iostream> // C++ 라이브러리

using namespace std;

// 함수 객체

void HelloWorld()
{
	cout << "HelloWorld" << endl;
}

void HelloNumber(int number)
{
	cout << "Hellonumber" << number << endl;
}
class Knight
{
public:
	void Addhp(int addhp)
	{
		_hp += addhp;
	}

private:
	int _hp = 100;
};

class Functor
{
public:
	void operator()()
	{
		cout << "Functor Test" << endl;
		cout << _value << endl;
	}

	bool operator()(int num)
	{
		cout << "Functor(int) Test" << endl;
		_value += num;
		cout << _value << endl;

		return true;
	}
private:
	int _value = 0;
};

int main()
{
	// 함수 객체(Functor) :  함수처럼 동작하는 객체
	// 함수 포인터의 단점 : 
	// 1) 시그니처가 안 맞으면 사용할 수 없다
	// 2) 상태를 가질수 없다

	// 함수 포인터 선언

	void (*pfunc)(void);
	// 동작을 넘겨줄땐 유용하다
	pfunc = &HelloWorld;
	(*pfunc)();

	//pfunc = &HelloNumber; -> error

	// [함수처럼 동작]하는 객체
	// () 연산자 오버로딩
	// () 연산자 오버로딩이 필요하다. 객체 지향 클래스 문법을 이용하되 함수처럼 이용할 수 있도록 () 연산자 오버로딩을 하는 것이다.
	// 함수 객체를 사용하게 되면 함수 포인터와 다르게 생성 시점과 실행 시점을 분리할 수 있다.

	HelloWorld();

	Functor functor;
	functor(); // "Functor Test" 와 int _value = 0을 출력
	// functor.operator()(); 이 코드와 같은 코드

	bool ret = functor(3);
	//bool ret = functor.operator()(3); 이 코드와 같은 코드

	// 활용 예
	// MMORPG를 만들 때 서버 쪽에서 유용하게 활용할 수 있다.
	// 예를 들어 클라(게임화면을 그려주는 역할)가 보내준 네트워크 패킷을 받아서 서버가 처리할 때를 생각해보자.
	// 만약 현재 처리하는 일이 많아서 요청은 받았지만 처리를 기다려야 할 때, 
	// Functor를 이용해 해당 기능을 처리해야 한다고 생성만 해둔 다음 여유가 될 때 일감을 실행시키게 되는 것이다.
	return 0;

}