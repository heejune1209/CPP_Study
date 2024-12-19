#include <iostream>
using namespace std;

// 다차원 배열

int main()
{
	int a[10] = { 1,2,3 };

	// [1] [1] [5] [2] [2] << 1층
	// [4] [2] [3] [4] [1] << 0층

	int first[5] = { 4, 2, 3,4,1 };
	int second[5] = { 1,1,5,2,2 };

	// [1] [1] [5] [2] [2] << 1층
	// [4] [2] [3] [4] [1] << 0층
	// => 2행 5열
	// 메모리를 까보면 그래서 이 모든 닭장은 사실 이어서 생성이 되어 있다는 게 굉장히 중요한 내용이고
	// 1차원으로 쭉 나열된 형태
	int apt2D[2][5] = { { 4, 2, 3,4,1},{1,1,5,2,2} }; // second의 index 4 : 2

	cout << apt2D[1][4] << endl;

	for (int floor = 0; floor < 2; floor++)
	{
		for (int room = 0; room < 5; room++)
		{
			// apt2D + ((floor * 5) + room) * 4를 한 주소
			int num = apt2D[floor][room];
			cout << num << " ";
		}
		cout << endl;
	}
	int apt1D[10] = { 4,2,3,4,1,1,1,5,2,2 };

	for (int floor = 0; floor < 2; floor++)
	{
		for (int room = 0; room < 5; room++)
		{
			int index = (floor * 5) + room;
			// apt1D + ((floor * 5) + room) * 4를 한 주소
			int num = apt1D[index];
			cout << num << " ";
		}
		cout << endl;
	}

	// 사실 이러나 저러나 성능상으로 혹은 메모리 구조상으로 완전히 똑같은 얘기가 된다.

	// 2차 배열은 언제 사용할까? 대표적으로 2D 로그라이크 맵
	int map[5][5] =
	{
		{ 1,1,1,1,1 },
		{ 1,0,0,1,1 },
		{ 0,0,0,0,1 },
		{ 1,0,0,0,0 },
		{ 1,1,1,1,1 },
	};

	for (int y = 0; y < 5; y++)
	{
		for (int x = 0; x < 5; x++) {
			int info = map[y][x];
			cout << info;
		}
		cout << endl;
	}


	return 0;
}