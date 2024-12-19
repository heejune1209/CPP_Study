#pragma once
#include "Creature.h"

enum MonsterType
{
	MT_SLIME = 1,
	MT_ORC = 2,
	MT_SKELETON = 3

};

class Monster : public Creature
{
public:
	Monster(int monsterType) : Creature(CT_MONSTER), _monsterType(monsterType)
	{

	}

	virtual void printInfo();

protected:
	int _monsterType;
};

class Slime : public Monster
{
public:
	Slime() : Monster(MT_SLIME)
	{
		_hp = 50;
		_attack = 5;
		_defence = 2;
	}
};

class Orc : public Monster
{
public:
	Orc() : Monster(MT_ORC)
	{
		_hp = 80;
		_attack = 8;
		_defence = 3;
	}

};

class Skeleton : public Monster
{
public:
	Skeleton() : Monster(MT_SKELETON)
	{
		_hp = 100;
		_attack = 15;
		_defence = 4;
	}

};

// 상속관계를 어떻게 사용하고 있는지 유심히 봐야한다
// 모든 슬라임이나 오크, 스켈레톤은 몬스터이다 보니 몬스터를 상속받게끔 하는거고
// 몬스터는 크리쳐를 상속받아가지고 크리쳐 즉 
// 플레이어랑 몬스터가 공통으로 갖고 있는 그런 모든 기능들은 다 크리쳐로 밀어 넣었다는것을 알수 있다.