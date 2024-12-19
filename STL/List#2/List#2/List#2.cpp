#include <iostream>
using namespace std;
#include <vector>
#include <list>
// 오늘의 주제 : list

// 리스트 구현
template<typename T>
class Node // 말그대로 나의 이전 노드와 다음 노드, 그리고 데이터를 가지고 있는 형태로만 구현
{
public:
	Node() : _next(nullptr), _prev(nullptr), _data(T())
	{

	}

	Node(const T& value) : _next(nullptr), _prev(nullptr), _data(value) // 만약에 혹시라도 이 Value 자체를 데이터 자체를 직접적으로 생성자에다가 이렇게 넣어준다고 하면은 
		// Next랑 Preview는 그대로 Null로 유지를 한 채 데이터만 이 Value로 이렇게 채워주도록 하겠습니다
	{

	}

public:
	Node* _next;
	Node* _prev;
	T _data;
};

template<typename T>
class Iterator
{
public:
	Iterator() : _node(nullptr)
	{

	}

	Iterator(Node<T>* node) : _node(node)
	{

	}
	// <T> 를 생략해도됨
	// ++it
	Iterator& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	// it++
	Iterator operator++(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_next;
		return temp;
	}

	// --it
	Iterator& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	// it--
	Iterator operator--(int)
	{
		Iterator<T> temp = *this;
		_node = _node->_prev;
		return temp;
	}
	// 데이터를 추출하는 부분, 복사가 아니라 참조 값으로 건네주는 이유는 실제로 이 데이터를 수정할 수도 있을 테니까
	T& operator*()
	{
		return _node->_data;
	}

	bool operator==(const Iterator& right)
	{
		return _node == right._node;
	}

	bool operator!=(const Iterator& right)
	{
		return _node != right._node;
	}

public:
	Node<T>* _node; // 이터레이터는 그냥 단순하게 내가 어떤 노드인지만을 가리키고 있는 상태면은 충분하다. 그러니까 이런식으로 내가 지금 어떤 노드인지를 관리하게끔 가리키면 되겠습니다
};

//   <-> [ header ] <-> 
// [1] <-> [2] <-> [3] <-> [4] <-> [ header ] <-> 
// 헤더라는 데만 들고 있으면 첫 번째 데이터를 찾고 싶으면 이 헤더에 넥스트로 넘어가 가지고 이 화살표로 뿅 타고 가 가지고 얘가 첫 번째 데이터라는 거를 인지를 할 수가 있었고요 
// 그 다음에 이 리스트 점 엔드를 찍어 가지고 리스트의 맨 마지막 비교값을 추출하고 싶었을 때는 그냥 이 헤더를 뱉어주는 형식으로 동작을 했었습니다.
// list.end는 결국에는 이 헤더를 가리키게 된다는 결론을 얻을 수가 있습니다.
// 이 헤더 같은 경우는 데이터가 아무것도 안 들어있는 상태라고 하더라도 이런 식으로 기본적으로 존재를 해야 되고 만약에 어떠한 데이터도 없다고 하면은 
// 이 헤더의 이전 값과 넥스트의 값을 자기 자신으로 연결을 시켜 주도록 할게요
template<typename T>
class List
{
public:
	List() : _size(0)
	{
		_header = new Node<T>(); // 노드의 기본생성자 출력(이전 노드와 다음노드는 널포인터로 초기화, 그리고 데이터를 0으로 초기화)
		_header->_next = _header;
		_header->_prev = _header;
		// 지금 이 상태는   <-> [ header ] <-> 와 같다. 즉 자기자신을 가리키고 있는 상태로 시작하게 한다
	}

	~List()
	{
		while (_size > 0)
			pop_back(); // 호출해주면 하나씩 하나씩 데이터를 꺼내 가지고 최종적으로 아무 데이터도 없는 상태까지 모든 노드들을 일단은 다 삭제를 해줄 거고 
		// 마지막에 우리가 디폴트로 만들어 준 그 더미 헤더만 이렇게 따로 삭제를 해주면 될 것 같다는 생각이 듭니다

		delete _header;
	}

	// AddNode로 push_back과 insert 기능 합치기
	void push_back(const T& value)
	{
		AddNode(_header, value);
		// 왜냐면 pushback이라는 것 자체가 헤더 이전에다가 뭔가 데이터를 밀어넣는 작업이었기 때문에 addnode만 잘 구현해주면 pushback은 따로 구현할필요없이 addnode를 재활용 하면 되겠다
	}

	// RemoveNode로 pop_back과 erase 기능 합치기
	void pop_back()
	{
		RemoveNode(_header->_prev); // 헤더의 이전 노드를 삭제
	}

	// 넣어줄 위치의 바로 다음 위치를 인자로 받음 -> before의 바로 뒤에 추가된다.
	// [node] <-> [ header ] <->  : 아무런 데이터가 없고 헤더 노드밖에 없다는 가정 하에서도 잘 작동 된다
	// [1] <-> [2] <-> [before] <-> [4] <-> [ header ] <->  : 이렇게 있다고 가정
	// [1] <-> [2] <-> [value] <-> [before] <-> [4] <-> [ header ] <-> 
	// [1] <-> [prevNode] <-> [node](결국 추가된 노드) <-> [before] <-> [4] <-> [ header ] <-> 
	Node<T>* AddNode(Node<T>* before, const T& value) // 어떤 노드 이전에 추가를 해야되느냐를 첫번째 인자로 받아줄것이고 두번째 인자는 넣어줄 값을 받아준다
	{
		Node<T>* node = new Node<T>(value); // [value] 노드 추가. 즉 [value]를 [node]로 만들어 준다

		// 이전 노드
		Node<T>* prevNode = before->_prev; // [before]의 이전 노드를 타고 가면 [2]노드를 가리킬거고 [2] 노드를 [prevNode]이전 노드로 저장
		prevNode->_next = node;  // [prevNode]의 다음 노드를 [node] 로 저장. [prevNode] -> [node] 이 상태.

		// 현재 노드 (삽입될 노드)
		node->_prev = prevNode; // [prevNode] <- [node] 이렇게 가리키게 한다. 그래서 즉, [prevNode] <-> [node] 이 상태로 만들어줌

		// 이후 노드
		node->_next = before; // [node] -> [before] 이렇게 가리키게 한다
		before->_prev = node; // [node] <- [before] 이렇게 가리키게 한다. 그래서 즉, [node] <-> [before] 이렇게 만듬

		_size++;

		return node; // 추가된 위치를 반환
	}

	// [1] <-> [prevNode] <-> [node] <-> [nextNode] <-> [ header ] <-> 
	// [1] <-> [prevNode] <-> [nextNode] <-> [ header ] <-> 
	Node<T>* RemoveNode(Node<T>* node)
	{
		Node<T>* prevNode = node->_prev;
		Node<T>* nextNode = node->_next;

		prevNode->_next = nextNode;
		nextNode->_prev = prevNode;

		delete node;

		_size--;

		return nextNode; // 얘가 반환해야 되는 거는 이 node를 기준으로 얘를 삭제를 했으면 그 다음 주소 이 next node라는 애를 반환을 해야 되는 것이다
	}

	int size() { return _size; }

public:

	typedef Iterator<T> iterator;

	iterator begin() { return iterator(_header->_next); }  // Iterator(Node<T>* node) 라는 iterator의 기타 생성자에서 인수를 포인터로 받고 있으니까 인자에 이터레이터를 반환해준다
	iterator end() { return iterator(_header); }  // header 자체가 end를 뜻하기 때문에 헤더를 넘겨줌

	iterator insert(iterator it, const T& value) // ((첫번째 인수)어디에 추가해줄것인지 , (두번째 인수)추가할 데이터 )
	{
		Node<T>* node = AddNode(it._node, value); // AddNode가 추가한 그 위치 자체를 노드 값으로 뱉어준다
		return iterator(node);
	}

	iterator erase(iterator it)
	{
		Node<T>* node = RemoveNode(it._node);
		return iterator(node);
	}

public:
	Node<T>* _header; // 더미 노드
	int _size; // 몇개의 데이터를 들고있는지
};


int main()
{
	List<int> li;

	List<int>::iterator eraseIt;

	for (int i = 0; i < 10; i++)
	{
		if (i == 5)
		{
			eraseIt = li.insert(li.end(), i); // 5 저장
		}
		else
		{
			li.push_back(i);
		}
	}

	li.pop_back(); // 9 삭제

	li.erase(eraseIt); // 5 삭제

	for (List<int>::iterator it = li.begin(); it != li.end(); ++it) // li.end(); 는 결국 헤더 노드를 가리킨다고 볼수 있다 
	{
		cout << (*it) << endl;
	}
	// 처음엔 어렵지만, 이게 헷갈리다 보면 그냥 그림을 그려가지고 하나씩 하나씩 그림을 그려보면서 생각을 하면 됩니다
	// 내가 어떤 노드를 연결시켜줘야 되는지를 곰곰이 생각해 보면서 한 땀 한 땀 코드를 만들면 이게 의외로 할만 하긴 해요
	// 사실 이터레이터는 말그대로 노드 포인터를 내부적으로 들고 있는 역할을 한다
	// 가장 핵심적으로 봐야할건 이 노드와 리스트를 관리하는 그 방법이 일단 가장 핵심적인 내용이라고 보면됨
	// 그리고 이런 부분들은 반복해서 몇 번 연습해봐도 가치가 있는 부분이기도 합니다
	// 참고로 벡터랑 리스트는 1시간 짜리로 한번 구현해봐라 하고 코딩 면접에서 출제되는 문제이기도함
	return 0;
}