#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

// delete (삭제된 함수)
// 뭔가 어떤 함수 자체를 막아버리고 싶다
// 함수의 삭제 선언
// C++의 컴파일러가 자동으로 만들어주는 함수 중 사용하지 않아야 할 함수를 삭제시키는 구문에 대해 알아보자.
// 클래스의 멤버 함수의 경우, 원래라면 private으로 설정하여 접근을 막으면 됐지만 Modern C++로 넘어오면서 delete라는 문법이 하나 생기게 되었다.
// 해당 문법을 사용하면 한 줄로 간편하게 함수 호출을 막을 수 있다.

class Knight
{
public:

	// 예전 문법
private: // => public
	// 내가 명시적으로 사용을 안 하겠다고 선언한 의미이다.
	// 정의되지 않은 비공개(private) 함수
	void operator=(const Knight& k) = delete; // 그 다음에 통상적으로 얘를 이제 public으로 만들어주는게 관례에요

	// 이 아이 한정 허용
	friend class Admin;
	friend void Print(const Knight& k);
private:
	int _hp = 100;
};

// 여기서 눈여겨 볼 것은 = delete 부분이다. 함수명 뒤에 붙여줌으로써 간단하게 해당 함수의 호출을 막을 수 있다.

// friend
// private으로 설정된 클래스 내부의 값들은 그 내부에서밖에 접근하지 못한다. 
// 하지만 friend를 사용하면 해당 클래스나 함수 한정으로 접근이 가능하게 만들어준다. 
// 하지만 정보 은닉에 위배되므로 웬만하면 사용을 지양하는 게 좋다.
// friend 문법은 클래스, 전역 함수, 멤버 함수에 한해 설정이 가능하다.


class Admin
{
public:
	void CopyKnight(const Knight& k)
	{
		Knight k1;
		// 복사 연산
		// k1 = k; // error
	}

};

void Print(const Knight& k)
{
	cout << k._hp << endl;
}

int main()
{
	Knight k1;

	Knight k2;

	// k1 = k2; // error

	Admin admin;
	admin.CopyKnight(k1);

	Print(k1);
	return 0;

	// 그래가지고 경우에 따라서 나중에 스마트 포인터 실습을 언젠가는 C++에서 하게 될지 서버에서 하게 될지는 모르겠지만 
	// 그런 부분에 대해서도 어떤 특정 기능 복사가 안 돼야 된다거나 하는 그런 추가 사항을 우리가 넣고 싶은 경우가 생기게 되는데 그럴 때 딜리트 문법을 활용을 하시면 되겠습니다
}