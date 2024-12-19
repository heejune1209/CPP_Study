#include <iostream>
using namespace std;

 // 제 6장 함수 마무리

// 오버로딩 (중복 정의 : 함수 이름의 재사용)
// - 매개변수 갯수가 다르거나
// - 매개변수 타입이 다르거나 (순서가 다른것을 포함)
// - 반환형식은 타입이 달라도 오버로딩 불가.
int Add(int a, int b)
{
	int result = a + b;
	return result;
}
int Add(int a)
{
	int result = a + 1;
	return result;
}
// 그래가지고 우리가 딱 이 Add라는 이름이 굉장히 마음에 들었는데 지금 인트가 이 버전이 선점하고 있으니까 
// 사용을 못하는 거 아닌가 싶기는 한데 사실 C나 C++에는 이 함수와 관련되어 가지고 중복 정의 기능을 지원합니다 
// 중복 정의를 하면 무엇이냐면 결국 함수 이름을 재사용 하는것.

// 기본 인자값
// 기본으로 인자값을 세팅하려고 하는 애들은 항상 맨끝으호 선언해줘야 한다. 중간에 설정 해두면 안됨.
void SetPlayerinfo(int hp, int mp, int attack, int guildid = 0, int cattleid = 0) // 여기서 인자값을 기본으로 세팅을 하면,
{

}

// 스택 오버플로우
// 만약, 매개 변수로 1000000(백만)을 넣은 후 디버깅해보자. 그러면 예외가 처리되지 않는다는 에러가 뜨게된다. 
// 스택을 초과해서 스택 오버플로우가 발생한 것이다. 
// 이러한 상황을 해결하려면 스택 오버플로우가 우려될 때는 반드시 예외 처리를 해줘야 한다.
// 즉, 너무나도 많은 함수를 연속해서 호출하면은 이렇게 프로그램이 터질 수 있다는 게 일단 오늘 핵심이다.
int Factorial(int n) // 재귀함수
{
	if (n <= 1)
		return 1;
	return n * Factorial(n - 1);
}

int main()
{
	/*int result = Add(1);
	cout << result << endl;*/

	int result = Factorial(5);
	cout << result << endl;

	SetPlayerinfo(100, 40, 10, 0, 1); // 이렇게 인풋을 세팅해도 문제가 없다.(함수을 만들때 인자값을 기본으로 세팅했기 떄문)
	// 만약 cattleid은 1로 설정 하고 싶고 guildid는 기본값으로 세팅하고 싶다면 
	// 위에처럼 guildid는 기본으로 세팅했던 값으로 써야한다.

	// 5! = 5x4x3x2x1 = 5* 4!
	// n! = n*(n-1)!
	return 0;
}