#include "Field.h"
#include "stdlib.h"
#include "Monster.h"
#include "Player.h"
Field::Field() : _monster(nullptr)
{

}

Field::~Field()
{
	if (_monster != nullptr)
		delete _monster;
}

void Field::Update(Player* player)
{
	if (_monster == nullptr)
		createMonster();

	StartBattle(player);
}

void Field::createMonster()
{
	int randvalue = 1 + rand() % 3;

	switch (randvalue)
	{
	case MT_SLIME:
		_monster = new Slime();
		break;
	case MT_ORC:
		_monster = new Orc();
		break;
	case MT_SKELETON:
		_monster = new Skeleton();
		break;

	}
}

void Field::StartBattle(Player* player)
{
	while (true)
	{
		player->printInfo();
		_monster->printInfo();

		// �÷��̾� -> ���� ����
		_monster->OnAttacked(player);

		if (_monster->isDead())
		{
			_monster->printInfo();
			delete _monster;
			_monster = nullptr; // �޸𸮸� delete���� ������ �����͵� �������ͷ� ����������
			break;
		}

		// ���� -> �÷��̾� ����
		player->OnAttacked(_monster);

		if (player->isDead())
		{
			player->printInfo();
			break;
			// ���⼭�� ���Ϳ� �޸� �÷��̾ �� ������ �ʾҴ��ĸ�, �̰� ���� ������ �����ϴ���, �����ֱ�� ���õ� �����ε�
			// �츮�� ���� ��ü�� �� �ʵ��� Ŭ���� ���ο��� ������ �ߴ� ���ϱ� ���⼭ �̷��� ���������� ������ �ص� ������ 
			// �÷��̾� ��쿣, �� Game.CPP�̶�� �ְ� ������ �ϰ� �ִ� �ִ� ���ϱ� ���⼭ �갡 ������ �ϰ� �Ǹ� ���߿� ��ȯ�� �Ѵ����� 
			// ������ �򰥸��� �ȴ�
			// ���� ���÷��̾ �����ϴ����� ������ ��Ȯ���� �ʰ� �Ǵ� ���ϱ�
			// �׷������� �� �ʵ忡���� �� �÷��̾ ������ �����ʰ� �׳� ���� ���·� �׳� ���� �����ٰ� ���� �ȴ�


		}
	}

}