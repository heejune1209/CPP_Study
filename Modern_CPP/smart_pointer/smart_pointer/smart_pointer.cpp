#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <algorithm>

// 스마트 포인터
    // 스마트 포인터(Smart Pointer)는 포인터를 알맞은 정책에 따라 관리하는 객체를 의미하며 포인터를 래핑해서 사용한다. 
    // 우리가 이제껏 배워왔던 일반 포인터는 직접적으로 어떤 메모리를 읽거나 수정할 수 있어서 물론 잘 사용하면 편리하게 사용할 수 있지만 
    // 엉뚱한 메모리를 건드릴 수도 있다는 위험성이 존재한다. 
    // 이러한 실수는 한 번만 해도 프로그램이 뻗는 치명적인 결과를 낳게된다. 이러한 일들을 방지하기 위해서 스마트 포인터를 사용하는 것이 좋다.

    // 스마트 포인터에는 shared_ptr, weak_ptr, unique_ptr가 있다.

class Knight {
public:
    Knight() { cout << "Knight 생성" << endl; }
    ~Knight() { cout << "Knight 소멸" << endl; }

    // shared_ptr
    /*
    void Attack()
    {
        if (_target)
        {
            _target->_hp -= _damage;
            cout << "HP : " << _target->_hp << endl;
        }
    }
    */

    // weak_ptr
    void Attack() {
        if (_target.expired() == false) // false면 그 메모리가 유효하다
        {
            shared_ptr<Knight> sptr = _target.lock();

            sptr->_hp -= _damage;
            cout << "HP : " << sptr->_hp << endl;
        }
    }
public:
    int _hp = 100;
    int _damage = 10;
    // Knight* _target = nullptr;
    // shared_ptr<Knight> _target = nullptr;
    weak_ptr<Knight> _target;
};

// shared_ptr 구현해보기
// reference count 관리 -> 참조를 얼마나 하고있는지 확인하기 위해
// 참조를 아무도 하지 않을 때 삭제
class RefCountBlock
{
public:
    int _refCount = 1;
    // int _weakCount = 1;  // weak_ptr
};

template<typename T>
class SharedPtr
{
public:
    SharedPtr() { }
    SharedPtr(T* ptr) : _ptr(ptr)
    {
        if (_ptr != nullptr)
        {
            _block = new RefCountBlock();
            cout << "RefCount : " << _block->_refCount << endl;
        }
    }

    SharedPtr(const SharedPtr& sptr) : _ptr(sptr._ptr), _block(sptr._block)
    {
        if (_ptr != nullptr)
        {
            _block->_refCount++;
            cout << "RefCount : " << _block->_refCount << endl;
        }
    }

    void operator=(const SharedPtr& sptr)
    {
        _ptr = sptr._ptr;
        _block = sptr._block;

        if (_ptr != nullptr)
        {
            _block->_refCount++;
            cout << "RefCount : " << _block->_refCount << endl;
        }
    }

    ~SharedPtr()
    {
        if (_ptr != nullptr)
        {
            _block->_refCount--;
            cout << "RefCount : " << _block->_refCount << endl;

            if (_block->_refCount == 0)
            {
                delete _ptr;
                delete _block;
                // weak_ptr에서는 _block 삭제 X
                cout << "Delete Data" << endl;
            }
        }
    }
public:
    T* _ptr = nullptr;    // 원본 객체의 포인터
    RefCountBlock* _block = nullptr;
};

int main()
{
    // Knight* k1 = new Knight();
    // Knight* k2 = new Knight();

    // k1->_target = k2;

    // delete k2;

    // k1->Attack(); // delete를 해주고 실행해보면 크래쉬는 나지 않고 실행은 되는데 우리가 지금 엉뚱한 메모리를 지금 고치고 있는걸 볼수 있다
    // k1이라는 애가 타겟으로 k2를 바라보고 있는 상태에서 그 객체를 날려줬기 때문에 이런 상황이 발생한것

    // 스마트 포인터 : 포인터를 알맞은 정책에 따라 관리하는 객체 (포인터를 래핑해서 사용)
    // shared_ptr, weak_ptr, unique_ptr     // 언리얼 엔진에도 똑같이 들어가있음
    // 스마트 포인터를 사용하면 알아서 메모리를 날려준다. -> delete 할 필요 없음

    // shared_ptr (대표적)
    // shared_ptr는 참조 정보를 관리하고 객체의 생명 주기를 자동으로 관리해주는 포인터이다.
    // 참조 카운트를 관리하며 해당 포인터가 가리키는 객체를 다른 포인터들이 얼마나 참조하고 있는지 확인하기 위한 용도로 카운트 정보를 담고 있다.
    // 참조 카운트가 0이 되면 메모리 해제를 고려한다.


    SharedPtr<Knight> k4; // k4는 빈상태이다
    {
        SharedPtr<Knight> k3(new Knight()); // 이제는 이 Shared PTR이 나이트를 관리하는 그런 주체가 되었다고 볼 수가 있겠습니다
        k4 = k3; // 복사대입 연산자로 실행됨
    }

    // 그래가지고 이렇게 스마트 포인터로 관리를 하는 순간 우리가 명시적으로 이 객체를 delete 해줄 필요가 없어지고 
    // 뭔가 자동으로 이 Shared PTR라는 객체 자체가 내부적으로 특정 조건을 만족하면 즉 여기서는 이제 아무도 얘를 기억하지 않을 때였죠.
    // 이렇게 될 때 장점은 이제는 메모리 관리에서 어떻게 보면 벗어나게 되는 거죠 알아서 이제가 필요 없게 되면은 알아서 메모리를 날려준다는 장점이 생긴다

    // make_shared : 메모리 블록을 한 번에 만들어줘서 new 객체 생성보다 훨씬 성능이 좋다.
    // k5(new Knight()); 와 같은 의미
    shared_ptr<Knight> k5 = make_shared<Knight>();
    {
        shared_ptr<Knight> k6 = make_shared<Knight>();
        k5->_target = k6; // 그 다음에 K5가 이제는 이 타겟 자체를 이런 식으로 스마트 포인트로 주시를 하게 된다
        // k6->_target = k5;    // 사이클 발생시 삭제가 되지 않는 문제 발생

        // 해당 포인터를 사용하면 범위가 작아 원래라면 소멸될 객체도 누군가가 참조를 하고 있다면 소멸되지 않는 특징이 있다. 
        // 단, 사이클 발생시 삭제가 되지 않는 문제가 발생하게 된다.
        // 서로의 존재를 서로 기억하고 있기 때문.

        // 소멸 전에 nullptr로 밀어주는 부분이 필요하다.
        // k5->_target = nullptr;
        // k6->_target = nullptr;
    }
    // k6라는 애를 명시적으로 지금 삭제를 한다 하더라도 , 누군가가 k6를 기억하고 있어서 k6가 사라지지 않고 남아있다. -> k5가 가리키고 있기 때문
    // 괄호 밖에 나와도 k5는 아직까지 메모리가 잘 살아 있다. 그래서 k5->Attack();이것이 별 문제없이 통과된다
    // 즉 내가 이 나이트를 기억하고 있기 때문에 너가 멋대로는 사라질 수가 없고 
    // 반드시 아무도 기억을 하지 않을 때에 돼서야 너는 사라질 수 있다는 그런 어마어마한 효과를 볼 수가 있는 것이다
    // 이렇게 하면은 아까 발생했던 그 엉뚱한 메모리를 이미 날라간 메모리를 참조하는 dangling 문제 혹은 use after free와 같은 문제들에 대해서 
    // 일단은 어느 정도 자유로워지게 된다는 장점이 생김
    // 이것이 shared_ptr의 장점이다
    k5->Attack();

    // weak_ptr : 객체가 날라갔는지 유무를 확인 .expired() == false면 유효
    // .lock() -> shared_ptr 반환
    // 객체가 날라갔는지 유무를 확인하게 되고 경우에 따라 shared_ptr를 반환해줘서 사이클 발생 같은 문제를 막아줄 수 있다.

    // weak_ptr을 쓰면 생명주기에서 자유로워 진다는 장점이 생김. 근데 단점은 expired로 명시적으로 체크를 한다음에 
    // 다시 shared_ptr로 전환하는 과정이 필요하기때문에 귀찮아진다

    // expired : 해당 객체가 날라갔는지 확인. 아직 있으면 false를 반환한다.
    // lock: 해당 객체의 shared_ptr 타입을 반환한다.

    // unique_ptr :  말 그대로 한 객체를 오로지 자기 자신만 가리키고 있어야 하는 포인터이다. 중복으로 가리키는 건 불가능하나 오른값 참조를 이용해 이동 연산은 가능하다.
    unique_ptr<Knight> uptr = make_unique<Knight>();
    // unique_ptr<Knight> uptr2 = uptr; // 불가능
    unique_ptr<Knight> uptr2 = move(uptr);  // 오른값 참조 캐스팅

    return 0;
}
