
#include "Game.h"
#include <iostream>
using namespace std;
#include "Player.h"
#include "Field.h"
// Namespace

// 나중에 가게되면 우리가 만든 헤더파일 뿐만 아니라 또다른 사람들이 만들어준 라이브러리를
// 갖다 쓰는 상황이 빈번하게 발생을 할거고 이렇게 공식적으로 C++ 공식 라이브러리에서 뭔가 지원하는
// 그런 기능들도 우리가 갖다 쓸일이 굉장히 많이 생길것이다. 그러다보면 운나쁘게 이름이 겹칠수 있다
// 예를들어서 Class test라는 클래스를 우리가 만약에 사용하고 싶은데 다른 라이브러리에서 다른 헤더 파일에서 클래스 테스트를 똑같이
// 정해가지고 사용하고 있다고 하면 이름이 겹치니까 헤더파일을 참조하는 순간에 이름이 겹쳐지고 에러가 나게 된다
// 그러다 보니까 이 테스트가 다 같은 이름을 사용하지 않게끔 앞에다가 이름공간을 지어줄수 있다

// 함수나 매크로 앞 부분에 namespace가 존재한다. 해당 라이브러리에 있는 함수를 사용한다는 의미이다.
// ex) cout : 출력해주는 함수이지만 원래는 std::cout으로 사용해야한다.코드가 길어지면 중복되는 부분이 늘어나므로 
// using namespace std;로 빼주어서 사용하게되면 중복되는 부분을 줄일 수 있다.

Game::Game() : _player(nullptr), _field(nullptr)// 클래스 외부에서 멤버 함수를 쓰는 법
{

}
// 게임이 끝날때 필드를 소멸
Game::~Game()
{
	if (_player != nullptr)
		delete _player;
	if (_field != nullptr)
		delete _field;


}

void Game::Init()
{
	_field = new Field();
}

void Game::Update()
{
	if (_player == nullptr) // 플레이어 여부 체크
	{
		CreatePlayer();
	}
	if (_player->isDead())
	{
		delete _player;
		_player = nullptr;
		CreatePlayer();
	}

	_field->Update(_player);
}

void Game::CreatePlayer()
{
	while (_player == nullptr)
	{
		cout << "-----------------------------" << endl;
		cout << "캐릭터를 생성하세요!" << endl;
		cout << "1) 기사 2) 궁수 3) 법사" << endl;
		cout << "-----------------------------" << endl;

		cout << ">";

		int input = 0;
		cin >> input;

		if (input == PT_Knight)
		{
			_player = new Knight();
		}
		else if (input == PT_Archer)
		{
			_player = new Archer();
		}
		else if (input == PT_Mage)
		{
			_player = new Mage();
		}

	}
}