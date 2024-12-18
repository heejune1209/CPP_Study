﻿#include <iostream>
using namespace std;

// 제 4장 지역변수와 값 전달

// 전역 변수
// 참고) 초기화 여부, const등을 참고 삼아서 . rodata, data, bss 에 들어갈수도 있음.
// 전역 변수는 언제 어디서든 쉽게 다 접근을 해 가지고 사용할 수 있다는 얘기가 됩니다.
// 전역으로 변수를 사용할 수 있다는 얘기는 나중에 실수할 가능성이 굉장히 많다는 뜻. (관리가 힘들다.)
// 이렇게 전역으로 변수를 만드는 거는 그냥 어지간해서는 지양을 해야 합니다.

void increaseHp(int hp)
{
	int finalhp = hp + 1;
	hp = hp + 1;
}

int g_value = 0;

void Test()
{
	cout << "전역변수의 값은 :" << g_value << endl;
	g_value++;
}
// [[매개변수][RET][지역변수(hp=1)] [매개변수(hp=1)][RET][지역변수(finalhp=2)] [매개변수][RET][지역변수]  ]
int main()
{
	int hp = 1;
	cout << "Increase 호출 전 : " << hp << endl;
	increaseHp(hp);
	cout << "Increase 호출 후 : " << hp << endl;

	// 지역 변수
	// 이렇게 각기 다른 공간에 있는 그런 지역 변수 같은 경우에는 기본적인 방법으로는 
	// 이렇게 함수들끼리 공유를 할 수 없다는 게 일단 굉장히 큰 그리고 중요한 그런 개념이라고 보시면 되겠습니다
	// 지역 변수 경우에는 뭔가 사용하기 쉽고 이렇게 서로 데이터를 넘기기도 굉장히 어려워 보이지만 
	// 어찌됐건 이게 더 장기적으로 봤을 때는 더 좋은 방법이다라는 걸 알 수 있었고 기본적으로 이렇게
	// 함수한테 다른 값을 넘길 때는 내가 지금 HP를 넘긴 것 같지만 이건 어디까지나 그냥 눈속임 입니다 
	// 사실은 HP 안에 있는 값을 이렇게 복사해가지고 지금 넘기고 있다가 가장 핵심적인 내용이 되겠습니다.
	int L_value = 0;

	return 0;

}
