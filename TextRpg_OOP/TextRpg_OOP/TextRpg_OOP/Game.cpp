
#include "Game.h"
#include <iostream>
using namespace std;
#include "Player.h"
#include "Field.h"
// Namespace

// ���߿� ���ԵǸ� �츮�� ���� ������� �Ӹ� �ƴ϶� �Ǵٸ� ������� ������� ���̺귯����
// ���� ���� ��Ȳ�� ����ϰ� �߻��� �ҰŰ� �̷��� ���������� C++ ���� ���̺귯������ ���� �����ϴ�
// �׷� ��ɵ鵵 �츮�� ���� ������ ������ ���� ������̴�. �׷��ٺ��� ��ڰ� �̸��� ��ĥ�� �ִ�
// ������ Class test��� Ŭ������ �츮�� ���࿡ ����ϰ� ������ �ٸ� ���̺귯������ �ٸ� ��� ���Ͽ��� Ŭ���� �׽�Ʈ�� �Ȱ���
// ���ذ����� ����ϰ� �ִٰ� �ϸ� �̸��� ��ġ�ϱ� ��������� �����ϴ� ������ �̸��� �������� ������ ���� �ȴ�
// �׷��� ���ϱ� �� �׽�Ʈ�� �� ���� �̸��� ������� �ʰԲ� �տ��ٰ� �̸������� �����ټ� �ִ�

// �Լ��� ��ũ�� �� �κп� namespace�� �����Ѵ�. �ش� ���̺귯���� �ִ� �Լ��� ����Ѵٴ� �ǹ��̴�.
// ex) cout : ������ִ� �Լ������� ������ std::cout���� ����ؾ��Ѵ�.�ڵ尡 ������� �ߺ��Ǵ� �κ��� �þ�Ƿ� 
// using namespace std;�� ���־ ����ϰԵǸ� �ߺ��Ǵ� �κ��� ���� �� �ִ�.

Game::Game() : _player(nullptr), _field(nullptr)// Ŭ���� �ܺο��� ��� �Լ��� ���� ��
{

}
// ������ ������ �ʵ带 �Ҹ�
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
	if (_player == nullptr) // �÷��̾� ���� üũ
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
		cout << "ĳ���͸� �����ϼ���!" << endl;
		cout << "1) ��� 2) �ü� 3) ����" << endl;
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