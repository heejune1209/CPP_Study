#pragma once
// 기본적으로 헤더 파일에서 정의만을 한다음에 구현부는 CPP파일에서 하는것이 원래는 일반적인데
// 이렇게 짧은 부분 즉, 여기에 내용이 어마어마하게 많지 않다고 하면 헤더파일에다가 이렇게 함수를 만들어도 되긴함.
#include "Creature.h" // 이렇게 creature 클래스를 상속 받고싶다면 헤더파일을 include를 해줘야한다

//  직업 클래스 생성 및 초기 세팅(수가 적어서 한 파일에 작성)

enum PlayerType
{
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3
};


class Player : public Creature
{
public:
	Player(int playerType) : Creature(CT_PLEAYER), _playerType(playerType)
	{

	}
	// 이렇게 인수가 있는 생성자를 만들어 줬으니까 기본생성자는 막히게 된다.
	// 즉, 원래 이걸 아무것도 우리가 안만들어줬으면 컴파일러가 명시적으로, 암시적으로 기본생성자를 만들어 주는데 우리가 다른 버전의 생성자를 만들어 주는 순간 기본 생성자도 막히기 때문에 
	// 사용할수 있는 기본 생성자가 없다는 에러를 뱉는다. 그래서 Creature(CT_PLEAYER) 초기화 리스트에 Creature의 기본 생성자가 아니라 인수를 받아주는 생성자를 넣어주면 문제는 해결된다 
	virtual ~Player()
	{

	}

	virtual void printInfo();



protected:
	int _playerType;
};

class Knight : public Player
{
public:
	Knight() : Player(PT_Knight)
	{
		_hp = 150;
		_attack = 10;
		_defence = 5;

	}
};

class Archer : public Player
{
public:
	Archer() : Player(PT_Archer)
	{
		_hp = 80;
		_attack = 15;
		_defence = 3;
	}
};

class Mage : public Player
{
public:
	Mage() : Player(PT_Mage)
	{
		_hp = 50;
		_attack = 25;
		_defence = 3;
	}

};

// 물론 얘네들도 이제 너무 방대해진다 싶으면 여기 안에다가 새로운 파일을 파줘가지고
// night.header, night.cpp, archer.header, archer.cpp
// 이런식으로 별도의 파일로 관리를 하는게 좋겠지만 이렇게 내용물이 많지 않을 때는 그냥 얘랑
// 연관된 하나의 파일에다가 기생해가지고 만드는 것도 괜찮습니다

// Player라고 한다면 얘가 이제 그냥 playerType만 들고 있는 게 아니라 어떻게 보면 전투를 하기 위해서 HP랑 공격력 그리고 디펜스를 다 갖고 있어야 되긴 하겠죠
// 근데 나중에 몬스터도 등장할 거를 미리 예측해 가지고 생각을 해보면 몬스터도 동일하게 HP랑 공격력 그리고 디펜스를 들고 있을 테니까 
// 플레이어랑 몬스터를 또 묶어줄 수 있는 공용 클래스를 하나를 만들어주면 좋을것 같다