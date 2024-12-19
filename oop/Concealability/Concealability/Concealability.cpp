#include <iostream>
using namespace std;
// 상속성

// 객체 지향(object oriented programming)
// 상속성
// 은닉성
// 다형성

// 은닉성(Data hiding) = 캡슐화(Encapsulation)
// 몰라도 되는 것은 깔끔하게 숨기겠다!
// 숨기는 이유
// - 1) 정말 위험하고 건드리면 안되는 경우
// - 2) 다른 경로로 접근하길 원하는 경우

// 자동차
// - 핸들
// - 페달 
// - 엔진
// - 문 
// - 각종 전기선

// 일반 구매자 입장에서 사용하는 것?
// - 핸들 / 페달 / 문
// 몰라도 됨 (오히려 건드리면 큰일남)
// - 엔진 , 각종 전기선

// // 클래스 내부에서 사용하는 (멤버) 접근 지정자
// public(공개적) protected(보호받는) private(개인의)

// public: 누구한테나 공개. 실컷 사용 가능
// protected: 자식 클래스한테만 허락(호출 가능)
// protected를 쓰면 자식클래스가 아니면 외부에서 호출하려하면 바로 에러가 난다 
// private: : class Car 내부에서만 사용할수 있다 -> 나만 사용
// 즉, private를 쓴곳은 클래스 외부에서 호출하려하면 바로 에러가 난다

// C++에서는 그냥 여기 한 번 이렇게 public OO으로 붙여주면 여기까지 다음에 따로 덮어쓰기 전까지 
// 이 영역은 그냥 쭉 public으로 된다고 보시면 되겠습니다

//그리고 private으로 선언된 멤버 변수(int* data;)는 클래스 내부에서만 접근할 수 있습니다.하지만 클래스 내부에 포함되는 범위에는 해당 클래스의 모든 멤버 함수도 포함됩니다.
//즉, 클래스 밖에서 구현된 멤버 함수라도 여전히 해당 클래스의 멤버 함수로 간주되기 때문에, private 멤버 변수에 접근할 수 있습니다.
//
//왜 클래스 밖에서 구현된 멤버 함수가 private 멤버에 접근할 수 있는가 ?
//멤버 함수는 클래스의 일부로 취급됩니다.
//private 제한은 클래스 외부에서 멤버 변수에 직접 접근하는 것을 막기 위한 것입니다.
//멤버 함수가 클래스 내부든 외부에서 구현되었든, 동일한 접근 권한을 갖습니다.



class Car
{
public: // (멤버) 접근 지정자
	void MoveHandle()
	{

	}
	void PushPedal()
	{

	}
	void OpenDoor()
	{

	}
	void Turnkey()
	{
		// 
		RunEngine();
	}

protected:
	void DisassembleCar() // 차를 분해한다
	{

	}
	void RunEngine() // 엔진을 구동시킨다
	{

	}
	void ConnectCircuit() // 전기선 연결
	{

	}


public:
	// 핸들
	// 페달
	// 엔진
	// 문
	// 각종 전기선
};

// 상속 접근 지정자 : 다음 세대한테 부모님의 유산을 어떻게 물려줄지?
// 부모님한테 물려받은 유산을 꼭 나의 자손들 한테도 똑같이 물려줘야하진 않음
// public: 공개적 상속? => 그냥 부모 클래스의 유산을 그냥 설계 그대로 물려준다 (public -> public, protected -> protected )
// protected : 보호받는 상속? 내 자손들한테만 물려준다.(public -> protected, protected-> protected)
// 부모 클래스에선 모두와 함께쓰라고 쿨하게 public으로 물려줬는데 나까지만 걔를 잘쓰고 그다음 자식이 물려받을땐 이제 protected로 바뀌는 개념
// private : 개인적인 상속? : 나까지만 잘쓰고 자식한테는 안물려준다 (public -> private, protected -> private)

// 거의 상속 접근 지정자에선 public만 거의 사용하게 될것임
// 그리고 상속 접근 지정자를 선언을 안하면 private로 인식됨.

class SuperCar : private Car // 상속 접근 지정자
{
public:
	// 나 까지만 사용하고 막아버릴 것임.
	void PushRemoteController()
	{
		RunEngine();
	}
};

class TestSuperCar : public SuperCar
{
public:
	void Test()
	{
		// class Car의 멤버 함수
		//DisassembleCar(); // 상속 접근 지정자가 private 라서 바로 에러
	}

	void PushRemoteController()
	{
		// 사용 불가능
		//RunEngine();
	}
	// SuperCar에서는 class car에서 상속받은 RunEngine을 사용할 수 있지만 결국 나 까지만 사용하게 되고, 나를 상속받은 나의 자식 클래스, 즉 자손 클래스에서는 public으로 나를 상속받았다해도 RunEngine을 사용할 수 없다.
};

// '캡슐화'
// 연관된 데이터와 함수를 논리적으로 묶어놓은것.

class Berserker
{
public:
	// 다른 경로로 접근하길 원하는 경우
	int GetHp() { return _hp; } // 외부에서 버서커를 볼때 Hp가 궁금해서 HP값을 얻고 싶으면 사용하는 함수


	void SetHp(int hp) // 세팅할떄 사용하는 함수
	{
		_hp = hp;
		if (_hp <= 50)
			SetBerserkerMode();
	}

	// 사양 : 체력이 50이하로 떨어지면 버서커 모드 발동(강해짐)
private:
	void SetBerserkerMode()
	{
		cout << "매우 강해짐" << endl;
	}

private:
	int _hp = 100;

};
//_hp 와 버서커 모드를 private으로 숨긴다. 그런 다음 _hp의 값이 변경될 때마다 체크해주는 부분을 추가하여 묶어주었다. 이렇게 되면 외부에선 _hp의 값을 가져오거나 설정까지만 하게되고 나머지 부분은 내부에서 자동으로 해주기 때문에 오류가 날 가능성이 적어지게된다. 조금 더 안정화된 작업이라 볼 수 있다.

// 이렇게 우리가 노출시키고 싶은 함수만 외부에 노출시키고 안에는 뭔가 빙하처럼 안에 숨겨놓는 개념을 이제 캡슐화라고 한다.
// 진짜 연관된 데이터와 함수가 이제 논리적으로 딱 묶여있는 상태가 된다.
// 이런것이 은닉성의 개념이라고 볼수 있다.

// 외부에서 호출을 하면 안 되는 함수들을 신나게 만들어 두게 되다 보면 이런 상황과 마찬가지로 로직이 굉장히 꼬이는 현상이 많이 일어나게 될 거예요
// 그래서 최대한 같이 동작해야 되는 로직은 이렇게 하나로 묶어 줘 가지고(GET,SET함수) 
// 하나의 함수로 이렇게 인터페이스를 만들어서 얘만 이렇게 외부에서 사용할 수 있게끔 만들어주는 게 굉장히 중요하다.




int main()
{
	Berserker b;

	b.SetHp(20);

	Car car;


	return 0;
}