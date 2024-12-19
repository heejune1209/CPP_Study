#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <set>
// set, multimap, multiset

int main()
{
	// set
	//셋(Set)은 맵에서 키와 데이터가 동일하다는 점 빼고는 동일하다.
	// (key = Value)
	set<int> s;
	// 사용법은 다른 STL 문법과 동일하며, set 라이브러리를 사용한다.

	// 삽입
	// insert를 사용한다.
	s.insert(10);
	s.insert(30);
	s.insert(20);
	s.insert(50);
	s.insert(40);
	s.insert(70);
	s.insert(90);
	s.insert(80);
	s.insert(100);
	s.insert(60);
	s.insert(60);

	// 삭제
	//erase를 사용한다.
	s.erase(40);

	// 조회
	// find를 사용한다.맵과 동일하게 이터레이터를 반환하고 찾지 못하면 end() 값을 반환한다.

	set<int>::iterator findIt = s.find(50);
	if (findIt == s.end()) cout << "못 찾음" << endl;
	else cout << "찾음" << endl;

	//순회
	// *연산자를 이용하여 값에 접근한다.

	for (set<int>::iterator it = s.begin(); it != s.end(); ++it)
		cout << (*it) << endl;
	// 자동 오름차순으로 정렬되며 중복된 값이 사라진다

	// s[10] = 10; 과 같은 접근은 불가능하다. (Key == Value기 때문이다.)

	//------------------------------------------------------------

	cout << "--------------------------" << endl;

	// Multimap
	// 키 값이 중복 허용되는 맵이다. 
	// 추가적으로 키 값과 일치하는 처음 위치와 마지막 다음 위치를 Pair 타입으로 반환해주는 함수 equal_range가 있다. 
	// 각각 따로도 반환해주는 함수 lower_bound와 upper_bound도 존재한다. 나머지는 일반 맵의 사용 방법과 동일하다.

	// 선언 방법
	multimap<int, int> mm;

	// 삽입
	mm.insert(make_pair(1, 100));
	mm.insert(make_pair(1, 200));
	mm.insert(make_pair(1, 300));
	mm.insert(make_pair(2, 100));
	mm.insert(make_pair(2, 200));

	// mm[1] = 500; // error

	// 삭제
	//mm.erase(1); // erase를 하나만 해줬는데 1로 되어있던 키들이 싹다 날라간다

	// 찾고

	// 만약 mm.insert(make_pair(1, 100)); 첫번째 데이터만 삭제하고 싶다고 한다면,
	multimap<int, int>::iterator itFind = mm.find(1); // 우리가 원하는 키값을 넣어주면, 이터레이터 하나를 딱 뱉어줄 거예요
	// 그러니까 이 첫 번째 버전을 데이터만 찾아줄 거라는 걸 알 수가 있는 거죠
	// 만약 두번째 버전을 삭제하고 싶다면,
	//++itFind; // 이렇게 하면 두번째 버전을 삭제해줄수 있다
	/*if (itFind != mm.end())
		mm.erase(itFind);*/


		// 조회
		// 만약 key가 1로 되어있는 모든 값들을 찾고 싶다면?
	pair<multimap<int, int>::iterator, multimap<int, int>::iterator> itPair;
	itPair = mm.equal_range(1); // 이때 equal_range이라는 것으로 받아주면  1이라는 값이 시작하는 mm.insert(make_pair(1, 100)); 이것을 first로 받아줄거고 1이 끝나는
	// mm.insert(make_pair(1, 300)); 이것의 다음데이터 => mm.insert(make_pair(2, 100)); 이것의 위치를 second로 받아주게 된다

	// begin, end와 비슷한 느낌
	multimap<int, int>::iterator itBegin = mm.lower_bound(1);  // lower_bound는 1이 시작하는 첫 주소 반환
	multimap<int, int>::iterator itEnd = mm.upper_bound(1);  // upper_bound는 1이 끝나는 마지막 주소의 다음 주소 반환

	// 순회
	for (multimap<int, int>::iterator it = itBegin; it != itEnd; ++it) // 1로 되어있는 모든 값들을 출력
		// lower_bound를 사용한후 itPair.first이 아니라 itBegin을 사용해도됨. 이것도 upper_bound를 사용한후 itPair.second 이렇게 itEnd 사용해도됨
		cout << it->first << " " << it->second << endl;

	//------------------------------------------------------------
	cout << "--------------------------" << endl;

	// multiset
	// 데이터가 중복 허용되는 셋이다. 멀티맵과 마찬가지로 equal_range, lower_bound, upper_bound 함수가 추가로 존재한다. 나머지는 일반 셋의 사용 방법과 동일하다.

	// 선언 방법
	multiset<int> ms;

	// 삽입
	ms.insert(100);
	ms.insert(100);
	ms.insert(100);
	ms.insert(200);
	ms.insert(200);

	// 찾고
	multiset<int>::iterator findit2 = ms.find(100);

	// 조회
	pair<multiset<int>::iterator, multiset<int>::iterator> itPair2;
	itPair2 = ms.equal_range(100);

	// begin, end와 비슷한 느낌
	multiset<int>::iterator itBegin2 = ms.lower_bound(100);  // 첫 주소 반환
	multiset<int>::iterator itEnd2 = ms.upper_bound(100);  // 마지막 주소의 다음 주소 반환

	for (multiset<int, int>::iterator it = itPair2.first; it != itPair2.second; ++it) // itPair2.first 대신 itBegin2 사용해도됨 , itPair2.second도 itEnd2이것을 사용해도됨
		cout << (*it) << endl;

}