#include <iostream>
using namespace std;

// 제 1장: 함수(프로시져, 메소드. 루틴)

/*

input으로 무엇을 받고, output으로 무엇을 뱉을지 정해준다.

반환타입 함수이름([인자타입 매개변수])
{
    함수 내용

    return ~~;

}

*/

// Hello World를 콘솔에 출력하는 함수를 만들어 보자!
// input : 없음 / output : 없음
// 타입 : int float double char ~~ 반환하는게 없거나 입력받을게 없다고 하면 타입을 void라고 입력을 해줘야한다. (생략가능)

void PrintHelloWorld()
{
    cout << "Hello World" << endl;

    return; // 함수 탈출 기능. 함수를 호출한 곳으로 돌아가게 한다. 그리고 반환하는게 없으면 얘도 생략할수 있음.
}

// 정수를 입력 받아서, 콘솔에 출력하는 함수를 만들어보자.
// input : int // output : 없음

void PrintNumber(int num) // 여기에서 void는 output : 없음 이니까 void를 써준다.
{
    cout << "넘겨주신 숫자는 " << num << "입니다." << endl;
}

// 2를 곱하는 함수를 만들어 보자
// input : int / output : int 
// 

int MultiPlyBy2(int a)
{
    int res = a * 2;
    return res; // 결과물을 반환.
}

// 두 숫자를 곱해서 결과물을 뱉는 함수를 만들어 보자
// input : int / output : int 

int MultiPlyBy(int a, int b)
{
    int c = a * b;
    return c;
}

int main()
{
    int a = 3;
    int b = 5;
    int result = MultiPlyBy2(3); // 함수의 결과값을 result에 저장
    int res2 = MultiPlyBy(a, b);
    PrintHelloWorld();
    PrintNumber(result);
    PrintNumber(res2);
}