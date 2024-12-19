#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

// Using

// using은 typedef와 비슷하게 동작하지만 문법은 다르다.
// 결론은 C++11에서 type define 대신 사용할 수 있는 새로운 문법이 추가되었다. 그게 Using이다

// typedef
typedef __int64 id;

// using
using id2 = int;

// using
template<typename T>
using List = list<T>;

// using 이전 방법
template<typename T>
struct List2
{
	typedef list<T> type;
};

// typedef
// 안 됨
/*
template<typename T>
typedef vector<T> List2;
*/

int main()
{
	id playerid = 0;

	// 장점
	// 1) 직관성이 뛰어나다.
	// 함수 포인터 같은 경우 포인터 이름이 가운데에 위치해 있기 때문에 코드를 보기가 어려웠다.using을 사용하면 조금 더 한 눈에 알아보기 쉽게 코드를 작성할 수 있다.

	// typedef
	typedef void (*MyFunc)();

	// using
	using MyFunc2 = void(*)();

	// 2) 템플릿 활용이 가능하다.
	// typedef는 struct를 사용하여 템플릿을 활용할 수 있었지만 코드가 복잡하고 곧바로 활용할 수는 없었다.
	// using은 템플릿과 곧바로 활용이 가능하다.

	List<int> li;

	li.push_back(1);
	li.push_back(2);
	li.push_back(3);

	// using 이전 방법
	List2<int>::type li2;


	return 0;
}