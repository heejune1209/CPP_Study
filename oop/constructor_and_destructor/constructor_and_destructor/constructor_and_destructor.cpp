﻿#include <iostream>
using namespace std;

// 생성자와 소멸자

// 생성자[Constructor]와 소멸자[destructor]
// 클래스에 '소속'된 함수들을 멤버 함수라고함
// 이 중에서 굉장히 특별한 함수 2종이 있는데, 바로 [시작]과[끝]을 알리는 함수들
// - 시작(탄생) -> 생성자
// - 끝(소멸) -> 소멸자(오직 1개만) 

// [암시적(implicit) 생성자]
// 생성자를 명시적으로 만들지 않으면,
// 아무 인자도 받지 않는 [기본 생성자]가 컴파일러에 의해 자동으로 만들어짐.
// 물론 내용은 비어있다!
// -> 그러나 우리가 명시적(Explicit)으로 아무 생성자 하나 만들면,
// // 자동으로 만들어지던 [기본 생성자]는 더 이상 만들어 지지 않음!

// 암시적인 거는 말 그대로 컴파일러가 자동으로 만들어 준 거고 우리가 이렇게 직접 코드를 만들어 가지고 쓴 거는 
// 명시적인 기본 생성자라고 볼 수 있겠습니다

// 클래스만 덩그러니 이렇게 만들어 놓고 내용물을 아무것도 안 채워놔도 기본 생성자가 원래 만들어지고 
// 거기다가 플러스로 복사 생성자도 기본으로 일단은 만들어진다고 보시면 되겠고요
// 실제로 기본적으로 컴파일러에 만들어진 그 암시적 복사 생성자 같은 경우에는 걔가 하는 역할은 
// 정말로 여기 있는 모든 멤버 변수들의 데이터를 토시 하나 안 틀리고 하나 하나 하나씩을 복사하게 된다.

// class는 일종의 설계도
class Knight
{
public:
	// [1] 기본 생성자 (인자가 없음)
	// 기본 생성자가 생성이 될 때 무조건 실행돼야 되는 코드가 있다고 하면은 무조건 여기다가 넣어주면 굉장히 편리하겠다는 생각이 들겠죠
	Knight()
	{
		cout << "knight() 기본 생성자 호출" << endl;

		_hp = 100;
		_attack = 10;
		_posx = 0;
		_posy = 0;
	}

	// [2] 복사 생성자 (자기 자신의 클래스 참조 타입을 인자로 받음)
	// (일반적으로 '똑같은' 데이터를 지닌 객체가 생성되길 기대한다. )
	// 그러다보니까 예를 들면 우리가 여기서 이미 만들어진 Knight라는 늠름한 기사가 있다고 가정을 한 다음에 
	// 여기서 두 번째 Knight를 만들어 본다고 가정을 해볼게요 이전 시간에는 우리가 이걸 이렇게 하나를 만들어 준 다음에 
	// 즉 기본 생성자로 만들어 준 다음에 데이터를 한 땀 한 땀 이렇게 우리가 채워 놨었죠
	// K2는 Attack 80 이런 식으로 근데 만약에 그런 게 아니라 정확하게 K1과 똑같은 데이터를 이용해 가지고 하나를 더 만들고 싶다고 
	// 가정을 하면 무조건 한 땀 한 땀 만드는 게 아니라 K1를 이렇게 넣어줄 수가 있게 됩니다
	// 말 그대로 여기 K1을 그대로 복사해가지고 도플갱어를 만들어서 똑같은 애를 하나를 더 만들고 싶다는 의미가 되는 거죠
	// 일반적으로 뭔가 어떤 똑같은 데이터를 지닌 객체가 생성되길 일단 기대한다고 보시면 되겠습니다

	// 사실상 우리가 애써서 만들어준 이 부분은 얘가 자동으로 만들어주는 부분이랑 별다른 차이가 없다고 보면된다.
	// 그러면은 이거는 어지간해서는 이렇게 만드는 게 맞으니까 얘를 뭐 굳이 명시적으로 만들 필요가 있을까 싶기는 
	// 하지만 일반 데이터는 뭐 굳이 이런 그냥 기본 방식으로 사용해도 충분하지만 
	// 여기서 이제 포인터를 하거나 참조값이 들어가기 시작하면 이제 문제가 조금 복잡해집니다 
	// 근데 이제 정확하게 어떤 문제가 일어나는지는 나중에 동적할당에 대해서 배운다.

	// 그러니까 일단은 이해해야 될 거는 얘가 일단 복사 생성자라는 것도 이렇게 정의를 해서 우리가 명시적으로 만들 수도 있고 
	// 그 다음에 안 만들어 줬으면 그냥 기본적으로 컴파일러가 기본적으로 만들어주는 기능을 가지고있다.

	Knight(const Knight& knight) // 복사만 기능하기에 const가 거의 다 붙는다
	{
		cout << "knight(const Knight& knight) 복사 생성자 호출" << endl;
		_hp = knight._hp;
		_attack = knight._attack;
		_posx = knight._posx;
		_posy = knight._posy;

	}

	// [3] 기타 생성자 -> 기본, 복사 외에 모든 생성자를 의미

	// 이 중에서 인자를 1개만 받는 [기타 생성자]를 [타입 변환 생성자]라고 부르기도 함.
		//  말인 즉슨, 알아서 형변환을 시켜준다는 의미
	// 명시적인 용도로만 사용할 것!

	// 그래가지고 이렇게 암시적으로 즉 컴파일러가 자꾸만 개입하는 게 너무 짜증이 나 가지고 막고 싶을 때는 
	// 얘를 암시적으로 사용하지 말아달라 즉 우리가 요 아이를 만든 용도는 명시적으로 사용하기 위해서 만들었다 라는것을 표현하기 위해 
	// 명시적인 용도로만 사용할 것 이라는 키워드를 붙여줘야 되는데 그게 바로 explicit라는 것이다
	explicit Knight(int hp)
	{
		// 명시적인 용도로만 사용할 것!
		cout << "knight(int) 기본 생성자 호출" << endl;

		_hp = hp;
		_attack = 10;
		_posx = 0;
		_posy = 0;
	}
	// 이렇게 생성자에 explicit를 붙여놓으면 아까처럼 암시적으로 k5 = 1; 이렇게 못쓰고, k5 = (Knight)1; 이렇게 앞에 (knight)라고 붙여줘야한다.

	Knight(int hp, int attack, int posx, int posy)
	{
		_hp = hp;
		_attack = attack;
		_posx = posx;
		_posy = posy;

	}

	// 소멸자
	// 얘는 무조건 이 클래스가 생성될 때 생성자가 호출되고 메인 함수가 종료될 때 소멸자가 호출된다.
	// 객체의 수명이 끝날 때 자동으로 호출
	// 소멸자는 객체의 자원을 해제하거나 정리할 때 사용됩니다.
	~Knight()
	{
		cout << "~knight() 소멸자 호출" << endl;
	}



	// 멤버 함수 선언
	// 일반적으로 이렇게 멤버 변수 같은 경우에는 얘가 멤버 변수라는 걸 표현하기 위해서 조금 표기법을 다르게 하는 경우가 많아요
	void Move(int y, int x);
	void Attack();
	void Die()
	{
		_hp = 0;
		this->_hp = 1;
		// _hp = 0; 이 코드를 풀어서 쓰면 this->_hp = 1; 이 코드임
		cout << "Die" << endl;
	}
	// 선언을 먼저 하고 그 다음에 정의하는 부분을 이렇게 따로 빼놔도 되고 
	// 경우에 따라서는 얘는 그냥 선언과 정의를 그냥 동시에 이렇게 정의 부분을 여기 안에다가 넣어도 되기는 합니다

	// 데이터와 동작이 같이 있는것이 가장 큰 차이라고 볼수 있다.
	// 그 다음에 이 멤버 함수 내부에서 이 같은 클래스 내부에 있는 함수는 굉장히 특이하게도 이 멤버 변수에 접근을 할 수가 있다는 특징이 있다
public:
	// 멤버 변수
// 보통 멤버 변수를 선언 할 때 m을 앞에 붙인다거나, _를 붙인다
	int _hp;
	int _attack;
	int _posx;
	int _posy;

};

// 그런데 엄밀히 말해서 여기 class Knight라는 이 아이 자체는 설계도에 불과하기 때문에 진짜 본체, 어떤 데이터가 들어가 있다는 건 아니었습니다
// 이 설계도를 기반으로 뭔가 건물을 지어야지만 그게 의미가 있다고 했는데 실질적으로 이 설계도를 따라가지고 
// 어떤 객체를 만드는 부분이 이렇게 스택에다 올리거나 나중에 배울 동적할당을 이용해가지고 힙에다 올리거나 하는 방법으로 
// 이제 메모리를 잡아가지고 그 해당 객체를 만들게 될 거예요

void Knight::Move(int y, int x)
{
	_posy = y;
	_posx = x;
	cout << "Move" << endl;
}

void Knight::Attack()
{
	cout << "Attack : " << _attack << endl;
}

void Move(Knight* knight, int y, int x)
{
	knight->_posy = y;
	knight->_posx = x;
}
// Instantiate 객체를 만든다!

void HelloKnight(const Knight& k) // 이렇게 하면 임시 객체 생성은 여전히 발생하지만, 함수 매개변수로 전달 시 복사본 생성이 방지됩니다.
{
	cout << "Hello Knight" << endl;
}


int main()
{
	Knight k1(100);
	// k1._hp = 100;
	k1._attack = 10;
	k1._posx = 0;
	k1._posy = 0;

	// k1의 주소로 가서 한번 분석한 결과 놀랍게도 지금 이렇게 데이터가 4개짜리로 되어 있는 걸 볼 수가 있습니다
	// 4바이트 4바이트 4바이트 4바이트 총 16바이트라는 걸 볼 수가 있는 거고 그래서 
	// 실질적으로 우리가 사이즈 오브 k1을 여기 조사식 아래쪽에다가 조사식에서 이렇게 엔터를 하면 16이 뜨는것을 알수 있다.
	// 그러니까 비록 우리가 설계도 상으로는 이렇게 멤버 변수와 멤버 함수를 같이 옹기종기 모아가지고 설계도를 만들어 놨지만은 
	// 실질적으로 데이터 자체는 이 아래 있는 이 멤버 변수들만 데이터에 잡혀 있는 걸 볼 수가 있죠
	// 그리고 여기 있는 함수들은 일단은 데이터에는 이 메모리에는 따로 잡혀 있지 않다는 걸 알수 있다.

	Knight k2(k1); // 복사 생성자 -> 복사와 생성자가 한번에 기능
	Knight k3 = k1; // 복사 생성자

	Knight k4; // 생성자
	k4 = k1; // 복사

	// 그냥 이렇게 덩그러니 k4만 이렇게 만든 다음에 그 다음에 이렇게 복사하는 부분은 
	// 얘가 한마디로 생성자 부분과 복사하는 부분이 이제 따로따로 구분이 된다고 보시면 되겠어요

		// k1의 정보를 k2에 복사, k2의 생성과 복사를 한번에
	k1.Move(2, 2);
	k1.Attack();
	k1.Die();

	// 암시적 형 변환 -> 컴파일러가 알아서 변환
	int num = 1;

	float f = num; // 암시적 < 우리가 별말 안했는데 컴파일러가 알아서 처리하고있음.

	//float f = (float)num; // 명시적 < 우리가 코드로 num을 float 바구니에 넣으라고 주문하고 있음
	// 즉, Knight(int hp)라는 생성자를 컴파일러가 알아서 암시적으로 _hp값을 1로 세팅하라고 타입을 변환해서 클래스를 생성해 준다
	Knight k5;
	k5 = (Knight)1;
	// 암시적으로 컴파일러가 1이라는 값을 변환해서 넣어준다. 그래서 k5의 _hp값은 1이다
		// Knight와 1이 호환이 안될거 같았는데 호환이 되는 이유는 타입 변환 생성자 때문이다.
		// 즉 인자를 한 개만 받는 요런 버전은 타입 변환 생성자라고 했는데 얘를 만들어 주는 순간 
		// 즉 정수를 이용해 가지고 이 Knight를 초기화 할 수 있는 것과 더불어 
		// 요렇게 어떤 형변환이 자동으로 또 이렇게 일어날 수 있다는 얘기가 되는 거죠

	Knight temp(100);         // temp 객체 생성자 호출
	HelloKnight(temp);        // 추가적인 생성자/소멸자 호출 없음 (참조 전달)

	HelloKnight((Knight)5); // 임시 객체 생성자와 소멸자 호출, HelloKnight(Knight(100));이 코드와 똑같이 타입변환 생성자를 사용해 임시객체를 생성
	// 왜냐면 그냥 위에 코드 처럼 객체를 만들어서 객체를 참조로 전달한게 아니라 타입 변환 생성자를 사용해서 임시객체를 만들었기 때문에 소멸자도 호출됨


	// 당연히 일반적인 경우라면 요렇게 어떤 늠름한 기사를 복사해서 넣어주는 게 일반적이겠지만 
	// 또 굉장히 신기하게 그냥 아무 숫자나 아무 정수나 요렇게 넣어줘도 얘가 또 아무런 위협은 없이 실행이 된다는 게 또 굉장히 놀랍습니다
	// 그러니까 결국에는 요렇게 컴파일러가 암시적으로 해주는 부분이 이렇게 계속 문제를 일으킬 수 있다는 얘기가 된다.

	// 그래서 얘가 Hello Night이 실제로 이렇게 호출하게 되면은 여기서 5를 넣어준 숫자
	// 때문에 실질적으로 이 Night라는 애가 만들어지면서 아까 얘기한 타입 변환 생성자를 이용해 가지고 
	// 이런 버전이 하나가 만들어져서 넘어간다고 보시면 되겠어요
	// explicit를 생성자에서 타입을 붙여주면 HelloKnight(5); 이렇게 쓰면 에러가 나는것을 볼수 있는데
	// 에러를 막을려면 HelloKnight((Knight)5);이렇게 명시적으로 써줘야한다.

	// 결론
	// 타입 변환 생성자를 사용하는 경우, 객체가 암시적 또는 명시적으로 생성되므로 생성자와 소멸자가 항상 호출됩니다. 
	// 이를 최적화하고 불필요한 호출을 방지하려면:

	// explicit 키워드로 암시적 호출을 제한.
	// 참조 전달을 통해 복사를 방지하는 설계를 사용하는 것이 좋습니다.

	// 1. explicit 키워드와 생성자/소멸자 호출
	// explicit 키워드를 사용하면 암시적 호출(예: Knight k1 = 1;)을 방지합니다.
	// 하지만 명시적 호출(예: Knight k1 = (Knight)1; 또는 Knight k1(1);)에서는 여전히 생성자와 소멸자가 호출됩니다.

	// explicit 키워드는 타입 변환 생성자가 암시적으로 호출되는 것을 막을 뿐, 
	// 객체를 명시적으로 생성하는 경우에는 여전히 생성자와 소멸자가 호출됩니다. 이는 객체를 생성했기 때문입니다. 
	// 결론적으로, explicit 키워드는 암시적 호출을 방지하는 데만 효과적이며, 생성자와 소멸자가 호출되는 것을 막을 수는 없습니다.

	// 2. 참조 전달과 생성자/소멸자 호출
	// 함수의 매개변수를 참조(const Knight&)로 전달하면 복사 생성자와 소멸자의 호출을 방지할 수 있습니다.
	// 하지만 함수 호출 전에 임시 객체를 생성했다면, 이 임시 객체의 생성자와 소멸자는 여전히 호출됩니다.

	// 왜냐면 참조로 전달하면 매개변수를 복사하지 않으므로 추가적인 복사 생성자와 소멸자는 호출되지 않습니다. 
	// 하지만 함수에 전달할 때 사용하는 객체가 임시 객체라면, 이 객체는 생성되고 소멸됩니다.
	return 0;
}

//그리고 생성자와 소멸자를 포함한 클래스의 모든 멤버 함수는 클래스 밖에서 구현할 수 있다
//멤버함수처럼 MyClass::MyClass(int value) 이렇게 반드시 함수의 이름 앞에 클래스 이름과 범위 지정 연산자(::)를 붙여야 합니다.