#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

class Knight
{
public:
	void Test()
	{

	}

};

Knight* FindKnight()
{
	return nullptr;
}

// nullptr
void Test(int a)
{
	cout << "Test(int)" << endl;
}
void Test(void* ptr)
{
	cout << "Test(*)" << endl;
}
// nullptr 구현
const
class
{
public:

	// 그 어떤 타입의 포인터와도 치환가능
	template<typename T>
	operator T* () const
	{
		return 0;
	}

	template<typename C, typename T>
	operator T C::* () const
	{
		return 0;
	}

private:
	void operator&() const; // 주소값 &(추출)을 막는다
}_Nullptr; // 클래스를 만들자마자 객체를 하나 만들어주는 부분. 이렇게 하면 위에 class Nullptr 이 부분에 Nullptr를 빼고 class로만 써도됨. 
// 그리고 Nullptr은 const여야하니까 위에 const를 쓰면 _Nullptr 이것이 const _Nullptr로 된다

// 이 구현이나 이런 건 사실 크게 중요한 부분은 아니고요 당장 이해할 필요는 없고 그냥 무조건 어떤 포인터랑 어떤 포인트가 없다는 것 자체를 사용할 때는 이 null이라는 것은
// 완전히 잊어야 되고 무조건 nullptr를 활용을 하면 된다고 일단 이거 하나만 기억을해주면 된다

//const Nullptr _Nullptr; // 전역 객체 선언

int main()
{
	// nullptr
	int* ptr = nullptr;
	// ptr 안을 까보면 0이 들어가 있는걸 알수 있다\
	// 0 null

	Test(0);
	Test(NULL);
	// 위에 두 코드 모두 "Test(int)" 가 출력
	Test(nullptr); // "Test(*)"

	// nullptr 사용 이유
	// 1) 오동작 방지

	auto knight = FindKnight();
	if (knight == _Nullptr)
	{

	}
	//auto whoami = nullptr; // 여기서 널포인터의 타입은 nullptr_t인것을 알수 있음
	//nullptr_t  whoami = nullptr;

	void (Knight:: * memFunc)(); // 멤버함수 포인터
	memFunc = &Knight::Test;

	if (memFunc == _Nullptr)
	{

	}
	return 0;
}