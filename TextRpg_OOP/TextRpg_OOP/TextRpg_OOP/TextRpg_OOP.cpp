#include <iostream>
using namespace std;
#include "Game.h"
// Text RPG - OOP

// 이번 시간엔 우리가 베운 객체지향적인 문법으로 나눠서 설계하는게 중점 사항

// 객체지향적인 사고 방식을 가질때는 모든 것을 객체 기반으로 생각을 한다.

// CPP파일에서는 신기하게도 전방선언을 하는게 아니다. 왜냐면 CPP파일에서는 이제 당장 어떤 코드가
// 동작하는 곳이기 때문에 헤더 파일은 그냥 말그대로 선언과 관련된 애들을 모아둔 부분이라고 보면 되는거고
// CPP파일은 실제 코드가 당장 돌아가는 부분이기 때문에 여기서는 그냥 안심하고 #include로 늘려줘도 상관이 없다

int main()
{
	srand((unsigned int)time(nullptr));
	Game game;
	game.Init();

	while (true)
	{
		game.Update();
	}



	return 0;
}