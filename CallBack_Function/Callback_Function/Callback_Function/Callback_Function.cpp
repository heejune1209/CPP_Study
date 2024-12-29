#include <iostream> // C++ 라이브러리

using namespace std;

class Item
{
public:

public:
    int _itemId = 0;
    int _rarity = 0;
    int _ownerId = 0;
};

// 함수 객체(Functor) 사용
class FindByOwnerId
{
public:
    bool operator()(const Item* item)
    {
        return (item->_ownerId == _ownerId);
    }
public:
    int _ownerId;
};

class FindByRarity
{
public:
    bool operator()(const Item* item)
    {
        return (item->_rarity >= _rarity);
    }
public:
    int _rarity;
};

// 템플릿 사용
template<typename T>
Item* FindItem(Item items[], int itemCount, T selector)
{
    for (int i = 0; i < itemCount; i++)
    {
        Item* item = &items[i];
        // TODO : 조건 체크
        if (selector(item)) // 클래스 객체를 받아서 함수 객체를 조건으로 사용
            return item;
    }

    return nullptr;
}

// 함수 포인터 #1에서 했던 버전
//typedef bool(ITEM_SELECTOR)(Item* , int);
//Item* Finditem(Item items[], int itemcount, ITEM_SELECTOR* selector, int value)
//{
//    for (int i = 0; i < itemcount; i++)
//    {
//        Item* item = &items[i];
//        if (selector(item, value))
//            return item;
//        // TODO 조건
//    }
//
//    return nullptr;
//}

int main()
{
    // 함수 포인터 + 함수 객체 + 템플릿
    // 콜백 : 다시 호출하다?
    // 게임을 만들때 이런 콜백의 개념이 많이 등장한다
    // ex) moveTask 실습 등

    // 어떤 상황이 일어나면 -> 이 기능을 호출해줘
    // ex) UI 스킬 버튼을 누르면  -> 스킬을 쓰는 함수를 호출

    // 콜백 함수(CallBack Function)이란, 쉽게 말해 함수의 생성 시점과 호출 시점이 달라 일반 함수와는 다른 호출 방법을 갖는 함수이다. 
    // 일반 함수는 호출하는 즉시 실행되지만 콜백 함수는 미리 등록해 둔 다음 추후에 호출할 수도 있고 바로 호출할 수도 있다는 차이점이 있다. 
    // 물론 함수의 생성 장소와 다른 외부에서도 호출이 가능하며 주로 특정한 이벤트가 발생할 때 호출된다. 
    // 함수 포인터, 함수 객체, 템플릿이 혼합된 개념이다.

    // 일반 함수는 클라이언트가 서버 측에 있는 함수를 가져와 호출하여 사용하는 반면, 
    // 콜백 함수는 클라이언트가 서버 측으로 함수를 전달하여 호출해달라는 의미라고 한다. 
    // 그래서 어떠한 상황(이벤트)이 일어났을 때 특정 기능을 호출해 준다는 상황이 성립된 것 같다.



    Item items[10];
    items[3]._ownerId = 100;
    items[8]._rarity = 2;

    FindByOwnerId functor1;
    functor1._ownerId = 100;

    FindByRarity functor2;
    functor2._rarity = 1;

    Item* item1 = FindItem(items, 10, functor1); 
    Item* item2 = FindItem(items, 10, functor2); 
    // 함수 포인터 #1 과 똑같은 상황으로 코드를 다르게 만들었다.
    // 이 스크립트에선 rarity 판정 기능과 ownerId 판정 기능을 클래스로 만들어서 함수 객체로 사용하였다.
    // 그때는 함수 포인터를 이용해서 코드를 작성했고, 이번엔 함수 객체와 템플릿을 이용해서 코드를 작성했다.

    // Item* rareitem = Finditem(items, 10, israretitem, 2); 함수 포인터#1 에서 했던 코드 버전
    // israretitem은 rarity를 찾아주는 함수이다

    // 약간 함수 포인터는 함수를 데이터처럼 썼던것 같고, 콜백함수에선 인자로 클래스 객체를 넘겨서, 넘긴 객체(아이템 찾는 판정 용도)를 함수 객체로 사용했다는 차이가 있다

    return 0;
}