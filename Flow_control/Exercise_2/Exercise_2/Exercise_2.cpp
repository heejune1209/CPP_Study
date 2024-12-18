#include <iostream>
using namespace std;

int main()
{
	// 가위바위보 연습문제
	// 나의 풀이
	int wins_count = 0;
	for (int count = 0; true; count++)
	{
		cout << "가위(1) 바위(2) 보(3) 중에 고르세요." << endl;
		if (count == 0)
			cout << "현재 나의 승률: 없음" << endl;
		else
		{
			int winpercent = ((wins_count * 100) / count);
			// 이부분에서 조심해야함 정수로 나타내야하기때문에 분자에다 먼저 100을 곱해주고 count로 나눠주는게 맞음.
			cout << "현재 나의 승률:" << winpercent << endl;
		}

		for (int i = 0; true; i++)
		{
			int input;
			cin >> input;
			srand(time(0)); // 시드 설정

			// 1 2 3               
			int value = 1 + rand() % 3; // rand()는 일반적으로 0~32767 정도 사이의 숫자를 랜덤으로 출력한다고 보면된다.

			if (input == value)
				cout << " 비겼습니다. " << endl;
			else if (input == 1 && value == 2)
			{
				cout << "컴퓨터는 바위를 선택했습니다! 컴퓨터가 이겼습니다. " << endl;
				break;
			}
			else if (input == 1 && value == 3)
			{
				cout << "컴퓨터는 보를 선택했습니다! 당신이 이겼습니다. " << endl;
				wins_count++;
				break;
			}
			else if (input == 3 && value == 1)
			{
				cout << "컴퓨터는 가위를 선택했습니다! 컴퓨터가 이겼습니다. " << endl;
				break;
			}
			else if (input == 2 && value == 3)
			{
				cout << "컴퓨터는 보를 선택했습니다! 컴퓨터가 이겼습니다. " << endl;
				break;
			}
			else if (input == 3 && value == 2)
			{
				cout << "컴퓨터는 바위를 선택했습니다! 당신이 이겼습니다. " << endl;
				wins_count++;
				break;
			}
			else if (input == 2 && value == 1)
			{
				cout << "컴퓨터는 가위를 선택했습니다! 당신이 이겼습니다. " << endl;
				wins_count++;
				break;
			}
			else
				break;
		}
	}

}
// switch문을 이용해서 가위바위보 판정을 만들어도 된다.