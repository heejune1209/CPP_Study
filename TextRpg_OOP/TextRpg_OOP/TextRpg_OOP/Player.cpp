#include "Player.h"
#include <iostream>
using namespace std;

void Player::printInfo()
{
	cout << "-----------------------------" << endl;
	cout << "[�÷��̾� ����]" << "HP: " << _hp << "ATT: " << _attack << "DEF: " << _defence << endl;
	cout << "-----------------------------" << endl;
}