#include <iostream>
using namespace std;

// 열거형(변수를 상수로 만드는 기능을 가지고 있는데 const보다 더 좋음.) 
const int SCISSORS = 1; // SCISSORS의 주소값을 보고싶어서 찾아봤는데 주소가 나타나지 않는것을 볼수 있다.
// 그러니까 실질적으로 이 변수들이 메모리에 올라가 있지 않는 상태라는 걸 알 수가 있는 거죠
const int ROCK = 2;
const int PAPER = 3;
// 변수를 상수로 만드는 기능:
// 1) const 2) Enum 3) #define


// 한마디로 여기서 중요한 건 뭐냐면 이 const int를 사용할 때는 경우에 따라서 컴파일러가 최적화를 할 수 있다면 
// 얘네들을 메모리에 안 올리고도 그냥 1, 2, 3으로 그냥 대체를 하겠지만, 그게아니라 이렇게 스택에다가 올리거나 아니면
// 아까와 같이 데이터 영역에 올려놓고 주소를 참조하는 경우라하면 SCISSORS 이것과 같은것들이 숫자로 치환되지 않고
// 실질적으로 SCISSORS 이런 변수들이 메모리에다가 올라간다. 즉 메모리 공간을 조금 낭비한다라는 그런 얘기가 된다.

// 근데 저 ENUM값들은 그러한 단점들이 없다는 얘기가 된다. 즉 숫자로 치환이 된다. => 메모리 공간 낭비를 줄일수 있음.

// 숫자를 지정 안하면 첫 값은 0부터 시작
// 그 다음 값들은 이전 값 + 1
// 
enum ENUM_TYPE
{
	ENUM_SCISSORS = 1,
	ENUM_ROCK,
	ENUM_PAPER
};

// #이 붙은거 => 전처리 지시문
// #include <iostream>이라는 파일을 찾아서 해당 내용을 그냥 복붙!
// 1) 전처리 2) 컴파일(번역) 3) 링크

#define DEFINE_SCISSORS 1 // define 같은 경우도 이건 이제 매크로를 만드는 그런 전체적인 명령이다.
#define DEFINE_TEST cout << "Hello World" << endl; // 코드 바꿔치기하는 기능을 가지고 있다.
// 근데 이런 define 보다 enum을 우선적으로 사용하는게 더 좋다.(상수로 만들땐 define 사용을 지양.)

int main()
{
	//DEFINE_TEST; // 이렇게 코드를 쓰면 "Hello World" 이런 문자열이 출력이 된다.
	srand(time(0)); // 시드 설정

	auto a = &SCISSORS; // 변수의 주소값을 a라는 변수에다 넣어주세요.

	int wins = 0;
	int total = 0;

	while (true)
	{
		cout << "가위(1) 바위(2) 보(3) 골라주세요! " << endl;
		cout << ">";

		if (total == 0)
		{
			cout << "현재 승률 : 없음 " << endl;
		}
		else
		{
			int winpercent = ((wins * 100) / total);
			// 이부분에서 조심해야함 정수로 나타내야하기때문에 분자에다 먼저 100을 곱해주고 count로 나눠주는게 맞음.
			cout << "현재 나의 승률:" << winpercent << endl;
		}

		int c_value = 1 + rand() % 3;

		int input;
		cin >> input;

		if (input == SCISSORS)
		{
			switch (c_value)
			{
			case SCISSORS:
				cout << "비겼습니다." << endl;
				break;
			case ROCK:
				cout << "졌습니다." << endl;
				total++;
				break;
			case PAPER:
				cout << "이겼습니다." << endl;
				wins++;
				total++;
				break;
			}
		}
		else if (input == ROCK)
		{
			switch (c_value)
			{
			case SCISSORS:
				cout << "이겼습니다." << endl;
				total++;
				wins++;
				break;
			case ROCK:
				cout << "비겼습니다." << endl;
				break;
			case PAPER:
				cout << "졌습니다." << endl;
				total++;
				break;
			}
		}
		else if (input == PAPER)
		{
			switch (c_value)
			{
			case SCISSORS:
				cout << "졌습니다." << endl;
				total++;
				break;
			case ROCK:
				cout << "이겼습니다." << endl;
				total++;
				wins++;
				break;
			case PAPER:
				cout << "비겼습니다." << endl;
				break;
			}
		}
		else
		{
			break;
		}
	}
}