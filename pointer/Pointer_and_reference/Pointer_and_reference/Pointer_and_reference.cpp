#include <iostream>
using namespace std;

// 제 5장 : 포인터 vs 참조

struct StatInfo
{
	int hp;
	int attack;
	int defence;
};


void CreateMonster(StatInfo* info)
{
	info->hp = 100;
	info->attack = 8;
	info->defence = 5;


}

// 특정 조건을 만족하는 몬스터를 찾는 함수
StatInfo* FindMonster()
{
	// TODO : heap이라는 동적 영역에서 뭔가를 찾아봄.
	// 찾았다!
	// return monster~;

	// 못찾았다!
	return nullptr;
	// 그래가지고 이렇게 포인터를 사용하게 될 경우에는 진짜로 우리가 원하는 주소가 있는지 아니면은 아예 못 찾았다는 의미로 0인지에 따라가지고 
	// 이렇게 두 가지 상태를 구분을 할 수 있다.
	// 참조 값을 사용하게 될 경우에는 아까 얘기한 그 nullptr이라는 개념이 없다 보니까 이런 부분에서 살짝 애매해질 수 있다는 얘기가 되는 거죠 
	// 그러다 보니까 만약에 없는 값을 표현해야 된다고 하면은 사실 이 버전이 조금 애매할 수도 있지만 반대로 포인터를 사용하는 버전이 
	// 이런 부분에서 강점이 있다는 얘기가 되는 거고 그런데 그러면 포인터를 사용하는 게 또 좋냐?
	// 그건 또 아닐 수도 있는 게 아까 얘기한 이렇게 없는 경우도 생길 수 있기 때문에 항상 어떤 포인터가 등장하게 되면 굉장히 긴장을 해야 됩니다.
	// 이게 혹시라도 어떤 이유에서든 nullptr과 같이 없는 값으로 들어올 수도 있으니까 어지간해서는 포인터를 사용하기 전에 항상 체크를 하는 게 좋습니다.
}

StatInfo globalInfo;


void PrintinfoRef(const StatInfo& info)
{
	cout << "---------------------" << endl;
	cout << "HP : " << info.hp << endl;
	cout << "ATT : " << info.attack << endl;
	cout << "DEF : " << info.defence << endl;
	cout << "---------------------" << endl;

	// 신입이 왔다
	// info.hp = 1000;
	// 내용물을 못바꿈
	// 포인터의 * 이전에 const를 붙어서 나오는 기능과 같음
}
#define OUT
void Changeinfo(OUT StatInfo& info)
{
	info.hp = 1000;
}

// [매개변수][RET][지역변수(info)][매개변수(&info)][RET][지역변수]
void PrintinfoByPtr(StatInfo* info)
{
	if (info == nullptr)
		return;
	/*if (!info)
		return;*/
		// 위의 두개의 코드를 하나 정해서 사용.(널 체크 용도)
	cout << "---------------------" << endl;
	cout << "HP : " << info->hp << endl;
	cout << "ATT : " << info->attack << endl;
	cout << "DEF : " << info->defence << endl;
	cout << "---------------------" << endl;

	// * 뒤에 붙인다면?
	// StatInfo* const info
	// info라는 바구니의 내용물(주소)을 바꿀수 없음.
	// info는 주소값을 갖는 바구니 -> 이 주소값이 고정이다.


	// * 이전에 붙인다면?
	// const StatInfo* info
	// info가 가리키고 있는 바구니(주소값)의 내용물을 바꿀수 없음
	// '원격' 바구니의 내용물을 바꿀수 없음.

	// info[주소값]  주소값 [원본 데이터]


}


int main()
{
	StatInfo info;
	CreateMonster(&info);
	// 포인터 vs 참조 세기의 대결!
	// 성능 : 똑같음!
	// 편의성 : 참조 승!

	// 1) 편의성 관련
	// 편의성이 좋다는게 꼭 장점만은 아니다.
	// 포인터는 주소를 넘기닌 확실하게 원본을 넘긴다는 힌트를 줄수 있는데.
	// 참조는 자연스럽게 모르고 지나칠수 있음!
	// ex) 마음대로 고친다면?
	// 그 문제를 방지하기위해 참조를 사용할때 보통 const를 사용해서(많이 씀) 이런 마음대로 고치는 부분 개선 가능

	// 참고로 포인터도 const를 사용가능.
	// * 기준으로 앞에 붙이느냐, 뒤에 붙이느냐에 따라 의미가 달라진다.

	// 2) 초기화 여부
	// 참조 타입은 바구니의 2번째 이름 (별칭?)
	// -> 참조하는 대상이 없으면 안됨
	// 반면 포인터는 그냥 어떤 ~ 주소라는 의미
	// -> 대상이 실존하지 않을수도 있음
	// 포인터에서 '없다'는 의미로? nullptr 
	// 참조 타입은 이런 nullptr

	// 즉, 참조 타입은 이런 nullptr의 개념이 없다는 것까지 설명을 드렸고 그래서 정말로 뭔가가 없다는 의미까지 표현하고 싶으면 
	// 포인터를 선택하는 게 좋을 거고 그게 아니라 무조건 그게 100% 확률로 무조건 있다고 확신을 한다면 이 참조 타입을 사용을 하면 
	// 널 포인터를 체크하는 부분이 날라가기 때문에 조금 더 성능 향상을 볼 수 있겠죠

	StatInfo* pointer = nullptr; // 어떠한 주소도 가리키지 않으려고 할때 nullptr을 사용.
	//pointer = &info;
	PrintinfoByPtr(pointer);

	StatInfo& reference = info;
	PrintinfoRef(reference);

	// 그래서 결론은? 
	// 사실 Team By Team... 정해진 답은 없다.
	// ex) 구글에서 만든 오픈 소스를 보면 거의 무조건 포인터 사용
	// ex) 언리얼 엔진에선 reference도 애용

	// Rookiss 선호 스타일)
	// - 없는 경우도 고려해야한다면 pointer (null 체크 필요)
	// - 바뀌지 않고 읽는 용도(readonly)만 사용하면 const ref&
	// - 그 외 일반적으로 ref (명시적으로 호출할 때 OUT을 붙인다)
	// OUT은 C++에서는 그냥 얘가 바뀔 수도 있다는 힌트만 주기 위해서 이렇게 out을 표현한다고 보면 된다.(가독성 측면)
	// -- 단, 다른 사람이 pointer를 만들어 놓은걸 이어서 만든다면, 계속 pointer (섞어 사용하진 않는다)
	Changeinfo(OUT info);

	// Bonus) 포인터로 사용하던걸 참조로 넘겨주려면?
	// pointer [ 주소[&info]  ]  ref,  info [ 데이터]
	StatInfo& ref = *pointer;
	// 참조로 넘어갈땐 *를 붙인다
	PrintinfoRef(ref); // 풀어쓰면 이렇게됨
	// Bonus) 참조로 사용하던걸 포인터로 넘겨주려면?
	// pointer [  주소  ]  reference, info[데이터]
	PrintinfoByPtr(&reference);
	return 0;
	// 포인터로 넘어갈땐 &를 붙인다

	// &에 대해서, 어떤 변수 앞에다가 붙으면은 그 주소를 꺼내 주세요 라는 의미가 되는 거고 
	// 그게 아니라 처음에 이렇게 어떤 변수를 선언할 때 이렇게 타입에다가 뒤에 붙는 거는 참조값이다, 참조 타입이다 라고 이해.

	// 그리고 매개변수로 받을 값, 함수 안에있는 데이터를 고칠생각이 없다고 한다면 const를 쓰는 것이 성능적으로 더 좋다.
	// 근데 수정을 해야하는 거면 define OUT를 해서 OUT을 붙여주는것이 가독성 차원에서 좋다.
}
