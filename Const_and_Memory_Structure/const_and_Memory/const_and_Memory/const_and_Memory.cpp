#include <iostream>
using namespace std;
// 한번 정해지면 절대 바뀌지 않을 값들
// constant의 약자인 const를 붙임(변수를 상수화 한다고 함)
// const를 붙였으면 초기값을 반드시 지정해야함

// 그러면 const도 바뀌지 않는 읽기 전용
// 즉 .rodata?
// 사실 C++ 표준에서 꼭 그렇게 하라는 말이 없음
// 그냥 컴파일러 (VS) 마음이다.
// 하지만 const라고 해도 함수 내부에서 썼다면 걔네들은 스택 영역에다가 만들어져 있다.

const int AIR = 0;
const int STUN = 1;
const int POLYMORPH = 2;
const int INVINCIBLE = 3;

// 전역 변수(함수 밖에서 선언된 변수)

// [데이터 영역]
// .data (초기값이 있는 경우)
int a = 2;
// .bss (초기값이 없는 경우)
int b;
// .rodata (읽기 전용 데이터)
const char* msg = "Hello World";

int main()
{
	// [스택 영역]
	// 함수 안에서 선언한 변수는 지역변수라고 한다.
	int c = 3;
}