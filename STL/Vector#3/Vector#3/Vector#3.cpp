#include <iostream>
#include <vector>
using namespace std;

// 벡터(vector)3
// 벡터 구현해보기

template<typename T>
class Iterator {
public:
    Iterator() : _ptr(nullptr) {

    }

    Iterator(T* ptr) : _ptr(ptr) {

    }

    // ++ 연산자 오버로딩
    // 전위 연산자
    Iterator& operator++() {
        _ptr++;
        return *this;
    }

    // 후위 연산자
    Iterator operator++(int) {
        Iterator it = *this;
        _ptr++;
        return it;
    }

    // -- 연산자 오버로딩
    // 전위 연산자
    Iterator& operator--() {
        _ptr--;
        return *this;
    }

    // 후위 연산자
    Iterator operator--(int) {
        Iterator it = *this;
        _ptr--;
        return it;
    }

    // + 연산자 오버로딩
    Iterator operator+(const int count) {
        Iterator temp = *this;
        temp._ptr += count;
        return temp;
    }

    // - 연산자 오버로딩
    Iterator operator-(const int count) {
        Iterator temp = *this;
        temp._ptr -= count;
        return temp;
    }

    // == 연산자 오버로딩
    bool operator==(const Iterator& right) {
        return _ptr == right._ptr;
    }

    // != 연산자 오버로딩
    bool operator!=(const Iterator& right) {
        // return _ptr != right._ptr;
        return !(*this == right);
    }

    // * 연산자 오버로딩
    T& operator*() {
        return *_ptr;
    }
public:
    T* _ptr;
};

template<typename T>
class Vector {
public:
    Vector() : _size(0), _capacity(0) {

    }

    ~Vector() {
        if (_data) delete[] _data;
    }

    void push_back(const T& val) {
        if (_size == _capacity) {
            // 메모리 증설 작업
            int newCapacity = static_cast<int>(_capacity * 1.5);
            if (newCapacity == _capacity) newCapacity++;
            reserve(newCapacity);
        }
        // 여유공간이 있는 상태
        // 데이터를 저장할 수 있는 상태
        // 데이터 저장
        _data[_size] = val;
        // 데이터 개수 증가
        _size++;
    }

    void reserve(int capacity) {
        _capacity = capacity;

        T* newData = new T[_capacity];
        // 데이터 복사
        for (int i = 0; i < _size; i++)
            newData[i] = _data[i];
        // 기존에 있던 데이터를 날린다.
        if (_data) delete[] _data;
        // 교체
        _data = newData;
    }

    T& operator[](const int pos) { return _data[pos]; }

    int size() { return _size; }
    int capacity() { return _capacity; }

public:
    typedef Iterator<T> iterator; // 앞으로 Iterator<T>를 iterator라는 이름으로 부르기로 했습니다.


    void clear() { _size = 0; }
    iterator begin() { return iterator(&_data[0]); } // 0번째 데이터의 주소값을 넘겨준다
    iterator end() { return begin() + _size; }

private:
    T* _data;
    int _size;
    int _capacity;
};

int main()
{
    // vector<int> v;
    Vector<int> v;

    //v.reserve(100);

    for (int i = 0; i < 100; i++) {
        v.push_back(i);
        cout << v.size() << " " << v.capacity() << endl;
    }

    for (int i = 0; i < v.size(); i++)
        cout << v[i] << endl;

    cout << "--------------------------------------\n";

    // for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
    for (Vector<int>::iterator it = v.begin(); it != v.end(); ++it)
        cout << (*it) << endl;

    v.clear();

    return 0;
}
// 자신만의 클래스에서 계속 연습을 하는 것도 나쁘지 않은 방법이 될 겁니다
// 설명을 드리지는 않았지만 이 정도를 구현을 해서 충분히 벡터에 대한 이해도가 쌓였다고 하면
// 면접에 대해서도 충분히 준비가 되어 있는 거고 나머지 기능들은 왠지 이런 기능이 있지 않을까라는 의심을 가지면서 비점을 찍어봐주고 여기다가 하나씩 하나씩 살펴보면 됩니다