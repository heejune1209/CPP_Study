#pragma once
// �⺻������ ��� ���Ͽ��� ���Ǹ��� �Ѵ����� �����δ� CPP���Ͽ��� �ϴ°��� ������ �Ϲ����ε�
// �̷��� ª�� �κ� ��, ���⿡ ������ ���ϰ� ���� �ʴٰ� �ϸ� ������Ͽ��ٰ� �̷��� �Լ��� ���� �Ǳ���.
#include "Creature.h" // �̷��� creature Ŭ������ ��� �ް�ʹٸ� ��������� include�� ������Ѵ�

//  ���� Ŭ���� ���� �� �ʱ� ����(���� ��� �� ���Ͽ� �ۼ�)

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
	// �̷��� �μ��� �ִ� �����ڸ� ����� �����ϱ� �⺻�����ڴ� ������ �ȴ�.
	// ��, ���� �̰� �ƹ��͵� �츮�� �ȸ���������� �����Ϸ��� ���������, �Ͻ������� �⺻�����ڸ� ����� �ִµ� �츮�� �ٸ� ������ �����ڸ� ����� �ִ� ���� �⺻ �����ڵ� ������ ������ 
	// ����Ҽ� �ִ� �⺻ �����ڰ� ���ٴ� ������ ��´�. �׷��� Creature(CT_PLEAYER) �ʱ�ȭ ����Ʈ�� Creature�� �⺻ �����ڰ� �ƴ϶� �μ��� �޾��ִ� �����ڸ� �־��ָ� ������ �ذ�ȴ� 
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

// ���� ��׵鵵 ���� �ʹ� ��������� ������ ���� �ȿ��ٰ� ���ο� ������ ���డ����
// night.header, night.cpp, archer.header, archer.cpp
// �̷������� ������ ���Ϸ� ������ �ϴ°� �������� �̷��� ���빰�� ���� ���� ���� �׳� ���
// ������ �ϳ��� ���Ͽ��ٰ� ����ذ����� ����� �͵� �������ϴ�

// Player��� �Ѵٸ� �갡 ���� �׳� playerType�� ��� �ִ� �� �ƴ϶� ��� ���� ������ �ϱ� ���ؼ� HP�� ���ݷ� �׸��� ���潺�� �� ���� �־�� �Ǳ� �ϰ���
// �ٵ� ���߿� ���͵� ������ �Ÿ� �̸� ������ ������ ������ �غ��� ���͵� �����ϰ� HP�� ���ݷ� �׸��� ���潺�� ��� ���� �״ϱ� 
// �÷��̾�� ���͸� �� ������ �� �ִ� ���� Ŭ������ �ϳ��� ������ָ� ������ ����