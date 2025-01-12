#pragma once

// 관계도를 생각했을때
// is~a
// has~a

class Player;
class Field;

// 전방 선언
// 포함 관계에 있는 클래스를 작성할 때 사용하는 방식이다. 
// 각 헤더 파일과 cpp 파일은 독립적으로 빌드된다. 그래서 다른 파일에 있는 클래스를 가져다 쓸 때 그냥 쓰게되면 에러가 발생하게 되는데, 
// 이러한 에러를 방지하기 위해선 해당 클래스가 있다는 것을 알려주어야한다. 이것을 전방선언이라 한다.
// 포인터 형이 아닌 일반 클래스를 포함하게 되면 위의 Game 클래스는 크기가 몇 바이트인지 정확하게 알지 못한다. 
// 그래서 include를 통해 해당 클래스가 있는 설계도 전부를 가져와야하고, 포함된 클래스가 완성이 되었다는 전제하에 Game 클래스가 만들어지게된다. 
// 의존성이 높아진 것이다.

// 반면 포인터 형이 포함되면 크기를 확실히 알 수 있기 때문에 해당 클래스가 있다는 존재만 알려주면 된다. 
// 그래서 위의 코드처럼 선언만 해주게 되는 것이다. 포인터형 앞에 class를 붙여 바로 선언할 수도 있다.
// 단, 전방선언을 한다는 것은 설계도 전체를 가져오는 게 아닌 해당 클래스가 다음에 나올 것이라는 예고만 해주는 의미이므로 
// 클래스 안의 변수 혹은 함수에 직접 접근은 하지 못한다.
// 그러나 자기 자신을 타입으로 가지는 포인터 형 클래스 변수는 전방선언을 하지 않아도 빌드가 가능하며 cpp에서 접근이 가능하다.

// 즉, 헤더파일에선 전방선언을 먼저 생각
// CPP파일은 include를 생각

// 게임 시작, 필드 생성, 캐릭터 생성 기능
class Game
{
public:
	Game();
	~Game();

	void Init();
	void Update();

	void CreatePlayer();


private:
	//Player _player; 
	Player* _player;
	//class Player* _player;
	// 이렇게 바로 선언 할수도 있음


	// 위 코드들의 차이는 크다고 말했었다.
	// 멤버 클래스로 들고 있으면 Game의 설계도를 만약에 만든다고 가정을 했을때,
	// 게임을 설계하기 위해서는 플레이어가 반드시 있어야 된다는 얘기가 된다
	// 즉, 게임이라는 거가 플레이어를 포함하고 있다 보니까
	// 결국 플레이어라는 설계도가 완성이 되어야지만 이게임도 뭔가 덧붙여가지고 최종적으로 완성할수
	// 있다는 얘기가 된다.
	// 즉 이 게임과 플레이어라는 클래스 사이에 엄청난 의존감이 생김
	// 그래서 멤버 클래스 형태로 들고 있는건 굉장히 안좋은 설계이다
	// 나중에 이 플레이어가 기사일수도 있고 궁수일수도 있고 경우가 다양해서
	// 만약에 이렇게 플레이어라는 애로 들고 있으면 나이트라거나 아처라거나 메이지라거나 쿨하게 저장할수 없다
	// 왜냐면 플레이어라는 클래스 자체가 나이트 보다 한참 작기 때문이다
	// 그래서 부분적으로 정보가 잘릴수 있음
	Field* _field;
};