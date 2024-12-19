#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>

// 알고리즘

#include <algorithm>

int main()
{

	// 자료구조(데이터를 저장하는 구조)
	// 알고리즘(데이터를 어떻게 사용할것인가?)

	// find
	// find if
	// count
	// count if 
	// all of
	// any of
	// none of
	// for each
	// remove
	// remove if

	srand(static_cast<unsigned int>(time(nullptr)));
	vector<int> v;

	for (unsigned int i = 0; i < 100; i++)
	{
		int num = rand() % 100;
		v.push_back(num);
	}

	// q1) number라는 숫자가 벡터에 들어가 있는지 체크하는 기능(반환형식은 bool이어도 되고 아니면 처음으로 등장하는 값의 이터레이터여도 상관 없음)
	{
		int number = 50;

		bool found = false;
		vector<int>::iterator it;

		//for (int i = 0; i < v.size(); i++)
		//{
		//	// a1) bool의 반환형식
		//	int data = v[i];
		//	if (data == 50)
		//	{
		//		found = true;
		//		break;
		//	}

		//}
		//  A2) 이터레이터 버전
		for (unsigned int i = 0; i < v.size(); i++)
		{
			int data = v[i];
			if (data == 50)
			{
				it = v.begin() + i;
				break;
			}

		}
		// find, find_if
		// 조회할 때 사용하는 함수이다. find는 일치하는 값을, find_if는 조건에 일치하는 값을 찾을 때 사용한다. 일치하는 첫 데이터의 이터레이터를 반환한다.
		// 만약 찾지 못한 경우 end() 값을 반환한다.
		// find
		vector<int>::iterator itFind = find(v.begin(), v.end(), number); // first, last, value를 넣어주는 것
		// 이 코드는 위에 for문을 이용해서 기능을 구현한거랑 똑같은 기능을 한다
		// 벡터 뿐만아니라 리스트로 대체 된다고 하더라도 얘는 이터레이터 기반으로 이렇게 두개의 첫 두인자를 받아주고 있어서 리스트여도 잘 동작하게 된다
		if (itFind == v.end())
		{
			cout << "못찾았음" << endl;
		}
		else
		{
			cout << "찾았음" << endl;
		}
	}

	// q2) 11로 나뉘는 숫자가 벡터에 있는지 체크하는 기능(반환형식은 bool이어도 되고 아니면 처음으로 등장하는 값의 이터레이터여도 상관 없음)
	{
		bool found = false;
		vector<int>::iterator it;

		for (unsigned int i = 0; i < v.size(); i++)
		{
			int data = v[i];
			int div = (data % 11);
			if (div == 0)
			{
				found = true;
				break;
			}
		}
		struct CanDivideBy11
		{
			bool operator()(int n) // 함수 객체 생성
			{
				return n % 11 == 0;
			}
		};
		// find_if
		// 함수 객체 생성 -> 추후엔 람다식으로 간편하게 만들 수 있음.
		// 람다식 : [](int n) { return n % 11 == 0; }

		// 람다식
		// vector<int>::iterator itFind = find_if(v.begin(), v.end(), [](int n) { return n % 11 == 0; });
		// 이렇게 만들면 for문으로 했던 기능과 같다
		vector<int>::iterator itFind = find_if(v.begin(), v.end(), CanDivideBy11());
		// (first, last, 조건에 해당하는 value)
		if (itFind == v.end())
		{
			cout << "못찾았음" << endl;
		}
		else
		{
			cout << "찾았음" << endl;
		}

	}
	// q3) 홀수인 숫자의 개수는? (count)
	{
		int count = 0;

		for (unsigned int i = 0; i < v.size(); i++)
		{
			int data = v[i];
			int div = (data % 2);
			if (div == 1)
			{
				count++;
			}
		}
		cout << count << endl;


		// count, count_if
		// 카운트 해주는 함수이다.count는 일치하는 값, count_if는 조건에 일치하는 값이면 1씩 증가시키고 총 누적 카운트를 반환한다.

		// count => (first, last, value)
		//int count = count(v.begin(), v.end(), 4);

		// count_if => (first, last, 조건에 해당하는 value)
		struct IsOdd
		{
			bool operator()(int n)
			{
				return n % 2 != 0;
			}
		};

		int n = count_if(v.begin(), v.end(), IsOdd());
		// 이렇게 하면 for문으로 했던것과 똑같은 기능을 한다


		// all_of, any_of, none_of
		// all_of : 모든 데이터가 조건을 만족하는가?
		// any_of : 조건을 만족하는 데이터가 하나라도 존재하는가?
		// none_of : 조건을 만족하는 데이터가 하나도 없는가?
		// (first, last, 조건에 해당하는 value)
		bool b1 = all_of(v.begin(), v.end(), IsOdd());
		bool b2 = any_of(v.begin(), v.end(), IsOdd());
		bool b3 = none_of(v.begin(), v.end(), IsOdd());

	}
	cout << "-------------------" << endl;

	// q4) 벡터에 들어가 있는 모든 숫자들에 3을 곱하라
	{

		for (unsigned int i = 0; i < v.size(); i++)
		{
			/*int& data = v[i];
			data *= 3;*/
			// 이렇게 해도됨

			v[i] *= 3;
			cout << v[i] << endl;

		}
		// for_each, (first, last, 조건에 해당하는 value)
		// 모든 데이터를 스캔할 때 사용한다. 모든 데이터를 순회하며 건드리거나 출력할 수 있다.
		struct MultiplyBy3
		{
			void operator()(int& n)
			{
				n *= 3;
				// 출력까지 하고 싶으면
				cout << n << endl;
			}
		};

		for_each(v.begin(), v.end(), MultiplyBy3());



	}

	// 홀수인 데이터를 일괄 삭제
	{
		//for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		//{
		//	if ((*it % 2) != 0)
		//	{
		//		it = v.erase(it); // erase는 이터레이터(포인터)를 반환. 그래서 it으로 받아줌
		//	}
		//	else
		//		++it;
		//} // 별로 안좋은 코드. 버그가 일어날수 있음

		// remove, remove_if
		// remove와 remove_if는 사용 시에 반드시 erase와 같이 사용해야한다.
		// 각각 일치하는 값, 조건에 일치하는 값을 삭제시켜주는데 그 즉시 삭제하게 되므로 뒷부분에 중복이 발생할 수 있다 .그 부분을 erase로 지워줘야한다.
		v.clear();

		v.push_back(1);
		v.push_back(4);
		v.push_back(3);
		v.push_back(5);
		v.push_back(8);
		v.push_back(2);
		// 1 4 3 5 8 2

		// remove (first, last, value)
		//v.erase(remove(v.begin(), v.end(), 4), v.end()); // 4 삭제

		struct IsOdd
		{
			bool operator()(int n)
			{
				return n % 2 != 0;
			}
		};

		// remove_if (first, last, 조건에 해당하는 value)
		//vector<int>::iterator it = remove_if(v.begin(), v.end(), IsOdd());
		//v.erase(it, v.end()); // 4, 8, 2 생존
		v.erase(remove_if(v.begin(), v.end(), IsOdd()), v.end()); // 한번에 만드는 방법 => 한번에 하는게 나음

		// 이 외에도 많은 알고리즘 문법이 있으니 필요한 기능이 있을 때마다 구글링하여 참고하자.
	}

	return 0;
}