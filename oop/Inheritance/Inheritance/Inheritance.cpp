#include <iostream>
using namespace std;

// 상속성

// 객체 지향(object oriented programming)
// 상속성
// 은닉성
// 다형성

// class는 일종의 설계도

// 생성자는 객체가 생성될때 호출되는 함수?
// - knight를 생성하면 -> player의 생성자? or knight의 생성자?
// --> 결론: 둘다 호출된다

// 원래 상속받게 설정을 했으면 player의 모든 함수들은 다 기본적으로 얘가 똑같이 물려받아 가지고 사용을 한다고 했는데 
// 다만 예외적으로 이런 생성자와 소멸자 같은 경우에는 뭔가 물려주는 개념이 아니라고 볼 수가 있겠습니다 
// 물려주는 게 아니라 이렇게 나이트도 자기만의 생성자와 소멸자가 따로따로 생긴다는것을 기억

// 근데 빌드할때 먼저 부모님의 생성자가 호출이 되고 그 다음에 자식의 생성자가 호출이 되고 그 다음에 
// 반대로 이제 제거할 때는 나이트의 즉 자식의 소멸자가 먼저 호출이 되고 그 다음에 부모님의 소멸자가 호출이 된다는 걸 알 수가 있습니다
// 이 순서를 반드시 숙지
class player
{
public:

	player()
	{
		_hp = 0;
		_attack = 0;
		_defence = 0;

		cout << "player() 기본 생성자 호출" << endl;
	}
	player(int hp)
	{
		_hp = hp;
		_attack = 0;
		_defence = 0;

		cout << "player(int hp) 기본 생성자 호출" << endl;
	}
	~player()
	{
		cout << "player() 소멸자 호출" << endl;
	}
	void Move()
	{
		cout << "player move 호출" << endl;
	}
	void Attack()
	{
		cout << "player Attack 호출" << endl;
	}
	void Die()
	{
		cout << "player Die 호출" << endl;
	}

public:
	int _hp;
	int _attack;
	int _defence;
};
class knight : public player // player한테 상속을 받는다 라는것을 알림. knight는 player의 자식 클래스가 되고 플레이어는 부모클래스가 된다
{
public:
	// 우리가 여기 나이트라는 생성자를 호출을 할 때 생성자는 일반 함수랑은 조금 다르게 동작하다고 보는 게 맞습니다
	knight()
	{
		/*

		  // 선처리 영역 : 밑에 코드가 실행되기 전에 먼저 코드가 처리되는 영역
		  // - 여기서 Player() 생성자를 호출
		  // 자식의 생성자가 호출되기 바로 이전에 선처리 영역에서 부모의 생성자를 호출

		*/

		_stamina = 100;

		cout << "knight() 기본 생성자 호출" << endl;
	}
	// 자식 생성자에서 부모 생성자가 무조건 호출이 된다는 것을 알게되었다. 
	// 부모의 기본 생성자 대신 기타 생성자를 호출하고 싶을 땐 어떻게 해야할까?
	// 아래처럼 기타 생성자 뒤에 : 부모 기타 생성자를 추가하면 해당 생성자를 호출하라는 의미가 된다.
	knight(int stamina) :player(100) // 스테미너를 받는 (knight k(100);) 이 버전에서는 그냥 기본 생성자가 아니라 부모님의 (player(int hp)) 이 버전의 생성자를 전달해주고 싶다하면 이렇게 쓰면된다
	{
		/*

		  // 선처리 영역 : 밑에 코드가 실행되기 전에 먼저 코드가 처리되는 영역
		  // - 여기서 Player() 생성자를 호출
		  // 자식의 생성자가 호출되기 바로 이전에 선처리 영역에서 부모의 생성자를 호출

		*/

		_stamina = stamina;

		cout << "knight(int stamina) 기본 생성자 호출" << endl;
	}
	~knight()
	{
		cout << "knight() 소멸자 호출" << endl;

		/*

		  // 후처리 영역 : 나중에 코드가 처리되는 영역
		  // - 여기서 Player() 소멸자를 호출
		  // 자식의 생성자가 호출되기 바로 이전에 선처리 영역에서 부모의 생성자를 호출

		*/

	}
	// 부모 객체의 멤버 함수와 같은 이름으로 자식 객체에 구현하게 되면 해당 함수는 재정의(Overriding)되게 된다. 즉, 상속을 받는 관계에서 재정의를 할 수 있게 된다.
		// 재정의 : 부모 클래스의 유산을 거부하고 새로운 이름으로 정의
	void Move()
	{
		cout << " knight move 호출" << endl;
	}


public:
	int _stamina;
};

class Mage : public player // player한테 상속을 받는다 라는것을 알림. Mage는 player의 자식 클래스가 되고 플레이어는 부모클래스가 된다
{
public:
	int mp;
};

//struct Statinfo
//{
//	int _hp;
//	int _attack;
//	int _defence;
//};
// 이렇게 데이터 부분은 구조체로 한번에 관리할수 있는데 함수같은 기능을 담당하는 부분은 공통적으로 관리할수 없을까해서 나온게 상속이다. 
// 상속(Inheritance) -> 부모가 자식한테 물려주는것
// 그럼 얘가 물려받은 물려받은 유산은 무엇이 포함이 되느냐
// 말 그대로 player가 들고 있는 데이터들 예를 들면은 여기서는 HP ,Attack,Defense와 같은 멤버 변수들도 포함이 되고 
// 그 다음에 이런 멤버 함수들 이동하다, 공격하다, 죽는다라는 기능(함수)을 얘도 기본적으로 사용할 수 있다는 얘기가 되는 겁니다

// 내용이 비어있어도 호출하면 아무런 문제없이 Player의 모든 멤버 변수와 멤버 함수를 사용할 수 있게된다.

// 상속했을때 메모리에선 어떻게 작동되냐면 
// [  player  ] -> 12바이트
// [     knight      ] -> 스태미나가 추가되어 16바이트
// 메모리는 일단은 원래 기존에 플레이어라는 것을 만들기 위해서 얘를 일단은 먼저 만든 다음에
// 그 위에다가 다시 한번 이 나이트가 덧붙여 쓰여가지고 확장된 개념이라고 볼 수가 있는 거죠
// 메모리는 부모 객체 👉 자식 객체 순으로 할당되며 자식 객체에서 확장된 내용은 부모 객체의 뒤에 붙게 된다.

// 생성자(여러개)/소멸자(1개)

// 상속관계에서 생성자와 소멸자 생성 소멸순서
//   2) [knight]
//   1) [player]    =>   3) [player]  => 4) 소멸
int main()
{
	knight k(100); // knight(int stamina) :player(100)를 출력
	k._hp = 100;
	k._attack = 10;
	k._defence = 1;
	k._stamina = 50;

	//k.Move(); // 자식클래스에서 기능을 재정의해서 함수 호출
	//k.player::Move(); // 부모 클래스의 함수 호출

// k.Move()의 실행값은 재정의 된 Knight Move 호출이 실행된다. 부모 객체의 함수를 실행하고 싶으면 k.Player::Move()를 입력하면 되는데, 보통은 사용하지 않는다.

	//k.Attack();
	// k.Die();



	return 0;
}