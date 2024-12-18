#include <iostream>
using namespace std;

// 제1장 : 분기문
// 데이터를 메모리에 할당하고 가공하고 방법에 대해 알아봄.
// 가공한 데이터를 이용해서 무엇인가를 하고 싶다면?


int main()
{
#pragma region	분기문
	//int hp = 100; // 몬스터 HP
	//int damage = 90; // 플레이어 데미지
	//
	//hp -= damage; // 피격 판정
	//bool isDead = (hp <= 0); // 처치 판정

	// 몬스터가 죽었으면 경험치 추가
	// 어셈블리에서 CMP JMP

	//if (isDead) // 괄호 안()은 참/ 거짓을 판단 
	//	cout << "몬스터를 처치했습니다" << endl;

	//if (!isDead) // 괄호 안()은 참/ 거짓을 판단 
	//	cout << "몬스터를 반격했습니다" << endl;

	// 사실 저렇게 처리하는것은 성능적인 낭비를 시킬수 있다 그래서 저 상황이면 잘 활용해야하는것이
	// 바로 if ~else 문이다.

	/*
	if (isDead) // 괄호 안()은 참/ 거짓을 판단
	{
		cout << "몬스터를 처치했습니다" << endl;
		cout << "몬스터를 처치했습니다" << endl;
		// 만약에 if문이나 else에 걸린게 한줄이면 괄호를 사용안하고
		//if (isDead) // 괄호 안()은 참/ 거짓을 판단
			//	cout << "몬스터를 처치했습니다" << endl;
		// 이렇게 사용할수 있는데, 여러줄을 출력해야할땐 이렇게 중괄호를 사용해서 출력해야한다.
	}
	*/
	//else
	//	cout << "몬스터를 반격했습니다" << endl;
	// 이게 더 효율성이 좋다.

	// if~ else if ~else
	//if (isDead) // 괄호 안()은 참/ 거짓을 판단 
	//	cout << "몬스터를 처치했습니다" << endl;
	//else if (hp <= 20)
	//	cout << "몬스터가 도망가고있습니다" << endl;
	//else
	//	cout << "몬스터를 반격했습니다" << endl;
#pragma endregion

	const int ROCK = 0;
	const int PAPER = 1;
	const int SCISSORS = 2;

	int input = ROCK;

	/*if (input == ROCK)
		cout << "바위를 냈습니다." << endl;
	else if (input == PAPER)
		cout << "보를 냈습니다." << endl;
	else if (input == SCISSORS)
		cout << "가위를 냈습니다." << endl;
	else
		cout << "뭘 낸겁니까." << endl;*/
		// 위의 코드에 대해서 프로그래머들이 이렇게 반복되는 코드를 굉장히 싫어하는 경향이 있다.

		// switch ~case문
		// 위에 있는 if ~ else if~else 문보다 가독성이 좋음.

		// switch () 괄호안에 정수 계열만 넣을 수 있다.
		// 사실 if ~ else if~else이 더 넓은 개념.
	switch (input)
	{
	case ROCK:
		cout << "바위를 냈습니다." << endl;
		break;
	case PAPER:
		cout << "보를 냈습니다." << endl;
		break;
	case SCISSORS:
		cout << "가위를 냈습니다." << endl;
		break;
		// break의 기능은 괄호로 넣어준 범위 밖으로 나오는 기능임. 즉 스위치문에서 빠져나오게 되는것임.
		// 즉. 스위치문에서 들어오는것까진 자유였지만 나갈땐 반드시 break를 써줘야만 빠져나올수 있다는 것임.
		// 만약에 case ROCK에 break를 안썻다고 하면 "바위를 냈습니다." 다음에 "보를 냈습니다." 까지 출력이 된다. 
	default:
		cout << "뭘 낸겁니까." << endl;
		break;
		// default는 그냥 옵션이고 모든게 다 걸리지 않았다고 하면 최종적으로 실행할 수 있는 안전장치로 보면됨.
		// 사실상 뭐 if - else로 하거나 아니면은 switch문으로 하거나 
		// 사실상 크게 뭐 어마어마하게 큰 그런 향상이 있다고 보기는 어렵구요 
		// 단지 가독성 차원에서 이렇게 해주는 게 더 정확하다고 보시면 되겠습니다
	}
}