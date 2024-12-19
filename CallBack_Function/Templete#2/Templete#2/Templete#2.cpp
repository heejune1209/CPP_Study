#include <iostream> // C++ 라이브러리

using namespace std;

// 클래스 템플릿
// 함수 템플릿과 사용 방법이 동일하다. 사용할 클래스 템플릿 위에 문법을 작성해주면 된다. 

// typename T를 붙이면 '조커 카드' (어떤 타입도 다 넣을수 있음)  
// typename을 붙이면 어떤 타입도 다 넣을 수 있다. 그런데 무조건 typename을 붙여야 하는 것은 아니다. 기본 타입을 설정할 수도 있다.
template<typename T, int SIZE>
class RandomBox
{
public:
    T GetRandomData()
    {
        int idx = rand() % SIZE;
        return _data[idx];
    }
public:
    T _data[SIZE];
};

// 탬플릿 특수화
//클래스 템플릿도 함수 템플릿과 마찬가지로 특수적인 상황에 대한 예외 처리를 할 수 있다. 
// 단, 클래스는 오버로딩이 안 되므로 특수화한 템플릿이라는 것을 알려주기 위해 클래스명 뒤에 꺽쇠를 이용해 정보를 추가해준다.
template<int SIZE>
class RandomBox<double, SIZE>
{
public:
    double GetRandomData()
    {
        cout << "RandomBox Double" << endl;
        int idx = rand() % SIZE;
        return _data[idx];
    }
public:
    double _data[SIZE];
};

int main()
{
    srand(static_cast<unsigned int>(time(nullptr)));
    RandomBox<int, 10> rb1;
    for (int i = 0; i < 10; i++)
        rb1._data[i] = i;

    int value1 = rb1.GetRandomData();
    cout << value1 << endl;

    //RandomBox<float, 20> rb2; // rb1과 다른 클래스로 만들어짐
    //for (int i = 0; i < 10; i++)
    //    rb2._data[i] = i + 0.5f;

    //float value2 = rb2.GetRandomData();
    //cout << value2 << endl;

    // 얼핏보면 함수와 비슷하게 생각하여 rb1과 rb2가 같아보일 수 있지만 두 클래스는 엄연히 다른 상태를 가지는 클래스가 된다.
    // 👉 rb1 = rb2가 성립하지 않는다.

    RandomBox<double, 20> rb3;
    for (int i = 0; i < 20; i++)
    {
        rb3._data[i] = i + 0.5;
    }
    double value3 = rb3.GetRandomData();
    cout << value3 << endl;
    // RandomBox의 초기 템플릿 자체가 <typename T, int SIZE>이므로 해당 규칙을 지켜줘야 한다. 
    // 그래서 SIZE 인자 하나 밖에 변하지 않지만 규칙을 지키기 위해 typename T에 해당하는 double을 입력해주었다.

    return 0;
}