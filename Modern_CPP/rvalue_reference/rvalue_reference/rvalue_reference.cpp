#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>


// 오른값 참조 (rvalue reference)
// 이것은 모던 C++의 꽃이고 보통 코어 라이브러리를 만들때 활용된다
class Pet
{

};

class Knight
{
public:

	// readonly
	/*void PrintInfo() const
	{

	}*/
	Knight()
	{
		cout << "Knight()" << endl;
	}

	~Knight()
	{
		if (_pet)
			delete _pet;
	}

	//void operator=(const Knight& knight)
	//{
	//	cout << "operator=(const Knight& knight)" << endl;
	//	// 얕은 복사
	//	_hp = knight._hp;
	//	//_pet = knight._pet;
	//	// 우리가 원하는건 나이트랑 똑같이 동작하는 형태로 모든 데이터가 복사가 돼야 된다는 의미였지 이런 식으로 펫까지 공용으로 공동 소유할 수 있다는 얘기는 아니었다

	//	if (knight._pet)
	//	{		
	//		// 이렇게 되면 우리가 원하던 거와 마찬가지로 서로 독립적인 객체가 생성이 된다는 장점이 있지만 이런식으로 복사가 일어나는 연산이 생각보다 비싸질수 있다
	//		// 나중에 가면 펫 뿐만 아니라 얘가 인벤토리도 가질 테고 포인트로 된 온갖 모든 정보들은 다 이런 식으로 매번 마다 다시 만들어 준 다음에 
	//		// 그 정보를 다시 복사하는 식으로 만들어 주지 않으면 우리가 원하던 완벽한 복사가 되지 않을 거라는 문제가 생기게 됩니다
	//		// 그리고 이렇게 우리가 모든 데이터를 하나하나씩 다 꺼내와야 됐었던 필연적인 이유는 뭐였냐면
	//		// 애당초 const Knight& knight 자체가 왼쪽 갑, 왼갑 참조였기 때문이죠
	//		// 왼값 참조라 하면 너가 이 나이트 원본을 가지고 데이터를 참고해도 되기는 해라는 얘기는 했지만 이 원본을 훼손해도 된다는 얘기는 절대 없었죠 
	//		// 그러다 보니까 우리가 멋대로 이 펫을 아 이제는 내가 잘 쓸게 라고 예를 막 날려준다거나 상대방(인자로 받는 것(객체))의 펫을 막 건드리고 이런 거는 당연히 말이 안된다
	//		// 꼭 내가 참고를 할 정보만 열심히 꺼내 준 다음에 나의 버전만 이렇게 만들어 주고 얘는 이제 잘 썼어 라고 돌려주는 기념이 되는 거죠
	//		// 근데 오른값 참조는 원본은 더이상 필요 없다는 어마어마한 힌트를 주게 된다
	//      
	//      // 깊은 복사
	//		_pet = new Pet(*knight._pet);
	//	}
	//}

	// 이동 생성자
	Knight(Knight&& knight)
	{
		cout << "Knight&&" << endl;
	}

	// 이동 대입 연산자
	void operator=(Knight&& knight) noexcept
	{
		cout << "operator=(const Knight&&)" << endl;

		// 얕은 복사
		// 얕은 복사가 되더라도 정보를 참고하는 오른값의 데이터를 건드릴 수 있다.
		_hp = knight._hp;
		_pet = knight._pet;

		// 오른값의 정보를 수정할 수 있다.
		knight._pet = nullptr;
	}

public:
	int _hp;
	Pet* _pet = nullptr;
};

void TestKnight_Copy(Knight knight)
{

}

void TestKnight_LValueRef(Knight& knight) { } 
// 나이트 원본을 넘겨 줄테니 얘를 수정할수도있고 꺼내쓸수도 있고 원본을 멋대로 가지고 놀면돼, 
// 우리가 평소에 사용하던 참조문법은 왼값참조라고 보면된다.
void TestKnight_ConstLValueRef(const Knight& knight) { /*knight.PrintInfo();  PrintInfo 함수에 const를 붙여줘서 통과*/ } 
// 원본을 넘겨주긴 넘겨줄건데 원본을 수정하면 안되고 읽는거만 허락.

void TestKnight_RValueRef(Knight&& knight) { }  // 이동 대상!
// 이것은 원본 객체를 넘겨줄텐데 읽고 쓰고하는것도 너가 마음대로 할수 있고 심지어 TestKnight_RValueRef 이 함수가 호출이 된다음에
// knight 이것을 활용하지도 않을 거니까 너가 멋대로 해도돼. 즉 knight은 이동대상이 되었다
// 굉장히 중요한것은 우리가 신나게 사용한 다음에 이 원본 자체는 더이상 사용하지 않을 거라는 힌트가 있다는것 자체가 큰 차이다
// 오른값 참조로 넘겼다는 것은 이제 원본 데이터를 유지되지 않아도 된다는 그런 엄청난 힌트를 줬다고 볼수 있다


int main()
{
	// 오른값 참조(RValue Reference)는 말 그대로 오른쪽의 값을 참조한다는 의미이다. 
	// 대입 연산자를 기준으로 왼쪽은 왼값(lvalue), 오른쪽은 오른값(rvalue)을 가지게 된다.

	// lvalue : 단일식을 넘어서 계속 지속되는 개체
	// rvalue: lvalue가 아닌 나머지(임시 값, 열거형, 람다, i++ 등)

	//int a = 3;

	Knight k1; // k1은 왼값이다.

	//TestKnight_Copy(k1);
	TestKnight_LValueRef(k1);
	TestKnight_ConstLValueRef(Knight()); // Knight()은 임시 객체. 즉 오른값이다. 그리고 TestKnight_ConstLValueRef이 함수는 인자로 왼값을 넣어줘야한다고 한다. 
	// 근데 const가 붙은 참조를 만들어 주게 되면 이런 오른값이라고 하더라도 받아준다
	// 오른 값이라 함은 결국엔 임시적으로만 만들어진 다음에 곧 소멸될 아이라는 그런 말이 되는건데 const를 안붙여 주게 되면 혹시라도 함수 내부에서 인자를 받은것으로 조작을 해봤자,
	// 사라질 거기 때문에 열심히 고치는것 자체가 헛짓거리가 된다 그래서 문법적으로 const를 붙여서 오른값을 받아줄수 있게끔 만들어졌다
	// 이렇게 하면 고치지않고 읽기 위한 용도로만 잠시 사용을 하는 것으로 생각이 든다 그래서 문법적으로 허용이 되는데 살짝 아쉬운 점음
	// const로 만들어주면 knight 이것과 관련된 정보들을 우리가 수정을 할수 없을 뿐더러 반드시 이제는 void PrintInfo() const 이런 식으로 const가 붙은 함수만 
	// 이제 또 호출할 수가 있다는 굉장히 불편한 상황이 된다

	// 근데 C++11에 오면서 오른값 참조를 받을수 있는 새로운 참조 방식이 생겼다
	// (rvalue reference)
	// 참조를 의미하는 앰퍼센트 두 개를 연달아 붙여서 사용한다.

	// 오른값의 참조값을 전달하게 되면 원본 자체를 건드릴 수 있게된다. 
	// 그 의미는 곧 더 이상 해당 원본은 사용하지 않을 예정이며 날려도 된다는 의미를 내포하고 있다. 
	// 쉽게 말해 이동 대상이 된다는 의미이다.

	// TestKnight_RValueRef(k1); // 오히려 왼값을 넣어서 오류가 난다
	// 오른값에 해당하는 임시 객체 전달
	TestKnight_RValueRef(Knight());
	// Knight()는 Knight 클래스의 기본 생성자를 호출하여 임시 객체를 만든다.
	// 타입 변환하여 전달 가능
	TestKnight_RValueRef(static_cast<Knight&&>(k1));
	// 이 코드는 기본생성자를 호출하지 않는다.

	Knight k2;
	k2._pet = new Pet();
	k2._hp = 1000;

	// 원본은 날려도 된다는 힌트를 주는 쪽에 가깝다
	Knight k3;
	// 오른값 참조로 넣어주기
	k3 = static_cast<Knight&&>(k2); // 이동대입 연산자가 호출
	// 이렇게 오른값 참조로 넘겨주면 k2는 더이상 버리는 애라고 우리가 힌트를 준게 되는거니까 
	// k3는 k2가 가진 모든 정보를 다 뺏어와서 그래서 펫을 그냥 자기가 뺏어올수가 있게 된다는 장점이 생김
	// 그러니가 복사를 하는 개념이 아니라 진짜로 이동을 하는 개념, 뺏어오는 개념에 더 가깝다고 볼수 있다

	// 복사가 되는거는 생각보다 양이 많아서 부담스러울 상황이 생길수 있는데 이동을 시키는 거는 상대방의 정보를 그냥 꺼내오는 거니까 더 빨리 동작을 할 확률이 높다

	// std::move
	// move 함수는 오른값 참조 캐스팅을 조금 더 편리하게 실행시켜주는 함수이다.rvalue_cast 의 의미에 가깝다.

	Knight k4;
	k4 = move(k3);  // 오른값 참조로 캐스팅
	// 위에 코드는 k3 = static_cast<Knight&&>(k2); 이 코드랑 똑같은 의미이다
	// k3를 오른값 참조로 캐스팅한 후에 k4로 이동시킨다음 k3의 펫 소유권을 박탈시키는 기능을 하게 될 것이다. (이동 대입 연산자 코드 참고)(k3를 널포인터로 밀어줬음)

	// unique_ptr은 오로지 하나만 존재하는 포인터를 의미한다. 고유한 값이기 때문에 복사가 불가능하다. 
	// 하지만 move를 이용하여 소유권을 계속 이전시키면 여러번 이동하며 해당 값을 유지할 수 있다.

	// 복사 불가
	unique_ptr<Knight> uptr = make_unique<Knight>();
	//unique_ptr<Knight> uptr2 = uptr; // error
	// 소유권 이전의 개념. 이동 후 uptr은 소멸된다.
	unique_ptr<Knight> uptr2 = move(uptr);

	return 0;
}