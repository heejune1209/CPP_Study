#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

// override, final

class Creature
{
public:
    virtual void Attack()
    {
        cout << "Creature!" << endl;
    }
    // 사실 여기서 virtual을 붙여놀으면 자기 자손들이건 손자건 누구던간에 꼭 virtual을 사용하지 않는다 하더라고 
    // 기본적으로 같은 이름의 같은 시그니처 함수도 가상함수로 작동을 하게된다
};

class Player : public Creature
{
public:
    virtual void Attack() override // 그래서 상속하는 클래스들이 많아지고 재정의하는 함수들이 많아지면 어디서 가상함수를 처음으로 썻는지 알기 쉽지 않으니까
        // override를 붙여줘서 재정의 하고 있다고 알려준다
    {
        cout << "Player!" << endl;
    }

    //// 나를 끝으로 더이상 재정의하지 않겠다.
    //virtual void Attack() final 
    //{
    //    cout << "Player!" << endl;
    //}

};

// final
// final은 override와 마찬가지로 재정의에 대한 상태를 나타내는데, 
// 단어 뜻 그대로 이번 재정의를 끝으로 더이상 재정의를 허락하지 않겠다는 의미이다.
// 혹여나 나를 상속받는 자식 클래스가 생긴다면, 자식 클래스에선 final이 붙은 함수를 더이상 재정의하지 못한다.


class Knight : public Player
{
public:
    // override를 붙여줌으로써 Player로부터 해당 함수를 상속 받아
    // 재정의 하고 있다는 사실을 알 수 있다.
    // 그리고 내가 크리처의 Attack이라는 가상함수를 사용하고 있구나 라는 것을 힌트를 주기 때문에 가독성도 좋아진다
    // 참고로 프로그래머들은 이것을 다 붙여주고 있다
    virtual void Attack() override
    {
        cout << "Knight!" << endl;
    }

    // 오버로딩(overloading) : 함수 이름의 재사용
    /*void Attack(int a)
    {

    }*/

    // 만약 함수명 뒤에 const 를 붙이면?

    // 재정의 성립 안 됨
    // readonly 가 된다
    //virtual void Attack() const 
    //{
    //    cout << "Knight!" << endl;
    //    // _stamina = 10;   // 불가능

    // 해당 함수처럼 const가 붙게 되면 해당 함수 내에서 아무것도 수정할 수 없다는 의미이다. 
    // 그리고 const를 붙임으로써 부모 클래스의 Attack 함수와 시그니처가 달라지므로 둘은 재정의 된 관계가 아닌 각자 다른 별개의 멤버 함수라고 볼 수 있다.

private:
    int _stamina = 100;
};

int main()
{
    // override
    // override는 상속받은 클래스 사이에서 부모의 멤버 함수를 자식이 그대로 물려받아 재사용 한다는 의미를 나타내는 문법이다. 
    // 그냥 재정의 해도 상관없지만 그렇게 되면 어디서부터 시작인지 알기가 힘들기 때문에 
    // 가독성은 높이고 에러 발생은 줄이기 위해 함수의 이름 뒤에 override를 붙여 관리한다.

    Knight* knight = new Knight();

    knight->Attack();

    Player* player = new Knight(); // 상속관계만 잘 유지가 된다면 기사를 플레이어로, 자기 부모 클래스의 포인터 타입으로 캐스팅 해서 저장을 할수 있었다는걸 알수가 있었다

    player->Attack(); // 이렇게 하면 virtual을 썼기 때문에 "Knight!"이 출력되는것을 알수 있다

    return 0;
}