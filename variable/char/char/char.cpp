#include <iostream>
using namespace std;
// 제3장 : 문자와 문자열
// bool은 그냥 정수지만, 참/거짓을 나타내기 위해 사용한다 했었다
// 사실 char도 마찬가지, 그냥 정수지만 '문자' 의미를 나타내기 위해 사용

// char : 알파벳 / 숫자 문자를 나타낸다.
// wchar_t:  유니코드 문자를 나타낸다.
// ASCII (American Standard code for Information Interchange)

// '문자'의 의미로 작은 따옴표 '' 사용


char ch = 'a';
char ch2 = '1';
char ch3 = 'a' + 1;

// 국제화 시대에는 영어만으로 서비스 할 수 없음.
// 전세계 모든 문자에 대해 유일 코드를 부여한것이 유니코드 (Unicode)
// 참고) 유니코드에서 가장많은 번호를 차지하는게 한국어/중국어

// 유니코드는 표기방식이 여러가지가 있는데 대표적으로 utf8 UTF16
// UTF8
// - 알파벳, 숫자 1바이트 (ASCII 동일한 번호)
// - 유럽 지역의 문자는 2바이트\
// - 한글 , 한자 등 3바이트
// UTF16
// -알파벳, 숫자, 한글, 한자 등 거의 대부분 문자 2바이트
// 매우 예외적인 고대문자만 4바이트 (사실상 무시)

//wchar_t wch = L'안'; // 유니코드라는것을 확실히 표기하기위해 글자 옆에 L을 붙임.
// UTF16을 저장하는 타입은 wchar_t 이다. 

//wchar_t wch = 0xc548; // L'안'

wchar_t wch = L'\''; // 작은 따옴표를 표현하는 방법

// Escape Sequence
// 표기하기 애매한 애들을 표현
// \0 = 아스키 코드 0 = Null
// \t = 아스키 코드 9 = Tab
// \n = 아스키 코드 10 = LineFeed (한줄 아래로)
// \r = 아스키 코드 13 = CarriageReturn (커서를 맨 처음으로 이동.)
//  작은 따옴표를 표현하는 방법
// \r\n == enter

// 문자열
// 문자들이 열을 지어서 모여 있는것 (문자 배열)
// 정수 (1~8바이트) 고정 길이로
// 문자들이 모여있긴한데 끝에는 무조건 \00(null) => 이게 있어야 문자열이 끝났다는것을 알리는것.

// char str[] = { 'h', 'e', 'l' ,'l', 'o' };
// 전역 변수로 사용했을땐 문제가 없지만 함수안에서 지역변수로서 선언한뒤 문자열을 표현할때는 무조건 문자열 끝에 '\0'을 붙여야함.
char str2[] = "Hello World"; // 위에처럼 사용하는것 보다 ""으로 문자열을 나타내는게 \0을 표시할 필요가없어서 더편함.
wchar_t str[] = L"Hello World"; // 유니코드로 자동으로 변환됨.

int main()
{
	//cout << ch << endl;
	//cout << ch2 << endl;
	//cout << ch3 << endl;
	//
	//// cout은 char 전용
	//wcout.imbue(locale("kor"));
	//wcout << wch << endl;
	char str[] = { 'h', 'e', 'l' ,'l', 'o', '\0' };
	cout << str2 << endl;
}