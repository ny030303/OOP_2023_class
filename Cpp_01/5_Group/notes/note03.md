# note03

# 내용 정리

## I. C++ 클래스 만드는 방법

1. **class (이름) {     }** 이런식으로 클래스 이름을 작성한다.
2. **클래스 선언문**에서 선언이 필요한 것들을 선언한다.
    - private-public을 작성하면서 접근 비접근을 정한다.
    - 객체 안에 사용될 변수들 prototype을 정하고 선언한다.
3. **클래스 구현문**에서 메서드들의 동작들을 구현한다.

## II. 생성자

- 생성자란: 객체가 **생성되는 시점**에서 **자동으로 호출되는 멤버 함수**이다.
    
    +클래스 이름과 동일한 함수이다. 
    
- 목적: 객체가 생성될 때 필요한 **초기화**를 하기 위해서이다.

- **매개변수에 따라 여러 생성자를 만들 수 있다. (ppt 예제 3-3 참고)**

### 위임 생성자

- 위임 생성자란: **생성자가 다른 생성자를 호출하는 것**을 뜻한다.
- **타겟 생성자**: 객체 **초기화**를 직접 해주는 생성자
- **위임 생성자**: 타겟 생성자를 **호출**하는 생성자.  → 객체 초기화를 위임한다(타겟에게)

### 기본 생성자

- 기본 생성자란: 클래스에 생성자가 **선언되지 않았을 경우** **자동**으로 만들어주는 생성자.
- **생성자는 꼭 있어야 한다.**
- ⇒ 만들지 않으면 컴파일러가 기본 생성자를 자동으로 생성한다.

## 토론주제: 기본 생성자가 자동으로 생성되지 않은 경우

→ 기본생성자가 생기지 않을것이다. 기본 생성자는 아무 생성자를 만들지 않았을때 생성이 된다. 따라서 donut 객체를 생성할때 존재하지 않는 생성자로 오류가 날 것.

ex. 

```cpp
class Circle {
public:
	int radius;
	double getArea();
	Circle(int r);
};
Circle::Circle(int r) {
	radius = r;
}
int main() {
	Circle pizza(30);
	Circle donut;
}
```

## III. 소멸자

- 소멸자란: 객체가 소멸되는 시점에서 **한번만** **자동**으로 호출되는 함수이다.
- **메모리 소멸 직전** 호출된다.
- 생성자는 여러 선언을 할 수 있지만 **소멸자는 X, 중복 할 수 없다.**
- 소멸자 함수의 이름은 **클래스 이름 앞에 ~**를 붙인다.
- 선언되어 있지 **않으면** 기본 소멸자가 **자동 생성**된다.

### 생성/소멸 실행 순서

- 지역 객체: 함수 내에 선언된 객체
    - 프로그램 선언된 **순서대로** 생성
    - **함수가 사라지면**, 객체 생성된 순서의 **역순으로 소멸**
- 전역 객체: 함수 밖에 선언된 객체
    - 함수가 호출되는 순간에 **순서대로** 생성
    - **프로그램이 종료**되면, 전역객체가 생성된 순서 **역순으로 소멸**

**예제 3-8 지역 객체와 전역 객체의 생성 및 소멸 순서 → 예측**

⇒ 전역 객체 생성 (1000, 2000)

⇒ 지역 객체 생성 (1, 30)

⇒ 지역 객체 생성 (100, 200)

⇒ 지역 객체 삭제(100, 200)

⇒ 지역 객체 삭제(1, 30)

⇒ 전역 객체 삭제(1000, 2000)

```cpp
Circle globalDonut(1000);
Circle globalPizza(2000);
void f() {
Circle fDonut(100);
Circle fPizza(200);
}
int main() {
Circle mainDonut;
Circle mainPizza(30);
f();
}
```

## IV. 접근 지정자

- **캡슐화**를 목적으로 사용된다.
- **private, public, protected**가 있다.

## V. 인라인 함수

- 시간 **오버헤드**가 발생하는 것을 **개선하기 위해** 사용함.(실제 계산시간 보다 함수 호출에 따른 시간이 더 길면 오버헤드다.)
- **inline** 키워드로 선언한다.
- 장점: 프로그램 **실행 시간**이 **빨라진다.**
- 단점: 컴파일 할 **전체 코드 크기**가 **증가**한다.
    - 30퍼 정도 증가함
    - 따라서 짧은 코드 함수를 선언하는 것이 좋음.

## VI. C++ 구조체

- class와 struct(구조체)는 사용법이 거의 동일하다.
- 사용이유: C언어와 호환성을 위해
- 구조체에서는 디폴트 접근지정이 public 이지만 클래스에서 디폴트 접근지정은 private이다.

### 바람직한 C++ 작성법

 ⇒ 헤더파일과 cpp파일을 분리하여 작성하는 것이 좋다.

헤더파일의 중복 include 문제

⇒ 조건 컴파일로 해결할 수 있다. 

```cpp
**#ifndef CIRCLE_H
#define CIRCLE_H**
class Circle {
private:
	int radius;
public:
	Circle();
	Circle(int r);
	double getArea();
};
**#endif**
```

# 예제 정리

## 예제 3-1 Circle - 클래스의 객체 생성 및 활용

```cpp
#include <iostream>
using namespace std;

class Round {
public:
	int num;
	double getSum();
};

double Round::getSum() {
	return num + num;
}

int main() {
	Round a;
	a.num = 3;
	double res1 = a.getSum();
	cout << res1 << ": res1";
	return 0;
}
```

## 예제 3-2(실습) – Rectangle 클래스 만들기

```cpp
#include <iostream>
using namespace std;

class Rectangle{
public:
	int width;
	int height;
	double getarea();
};

double Rectangle::getarea() {
	return width * height;
}

int main() {
	Rectangle rect;
	rect.width = 3;
	rect.height = 5;
	cout << "사각형의 면적은 " << rect.getarea() << endl;
}
```

## 예제3-3 - 2 개의 생성자를 가진 Circle 클래스

```cpp
#include <iostream> 
using namespace std;

class Circle; {
public:
	int radius;
	Circle();
	Circle(int r);
	double getArea();
};

Circle::Circle() {
	radius = 1;
	cout << "반지름" << radius << "원 생성" << endl;
}

Circle::Circle(int r) {
	radius = r;
	cout << "반지름" << radius << "원 생성" << endl;
}

double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle donut;
	double area = donut.getArea();
	cout << "donut 면적은" << area << endl;

	Circle pizza(30);
	area=pizza.getArea();
	cout << "pizza 면적은" << area << endl;
}
```

## 예제 3-4 생성자에서 다른 생성자 호출 연습

```cpp
lass Circle {
public:
	int radius;
	Circle(); // 위임 생성자
	Circle(int r); // 타겟 생성자
	double getArea();
};
Circle::Circle() : Circle(1) { } // 위임 생성자
Circle::Circle(int r) { // 타겟 생성자
	radius = r;
	cout << "반지름 " << radius << " 원 생성" << endl;
}
double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {

	Circle donut; // 매개 변수 없는 생성자 호출
	double area = donut.getArea();
	cout << "donut 면적은 " << area << endl;
	Circle pizza(30); // 매개 변수 있는 생성자 호출
	area = pizza.getArea();
	cout << "pizza 면적은 " << area << endl;

	return 0;
}
```

## 예제 3-6(실습) – Rectangle 클래스 만들기

```cpp
#include <iostream>
using namespace std;

class Rectangle {
public:
	int x;
	int y;
	Rectangle();
	Rectangle(int x, int y);
	Rectangle(int num);
	bool isSquare();
};

Rectangle::Rectangle() : Rectangle(1, 1) {}
Rectangle::Rectangle(int num) : Rectangle(num, num) {}
Rectangle::Rectangle(int x, int y) : x(x), y(y) {}

bool Rectangle::isSquare() {
	if (x == y) return true;
	else return false;
};

int main() {
	Rectangle rect1;
	Rectangle rect2(3, 5);
	Rectangle rect3(3);
	if (rect1.isSquare()) cout << "rect1은 정사각형이다." << endl;
	if (rect2.isSquare()) cout << "rect2는 정사각형이다." << endl;
	if (rect3.isSquare()) cout << "rect3는 정사각형이다." << endl;
}
```

```cpp
#include <iost#include <iostream> 
using namespace std;

class Rectangle {
public:
	int width;
	int height;
	Rectangle();
	Rectangle(int w, int h);
	Rectangle(int lenghh);
	double isSquare();
};

Rectangle::Rectangle() {
	width = height=1;
}
Rectangle::Rectangle(int w, int h) {
	width =w, height = h;
}
Rectangle::Rectangle(int length) {
	width = height = length;
}
double Rectangle::isSquare() {
	if (width == height) return true;
	else return false;
}

int main() {
	Rectangle rect1;
	Rectangle rect2(3, 5);
	Rectangle rect3(3);
	if (rect1.isSquare()) cout << "rect1은 정사각형이다." << endl;
	if (rect2.isSquare()) cout << "rect2는 정사각형이다." << endl;
	if (rect3.isSquare()) cout << "rect3는 정사각형이다." << endl;
}eam>
using namespace std;

class Rectangle {
public:
	int x;
	int y;
	Rectangle();
	Rectangle(int x, int y);
	Rectangle(int num);
	bool isSquare();
};

Rectangle::Rectangle() : Rectangle(1, 1) {}
Rectangle::Rectangle(int num) : Rectangle(num, num) {}
Rectangle::Rectangle(int x, int y) : x(x), y(y) {}

bool Rectangle::isSquare() {
	if (x == y) return true;
	else return false;
};

int main() {
	Rectangle rect1;
	Rectangle rect2(3, 5);
	Rectangle rect3(3);
	if (rect1.isSquare()) cout << "rect1은 정사각형이다." << endl;
	if (rect2.isSquare()) cout << "rect2는 정사각형이다." << endl;
	if (rect3.isSquare()) cout << "rect3는 정사각형이다." << endl;
}
```

# 156p 코드 제출 과제 - 답안

main.cpp

```cpp
#include <iostream>
#include "Ram.h"
using namespace std;

int main() {
	Ram ram;
	ram.write(100, 20);
	ram.write(101, 30);
	char res = ram.read(100) + ram.read(101); // 20 + 30 = 50
	ram.write(102, res);
	cout << "102 번지의 값 = " << (int)ram.read(102) << endl;
	
}
```

Ram.cpp

```cpp
#include <iostream>
using namespace std;
#include "Ram.h" 

Ram::Ram()
{
}

Ram::~Ram() {
	cout << "메모리 제거됨" << endl;
}

char Ram::read(int address)
{
	return mem[address];
}

void Ram::write(int address, char value)
{
	mem[address] = value;
}
```

Ram.h

```cpp
class Ram {
	char mem[100 * 1024];
	int size;
public:
	Ram();
	~Ram();
	char read(int address);
	void write(int address, char value);

};
```