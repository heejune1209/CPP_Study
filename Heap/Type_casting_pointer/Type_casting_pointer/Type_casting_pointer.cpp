#include <iostream>
using namespace std;

// 타입 변환 #2
class Knight
{
public:
    int _hp = 0;
};

class Item
{
public:
    Item()
    {
        cout << "Item()" << endl;
    }
    Item(int itemType) : _itemType(itemType)
    {
        cout << "Item(int itemType)" << endl;
    }

    Item(const Item& item)
    {
        cout << "Item(const Item&)" << endl;
    }

    virtual ~Item()
    {
        cout << "~Item()" << endl;
    }
    virtual void Test()
    {
        cout << "Test Item" << endl;
    }

public:
    int _itemType = 0;
    int _itemDbId = 0;

    char _dummy[4096] = {}; // 이런 저런 정보들로 인해 비대해진 공간
};
enum ItemType
{
    IT_WEAPON = 1,
    IT_ARMOR = 2
};

class Weapon : public Item
{
public:
    Weapon() : Item(IT_WEAPON)
    {
        cout << " Weapon()" << endl;
        _damage = rand() % 100;
    }

    virtual ~Weapon()
    {
        cout << "~Weapon()" << endl;
    }
    // 부모 클래스 내에서만 virtual을 설정해주어도 그대로 상속된다. 자식 클래스에 있는 아이들도 간접적으로 virtual을 붙인셈이 된다. 

    virtual void Test() // 재정의
    {
        cout << "Test Weapon" << endl;
    }
public:
    int _damage = 0;
};

class Armor : public Item
{
public:
    Armor() : Item(IT_ARMOR)
    {
        _itemType = 2;
        cout << "Armor()" << endl;
    }

    ~Armor()
    {
        cout << "~Armor()" << endl;
    }
public:
    int _defence = 0;
};

void TestItem(Item item)
{

}
void TestItemPtr(Item* item)
{
    item->Test();
}

int main()
{
    // 연관성이 없는 클래스 사이의 포인터 변환 테스트
    {
        // Stack [ 주소 ] -> Heap[_hp(4) ]
        Knight* knight = new Knight;

        // 암시적으로 NO
        // 명시적으로 YES

        // Stack [ 주소 ]
        /*Item* item = (Item*)knight;
        item->_itemType = 2;
        item->_itemDbId = 1;*/

        delete knight;

        // knight는 힙 영역에 생성된 Knight 클래스를 가리키는 주소이고 item은 스택 영역에서 knight의 주소를 담고 있다.

        // 현재 knight는 4바이트이고 item은 4000바이트 이상의 크기를 가지게 되는데 위처럼 강제 타입 변환 후 값을 변경시켜버리면 
        // 해당 범위를 벗어난 메모리의 값을 변경시키게 되는 위험성이 존재한다.
    }
    // 부모 -> 자식간의 변환
    {
        Item* item = new Item();

        // [ [item] ]
        // [ _damage ]
        //Weapon* weapon = (Weapon*)item;
        //weapon->_damage = 10;
        // 암시적으로 안되지만 이렇게 명시적으로 바꾸면 가능은 하지만 바꿨다고 해서 코드가 잘 동작하는건 아니고 잘못된 메모리를 건드리게 되는
        // 것이니까 굉장히 위험한 행동이다
        // 메모리 크기가 작은거에서 큰거로 이렇게 변환을 하려고 하면 이렇게 캐스팅 했다는 의미 자체는 weapon얘가 초과해서 엉뚱한 메모리를
        // 건드릴수 있다는 얘기가 된다

        delete item;
    }



    // 자식 -> 부모간의 변환
    {
        // [ [item] ]
        // [ _damage ]
        Weapon* weapon = new Weapon();

        // 암시적으로도 된다
        Item* item = weapon;
        TestItemPtr(item);

        delete weapon;
    }

    // 명시적으로 타입 변환 할때는 항상 조심해야한다!
    // 암시적으로 될때는 안전하다?
    // -> 평생 명시적으로 타입 변환(캐스팅)은 안하면 되는거 아닌가?

    // 암시적으로 자식 👉 부모 타입 변환이 적용된 상황이다.
    Item* inventory[20] = {};

    srand((unsigned int)time(nullptr));
    for (int i = 0; i < 20; i++)
    {
        int randValue = rand() % 2; // 0 ~ 1
        switch (randValue)
        {
        case 0:
            inventory[i] = new Weapon();
            break;
        case 1:
            inventory[i] = new Armor();
            break;
        }
    }
    // weapon과 armor를 두가지 상태를 다 만든다음 Item* 로 관리를 해주는 형태

    // 인벤토리에 들고 있는 목록을 출력하는 기능
    for (int i = 0; i < 20; i++)
    {
        Item* item = inventory[i];
        // 우린 위에서 아이템 20개를 다 만들어 놨으니까 여기서 없는 경우는 없겠지만, 일반적으로 이렇게 포인터를 다룰땐
        // 항상 item 얘가 있는지 없는지 널 체크해주는 습관을 길러야 한다
        if (item == nullptr)
            continue;


        if (item->_itemType == IT_WEAPON)
        {
            Weapon* weapon = (Weapon*)item;
            // 지금은 이 아이템이 가리키고 있는 것 자체가 진짜 아이템이 아니라 원래 원본자체가 weapon이었기 때문에 다시 웨폰으로 변환을 해도
            // 굉장히 안전한 것이지만
            // 혹시라도 만약에 원본이 웨폰이 아니라 다른 형태였다고 하면 이 문법은 굉장히 잘못된 타입변환이다

            cout << "Weapon Damage : " << weapon->_damage << endl;
        }
    }

    // 반대로 값을 꺼내와 확인 후 변환한다고 가정한다면 명시적으로 타입 변환을 해줘야 할 것이다. 
    // 위의 상황은 부모 👉 자식 방향의 타입 변환이지만 Weapon 클래스를 확실시 할 수 있으므로 나름 안전한 변환이라 볼 수 있다.

    //----------------------- 매우매우 중요 -----------------------------
    for (int i = 0; i < 20; i++)
    {
        Item* item = inventory[i];
        // 우린 위에서 아이템 20개를 다 만들어 놨으니까 여기서 없는 경우는 없겠지만, 일반적으로 이렇게 포인터를 다룰땐
        // 항상 item 얘가 있는지 없는지 널 체크해주는 습관을 길러야 한다
        if (item == nullptr)
            continue;

        delete item;
        // 디버깅을 해보면 delete를 할때 Item의 소멸자로만 지금 호출해 주고있는것을 볼수 있다
        // 이것이 굉장히 문제가 되는 것은 원래는 원본 객체 자체가 weapon이다 보니까 깔끔하게 정리가 되기 위해서는
        // 아이템의 소멸자만 호출이 되면 안되고, 무기의 소멸자가 먼저 호출이 되고 그 다음에 이어서 아이템의 소멸자가 호출이 되야 맞다

        /*if (item->_itemType == IT_WEAPON)
        {
            Weapon* weapon = (Weapon*)item;
            delete weapon;
        }
        else
        {
            Armor* armor = (Armor*)item;
            delete armor;
        }*/
        // 이것이 올바른 해결 방법이다

        // Item을 이용해서 delete를 할때는 소멸자가 weapon이나 armor의 것을 호출해주지 않았던 문제가 있는데
        // 그러면 왜 굳이 아이템의 소멸자를 호출하고 이렇게 원본의 타입을 이용해서 소멸자를 자동으로 불러주지 않을까?

        // 그러면 virtual을 사용하면 된다
        // virtual을 붙여주면 자동으로 자식의 함수를 호출시켜주는 걸 알 수 있었는데, 애당초 생성자나 소멸자도 결국엔 함수는 함수이다 보니까
        // 소멸자에도 똑같은 룰이 따르게 된다
        // 마찬가지로 상속 관계에 있는 클래스 내에서, 부모 소멸자 앞에 반드시 virtual을 붙여주어 
        // 자식 클래스의 소멸자도 호출되도록 해주어야 한다.

        // 즉 소멸자에도 virtual을 붙여주면 
        /*if (item->_itemType == IT_WEAPON)
        {
            Weapon* weapon = (Weapon*)item;
            delete weapon;
        }
        else
        {
            Armor* armor = (Armor*)item;
            delete armor;
        }*/
        // 이렇게 코드를 작성해줄 필요없이 delete item; 이렇게 써주기만 하면 우리가 원하는 대로 자식의 소멸자도 호출이 된다

        // 즉 부모 클래스의 소멸자에는 항상 가상함수 virtual을 붙여줘야하는것을 까먹으면 안된다
        // 그렇게 안하면 소멸자가 일부만 실행된다

        // [결론]
        // - 포인터 vs 일반 타입 : 차이를 이해하자
        // 포인터냐 일반 타입이냐에 따라서 메모리 구조의 차이가 있었다
        // 이 차이를 이해하는것이 매우 중요하다
        // 그리고 함수한테 넘겨줄때도 이렇게 복사방식으로 넘겨주는 것과 포인터 방식으로 넘겨주는것은 완전히 얘기가 다르다
        // 복사 방식으로 이렇게 넘겨주게 되면 사실상 이 아이도 어떻게 보면 생명체는 생명체이다 보니 복사 생성자를 호출하고 그리고 여기서 소멸자를
        // 다시 호출해줘 가지고 날리고 하는 그런 부분이 있었고 포인터로 할때는 그런부분이 사라지고 포인터는 말그대로 원격으로 조종하는 애이기 때문에
        // 살아있는 생명체로 인정을 안해주는 그럼 느낌이다


        // - 포인터 사이의 타입 변환(캐스팅)을 할 때는 매우매우 조심해야한다
        // 인벤토리 처럼 자식에서 부모타입으로 변환도 하고 다시 부모 타입에서 자식 클래스로 변환도 하고 이렇게 왔다갔다 하는 일이 자주 생기게
        // 될거라는 것을 기억해 주면 된다
        // 그리고 가장 중요한것은 부모 클래스의 소멸자에는 까먹지 말고 무조건 virtual을 붙이는것을 까먹으면안된다
        // 무조건 소멸자에는 virtual을 붙여야 된다고 공식 처럼 외우지 말고 이게 상속 관계에 의해가지고 함수를 재정리 해봤자 어떤 타입에 따라가지고
        // 누구가 어떤 한 애만 골라가지고 실행이 되기 때문에 virtual을 붙여주게 되면 가상함수 테이블이 만들어지게 되면서 실제 객체가 어떤애로
        // 만들어 졌냐, 즉 원본 자체가 뭐로 만들어졌냐에 따라가지고 그 함수를 찾아서 호출한다고 했었다
        // 이것을 얘기하는게 중요한것은 면접의 단골 주제이기 때문이다 10번중에 8번은 가상 소멸자에대한 내용이 꼭 나오게 된다
        // 그만큼 중요한 내용이고 C++의 기초가 잡혔느냐 하는 질문이다

    }



    return 0;

}