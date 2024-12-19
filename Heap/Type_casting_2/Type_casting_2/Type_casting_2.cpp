#include <iostream>
using namespace std;
// 타입 변환 #2

class Item
{
public:
    Item()
    {
        cout << "Item()" << endl;
    }

    Item(const Item& item)
    {
        cout << "Item(const Item&)" << endl;
    }

    ~Item()
    {
        cout << "~Item()" << endl;
    }
public:
    int _itemType = 0;
    int _itemDbId = 0;

    char _dummy[4096] = {}; // 이런 저런 정보들로 인해 비대해진 공간
};

void TestItem(Item item)
{

}
void TestItemPtr(Item* item)
{

}

int main()
{
    // 복습

    {
        // Stack { type(4) dbid(4) dummy (4096) }
        Item item;

        // Stack{ 주소(4~8) } => Heap 주소{type(4) dbid(4) dummy (4096)} 아이템에 대한 데이터는 힙 영역에 저장이 되어있다
        Item* item2 = new Item();

        TestItem(item);
        TestItem(*item2);

        TestItemPtr(&item);
        TestItemPtr(item2);
        // 여기에서 알수 있는것은 실질적으로 이렇게 포인터 혹은 참조를 넘겨줄때는 어떤 생성자나 소멸자가 따로 호출이 되는 것이 아니라 
        // 말 그대로 우리는 얘를 원격으로 뭔가 조작하거나 아니면 데이터만 빼낼수 있는 그럼 주소값을 넘겨준거기 때문에 아무런 부하없이 편하게
        // 참조를 할수 있다


        // 포인터가 아닌 일반형식으로 만들어 주게 되면 Item item; 얘가 없어지면서 소멸자를 호출해 주게 될것이다
        // 반면 포인터를 들고 있는 버전은 사실 원본 데이터가 지금 당장 안에 들어가 있는 개념이 아니라 원본은 저 멀리 어딘가에 있는 개념
        // 이기 때문에 Item* item2 이 아이같은 경우엔 생성자를 호출하지 않는다.
        // 주소값은 그냥 어떤 정수에 불과하지, 뭔가 데이터가 저장이 된게 아니기 때문이다

        // 메모리 누수(Memory Leak) -> 점점 가용 메모리가 줄어들어서 crash
        // 그걸 방지하기위해 delete를 쓴다
        delete item2;



        // 배열
        {
            cout << "------------일반----------" << endl;
            // 진짜 아이템이 100개 있는것 (스택 메모리에 올라와 있는)
            // 디버깅을 하면 이 버전은 생성자가 100개가 뜨는것을 볼수 있고
            Item item3[100] = {};

            cout << "--------------일반 -------------" << endl;

            // 아이템이 100개 있을까?
            // 아이템을 가리키는 바구니가 100개, 실제 아이템은 1개도 없을수 있음
            // 포인터 버전은 생성자가 아무것도 안뜨는것을 볼수 있다
            // 포인터는 있을수도 없을수도 있고 저 멀리 어딘가에 원격에다가 지금 가리키고 있는 개념이지 얘자체만 놓고보면
            // 실제 데이터가 있다는 보장이 없다는 얘기가 된다
            Item* item4[100] = {};

            // 포인터로 생성자 만드는 법
            for (int i = 0; i < 100; i++)
            {
                item4[i] = new Item();
            }

            cout << "-----------------------------" << endl;
            for (int i = 0; i < 100; i++)
            {
                delete item4[i];
            }

            cout << "-----------------------------" << endl;
        }




    }
}
