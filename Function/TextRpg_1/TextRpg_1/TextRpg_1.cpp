#include <iostream>
using namespace std;

// 제 7장 TEXT RPG
enum PlayerType
{
	PT_Knight = 1,
	PT_Archer = 2,
	PT_Mage = 3
};
enum MonsterType
{
	MT_Slime = 1,
	MT_Orc = 2,
	MT_Skeleton = 3
};

struct ObjectInfo
{
	int Type;
	int hp;
	int attack;
	int defence;
};
// int가 4개니까 총 16바이트의 메모리를 차지한다. 하지만 float, char 등등 여러종류가 섞일땐 
// 각 타입의 바이트를 합한것이 구조체의 총 바이트 수는 아니다.

ObjectInfo playerInfo;
ObjectInfo monsterInfo;

void EnterLobby();
void SelectPlayer();
void EnterField();
void CreateRandomMonster();
void EnterBattle();

int main()
{
	// 랜덤 시드 설정
	srand(time(0));

	EnterLobby();

	return 0;
}

void EnterLobby()
{
	while (true)
	{
		cout << "---------------" << endl;
		cout << "로비에 입장했습니다." << endl;
		cout << "---------------" << endl;

		// 플레이어 직업 선택
		SelectPlayer();

		cout << "---------------------------" << endl;
		cout << "(1) 필드 입장  (2) 게임 종료" << endl;
		cout << "---------------------------" << endl;
		int input; // 만약 while문 밖에서 선언했으면 엔터 로비 함수에서 살아있을거고, 
		// while문 안에서 선언한거면 while문 괄호 안에서만 쓸수 있다. 
		// 하지만 둘다 스택 영역에 있다는것은 변함 없음.

		cin >> input;
		if (input == 1)
		{
			EnterField();
		}
		else
		{
			return;
		}
	}



}
void SelectPlayer()
{
	while (true)
	{
		cout << "---------------" << endl;
		cout << "직업을 골라주세요!" << endl;
		cout << "(1)기사 (2)궁수 (3)법사" << endl;
		cout << ">" << endl;

		cin >> playerInfo.Type;

		if (playerInfo.Type == PT_Knight)
		{
			cout << "기사 생성중....!" << endl;
			playerInfo.hp = 150;
			playerInfo.attack = 10;
			playerInfo.defence = 5;
			break;
		}
		else if (playerInfo.Type == PT_Archer)
		{
			cout << "궁수 생성중....!" << endl;
			playerInfo.hp = 100;
			playerInfo.attack = 15;
			playerInfo.defence = 3;
			break;
		}
		else if (playerInfo.Type == PT_Mage)
		{
			cout << "법사 생성중....!" << endl;
			playerInfo.hp = 80;
			playerInfo.attack = 25;
			playerInfo.defence = 0;
			break;
		}
	}


}
void EnterField()
{
	while (true)
	{
		cout << "---------------" << endl;
		cout << "필드에 입장했습니다." << endl;
		cout << "---------------" << endl;

		cout << "[PLAYER] HP : " << playerInfo.hp << " / ATT : " << playerInfo.attack << " / DEF  : " << playerInfo.defence << endl;

		CreateRandomMonster();

		cout << "---------------" << endl;
		cout << "(1) 전투 (2) 도주" << endl;
		cout << ">" << endl;

		int input;

		cin >> input;
		if (input == 1)
		{
			EnterBattle();
			if (playerInfo.hp == 0)
				return;
		}
		else
		{
			return;
			// 이때 돌아가면 EnterLobby의 while문으로 다시 돌아간다.
		}
	}

}
void CreateRandomMonster()
{
	// 1~3
	monsterInfo.Type = 1 + (rand() % 3); // 1 2 3
	// SelectPlayer함수와는 달리 monsterType은 무조건 123중 하나의 값을 갖게 될테니까 switch문으로 사용해봄.
	// 그리고 while 문으로 돌 필요도 없음.

	switch (monsterInfo.Type)
	{
	case MT_Slime:
		cout << "슬라임 생성중....! (HP: 15 / ATT: 10 / DEF: 0)" << endl;
		monsterInfo.hp = 15;
		monsterInfo.attack = 10;
		monsterInfo.defence = 0;
		break;
	case MT_Orc:
		cout << "오크 생성중....! (HP: 40 / ATT: 10 / DEF: 3)" << endl;
		monsterInfo.hp = 40;
		monsterInfo.attack = 10;
		monsterInfo.defence = 3;
		break;
	case MT_Skeleton:
		cout << "스켈레톤 생성중....! (HP: 80 / ATT: 15 / DEF: 10)" << endl;
		monsterInfo.hp = 80;
		monsterInfo.attack = 15;
		monsterInfo.defence = 10;
		break;
	}

}
void EnterBattle()
{
	while (true)
	{
		int damage = playerInfo.attack - monsterInfo.defence;
		if (damage < 0)
			damage = 0;

		//선빵
		monsterInfo.hp -= damage;
		if (monsterInfo.hp < 0)
			monsterInfo.hp = 0;
		cout << "몬스터 남은 체력 : " << monsterInfo.hp << endl;
		if (monsterInfo.hp == 0)
		{
			cout << "몬스터를 처치했습니다! " << endl;
			return;
		}

		// 몬스터 반격
		damage = monsterInfo.attack - playerInfo.defence;
		// 같은 이름을 이렇게 동일하게 두 번을 사용할 수는 없고 얘를 데미지 2로 바꿔 준다거나 
		// int를 빼고 사용한다던지 한다.
		if (damage < 0)
			damage = 0;

		playerInfo.hp -= damage;
		if (playerInfo.hp < 0)
			playerInfo.hp = 0;
		cout << "플레이어 남은 체력 : " << playerInfo.hp << endl;
		if (playerInfo.hp == 0)
		{
			cout << "당신은 사망했습니다...... GAME OVER" << endl;
			return;
		}
	}
}
