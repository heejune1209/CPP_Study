#include <iostream>
using namespace std;

int a = 0;
int b = 1;

bool issame;
bool isdif;
bool isGreater;
bool issmaller;
bool test;


int hp = 100;
bool isInvincible = true;

int main()
{
#pragma region 비교연산

	// 언제 필요한가?
	// ex) 체력이 0이되면 사망.
	// ex) 체력이 30%이하이면 궁극기를 발동 (100 * hp / maxhp)
	// ex) 경험치가 100 이상이면 레벨업

	// a == b : a와 b의 값이 같은가?
	// 같으면 1, 다르면 0
	issame = (a == b);

	// a != b : a와 b는 다른가?
	// 다르면 1, 같으면 0
	isdif = (a != b);

	// a > b : a가 b보다 큰가?
	// a >= b : a가 b보다 크거나 같은가?
	// 1 아니면 0
	isGreater = (a > b);


	// a < b : a가 b보다 작은가?
	// a <= b : a가 b보다 작거나 같은가?
	// 1 아니면 0
	issmaller = (a < b);


#pragma endregion



#pragma region 논리연산

	// 언제 필요한가? 조건에 대한 논리적 사고가 필요할때
	// ex) 로그인할때 아이디도 같고 AND 비밀번호도 같아야한다.
	// ex) 길드 마스터거나 OR 운영자면 길드 해산 가능.

	// ! not
	// 0이면 1, 그외 다 0

	test = !issame; // 사실상 isdif의 의미.


	// && and
	// a && b : 둘다 1이면 1, 그외엔 0

	test = (hp <= 0 && isInvincible == false); // -> 죽음

	// || or
	// a || b : 둘중 하나라도 1이면 1, 그외 0(둘다 0이어도 0)

	test = (hp > 0 || isInvincible == true); // 생존
	// = !(hp <= 0 && isInvincible == false); =>  이렇게 작성해도 같은 뜻임.

#pragma endregion
}
