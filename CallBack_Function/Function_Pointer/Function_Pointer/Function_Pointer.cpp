#include <iostream>
using namespace std;

// 함수 포인터

// 함수 포인터(Function Pointer)는 함수를 데이터 타입으로 가지는 포인터를 의미한다.
// 이전 시간에 배웠던 포인터는 일반적인 변수의 주소값을 담고 있었다. 함수 포인터는 함수의 시작 주소를 담으며, 
// 함수의 이름은 함수의 시작 주소를 의미한다.(배열과 유사하다.)

// 함수 포인터 선언은 다음과 같다.

// [반환 타입](함수 포인터 이름)(인자)

// 보통은 길기 때문에 typedef를 이용하여 이름을 따로 지정해줄 수 있다.
// typedef [반환 타입] (함수 포인터 이름)(인자);

// 사용하는 이유
// 여러 줄의 코드를 한 번에 관리할 수 있다.
// 수를 중복 호출하는 코드가 있을 때, Add 함수를 사용하다 Sub 함수로 변경하려면 여러 줄의 코드를 일일이 수정해야한다는 문제점이 있다. 
// 함수 포인터를 사용하면 포인터를 지정한 한 줄만 변경함으로써 여러 줄의 코드를 한 번에 변경할 수 있다.
int Add(int a, int b)
{
	return a + b;
}

int Sub(int a, int b)
{
	return a - b;
}

class Item
{
public:
	Item() : _itemid(0), _rarity(0), _ownerid(0)
	{

	}
public:
	int _itemid; // 아이템을 구분하기 위한 id
	int _rarity; // 희귀도
	int _ownerid; // 소지자 id
};
//Item* FinditemByrarity(Item items[], int itemcount, int rarity)
//{
//	for (int i = 0; i < itemcount; i++)
//	{
//		Item* item = &items[i];
//		if (item->_rarity == rarity)
//			return item;
//	}
//
//	return nullptr;
//}
//Item* FinditemByitemId(Item items[], int itemcount, int itemid)
//{
//	for (int i = 0; i < itemcount; i++)
//	{
//		Item* item = &items[i];
//		if (item->_itemid == itemid)
//			return item;
//	}
//
//	return nullptr;
//}

// 즉 다시 요약을 해보면 우리가 원하는 인자를 받을 함수를 이렇게 만들어 준 다음에 이름을 푹 떼어 준 다음에 요렇게 괄호를 만들어 준 게 사실 이 함수의 타입이라고 했었습니다
// bool isrartitem(Item* item) -> bool()(Item* item) => 이렇게 만든것이 함수의 타입
// typedef bool(ITEM_SELECTOR)(Item* item) => typedef 문법으로 이렇게 만들어 줄수 있다고 했었다
// ITEM_SELECTOR 라는것 자체가 함수의 시그니처 타입을 정의하고 있으니까 불리언을 반환 해주고 아이템 포인터를 받아주는 모든 함수들을 다 ITEM_SELECTOR라는 타입으로 인정을 해주게 된다
// 그러면 아래의 함수를 Item* Finditem(Item items[], int itemcount, bool(*selector)(Item* item)) 이렇게 써도 되지만,
// Item* Finditem(Item items[], int itemcount, ITEM_SELECTOR* selector) 이렇게 써도 된다

// 중요한것은 어떤 함수의 형태를 만들어준 다음에, 그 함수에 주소를 받아주는 함수 포인터 형태로 일단 인자로 만들어 줬다는 게 굉장히 중요.

typedef bool(ITEM_SELECTOR)(Item*, int);

Item* Finditem(Item items[], int itemcount, ITEM_SELECTOR* selector, int value)
{
	for (int i = 0; i < itemcount; i++)
	{
		Item* item = &items[i];
		if (selector(item, value))
			return item;
		// TODO 조건
	}

	return nullptr;
}
// 이렇게 반복적인 코드가 많아지면 코드의 유지 보수성도 굉장히 떨어지고 버그가 일어날 확률도 당연히 높아진다
// 그래서 함수 포인터를 이용하면 우리가 어떤 함수를 사용할것인지를 골라줄수 있게 된다는 거니까 
// 동작 자체를 어떻게 보면 이 함수의 인자로도 넣어줄수 있다는 얘기가 된다

// 원래라면 조건대로 함수를 중복 생성해야 하지만 함수 포인터를 사용하면 해당 인자를 받는 함수 하나로 
// 여러 개의 조건문을 포함한 함수를 만들 수 있게 된다.

bool israretitem(Item* item, int value)
{
	return item->_rarity >= value;
}

bool isOwnerItem(Item* item, int ownerid)
{
	return item->_ownerid == ownerid;
}
// 근데 이 함수는 ITEM_SELECTOR의 형식과 호환이 되어야하는데 isOwnerItem엔 인자가 하나 더 추가되었기 때문에 Finditem에 넣어줄수 없게 된다
// 만약에 적용을 시키고 싶다면 typedef bool(ITEM_SELECTOR)(Item* , int); 이렇게 시그니처를 맞춰주고 Finditem에도 시그니처를 같이 호환이 되게 추가하고 
// israretitem에도 인자를 하나더 추가해야한다

int main()
{
	int a = 10;

	// 바구니 주소
	// pointer[ 주소 ] -> 주소 [   ]

	// 1) 포인터    : *
	// 2) 변수 이름 : pointer
	// 3) 데이터 타입 : int  

	typedef int DATA; // 이렇게 타입을 정해서 적용할수 있었음
	DATA* pointer = &a;

	// 함수
	typedef int(FUNC_TYPE)(int a, int b); // (int , int ) 이렇게 써도됨

	// 1) 포인터 : *
	// 2) 변수 이름   fn
	// 3) 데이터 타입 : 함수(인자는 int , int 반환은 int)
	FUNC_TYPE* fn;

	// 함수 포인터
	fn = Add;

	// 함수의 이름은 함수의 시작 주소 (배열과 유사)
	int result = fn(1, 2); // 기본 문법 버전
	cout << result << endl;

	int result2 = (*fn)(1, 2); // 함수 포인터는 *(접근 연산자) 붙어도 함수 주소! , 이렇게 써도 위에 기본 문법 버전과 똑같다
	cout << result2 << endl;
	/*
	fn = Sub;

	// 함수의 이름은 함수의 시작 주소 (배열과 유사)
	int result = fn(1, 2); // 기본 문법 버전
	cout << result << endl;

	int result = (*fn)(1, 2); // 함수 포인터는 *(접근 연산자) 붙어도 함수 주소! , 이렇게 써도 위에 기본 문법 버전과 똑같다
	cout << result << endl;
	*/ // 이렇게 sub이라는 함수를 사용하고 싶다면 fn = Sub;이랗게만 바꿔줘도 사용할수 있게된다

	Item items[10] = {};
	items[3]._rarity = 2; // RARE
	Item* rareitem = Finditem(items, 10, israretitem, 2); // 함수에 어떤 함수를 인자로 받는다


	return 0;
}