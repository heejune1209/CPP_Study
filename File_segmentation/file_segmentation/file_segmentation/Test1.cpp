#include <iostream>
using namespace std;
#include "Test1.h"
// 전처리 문법
// 이 Test1.h라는 파일을 include 해라 포함해라라는 의미가 되기 때문에 실질적으로
// 얘가 하는 거는 여기 있는 모든 내용물을 긁어가지고 얘를 이렇게 복붙을 해가지고 대체를
// 하는 그런 기능.

void Test_1()
{
	Test_2();
}
void Test_2()
{
	cout << "Hello World" << endl;
}
