#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

// 중괄호 초기화 {}

class Knight
{
public:
	Knight() {

	}

	Knight(int a, int b) {
		cout << "Knight(int, int)" << endl;
	}

	// 우선순위가 제일 높음
	Knight(initializer_list<int> li) {
		cout << "Knight(initializer_list)" << endl;
	}

};
// 이렇게 된다면 int 타입의 인자를 두 개 받는 기사 클래스 선언부가 있다고 했을 때 어떤 생성자를 호출해야 할지 애매해진다는 단점이 있다.

int main()
{
	// 중괄호 초기화 {}

	int a = 0;
	int b(0);
	int c{ 0 };

	Knight k1;
	Knight k2 = k1; // 복사 생성자 (대입 연산자 X)

	//Knight k3; // 기본 생성자
	//k3 = k1; // 대입 연산자

	Knight k3{ k2 };
	// 이렇게 변수명 바로 뒤에 중괄호를 사용해 초기화 할 값을 세팅해주면 쉽게 사용할 수 있다.

	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);

	vector<int> v2(10, 1);

	vector<int> v{ 1, 2, 3, 4 };

	// 벡터와 중괄호 초기화
	// // 초기화
    // rvalue를 이용한 이동 연산
	// discovered.push_back(VertexCost{ here,0 }); // 중괄호 초기화를 사용한 객체 생성 방식, 이동 연산으로 lvalue를 이용한 방법보다 더 효율적임

	// lvalue를 전달 했을 경우
	// VertexCost vc = { here, 0 };
	// discovered.push_back(vc);  // lvalue 전달
	// push_back(const T& value)가 호출, 복사 비용이 발생

	// 이것이 되는 이유는 push_back엔 오른값, 즉 임시값을 넣어야하기 때문에 VertexCost{ here,0 } 이라는 임시 객체를 생성해서 넣어줬기 떄문에 가능하다
	// 생성자가 정의되어 있다면 VertexCost(here, 0)과 같은 방식도 사용 가능
	// -------------------------------------------------------------------

	// 장점
	// 중괄호 초기화도 C + 11 이후에 나온 개념이며 해당 초기화 방법을 사용함으로써 생기는 장점 몇 가지가 존재한다.

	// 1) 초기화 문법의 일치화
	// 어떠한 타입의 변수든 중괄호를 이용하여 작성하면 되기 때문에 중구난방이던 초기화 문법이 통일된다.

	// 2) 축소 변환 방지

	//int x = 0;
	//double y{ x }; // error
	// 위와 같은 코드가 있다고 가정했을 때 데이터 손실이 생기는 축소 변환을 우려하여 프로젝트가 실행되지 않는다. 오버플로우 등을 방지할 수 있다는 장점이 있다.

	// 3) vector 등의 컨테이너와 잘 어울린다.
	// 중괄호를 사용하면 컨테이너도 아주 간단하게 초기화할 수 있다.

	// 4) Bonus
	Knight k4{}; // 기본 생성자 버전이 만들어짐

	// 단점
	Knight k6{ 1,2,3,4,5 }; // 이렇게 숫자를 생성자로 받아주고 싶다면 initializer_list<int> 을 쓴다 // 이코드는 initializer_list<int>버전으로 생성이 된다
	Knight k5{ 1, 2 }; // 근데 만약 인자 2개를 받아주는 생성자를 호출시키고 싶다고 한다면 이렇게 설정하면 이것도 initializer_list<int>버전으로 생성이 되는 문제가 생긴다


	// 중괄호를 사용하게 되면 무조건 초기화 리스트를 인자로 받는 생성자가 호출된다. 우선순위가 가장 높기 때문이다. 
	// int 타입의 인자 두 개를 받는 생성자를 호출하고 싶으면 일반 괄호를 사용해야 한다.

	// 💡 initializer_list<int> li를 인자로 받는 생성자를 통해 초기화 리스트에 접근할 수 있다.

	// 괄호와 중괄호
	// 괄호의 종류에 따라 코드 스타일을 두 가지로 나눌 수 있다.

	// 괄호 초기화() 를 기본으로 간다.
	// - 전통적인 C++ 문법이라 거부감이 없다.
	// - vector 등 특이한 케이스에 대해서만 { } 초기화를 사용하면 편리하다.

	// 중괄호 초기화{ } 를 기본으로 간다.
	// - 초기화 문법을 일치화할 수 있다.
	// - 축소 변환을 방지해준다.
	// - 어떤 기준을 잡냐에 따라 개개인의 코드 스타일이 달라진다.
	// 구글링을 좀 해보니 아무래도 현대 문법인 중괄호를 사용하여 예상 못한 버그를 미리 방지하는 식으로 생각하여 중괄호 초기화를 좀 더 선호하는 것 같다.참고만 하자!!



	return 0;
}