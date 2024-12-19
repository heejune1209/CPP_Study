#include <iostream>
using namespace std;


/// TEXT RPG#3

// 전역 메모리를 활용 안하고 스택 메모리에만 플레이어랑 몬스터를 만들어서 작업
// 나중에 게임을 만들게 되면 힙 메모리에다가 나중에 몬스터랑 플레이어를 올리게 되겠지만 그건 나중에 배울내용

// main
// - EnterLobby (PlayerInfo)
// -- CreatePlayer
// -- EnterGame (monsterinfo)
// --- CreateMonsters
// --- Enterbattle

//  결국에는 이 엔터게임 내부에서만 이 몬스터 인포가 유효하다고 했었죠
// 스택 메모리다 보니까 그러다 보니까 monsterinfo는 결국에는 요 CreateMonsters, Enterbattle 까지는 넘겨도 되지만
// EnterGame 위쪽으로 거꾸로 리턴해서 넘기는 건 말도 안된다라는 얘기.
// PlayerInfo의 생명 주기는 그 EnterLobby 아래까지 얘기가 되는 거죠

enum PlayerType
{
	PT_knight = 1,
	PT_Archer = 2,
	PT_Mage = 3,
};

enum MonsterType
{
	MT_Slime = 1,
	MT_Orc = 2,
	MT_Skeleton = 3,
};

struct StatInfo
{
	int hp = 0;
	int attack = 0;
	int defence = 0;
};

void EnterLobby();
void PrintMessage(const char* msg);
void CreatePlayer(StatInfo* playerinfo);
void PrintStatInfo(const char* name, const StatInfo& info);
// const를 사용한 이유는 출력하는 용도로만 사용할 것이지, 내부에서 여기있는 인포를 수정하지는 않을것이기 때문이다
// 그래서 const와 참조는 같이 자주쓰인다
void EnterGame(StatInfo* playerInfo);
void CreateMonsters(StatInfo monsterinfo[], int count);
// CreateMonsters가 포인터를 받아주는 형태로 만들어져 있는걸 볼수 있다
bool Enterbattle(StatInfo* playerinfo, StatInfo* monsterinfo);



int main()
{
	srand((unsigned)time(nullptr));
	EnterLobby();
	return 0;
}

void EnterLobby()
{
	while (true)
	{
		PrintMessage("로비에 입장했습니다");

		// PLAYER!
		StatInfo playerinfo;
		// 이 엔터 로비에 지역 변수 쪽에다가 스탯 인포라는 공간을 이제는 사용하겠다라고 지금 선포를 한것임.
		// 전 시간에 배웠던 핵심적인 내용중 하나는 어떤 스택의 주소를 외부로 발설하는 것은 굉장히 위험한 행동임.
		// 왜냐면 스택 메모리 특성상 함수가 종료되면 그 영역은 더이상 유효하지 않기 때문에
		// 사실 여기있는 StatInfo playerinfo 이 주소를 외부에다가 넘겨주는건 당연히 말이 안되고 위험한짓임.
		// 하지만 이렇게 내부에서는 어디까지나 이 영역에선  얘가 계속 유효하기 때문에 다음 함수한테 playerinfo
		// 저 주소를 넘기는것은 100퍼 안전하다는 얘기
		// 그래서 이것을 구분할수 있는 눈이 생겨야 한다.
		// 사실 저 위에 그려놓은 그림에 따르면 EnterLobby가 제일 먼저 실행이 되고 그다음 세부적으로 안에서
		// CreatePlayer, enter game, create monster, enterbattle이 일어나게 된다.
		// 그래서 EnterLobby 얘가 가장 먼저 만들어지고 그 데이터를 아래로 
		// CreatePlayer, enter game, create monster, enterbattle
		// 여기다가 넘기는거기 때문에 완전히 안전하다.
		// 물론 이 데이터를 혹시라도 main함수에서 꺼내서 넘기게 되면 우리가 이전에 본것처럼 위험한 짓거리가 될거다.
		CreatePlayer(&playerinfo);
		PrintStatInfo("player", playerinfo);

		EnterGame(&playerinfo);


	}
}

void PrintMessage(const char* msg)
{
	cout << "*************************" << endl;
	cout << msg << endl;
	cout << "*************************" << endl;
}

void CreatePlayer(StatInfo* playerinfo)
{
	bool ready = false;
	while (ready == false)
	{
		PrintMessage("캐릭터 생성창");
		PrintMessage("[1] 기사 [2] 궁수 [3] 법사");
		cout << ">";

		int input;
		cin >> input;

		switch (input)
		{
		case PT_knight:
			playerinfo->hp = 100;
			playerinfo->attack = 10;
			playerinfo->defence = 5;
			ready = true;
			break;
		case PT_Archer:
			playerinfo->hp = 80;
			playerinfo->attack = 15;
			playerinfo->defence = 3;
			ready = true;
			break;
		case PT_Mage:
			playerinfo->hp = 50;
			playerinfo->attack = 25;
			playerinfo->defence = 1;
			ready = true;
			break;
			// 플레이어를 골랐으면 밖으로 빠져나가고 싶은데 종료를 어떻게 하지?
			// 여러가지 방법이 있는데 break 대신 return을 해서 함수에서부터 도망가는 방법이 있음
			// 이렇게 케이스 문이라고 해가지고 꼭 브레이크를 써야 된다는 얘기는 아닌 거죠
			// 아니면 while문 조건식에 ready == false로 설정해서 true가 되면 빠져나가게 한다.
		}

		// 나중에 가면 이렇게 코드에다가 하드코딩을 하는 형태가 아니라 어딘가에다가 어떤 파일에다가 
		// 따로 뽑아 가지고 데이터를 관리를 하게 될 겁니다
	}
}

void PrintStatInfo(const char* name, const StatInfo& info)
{
	cout << "*******************************" << endl;
	cout << name << " : HP = " << info.hp << " ATT = " << info.attack << " DEF = " << info.defence << endl;
	cout << "*******************************" << endl;
}

void EnterGame(StatInfo* playerInfo)
{
	const int MONSTER_COUNT = 2;
	PrintMessage("게임에 입장했습니다!");

	while (true)
	{
		StatInfo monsterInfo[MONSTER_COUNT];
		CreateMonsters(monsterInfo, MONSTER_COUNT);
		// 일단은 이 monsterInfo를 넘겨 준 다음에 그 다음에 이 배열의 크기도 같이 넘겨 줘야 되겠죠 
		// 왜냐면 배열은 함수에 그냥 뿅 넘어가는 게 아니라 그냥 포인터 형태로 넘어간다고 했었다
		// 배열 자체를 넘길수 있는 방법은 없었다.

		// 배열 표기법(StatInfo monsterinfo[])은 함수 내부에서 배열만 처리할 것이라는 암묵적인 가정을 하게 만듭니다. 
		// 배열 표기법(StatInfo monsterinfo[])을 함수 인자로 사용하면 배열만 받을 수 있고 단일 객체는 받을 수 없습니다. 
		// 하지만 포인터 표기법(StatInfo* monsterinfo)은 "포인터로 전달된 데이터를 처리한다"는 명확한 의도를 전달합니다.

		for (int i = 0; i < MONSTER_COUNT; i++)
		{
			PrintStatInfo("Monster", monsterInfo[i]);
			// 여기서는 거꾸로 우리가 포인터가 아니라 참조, const참조로 넘겨놨기 때문에 
			// 몬스터 인포 i번째의 주소를 넘겨주는게 아니라 그 바구니 자체를 넘겨주는 형태로 만들어줘야한다.
		}
		PrintStatInfo("Player", *playerInfo);
		// StatInfo는 참조값으로 받고 있는데 우리가 playerInfo는 포인터로 받아주고있었다. playerInfo는
		// 주소값 바구니이고 실질적으로 playerInfo를 꺼내서 여기다가 넣어주기 위해서는 
		// 위해서는 해당 주소로 순간 이동을 해야 되기 때문에 이렇게 사용을 해줘야 됩니다
		// 그렇게 안하고 playerInfo 이렇게 넘겨주면 주소값을 넘겨주게됨

		// 그러니까 포인터는 무조건 주소를 넘겨줘야 되는 거고 레퍼런스 형태, 이 레퍼런스 형태는 마치
		// 우리가 복사를 해주는 것처럼 맨 처음에 배웠던 문법처럼 그냥 복사를 하는 느낌으로 
		// 계속 유도를 해줘야 된다는 얘기가 되는 거죠 

		PrintMessage("[1] 전투 [2] 전투 [3] 도망");

		int input;
		cin >> input;

		if (input == 1 || input == 2)
		{
			int index = input - 1;
			bool victory = Enterbattle(playerInfo, &(monsterInfo[index]));
			// 여기 마우스를 갖다 대면 Enterbattle에 포인터를 넘겨줘야 되는데 우리가 (monsterInfo[index])
			// 이렇게 해가지고 결국은 이 배열을 이동해 가지고 들어가 있는 그 값은 이 StatInfo죠
			// 주소값이 아니라 그렇기 때문에 주소값을 넘기기 위해서는 결국 얘도 (&) 이렇게 주소값을 표현을
			// 해줘야 된다는 얘기가 되는 거고 이렇게 괄호를 한번 묶어 줘 가지고 얘가 먼저 실행이 된 다음에 
			// 다음에 주소값을 넣어 준다고 확신을 이해를 해주시면 되겠어요
			if (victory == false)
			{
				break;
			}
		}
	}
}

void CreateMonsters(StatInfo monsterinfo[], int count) // 배열은 내부적으로 포인터를 넘겨주는 개념
{
	for (int i = 0; i < count; i++)
	{
		int randvalue = 1 + rand() % 3;

		switch (randvalue)
		{
		case MT_Slime:
			monsterinfo[i].hp = 30;
			monsterinfo[i].attack = 5;
			monsterinfo[i].defence = 1;
			// 1차 포인터랑 1차 배열은 완전히 호환
			break;
		case MT_Orc:
			monsterinfo[i].hp = 40;
			monsterinfo[i].attack = 8;
			monsterinfo[i].defence = 2;
			// 1차 포인터랑 1차 배열은 완전히 호환
			break;

		case MT_Skeleton:
			monsterinfo[i].hp = 30;
			monsterinfo[i].attack = 15;
			monsterinfo[i].defence = 3;
			// 1차 포인터랑 1차 배열은 완전히 호환
			break;
		}
	}
}

bool Enterbattle(StatInfo* playerinfo, StatInfo* monsterinfo)
{
	while (true)
	{
		int damage = playerinfo->attack - monsterinfo->defence;
		if (damage < 0)
			damage = 0;
		monsterinfo->hp -= damage;
		if (monsterinfo->hp < 0)
			monsterinfo->hp = 0;

		PrintStatInfo("Monster", *monsterinfo);

		if (monsterinfo->hp == 0)
		{
			PrintMessage("몬스터를 처치했습니다");
			return true;
		}

		damage = monsterinfo->attack - playerinfo->defence;
		if (damage < 0)
			damage = 0;
		playerinfo->hp -= damage;
		if (playerinfo->hp < 0)
			playerinfo->hp = 0;

		PrintStatInfo("Player", *playerinfo);
		// 포인터에 접근해서 주소값이 아니라 주소값에 순간이동해서 playerinfo의 정보를 넘겨줘야한다.

		if (playerinfo->hp == 0)
		{
			PrintMessage("Game Over");
			return false;
		}

	}
}

// 있습니다 지금 이렇게만 봐도 굉장히 복잡해지는데 이걸 나중에 더 깔끔하게 
// 뭔가 객체지향적으로 관리하는 방법에 대해서는 또 나중에 알아볼 거예요
// 지금은 이게 어떻게 보면 우리의 최대의 무식한 역대 최대의 무식한 코드라고 볼 수가 있는거다

// 어찌됐건 이상 텍스트 RPG2를 완성을 해볼 거고 여기 있는 내용은 몇 번씩 복습을 해보면서 
// 그냥 혼자 안 보고 한번 만들어 보는 연습을 몇 번 해보셨으면 좋겠어요
// 반복적으로 타이핑해서 문법적으로 손에 익게끔 만드는 경우가 있는데 그게 생각보다 많이 도움이 된다
