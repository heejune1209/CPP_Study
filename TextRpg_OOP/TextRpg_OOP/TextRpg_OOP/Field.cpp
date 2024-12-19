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

		// 플레이어 -> 몬스터 공격
		_monster->OnAttacked(player);

		if (_monster->isDead())
		{
			_monster->printInfo();
			delete _monster;
			_monster = nullptr; // 메모리를 delete한후 무조건 포인터도 널포인터로 만들어줘야함
			break;
		}

		// 몬스터 -> 플레이어 공격
		player->OnAttacked(_monster);

		if (player->isDead())
		{
			player->printInfo();
			break;
			// 여기서는 몬스터와 달리 플레이어를 왜 지우지 않았느냐면, 이건 누가 누구를 관리하는지, 생명주기와 관련된 문제인데
			// 우리가 몬스터 자체는 이 필드라는 클래스 내부에서 관리를 했다 보니까 여기서 이렇게 직접적으로 삭제를 해도 됐지만 
			// 플레이어 경우엔, 이 Game.CPP이라는 애가 관리를 하고 있는 애다 보니까 여기서 얘가 삭제를 하게 되면 나중에 반환을 한다음에 
			// 굉장히 헷갈리게 된다
			// 누가 이플레이어를 관리하는지가 굉장히 명확하지 않게 되다 보니까
			// 그래가지고 이 필드에서는 이 플레이어를 삭제는 하지않고 그냥 죽은 상태로 그냥 돌려 보낸다고 보면 된다


		}
	}

}