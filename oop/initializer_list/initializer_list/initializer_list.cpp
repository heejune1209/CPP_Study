#include <iostream>
using namespace std;

// 초기화 리스트

// 멤버 변수 초기화? 다양한 문법이 존재

// 초기화 왜 해야할까?
// - 버그예방에 중요
// - 포인터 등 주소값이 연루 되어 있을 경우 특히 더 중요

// 초기화 방법
// - 생성자 내에서 초기화
// - 초기화 리스트
// - C++11 문법

// 초기화 리스트
// - 일단 상속관계에서 원하는 부모 생성자를 호출할때 필요하다
// - 생성자 내에서 초기화 VS 초기화 리스트
// -- 일반 변수는 별 차이 없음
// -- 멤버 타입이 클래스인 경우 차이가 난다

// -- 정의함과 동시에 초기화가 필요한 경우 (참조타입, const 타입)

class Inventory
{
public:
	Inventory() { cout << "Inventory()" << endl; }
	Inventory(int size) { cout << "Inventory(int size)" << endl;  _size = size; }

	~Inventory() { { cout << "~Inventory()" << endl; } }
public:
	int _size = 10;
};

class Player
{
public:
	Player() {}
	Player(int id) {}
};

// is-a => (Knight is-a Player? 기사는 플레이어이다) ok -> 상속 관계
// has-a => (knight has-a inventory? 기사는 인벤토리를 가지고 있다? 없다?) ok => 포함관계

class Knight : public Player
{
public:
	Knight() : Player(1), _hp(100), _inventory(20), _hpRef(_hp), _hpConst(100)
		//  = 초기화 리스트
// _inventory(20)은 포함관계로 있는 인벤토리 객체를 만들어서 생성자 초기화.
//  _hp(100), _hpRef(_hp), _hpConst(100) 이것들은 나이트 클래스 내부의 멤버 변수들
// (이렇게 초기화를 하는 두가지 방법이 있었다) 
// Player(1) 이렇게 다른 버전의 생성자를 호출하고 싶다면 이런식으로 선처리 영역이라고 명명한 이런 부분에서 
// 강제로 다른 값으로 이렇게 세팅을 할수가 있다. 초기화 리스트는 이 문법을 얘기한다
	{
		/*

		선처리 영역
				 // 생성자 안에서 만들어 준것
		_inventory = Inventory()
		// "Inventory()" 출력 (선처리 영역에서 생성자 호출)-> Inventory(int size)출력 (선처리 영역 밖에서 초기화한 것을 출력) =>
		~Inventory()(선처리 영역에서 호출한것의 소멸자)출력 ==> ~Inventory()(Inventory(20)으로 호출해던것의 소멸자 호출)

		그럼 어떻게 해야하냐?
		생성자 안에서 새로 만들어 주는것이 아니라 한방에 처리할 수 있게끔 Knight() : Player(1), _hp(100) , _inventory(20) 이렇게 만들어줘야한다
		그러면 기본적으로 인벤토리의 기본 생성자를 이용해서 만드는 부분이 없어지고 두번째 생성자를 이용해서 만들어 준다는 차이가 있다

		// 그래서 한방에 처리한 결과 Inventory(int size) , ~Inventory() 이것만 출력되는 것을 볼수 있다

		*/

		_hp = 100; // C++11이전에는 이방법으로 초기화를 하거나
		//_inventory = Inventory(20); // 두번째 생성자로 호출
		// knight라는 것을 초기화 하는 방법이 생성자 내부에서 하는 방법이 하나 있다해서 코드를 작성했더니 
		// 인벤토리의 생성자가 두번 호출이 되고 소멸자도 두번 호출되는것을 알수 있다.
		// 왜냐면 선처리 영역에서 만들어 주지않고 여기 내부에서 만들어 줬다는 것이 문제가 되는 것이다

		// 아무튼 하고싶은 말은 초기화를 할때는 일반 함수처럼 함수 내부에서 하기 보다는 Knight() : Player(1), _hp(100) , _inventory(20)
		// 이렇게 초기화 하는것이 훨씬 더 좋다

		// _hpRef = _hp;
		//_hpConst = 100; // 참조와 const는 여기서 초기화를 하면 안된다
		// 무조건 Knight() : (여기에 초기화 해줘야함)

	}
	// Knight(int a) : Player(a) 이런식으로 매개변수를 넣어줘도 된다


public:
	int _hp = 200; // 쓰레기 값
	Inventory _inventory; // knight와 인벤토리간의 포함관계로 설정
	// knight가 만들어짐과 동시에 이 인벤토리가 간접적으로 선처리 영역에서 같이 만들어지게 될것이다

	// 상속관계로 이루어 졌을때 나이트 생성자에서 명시를 하지 않았다 하더라도 플레이어의 생성자를 기본적으로 알아서 호출해주고 있었다.
	// 마찬가지로 포함관계, 즉, 나이트가 인벤토리를 들고 있는 관계에선 어찌됐건 나이트라는 것을 만들어 주기위해서는 인벤토리라는것이 딸려서
	// 같이 만들어줘야하기때문에, 이 선처리 영역에서 인벤토리의 기본 생성자가 같이 호출이 되게 됩니다
	// 그래서 실제로 빌드를 하면 인벤토리의 생성자가 호출이 된다
	// 인벤토리 클래스의 생명주기는 나이트를 따라서 소멸되고 생성된다

	int& _hpRef;
	const int _hpConst;

};

int main()
{
	Knight k;

	cout << k._hp << endl;

	if (k._hp < 0)
		cout << k._hp << endl;

	return 0;
}