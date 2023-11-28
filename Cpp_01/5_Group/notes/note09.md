# note09

# 내용 정리

## I. C++ 입출력 기초

- 스트림의 **양 끝**에는 **프로그램과 장치**가 **연결**된다
- 입출력 기본 단위 : **바이트**
- 데이터의 흐름, 혹은 데이터를 전송하는 **소프트웨어 모듈**

### C++ 스트림 종류

- **입력** 스트림 (cin)
- **출력** 스트림 (cout)

### C++ 입출력 스트림 버퍼

- 입력 장치로부터 입력된 데이터를 프로그램으로 전달하기 전에 **일시 저장한다**.
- 키 입력 도중 **수정 가능**
    - <Backspace> 키가 입력되면 이전에 입력된 키를 버퍼에서 지움
- C++ 응용 프로그램은 사용자의 키 입력이 끝난 시점에서 읽음

![Untitled](note09%2083f19b27c57047f4b14dffc51304150a/Untitled.png)

### 입출력 방식 2가지

- **스트림 입출력** 방식(stream I/O)
    - **스트림 버퍼**를 이용한 **입출력 방식**이다
    - 입력된 키는 버퍼에 저장된다
        - <Enter>키가 입력되면 프로그램이 버퍼에서 읽어가는 방식
        - 출력되는 데이터는 일차적으로 스트림 버퍼에 저장
        
- **저 수준 입출력** 방식(raw level console I/O)
    - 키가 입력되는 즉시 프로그램에게 키 값 전달
    - <Backspace>키 그 자체도 프로그램에게 바로 전달
    - 게임 등 키 입력이 즉각적으로 필요한 곳에 사용
    - 컴파일러마다 다른 라이브러리나 API 지원

 **C++ 표준은 스트림 입출력 방식만 지원**

### 2003년 이전의 C++ 입출력 라이브러리의 약점

- 문자를 **한 바이트**의 **char로 처리**
    - cin >>로 문자를 읽을 때, 한글 문자 읽을 수 없음
        - 영어나 기호 : 1 바이트의 문자 코드
        - 한글 문자 : 2 바이트의 문자 코드
- 지금도 마찬가지로 cin으로 한글을 문자 단위로는 읽을
수 없음

### 현재의 표준 C++ 입출력 라이브러리

![Screenshot_2023-11-27-12-19-02-426.jpeg](note09%2083f19b27c57047f4b14dffc51304150a/Screenshot_2023-11-27-12-19-02-426.jpeg)

### 입출력 클래스 소개

![Screenshot_2023-11-27-12-22-39-806.jpeg](note09%2083f19b27c57047f4b14dffc51304150a/Screenshot_2023-11-27-12-22-39-806.jpeg)

### C++ 프로그램이 실행될 때 자동으로 생겨나는 스트림

- cin : istream 타입의 스트림 객체로서 키보드 장치와 연결
- cout : ostream 타입의 스트림 객체로서 스크린 장치와 연결
- cerr : ostream 타입의 스트림 객체로서 스크린 장치와 연결
    - 오류 메시지를 출력할 목적
    - 스트림 내부 **버퍼 거치지 않고** 출력
- clog : ostream 타입의 스트림 객체로서 스크린 장치와 연결
    - 오류 메시지를 출력할 목적
    - 스트림 내부에 **버퍼 거쳐** 출력

### istream 멤버 함수 – 문자 입력, get() 함수

![Untitled](note09%2083f19b27c57047f4b14dffc51304150a/Untitled%201.png)

### 문자열 입력 (배열)

![Screenshot_2023-11-27-12-50-19-421.jpeg](note09%2083f19b27c57047f4b14dffc51304150a/Screenshot_2023-11-27-12-50-19-421.jpeg)

### 한 줄 읽기

![Screenshot_2023-11-27-12-59-07-849.jpeg](note09%2083f19b27c57047f4b14dffc51304150a/Screenshot_2023-11-27-12-59-07-849.jpeg)

### 입력 문자 건너 띄기와 문자 개수 알아내기

![Untitled](note09%2083f19b27c57047f4b14dffc51304150a/Untitled%202.png)

## II.포맷 플래그

### 포맷 플래그

- 입출력 스트림에서 **입출력 형식**을 **지정**하기 위한 플래그

### 포맷 플래그를 세팅하는 멤버 함수

![Untitled](note09%2083f19b27c57047f4b14dffc51304150a/Untitled%203.png)

### 포맷 함수 활용(width, fill, precision)

![스크린샷 2023-11-27 133034.png](note09%2083f19b27c57047f4b14dffc51304150a/%25EC%258A%25A4%25ED%2581%25AC%25EB%25A6%25B0%25EC%2583%25B7_2023-11-27_133034.png)

## III. 조작자

### 조작자

- **manipulator, 스트림 조작자(stream manipulator)**
- 조작자는 **함수**다
- 조작자는 항상 **<< 나 >> 연산자**와 함께 사용됨

- **매개 변수 없는** 조작자

```cpp
cout **<< hex <<** showbase << 30 << endl;
cout **<< dec <<** showpos << 100 << endl;
```

![Untitled](note09%2083f19b27c57047f4b14dffc51304150a/Untitled%204.png)

- **매개 변수 있는** 조작자
    - **#include <iomanip> 필요**

```cpp
cout **<< setw(10) <<** setfill('^') << "Hello" << endl;
```

![Untitled](note09%2083f19b27c57047f4b14dffc51304150a/Untitled%205.png)

## IV. 삽입 연산자(<<)와 추출 연산자(>>)

### 삽입 연산자(<<)

- insertion operator, 삽입자라고도 부름
- **ostream 클래스에 중복 작성되어 있음 (중복 연산자 부분 참고)**

```cpp
class ostream : virtual public ios {
	..........
	public :
	**ostream& operator<< (int n); // 정수를 출력하는 << 연산자
	ostream& operator<< (char c); // 문자를 출력하는 << 연산자
	ostream& operator<< (const char* s); // 문자열을 출력하는 << 연산자**
	..........
};
```

### 사용자 삽입 연산자 만들기

- 개발자가 작성한 클래스의 객체를 << 연산자로 출력
- **cin >> p;를 위한 >> 연산자 만들기**

![스크린샷 2023-11-27 135648.png](note09%2083f19b27c57047f4b14dffc51304150a/%25EC%258A%25A4%25ED%2581%25AC%25EB%25A6%25B0%25EC%2583%25B7_2023-11-27_135648.png)

### 추출 연산자(>>)

- extraction operator
- **ostream 클래스에 중복 작성되어 있음 (중복 연산자 부분 참고)**

```cpp
class istream : virtual public ios {
	..........
	public :
	**istream& operator>> (int& n); // 정수를 입력하는 >> 연산자
	istream& operator>> (char& c); // 문자를 입력하는 >> 연산자
	istream& operator>> (const char* s); // 문자열을 입력하는 >> 연산자**
	..........
};
```

### 사용자 추출 연산자 만들기

- 개발자가 작성한 클래스의 객체에 >> 연산자로 입력
- **cin >> p;를 위한 >> 연산자 만들기**

![Untitled](note09%2083f19b27c57047f4b14dffc51304150a/Untitled%206.png)

### 사용자 조작자 만들기

![Untitled](note09%2083f19b27c57047f4b14dffc51304150a/Untitled%207.png)

# 예제 정리

## 예제 11-1 ostream 멤버 함수를 이용한 문자 출력

```cpp
#include <iostream>
using namespace std;
int main() {
// "Hi!"를 출력하고 다음 줄로 넘어간다.
cout.put('H');
cout.put('i');
cout.put(33);
cout.put('\n');
// "C++ "을 출력한다.
cout.put('C').put('+').put('+').put(' ');
char str[] = "I love programming";
cout.write(str, 6); //  str 배열의 6 개의 문자 "I love"를 스트림에 출력
}
```

```cpp
Hi!
C++ I love
```

## 예제 11-2 get()과get(char&)을이용한 한 줄의문자 읽기

```cpp
#include <iostream>
using namespace std;
void get1() {
cout << "cin.get()로 <Enter> 키까지 입력 받고 출력합니다>>";
int ch; // EOF와의 비교를 위해 int 타입으로 선언
while ((ch = cin.get()) != EOF) { // 문자 읽기. EOF 는 -1
cout.put(ch); // 읽은 문자 출력
if (ch == '\n')
break; // <Enter> 키가 입력되면 읽기 중단
}
}
void get2() {
cout << "cin.get(char&)로 <Enter> 키까지 입력 받고 출력합니다>>";
char ch;
while (true) {
cin.get(ch); // 문자 읽기
if (cin.eof()) break; // EOF를 만나면 읽기 종료
cout.put(ch); // ch의 문자 출력
if (ch == '\n')
break; // <Enter> 키가 입력되면 읽기 중단
}
}
int main() {
get1(); // cin.get()을 이용하는 사례
get2(); // cin.get(char&)을 이용하는 사례
}
```

```cpp
cin.get()로 <Enter> 키까지 입력 받고 출력합니다>>Do you love C++?
Do you love C++?
cin.get(char&)로 <Enter> 키까지 입력 받고 출력합니다>>Yes, I do.
Yes, I do.
```

## 예제 11-3 get(char*, int)을 이용한 문자열 입력

```cpp
#include <iostream>
#include <cstring>
using namespace std;
int main() {
char cmd[80];
cout << "cin.get(char*, int)로 문자열을 읽습니다." << endl;
while (true) {
cout << "종료하려면 exit을 입력하세요 >> ";
cin.get(cmd, 80); // 79개까지의 영어 문자 읽음.
if (strcmp(cmd, "exit") == 0) {
cout << "프로그램을 종료합니다....";
return 0;
}
else
cin.ignore(1); // 버퍼에 남아 있는 <Enter> 키 ('\n') 제거
}
}
```

```cpp
cin.get(char*, int)로 문자열을 읽습니다.
종료하려면 exit을 입력하세요 >> ex
종료하려면 exit을 입력하세요 >> exi
종료하려면 exit을 입력하세요 >> exit
프로그램을 종료합니다....
```

## 예제 11-4 getline()으로 한 줄 단위로 문장 읽기

```cpp
#include <iostream>
using namespace std;
int main() {
char line[80];
cout << "cin.getline() 함수로 라인을 읽습니다." << endl;
cout << "exit를 입력하면 루프가 끝납니다." << endl;
int no = 1; // 라인 번호
while (true) {
cout << "라인 " << no << " >> ";
cin.getline(line, 80); // 79개까지의 문자 읽음
if (strcmp(line, "exit") == 0)
break;
cout << "echo --> ";;
cout << line << endl; // 읽은 라인을 화면에 출력
no++; // 라인 번호 증가
}
}
```

```cpp
cin.getline() 함수로 라인을 읽습니다.
exit를 입력하면 루프가 끝납니다.
라인 1 >> It's now or never.
echo --> It's now or never.
라인 2 >> Come hold me tight.
echo --> Come hold me tight.
라인 3 >> Kiss me my darling, be mine tonight.
echo --> Kiss me my darling, be mine tonight.
라인 4 >> 엘비스 프레슬리 노래입니다.
echo --> 엘비스 프레슬리 노래입니다.
라인 5 >> exit
```

## 예제 11-5 setf(), unsetf()를 사용한 포맷 출력

```cpp
#include <iostream>
using namespace std;

int main() {
cout << 30 << endl; // 10진수로 출력

cout.unsetf(ios::dec); // 10진수 해제
cout.setf(ios::hex); // 16진수로 설정
cout << 30 << endl;

cout.setf(ios::showbase); // 16진수로 설정
cout << 30 << endl;

cout.setf(ios::uppercase); // 16진수의 A~F는 대문자로 출력
cout << 30 << endl;

cout.setf(ios::dec | ios::showpoint); // 10진수 표현과 동시에
// 소숫점 이하 나머지는 0으로 출력
cout << 23.5 << endl;

cout.setf(ios::scientific); // 실수를 과학산술용 표현으로 출력
cout << 23.5 << endl;

cout.setf(ios::showpos); // 양수인 경우 + 부호도 함께 출력
cout << 23.5;
}
```

```cpp
30
1e
0x1e
0X1E
23.5000
2.350000E+01
+2.350000E+01
```

## 예제 11-6 width(), fill(), precision()을 사용한 포맷 출력

```cpp
#include <iostream>
using namespace std;
void showWidth() {
cout.width(10); // 다음에 출력되는 "hello"를 10 칸으로 지정
cout << "Hello" << endl;
cout.width(5); // 다음에 출력되는 정수 12를 5 칸으로 지정
cout << 12 << endl;
cout << '%';
cout.width(10); // 다음에 출력되는 "Korea/"만 10 칸으로 지정
cout << "Korea/" << "Seoul/" << "City" << endl;
}
int main() {
showWidth();
cout << endl;
cout.fill('^');
showWidth();
cout << endl;
cout.precision(5);
cout << 11. / 3. << endl;
}
```

Hello
12
%    Korea/Seoul/City

^^^^^Hello
^^^12
%^^^^Korea/Seoul/City

3.6667

## 예제 11-7 매개 변수 없는 조작자 사용

```cpp
#include <iostream>
using namespace std;

int main() {
cout << hex << showbase << 30 << endl;
cout << dec << showpos << 100 << endl;
cout << true << ' ' << false << endl;
cout << boolalpha << true << ' ' << false << endl;
}
```

```cpp
0x1e
+100
+1 +0
true false
```

## 예제 11-8 매개 변수를 가진 조작자 사용 예

```cpp
**#include <iostream>
#include <iomanip>
using namespace std;

int main() {
	cout << showbase;
	
	// 타이틀을 출력한다.
	cout << setw(8) << "Number";
	cout << setw(10) << "Octal";
	cout << setw(10) << "Hexa" << endl;

	// 하나의 수를 십진수, 8진수, 16진수 형태로 한 줄에 출력한다.
	for(int i=0; i<50; i+=5) { 
		cout << setw(8) << setfill('.') << dec << i; // 10진수
		cout << setw(10) << setfill(' ') << oct << i; // 8진수
		cout << setw(10) << setfill(' ') << hex << i << endl; // 16진수
	}
}**
```

```cpp
Number     Octal      Hexa
.......0         0         0
.......5        05       0x5
......10       012       0xa
......15       017       0xf
......20       024      0x14
......25       031      0x19
......30       036      0x1e
......35       043      0x23
......40       050      0x28
......45       055      0x2d
```

## 예제 11-9 Point 객체를 스트림에 출력하는 << 연산자 작성

```cpp
#include <iostream>
using namespace std;

class Point { // 한 점을 표현하는 클래스
	int x, y; // private 멤버
public:
	Point(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	}
	friend ostream& operator << (ostream& stream, Point a);
};

// << 연산자 함수
ostream& operator << (ostream& stream, Point a) {
	stream << "(" << a.x << "," << a.y << ")";
	return stream;
}

int main() {
	Point p(3, 4); // Point 객체 생성
	cout << p << endl; // Point 객체 화면 출력

	Point q(1, 100), r(2, 200); // Point 객체 생성
	cout << q << r < endl; // Point 객체들 연속하여 화면 출력
}
```

```cpp
(3,4)
(1,100)(2,200)
```

## 예제 11-10 Book 클래스를 만들고 Book 객체를 스트림에 출력하는 << 연산자 작성

```cpp
#include <iostream>
#include <string>
using namespace std;

class Book { // 책을 표현하는 클래스
	string title; 
	string press;
	string author; 
public:	
	Book(string title="", string press="", string author="") {
		this->title = title;
		this->press = press;
		this->author = author;
	}
	friend ostream& operator << (ostream& stream, Book b); // friend 선언
};

// << 연산자 함수
ostream& operator << (ostream& stream, Book b) {
	stream << b.title << "," << b.press << "," << b.author;
	return stream;
}

int main() {
	Book book("소유냐 존재냐", "한국출판사", "에리히프롬"); // Book 객체 생성
	cout << book; // Book 객체 book 화면 출력
}
```

```cpp
소유냐 존재냐,한국출판사,에리히프롬
```

## 예제 11-11 Point 객체를 입력 받는 >> 연산자 작성

```cpp
#include <iostream>
using namespace std;

class Point { // 한 점을 표현하는 클래스
	int x, y; // private 멤버
public:	
	Point(int x=0, int y=0) {
		this->x = x; 
		this->y = y;
	}
	friend istream& operator >> (istream& ins, Point &a); // friend 선언
	friend ostream& operator << (ostream& stream, Point a); // friend 선언
};

istream& operator >> (istream& ins, Point &a) { // >> 연산자 함수
	cout << "x 좌표>>";
	ins >> a.x;
	cout << "y 좌표>>";
	ins >> a.y;
	return ins;
}
ostream& operator << (ostream& stream, Point a) { // << 연산자 함수
	stream << "(" << a.x << "," << a.y << ")";
	return stream;
}

int main() {
	Point p; // Point 객체 생성
	cin >> p;  // >> 연산자 호출하여 x 좌표와 y 좌표를 키보드로 읽어 객체 p 완성
	cout << p;  // << 연산자 호출하여 객체 p 출력
}
```

```cpp
x 좌표>>100
y 좌표>>200
(100,200)
```

## 예제 11-12 사용자 정의 조작자 만들기

```cpp
#include <iostream>
using namespace std;

ostream& fivestar(ostream& outs) {
	return outs << "*****";
}

ostream& rightarrow(ostream& outs) {
	return outs << "---->";
}

ostream& beep(ostream& outs) {
	return outs << '\a'; // 시스템 beep(삑 소리) 발생
}

int main() {
	cout << "벨이 울립니다" << beep << endl;
	cout << "C" << rightarrow << "C++" << rightarrow << "Java" << endl;
	cout << "Visual" << fivestar << "C++" << endl;
}
```

```cpp
벨이 울립니다
C---->C++---->Java
Visual*****C++
```

## 예제 11-13 사용자 정의 조작자 만들기

```cpp
#include <iostream>
#include <string>
using namespace std;

istream& question(istream& ins) {
	cout << "거울아 거울아 누가 제일 예쁘니?";
	return ins;
}

int main() {
	string answer;
	cin >> question >> answer;
	cout << "세상에서 제일 예쁜 사람은 " << answer << "입니다." << endl;
}
```

```cpp
거울아 거울아 누가 제일 예쁘니?백설공주
세상에서 제일 예쁜 사람은 백설공주입니다.
```