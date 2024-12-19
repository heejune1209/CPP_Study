#include <iostream>
using namespace std;

// 객체 지향의 시작

// 절차 지향 프로그래밍 - 지금까지 했던것들
// 객체 지향 프로그래밍(OOP)

// 데이터 + 가공(로직, 동작)

// 객체지향 = 객체
// 객체란? 플레이어, 몬스터, GameRoom

// knight를 설계해보자
// - 속성(데이터) : hp, attack, y, x 
// - 기능(동작): Move, Attack, Die

// knight가 갖고 있는 모든 속성들과 기능들을 이렇게 쭉 나열을 해본 다음에 그거에 대한 일단 설계도를 그려줘야함
// class는 struct랑 종이한장 차이

// class는 일종의 설계도
class Knight
{
public:

	// 멤버 함수 선언
	void Move(int y, int x);
	void Attack();
	void Die() // 클래스 내부에 구현할때
	{
		hp = 0;
		cout << "Die" << endl;
	}
	// 선언을 먼저 하고 그 다음에 정의하는 부분을 이렇게 따로 빼놔도 되고 
	// 경우에 따라서는 얘는 그냥 선언과 정의를 그냥 동시에 이렇게 정의 부분을 여기 안에다가 넣어도 되기는 합니다

	// 데이터와 동작이 같이 있는것이 가장 큰차이라고 볼수 있다.
	// 그 다음에 이 멤버 함수 내부에서 이 같은 클래스 내부에 있는 함수는 굉장히 특이하게도 이 멤버 변수에 접근을 할 수가 있다는 특징이 있다
public:
	// 멤버 변수
	int hp;
	int attack;
	int posx;
	int posy;

};
// 멤버함수를 클래스 외부에 구현
void Knight::Move(int y, int x)
{
	posy = y;
	posx = x;
	cout << "Move" << endl;
}

void Knight::Attack()
{
	cout << "Attack : " << attack << endl;
}

void Move(Knight* knight, int y, int x)
{
	knight->posy = y;
	knight->posx = x;
}
// Instantiate 객체를 만든다!


int main()
{
	Knight k1;
	k1.hp = 100;
	k1.attack = 10;
	k1.posx = 0;
	k1.posy = 0;

	// k1의 주소로 가서 한번 분석한 결과 놀랍게도 지금 이렇게 데이터가 4개짜리로 되어 있는 걸 볼 수가 있습니다
	// 4바이트 4바이트 4바이트 4바이트 총 16바이트라는 걸 볼 수가 있는 거고 그래서 
	// 실질적으로 우리가 사이즈 오브 k1을 여기 조사식 아래쪽에다가 조사식에서 이렇게 엔터를 하면 16이 뜨는것을 알수 있다.
	// 그러니까 비록 우리가 설계도 상으로는 이렇게 멤버 변수와 멤버 함수를 같이 옹기종기 모아가지고 설계도를 만들어 놨지만은 
	// 실질적으로 데이터 자체는 이 아래 있는 이 멤버 변수들만 데이터에 잡혀 있는 걸 볼 수가 있죠
	// 그리고 여기 있는 함수들은 일단은 데이터에는 이 메모리에는 따로 잡혀 있지 않다는 걸 알수 있다.

	Knight k2;
	k2.hp = 80;
	k2.attack = 5;
	k2.posx = 1;
	k2.posy = 1;

	Move(&k1, 2, 2);

	k1.Move(2, 2);
	k1.Attack();
	k1.Die();
	return 0;
}
