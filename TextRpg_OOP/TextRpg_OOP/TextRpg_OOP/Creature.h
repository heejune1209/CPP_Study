#pragma once
// 플레이어와 몬스터의 정보 출력, 데미지 계산, 생사 여부 확인

enum CreatureType
{
	CT_PLEAYER = 0,
	CT_MONSTER = 1
};

class Creature
{
public:
	Creature(int creatureType) : _creatureType(creatureType), _hp(0), _attack(0), _defence(0) // 초기화 리스트
	{

	}
	virtual ~Creature()
	{

	}

	virtual void printInfo() = 0; // 추상 클래스(순수 가상함수 선언)

	void OnAttacked(Creature* attacker);
	bool isDead() { return _hp <= 0; }

protected:
	int _creatureType;
	int _hp;
	int _attack;
	int _defence;

	// 그래가지고 외부에서 만약에 이런 아이들을 참조할 일이 생긴다고 하면은 별도의 get 함수
	// 혹은 set 방식의 함수를 만들어 가지고 개를 이용해 가지고 간접적으로 이렇게 참조를 하는 식으로 만들어보겠다
};