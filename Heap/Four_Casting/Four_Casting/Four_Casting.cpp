#include <iostream>
using namespace std;

// 캐스팅 (타입 변환)

// 1) Static_cast
// 2) dynamic_cast
// 3) const_cast
// 4) reinterpret_cast

// 캐스팅과 관련된 이 네가지는 그냥 면접에서 맨날 나오는 그런 질문들이다

class Player
{
public:
	virtual ~Player()
	{

	}
};

class knight : public Player
{
public:
};

class Archer : public Player
{
public:
};

class Dog
{

};

void PrintName(char* str)
{
	cout << str << endl;
}


int main()
{
	// static_cast : 타입 원칙에 비춰볼 때 상식적인 캐스팅만 허용해준다.
	// 1) int <-> float
	// 2) player* <-> knight* (다운캐스팅)

	// 1) int <-> float
	int hp = 100;
	int maxHp = 200;
	float ratio = static_cast<float>(hp) / maxHp; // (float)hp 대신 static_cast<float>(hp) 이렇게 쓴다

	// 부모-> 자식
	// 반드시 이 상황에선 캐스팅 문법이 필요
	// 단, 안전성은 보장 못한다.
	Player* p = new knight();
	knight* k1 = static_cast<knight*>(p); // (knight*)p 이렇게 쓰는것 대신  static_cast<knight*>(p) 으로 대체

	// 자식 -> 부모
	knight* k = new knight();
	Player* p2 = k; // static_cast<Player*>(k);로 대체 가능

	//Player* p = new Archer();
	//knight* k1 = static_cast<knight*>(p);
	// 이 코드는 아처랑 나이트라는 애가 설계도가 달라가지고 서로 크기가 달랐다고 하면 엉뚱한 메모리를 고치는 그럼 작업을 해주는 셈이 된다
	// 그래서 굉장히 위험한 코드

	// 그래서 결국엔 static_cast를 활용을 할때는 어떤 형식으로든 우리가 지금 p라는 애가 정말 나이트라는것을 알수 있을때 그때 다운 캐스팅을 하는경우
	// 에 대해서만 활용을 해야한다
	// static_cast라는 문법 자체는 int랑 float사이의 캐스팅이라거나 상속관계에 있을때 부모에서 자식 혹은 자식에서 부모같이 이런 상속관계의 캐스팅
	// 경우에 활용

	// dynamic_cast: 상속관계에서의 안전한 형변환을 지원
	// RTT : (Runtime Type Information)
	// 다형성을 활용하는 방식
	// virtual 함수를 하나라도 만들면, 객체의 메모리에 가상 함수 테이블(vftable) 주소가 기입된다. 
	// 만약 잘못된 타입으로 캐스팅을 했으면 nullptr을 반환한다. 이를 이용하면 맞는 타입으로 캐스팅을 했는지 확인할 때 유용하다.
	// dynamic_cast를 활용하고 싶으면 반드시 virtual 함수가 하나라도 등장을 해야된다
	knight* k2 = dynamic_cast<knight*>(p);

	// 안전하다해서 무조건 좋은것은 아니다
	// dynamic_cast는 RTT를 활용해서 원본을 체크하는 부분이 추가되니까 static_cast보다는 조금 더 느리게 동작을 할수밖에 없다

	// const_cast : const를 붙이거나 떼거나~
	PrintName(const_cast<char*>("DanDi")); // "DanDi"는 const char*이니까 const를 떼줘서 넘겨줘야지만 통과가 된다

	// reinterpret_cast
	// re-interpret은 다시-간주하다, 다시-생각하다라는 의미이며, 가장 위험하고 강력한 형태의 캐스팅이다. 
	// 포인터랑 전혀 관계없는 다른 타입 변환이나 ,상관 없는 클래스 간의 타입 변환을 허용한다.
	__int64 address = reinterpret_cast<__int64>(k2);

	Dog* dog1 = reinterpret_cast<Dog*>(k2);

	void* p = malloc(1000);
	Dog* dog2 = reinterpret_cast<Dog*>(p);

	// 이번 시간에는 C++ 스타일의 4가지의 캐스팅 문법에 대해 알아보았다. 
	// C 스타일의 문법(괄호 사용)은 방대하게 사용할 수 있지만 그만큼 실수 발생률도 높아진다. 
	// 즉, 옛날에 사용하던 c스타일의 타입 변화는 잊으라는 얘기.
	// 이러한 실수를 조금이라도 방지하기 위해 C++ 스타일의 캐스팅 문법을 사용하면 좋을 것 같다.


	return 0;
}