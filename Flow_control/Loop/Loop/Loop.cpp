#include <iostream>
using namespace std;

// 제 2 장 : 반복문
// 데이터를 메모리에 할당하고 가공하고 방법에 대해 알아봄.
// 가공한 데이터를 이용해서 무엇인가를 하고 싶다면?


int main()
{
	// Whlie ~ 동안에
	// if~ else 굉장히 유용함
	// 하지만 한번만 실행하는게 아니라, 특정 조건까지 계속 반복해야하는 상황
	// ex) 게임을 끌때 까지 계속 게임을 실행해라
	// ex) 목적지에 도달할 때 까지 ~ 계속 이동하라

	// break; , continue; 이 두개는 for문이든 while문이든 둘다 사용가능

	/*while (조건식)
	{
		break; // 이렇게 break를 넣어주게 되면 조건식을 만족하곤 안하곤 관심없이
				  while문에서, 반복문에서 그냥 빠져나가라 라는 뜻이된다.
		즉, 범위 안에 찝혀있는 그 범위만 빠져나간다는 그런 의미로 보시면 된다.

		continue; // 완전 빠져나가는건 아니지만 이 해당 조건을 그냥 간략하게 통과를 하고 싶은 경우가 있는데 그때 continue를 사용하게 된다.
				  // 어떤 코드가 실행이 됐다가 continue를 쓰는 순간 아랫부분을 실행을 안한 상태에서 그냥 계속 이어서
				  // 반복문을 한번 더 돌게 된다. 약간 스킵의 개념이라고 보면된다.
				  // for문이라고 했을땐, continue 아래에 있는 코드는 실행을 안하고 count++; 카운트 증가로 실행하게됨.

		명령문
	}*/

	/*int count = 0;

	while (count <= 5)
	{
		cout << "Hello World" << endl;
		count++;
	}*/

	// while 문은 조건식이 참이면 실행되고 거짓이면 실행을 안하지만, do~while문은 무조건 조건에 관계없이 한번은
	// 실행되고 그다음 while 옆에있는 조건식을 체크한다는 차이가 있다.

	/*do
	{
		cout << "Hello World" << endl;
		count++;
	} while (count < 5);*/

	// FOR문 while보다 많이 사용됨.

	/*for (int count = 0; count < 5; count++)
	{
		cout << "Hello World" << endl;
	}*/
	// for문의 실행 순서. int count = 0; -> 1번 (변수 초기화)
	// count < 5; => 2번 (조건식)
	// cout << "Hello World" << endl; => 3번 (실행문)
	// count++ => 4번 (버그방지문)

	// break문 예시문
	/*
	int round = 1;
	int hp = 100;
	int damage = 35;

	// 무한 루프 : 전투 시작
	while (true)
	{
		hp -= damage;
		if (hp < 0)
			hp = 0; // 음수 체력을 0으로 보정

		// 시스템 메세지
		cout << "round" << round << "몬스터 체력" << hp << endl;

		if (hp == 0)
		{
			cout << "몬스터 처치!" << endl;
			break;
			// 이 break문은 이 if문을 나가라는 의미가 아니라 이 if문의 조건이 만족되면
			// 아랫 부분은 실행되지 않고 while문 빠져나가게 된다고 보면된다..
		}

		if (round == 5)
		{
			cout << "제한 라운드 종료" << endl;
			break;
		}

		round++;
	}
	*/


	// 1~10 사이의 홀수만 출력하기

	for (int count = 1; count <= 10; count++)
	{
		bool isEven = ((count % 2) == 0);

		if (isEven)
			continue; // 스킵

		if (isEven == false)
			cout << count << endl;
	}

}
