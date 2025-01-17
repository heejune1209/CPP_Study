#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

// enum class 
// 이런 기본 enum을 Unscoped Enum(범위 없는)이라고 이제 부릅니다
enum PlayerType // : char // 만약 1바이트로 만들어줘 라고 하면 이렇게 써주면 된다
{
    // None,    // 중복 사용 불가
    PT_Knight,
    PT_Archer,
    PT_Mage
};
// 이런식으로 아무것도 건드려 주지 않으면 얘는 기본적으로 4바이트. int로 잡힘

enum MonsterType
{
    // None,    // 중복 사용 불가
};

// enum class
enum class ObjectType : int
{
    Player,
    Monster,
    Projectile
};

// 이름 중복 사용 가능
enum class ObjectType2
{
    Player,
    Monster,
    Projectile
};
// 익명 열거형
enum
{
    DIR_COUNT = 4,
    MAX_HP = 100,
    MAX_MP = 50
};


int main()
{
    // enum class (Scoped Enum)
    // 1) 이름공간 관리 (scoped)
    // 2) 암묵적인 변환 금지

    PlayerType t;
    cout << sizeof(t) << endl; // 4바이트

    cout << sizeof(PlayerType) << endl; // 4바이트
    // 일반 열거형인 enum에 클래스가 붙은 열거형이다. 
    // 일반 열거형은 Unscoped Enum, 범위가 없는 열거형이며 지정한 이름을 다른 열거형에서 중복으로 사용할 수 없다. 
    // enum class는 이름의 공간이 한정적이어서 중복 사용이 가능하다.

    // 대신에 사용할 때 클래스 명을 반드시 붙여줘야한다.
    ObjectType::Player;

    // 또한 enum class는 암묵적인 변환이 금지된다. 
    // 일반 열거형은 타입을 따로 지정해주지 않으면 자동으로 int 타입으로 세팅되지만 enum class는 사용할 때 타입 변환을 반드시 해줘야한다. 
    // 경우에 따라 장점이 될 수도 있지만 단점이 될 수도 있다.

    double value = PT_Knight; // 가능(일반 enum)
    //double value2 = ObjectType::Player; // 불가능
    double value2 = static_cast<double>(ObjectType::Player);
    // 이러한 점은 코드가 길어진다는 단점을 가진다.

    int choice;
    cin >> choice;

    if (choice == static_cast<int>(ObjectType2::Monster))
    {
        cout << "yyy" << endl;
    }

    unsigned int bitFlag;
    bitFlag = (1 << static_cast<int>(ObjectType::Player));

    // 이름이 없는 Enum도 있다 그것을 익명 열거형이라고 하는데 이것은 일반적으로 간단한 상수 값을 정의하는데 사용되고, 
    // 특정한 타입 이름없이 전역 상수처럼 동작한다. (별도의 네임스페이스 없이 접근 가능)
    cout << "DIR_COUNT: " << DIR_COUNT << endl;
    cout << "MAX_HP: " << MAX_HP << endl;
    cout << "MAX_MP: " << MAX_MP << endl;

    // 그리고 추가로 Enum을 사용할때 이름이 있는 경우 특정 타입으로 변수 선언이 가능하다.
    PlayerType t1 = PT_Archer; // t1에 PT_Archer(1)을 대입

    return 0;
}