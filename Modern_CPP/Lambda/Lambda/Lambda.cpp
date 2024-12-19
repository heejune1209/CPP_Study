#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

// 람다
// 함수 객체를 빠르게 만드는 문법

enum class Itemtype
{
	None,
	Armor,
	Weapon,
	Jewelry,
	Consumable

};

enum class Rarity
{
	Common,
	Rare,
	Unique
};

class Item
{
public:
	Item()
	{

	}

	Item(int itemid, Rarity rarity, Itemtype type) : _itemid(itemid), _rarity(rarity), _type(type)
	{

	}

public:
	int _itemid = 0;
	Rarity _rarity = Rarity::Common;
	Itemtype _type = Itemtype::None;

};

int main()
{
	vector<Item> v;
	v.push_back(Item(1, Rarity::Common, Itemtype::Weapon)); // push_back에 커서를 갖다 대면 Item&&, 즉 오른값으로 받아주고있는걸 볼수가 있다
	v.push_back(Item(2, Rarity::Common, Itemtype::Armor));
	v.push_back(Item(3, Rarity::Rare, Itemtype::Jewelry));
	v.push_back(Item(4, Rarity::Unique, Itemtype::Weapon));

	// 람다 자체로 C++11에 새로운 기능이 들어간 것은 아니고 일종의 익명 함수(이름이 지어지지 않은 함수)라고 볼 수 있다.
	{
		// Functor 이용
		struct IsUniqueItem
		{
			bool operator()(Item& item)
			{
				return item._rarity == Rarity::Unique;
			}
		};

		/*auto findIt = find_if(v.begin(), v.end(), IsUniqueItem());
		if (findIt != v.end())
			cout << "아이템 ID : " << findIt->_itemid << endl;*/
			// 사실 이 조건을 딱 이렇게 찾을때 딱 한번만 쓰고 얘는 평생 다시 안쓸것임에도 불구하고 이런 식으로 매번마다 struct나 class를 만들어 준 다음에 
			// 뭐 operator로 오버로딩 하고 하는 부분이 너무너무 귀찮죠
			// 람다를 이용하면 쉽게 함수객체를 만들수 있다

			// 람다 표현식(Lambda Expression)
			// [캡처](인자값) {구현부}
			// 함수 객체가 필요한 부분에 조금 더 간편하게 구현할 수 있는 장점이 있다.

			// 기존의 함수 객체를 이용하면 비록 한 번만 사용하더라도 구조체를 만들어 지정을 해줬어야 했는데, 람다 표현식을 사용하면 한 줄로 구현이 가능하다.

			// 람다 이용
		auto isUniqueLambda = [](Item& item) { return item._rarity == Rarity::Unique; }; // isUniqueLambda 람다객체이다
		// 위 코드 자체가 위에 struct로 구현된거랑 똑같다고 생각하면됨

		auto findIt = find_if(v.begin(), v.end(), isUniqueLambda);
		if (findIt != v.end())
			cout << "아이템 ID : " << findIt->_itemid << endl;

		/*auto findIt = find_if(v.begin(), v.end(), [](Item& item) { return item._rarity == Rarity::Unique; });
		if (findIt != v.end())
			cout << "아이템 ID : " << findIt->_itemid << endl;*/
			// 이렇게 한번에 일회성으로 활용할것이라면 이렇게 해도된다

			// 반환 타입 설정
			// 반환 타입 추가
			//auto isUniqueLambda = [](Item& item) -> int { return item._rarity == Rarity::Unique; }; // 이렇게 하면 int를 뱉어준다

			// 여기서 isUniqueLambda는 클로저(closure)라고도 부른다. 
			// 람다에 의해 만들어진 실행 시점 객체를 의미한다. find_if에 람다식을 바로 넣을 수도 있다. 
	}

	{
		struct FinditemByItemid
		{
			FinditemByItemid(int itemid) : _itemid(itemid)
			{

			}
			bool operator()(Item& item)
			{
				return item._itemid == _itemid;
			}

			int& _itemid;
		};

		//int itemid = 4;

		//auto findByItemIdLambda = [&](Item& item) { return item._itemid == itemid; }; // 값 복사 방식, 캡처모드, 이 코드의 의미가 위에 struct에 구현해놓은 코드들의 기능과 똑같다
		//itemid = 10;

		////auto findIt = find_if(v.begin(), v.end(), FinditemByItemid(itemid)); // 일반 함수 객체 방법
		//auto findIt = find_if(v.begin(), v.end(), findByItemIdLambda);
		//if (findIt != v.end())
		//	cout << "아이템 ID : " << findIt->_itemid << endl;

		// 우리가 일반적인 함수 객체가 함수 포인터에 비해서 큰 장점이 있다고 했었는데 
		// IsUniqueItem 이것은 어떤 객체이다 보니까 데이터를 저장할수 있는 용도로도 활용할수가 있다
		// 즉 함수 객체를 이용하게 되면 그냥 하나의 함수만 뿅 실행하는 게 아니라 이렇게 우리가 원하는 데이터도 넣어줄수 있다는 장점이 있었다

		// 근데 람다로도 편리하게 넣어줄수 있다

		// 캡처 모드
		// 람다식의 대괄호 [ ]에 들어가는 부분을 캡처라고 한다. 해당 부분은 사진을 캡처 하듯, 
		// 일종의 스냅샷을 찍는다고 이해하면 편하며 함수 객체 내부에 변수를 저장하는 개념과 유사하다.
		// 외부에 있는 변수를 사용할 수 있는데, 캡처 부분에서 값을 어떻게 가져올건지 방식을 정해줄 수 있다
		// 기본 캡처 모드 :
		// = : 값 복사 방식
		// &: 값 참조 방식

		// 위의 코드가 있다고 가정했을 때, 값 복사 방식을 사용하게되면 람다식 뒤에 itemId를 10으로 바꿨다 해도 이미 4가 저장되어 변하지 않는다. => 아이템 ID : 4 가 출력됨 
		// 반면에 참조 방식을 사용하게되면 itemId의 참조 주소값을 가지고 있기 때문에 람다식 이후에 값이 변경되면 변경된 값을 가리키게 된다. 
		// => 그래서 10번을 찾아달라해서 못찾아서 출력을 못해준다

		// 그리고 해당 캡처 부분의 방식 중엔 위처럼 =, & 를 통해 모든 변수를 통틀어 관리할 수 있기도 하지만 변수 하나하나씩 방식을 지정해줄 수도 있다.
		// 전자처럼 이렇게 [=], [&] 한데 묶어 관리하는 방식은 지양해야 하며 변수가 많더라도 하나씩 지정해주는 방식이 더 선호된다.

		int itemId = 4;
		Rarity rarity = Rarity::Unique;
		Itemtype type = Itemtype::Weapon;

		auto findItemLambda = [&itemId, rarity, type](Item& item)
			{
				return item._itemid == itemId && item._rarity == rarity && item._type == type;
			};

		auto findIt = find_if(v.begin(), v.end(), findItemLambda);

		if (findIt != v.end())
			cout << "아이템 ID : " << findIt->_itemid << endl;

		// 변수마다 캡처 모드를 지정해서 사용이 가능하다.
		// [변수명] : 값 복사 방식
		// [&변수명] : 값 참조 방식

		// 여기서 isUniqueLambda는 클로저(closure)라고도 부른다. 
		// 람다에 의해 만들어진 실행 시점 객체를 의미한다. find_if에 람다식을 바로 넣을 수도 있다. 

	}

	{

		// 참조 방식으로 할 때도 얘는 어떤 주소값을 넘기는 거다 보니까 조심해서 사용해야 되겠구나라는 걸 이제 확실히 알 수 있는 거죠
		// 이렇게 주소값을 넘겼다는 의미는 애당초 만약에 이 메모리 자체가 날라가게 되면 사실 이 주소값은 더 이상 사용을 하면 안 되는 상태가 발생할 수 있는 거기 때문에 
		// 이렇게 람다 캡쳐를 할 때는 굉장히 조심해서 얘를 활용을 해야 된다는 그런 견해를 얻을 수가 있어요
		// 사실상 구조페로 만들어서 일반 함수 객체로 했을때도 마찬가지지만 우리가 어떤 참조값을 넘겨준다는 거는 
		// 우리가 이 find 아이템을 사용할 때까지 우리가 처음에 넘겨준 참조값이 계속 유효해야 된다는 어떻게 보면
		// 보장을 해줘야지만 이게 말이 되는 거고 만약에 그 메모리가 어떤 이유로 날아갔다고 하면 이제 코드가 어떻게 동작하게 될지 예측을 못하는 엄청난 무서운 일이 발생할 수도 있겠죠
		// 주소값을 다루는 거는 항상 그렇게 조심을 해야 됩니다 
		// 근데 그것뿐만 아니라 만약에 우리가 모든 애들을 다 복사 방식으로 넣어 준다고 해도 사실 예측하지 못한 상황에서 버그가 발생할 확률도 있어요

		// 만약 ResetHpJob이 실행되자마자 HP를 세팅하는게 아니라 나중에 실행될수 있게끔 어떤 함수 객체로 만들어서 전달해주고 싶은 상황이 발생했다고 가정해보자

		// 주의할 점
		// 람다는 호출되는 범위 내에 존재하는 모든 변수들을 캡처할 수 있다. 
		// 클래스 멤버 함수 내에서 선언되면 this 포인터를 켑처할 수 있는데, 외부에서 호출할 때 문제가 발생할 수 있다.

		class Knight
		{
		public:
			auto ResetHpJob()
			{
				auto f = [this]() // auto f = [=]() 이렇게 만들어줬다고 해도 모든게 다 안전하게 동작한다는 보장이 없다. this이렇게 써주므로서 위화감을 들게 해준다
					{
						this->_hp = 200; // delete k;를 해준다음 job(); 부분에 breakpoint를 해줘서 살펴보면 this는 이미 날라가있다, 즉 메모리가 오염되어있음
					};

				return f;
			}

		public:
			int _hp = 100;
		};

		Knight* k = new Knight();
		auto job = k->ResetHpJob();
		delete k;
		job(); // 딜리트로 나이트가 날라간다음 실행하면 당연히 문제가 생김

		// 위와 같은 코드가 있다고 가정했을 때, 람다식이 Knight의 멤버 함수 ResetHpJob 내부에서 선언되어있는 상태다. 
		// 람다식은 수행 시점과 선언 시점이 달라 위처럼 구현할 수 있는 것이다.

		// 하지만 클래스 외부에서 객체를 만들고, 함수 실행문도 따로 저장해둔 다음 객체를 삭제한 후 함수를 실행시키면 
		// 이미 없어진 객체를 가리키는 람다식 내의 this가 전혀 상관없는 메모리를 가리키게 된다.
		// 이렇게 되면 메모리 오염이 발생하게 되는것이다.

		// 이렇게 람다식을 사용할 때는 시점이 바뀌면서 유효함이 사라지지 않는지 신중하게 생각하고 구현해야 위 같은 에러를 방지할 수 있다.
		// 해당 에러는 바로 알기가 힘들어 시간이 지난 후에 크래시가 날 확률이 높다.

		// 결국에는 C++에서 람다를 사용할때는 기본적으로 기본 캡처모드 그러니까 모든 애들을 값복사 방식으로 하거나 참조방식으로 하겠다라는 이 문법 자체를 최대한 지양하라고 한다
		// 함수 객체 자체에다가 this를 넘겨주는데 이 나이트가 소멸되면 어떡하지? 라는게 눈에 보인다

		// 근데 핵심적으로 만약에 어떤 람다 객체를 외부로 넘기고 그럴게 아니라고 하면은 사실 기본캡처 모드를 한다고 크게 문제가 될 부분은 없다
		// 근데 결국에는 이 lambda 문법이 굉장히 굉장히 쿨한 게 뭐냐면 이런 식으로 매번마다 struct나 class를 만들어가지고 functor를 만들어주고 인자를 저장하고 
		// 그 인자를 사용하고 이런 부분들을 다 생략해도 된다는 엄청난 장점이 생겨드는 거죠
	}

	return 0;
}