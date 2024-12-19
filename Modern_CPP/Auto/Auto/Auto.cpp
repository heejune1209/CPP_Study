#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

// auto
// Modern C++은 C++11 이후부터 나온 C++을 일컫는 말이다. 11버전은 2011년도에 나왔다. 이번 시간에는 Modern C++의 문법 중 하나인 auto에 대해서 알아볼 것이다.

class knight
{
public:
	int _hp;
};

int main()
{
	// auto
	// auto는 형식 연역(type deduction) 규칙을 따르며 변수의 타입을 추론하여 세팅해주는 문법이다. 템플릿의 typename과 비슷하게 작동한다.

	/*int a = 3;
	float b = 3.14f;
	double c = 1.23;
	knight d = knight();
	const char* e = "Dandi";*/

	auto a = 3;
	auto b = 3.14f;
	auto c = 1.23;
	auto d = knight();
	auto e = "Dandi";

	// auto는 일종의 조커 카드
	// 추론 규칙은 생각보다 복잡해질 수 있다

	auto f = &d;
	const auto test1 = b;
	auto* test2 = e;

	// 주의! 
	// 기본 auto는 const, &를 무시한다.
	//int& reference = a;
	//const int cst = a;

	//auto test4 = reference; // int& 에서 &가 무시가 되어서 int로 인식됨
	//auto test5 = cst; // int

	// 위처럼 참조값이나 const는 자동으로 무시되어지기 때문에 주의해야한다. 
	// 예를 들어 참조를 통해 값을 변경하는 코드에 auto를 사용하게 되면 복사 연산이 되기 때문에 연산 결과가 달라질 수 있기 때문이다.
	// 그럼에도 auto를 사용하고 싶다면 캐스팅을 통해 타입을 명시해주거나 auto 뒤에 참조를 의미하는 & 를 붙이면 된다.

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	for (vector<int>::size_type i = 0; i < v.size(); i++)
	{
		int& data = v[i];

		data = 100;
	}

	//int& data = v[0];
	// auto 사용
	// auto data = v[0];  // int data = v[0]의 의미
	auto& data = v[0]; // int& data = v[0];와 동일
	//auto data = static_cast<int&>(v[0]);


	// auto는 대부분 타이핑이 길어진다거나 할 때만 사용하는 게 좋고 가독성을 위해서는 일반적으로 변수의 타입을 놔두는 게 좋다. 
	// auto는 컴파일 타임에 결정되기 때문에 딱히 큰 성능 차이는 없다고 볼 수 있다.

	map<int, int> m;
	auto ok = m.insert(make_pair(1, 100));

	for (auto it = v.begin(); it != v.end(); ++it) // 이터레이터와 관련된 부분은 이땐 기본적으로 타입이 길어지니까 auto를 사용해도됨
	{
		cout << *it << endl;
	}
	return 0;
}