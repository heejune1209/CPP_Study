#include <iostream>
using namespace std;
// 제 6장 : 배열
struct StatInfo
{
	int hp = 0xAAAAAAAA;
	int attack = 0xBBBBBBBB;
	int defence = 0xDDDDDDDD;
};

int main()
{
	// 근데 몬스터가 최대 1만마리라면?
	// 배열 선언 -> TYPE 이름[개수];

	// 배열의 크기는 상수여야 함 (VC 컴파일러 기준)
	const int monsterCount = 10;
	StatInfo monsters[monsterCount];

	// 여태껏 변수들의 [이름]은 바구니의 이름이었음.
	int a = 10;
	int b = a;

	// 그런데 배열에선 [이름]이 다르게 동작한다.
	// StatInfo players[10];
	// players = monsters; // 사용불가. => 배열에선 [이름]이 시작 위치를 가리키는 TYPE* 포인터라고 볼 수 있다. 그래서 저렇게 일반 변수처럼 사용 불가하다.  

	// 그럼 배열의 이름은 뭐지?
	// 배열의 이름은 곧 배열의 시작 주소
	// 정확히는 시작위치를 가리키는 TYPE* 포인터
	auto WhoamI = monsters; // StatInfo* whoAmI

	// StatInfo[(100, 10, 1) ] StatInfo[ ] StatInfo[ ] StatInfo[ ] StatInfo[ ] ...
	// monster_0[주소]
	StatInfo* monster_0 = monsters;
	monster_0->hp = 100;
	monster_0->attack = 10;
	monster_0->defence = 1;

	// 포인터의 덧셈! 진짜 1을 더하라는게아니라, StatInfo 타입 바구니 한개씩 이동하라는 의미
	// StatInfo[ ] 주소[(200, 20, 2)] StatInfo[ ] StatInfo[ ] StatInfo[ ] StatInfo[ ] ...
	// monster_1[주소]
	StatInfo* monster_1 = monsters + 1;
	monster_1->hp = 200;
	monster_1->attack = 20;
	monster_1->defence = 2;

	// 포인터와 참조는 자유자재로 변환 가능하다.
	// StatInfo[ ] StatInfo[ ] monster_2.주소[] StatInfo[ ] StatInfo[ ] StatInfo[ ] ...
	// monster_2[주소]
	StatInfo& monster_2 = *(monsters + 2);
	monster_2.hp = 300;
	monster_2.attack = 30;
	monster_2.defence = 3;

	// [주의] 이거는 완전 다른 의미다.
	// StatInfo[ ] StatInfo[ ] 주소[내용물] StatInfo[ ] StatInfo[ ] StatInfo[ ] ...
	// temp[ 내용물 ]
	// 주소가 아니다 보니까 temp는 monster_2에 접근을 해가지고 주소에 있는 내용물 자체를 
	// 그냥 하나하나씩 temp[ 내용물 ] 여기 안에다가 이렇게 복사하는 그런 개념이 되겠습니다
	// 배열에 있는 실제 데이터를 뭔가 조작을 하는 걔념은 아님.

// 자칫 monster_2와 같은 값을 가리킨다고 볼 수 있지만 temp는 포인터도 참조도 아닌, 값 복사 방식을 사용하는 변수이다. 고로 해당 변수는 StatInfo 타입의 데이터 자체를 담는 그릇이기 때문에, monsters + 2가 가리키는 곳의 데이터를 그대로 복사해와 temp에 담아서 값을 변경하는 방식이 된다. 원본값을 건드리는 것이 아니다.


	StatInfo temp = *(monsters + 2);
	monster_2.hp = 400;
	monster_2.attack = 40;
	monster_2.defence = 4;

	// 위에있는 코드들을 이렇게 반복문으로 조금 더 자동화 한다!
	/*for (int i = 0; i < 10; i++)
	{
		StatInfo& monster = *(monsters + i);
		monster.hp = 100 * (i + 1);
		monster.attack = 10 * (i + 1);
		monster.defence = 1 * (i + 1);
	}*/

	// 근데 *(monsters + i) 너무 불편하고 가독성이 떨어진다.. 더 편한 방법?
	// 인덱스!(위의 for문 방식보다 이 방식으로 기억)
	// 배열은 0번부터 시작. N번째 인덱스에 해당하는 데이터에 접근하려면 배열이름[N]
	// *(monsters + i) == monsters[i]

	monsters[0].hp = 100;
	monsters[0].attack = 10;
	monsters[0].defence = 1;

	for (int i = 0; i < 10; i++)
	{
		StatInfo& monster = monsters[i];
		monsters[i].hp = 100 * (i + 1);
		monsters[i].attack = 10 * (i + 1);
		monsters[i].defence = 1 * (i + 1);
	}
	// 위의 방식과 기능은 같다.

	// 배열 초기화 문법 몇가지
	int numbers[5] = {}; // 이 방식은 값을 일단 0으로 초기화하는 방법.
	int number1[10] = { 1,2,3,4,5 }; // 설정한 애들은 설정한 값들로, 나머지 값들은 0으로 초기화
	int number2[] = { 1,2,3,4,11,24,124,14,1 }; // 데이터 개수만큼의 크기에 해당하는 배열로 만들어준다.

	char helloStr[] = { 'H','e','l','l','o','\0' };
	cout << helloStr << endl;

	// 배열 요약:
	// 1) 선언한다
	int arr[10] = {};

	// 2) 인덱스로 접근해서 사용
	arr[1] = 1;
	cout << arr[1] << endl;

	return 0;
}