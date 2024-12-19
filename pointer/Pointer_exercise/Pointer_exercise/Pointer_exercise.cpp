#include <iostream>
using namespace std;

// 제 3장 : 포인터 실습

struct StatInfo
{
    int hp;  // +0
    int attack;  // +4
    int defence;  // +8
};

void EnterLobby();
StatInfo CreatePlayer();

void CreateMonster(StatInfo* info);
bool StartBattle(StatInfo* player, StatInfo* monster);


int main()
{
    EnterLobby();


    return 0;
}
void EnterLobby()
{
    cout << "로비에 입장했습니다." << endl;

    StatInfo Player;
    // 메모리를 편하게 살펴보기 위해 임의의 값 세팅
    Player.hp = 0xbbbbbbbb;
    Player.attack = 0xbbbbbbbb;
    Player.defence = 0xbbbbbbbb;

    // [매개변수][RET][지역변수(temp(100,10,2) , Player(100,10,2))] [매개변수(&temp)][RET][지역변수(ret(100,10,2))]
    Player = CreatePlayer(); // 반환값으로 뱉느냐

    StatInfo monster;
    // 메모리를 편하게 살펴보기 위해 임의의 값 세팅
    monster.hp = 0xbbbbbbbb;
    monster.attack = 0xbbbbbbbb;
    monster.defence = 0xbbbbbbbb;

    // [매개변수][RET][지역변수(temp(40,8,1) , Player(&monster))] [매개변수(&temp)][RET][지역변수(ret(100,10,2))]
    CreateMonster(&monster);

    // 번외편 : 구조체들끼리 복사하면 어떻게 될까?

    //Player = monster;
    // 위의 코드는 아래와 같이 3줄로 써놓은 코드와 똑같다고 볼수 있다.
    // 즉, 얘기하고싶은건 Player = monster; 이렇게 한줄이라고 해도 어셈블리 상에선 밑에 처럼 3줄로 작업하기떄문에 절대로 빠르다고 단정지으면안됨.
    // 대규모 MMORPG게임의 경우에서 이렇게 함부로 구조체들끼리 복사하는것은 조심해서 사용해야한다.
    /*Player.hp = monster.hp
    Player.attack = monster.attack
    Player.defence = monster.defence*/

    bool Victory = StartBattle(&Player, &monster);
    if (Victory)
    {
        cout << "승리!" << endl;
    }
    else
    {
        cout << "패배 ㅠ" << endl;
    }
}
StatInfo CreatePlayer()
{
    StatInfo ret;

    cout << "플레이어 생성" << endl;

    ret.hp = 100;
    ret.attack = 10;
    ret.defence = 2;

    return ret;
}

void CreateMonster(StatInfo* info) // 포인터로 받아줘서 여기서 세팅을 하느냐
{
    cout << "몬스터 생성" << endl;

    info->hp = 40;
    info->attack = 8;
    info->defence = 1;
}
bool StartBattle(StatInfo* player, StatInfo* monster)
{
    while (true)
    {
        int damage = player->attack - monster->defence;
        if (damage < 0)
            damage = 0;

        monster->hp -= damage;
        if (monster->hp < 0)
            monster->hp = 0;

        cout << "몬스터 HP :" << monster->hp << endl;

        if (monster->hp == 0)
            return true;

        damage = monster->attack - player->defence; // 계산용도, 재활용해서 다시사용.
        if (damage < 0)
            damage = 0;
        cout << "플레이어 HP :" << player->hp << endl;

        player->hp -= damage;
        if (player->hp < 0)
            player->hp = 0;


        if (monster->hp == 0)
            return false;
    }
}

// 사실 핵심적인 내용은 이렇게 포인터로 넘길 때와 그냥 이렇게 반환값으로 복사해가지고 뱉어줄 때의 차이점이 사실 오늘의 가장 핵심적인 내용이었습니다.
// 스택프레임에 관해서 여기서 유일하게 아셔야 되는 거는 이런식으로 이제 구조체 자체를 그냥 뱉어주는 형식으로 요렇게 만들어 줄 경우 
// 그리고 실제 내부에서도 이렇게 변수를 만들어 줘 가지고 뱉어 주는 경우에는 복사가 여러번 일어날 수 있다. 이것을 이해.
// 반대로 이렇게 포인터를 넘겨준 부분으로 만들어주게 될 경우에는 이 실제 원본을 대상으로 
// 작업을 한다는 의미가 되기 때문에 얘가 훨씬 더 빨리 작업이 될 수 있다는 얘기가 되는거다.
// 왜냐면 포인터로 작업을 하면, 그 주소값에 이동을 해가지고 그 실제 주소에서 HP를 뭔가 고치고 있는거니까 
// 실제로 원본 데이터에 가가지고 지금 이렇게 HP와 Attack 그리고 Defense를 세팅을 하고 있다고 보시면 되겠습니다.
// 반환값으로 복사해서 하는것은, 말 그대로 어디 그냥 자기가 메모장에다가 사용하고 있던 그 스택 메모리의 지역 변수에다가 
// 이렇게 임시값을 만들어가지고 걔를 세팅한 다음에 그 임시값을 통째로 이제 다 적었으니까 얘를 이제 밖으로 내보내기 위해서 복사를 해주세요 라는 요청이 된것으로 이해.