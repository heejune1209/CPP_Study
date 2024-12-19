#include <iostream>
using namespace std;

// 제 4장 : 참조

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};

// [매개변수][RET][지역변수(info)][매개변수(&info)][RET][지역변수]
void CreateMonster(StatInfo* info)
{
	info->hp = 100;
	info->attack = 8;
	info->defence = 5;
}

// [매개변수][RET][지역변수(info)][매개변수(info(100,8,5))][RET][지역변수] --> StatInfo라는 구조체를 통째로 복사해서 매개변수에 전달
void CreateMonster(StatInfo info)
{
	info.hp = 100;
	info.attack = 8;
	info.defence = 5;
}
// 일단은 별표가 붙지 않았으면 얘를 무조건 값방식. 그러니까 뭔가 복사가 일어난다고 알면된다.

// 위의 방식을 사용할땐 우리가 원본 데이터를 건드리고 싶었기 때문에 이렇게 포인터를 이용해서 접근을 해야지 맞는 상황이 되는 건데
// 경우에 따라서는 얘를 수정하는 게 아니라 그냥 값만 읽어보고 싶은 상황도 발생할 수 있겠죠(아래 방식)

// 값을 수정하지 않는다면, 양쪽 다 일단 문제 없음

// 1) 값 전달 방식

void PrintinfoByCopy(StatInfo info)
{
	cout << "---------------------" << endl;
	cout << "HP : " << info.hp << endl;
	cout << "ATT : " << info.attack << endl;
	cout << "DEF : " << info.defence << endl;
	cout << "---------------------" << endl;
}
// 이 값을 그냥 간단하게 읽어가지고만 사용한다고 하면은 이 방식도 사실 뭐 안 된다는 얘기는 아니다. 

// 2) 주소 전달 방식

// StatInfo 구조체가 1000바이트짜리 대형 구조체라면?
// - (값 전달) StatInfo로 넘기면 1000바이트가 복사되는 상태가 발생. (1000바이트라 부담이 큼)
// - (주소 전달) StatInfo에 포인터를 넘겨준거니까 주소값이니까 4바이트 or 8바이트가 된다. (크기 고정)(4바이트 or 8바이트라서 부담이 없음)
// 매우 중요
// - (참조 전달) StatInfo&는 일단 주소를 넘기는 것이기에 4바이트 or 8바이트가 된다.

// 3) 참조 전달 방식
// 값 전달처럼 편리하게 사용하고!
// 주소 전달처럼 주소값을 이용해 진퉁을 건드리는!
// 일석이조의 방식!
// (내 스타일)

void PrintinfoByRef(StatInfo& info)
{
	cout << "---------------------" << endl;
	cout << "HP : " << info.hp << endl;
	cout << "ATT : " << info.attack << endl;
	cout << "DEF : " << info.defence << endl;
	cout << "---------------------" << endl;
}


void PrintinfoByPtr(StatInfo* info)
{
	cout << "---------------------" << endl;
	cout << "HP : " << info->hp << endl;
	cout << "ATT : " << info->attack << endl;
	cout << "DEF : " << info->defence << endl;
	cout << "---------------------" << endl;
}


int main()
{
	// 4바이트 정수형 바구니를 사용할거야
	// 앞으로 그 바구니 이름을 number라고 할게
	// 그러니까 number에서 뭘 꺼내거나, number에 뭘 넣는다고 하면,
	// 찰떡 같이 알아 듣고 해당 주소(data, stack, heap)에 1을 넣어주면 된다!

	int number = 1;

	// * :주소를 담는 바구니
	// int : 그 바구니를 따라가면 int 데이터(바구니)가 있음
	int* pointer = &number;
	// pointer 바구니에 있는 주소를 타고 이동해서, 그 멀리 있는 바구니에 2를 넣는다
	*pointer = 2;

	// 로우레벨(어셈블리) 관점에서 실제 작동 방식은 int*와 똑같음

	int& reference = number;

	// C++ 관점에서는 number라는 바구니에 또 다른 이름을 부여한 것.
	// number라는 바구니에 reference라는 다른 이름을 지어줄게~
	// 앞으로 reference 바구니에다가 뭘 꺼내거나 넣으면
	// 실제 number 바구니(진퉁에다가) 그 값을 꺼내거나 넣으면 됨!
	// 말 그대로 다시 요약하면 포인터 기능이랑 똑같은 기능을 하지만 문법적으로만 이렇게 좀 다른 느낌으로 바뀐 상태라고 보면 된다.

	// 즉, 포인터랑 완전 똑같이 동작을 하지만, 사용하는 인터페이스 자체가 포인터랑 다르게 그냥 일반적인 복사랑 비슷하게 한다고 결론.
	reference = 3;
	// 해당 코드는 number라는 변수에 reference라는 또 다른 이름을 지어준 것이다. number 변수를 참조한다는 뜻이다.


// 그런데 귀찮게 또 다른 이름을 짓는 이유는?
// 그냥 number = 3 이라고 해도 똑같은데..
// 참조 전달 때문!

	//값에 접근할 때는 포인터처럼, 값을 가져올 때는 복사 방식처럼 편하게 가져오기 위한, 각 방식의 장점만 합쳐 만든 중간 단계라고 볼 수 있다.

	StatInfo info;
	CreateMonster(&info);

	PrintinfoByCopy(info);
	PrintinfoByPtr(&info);
	PrintinfoByRef(info);

	return 0;
}
