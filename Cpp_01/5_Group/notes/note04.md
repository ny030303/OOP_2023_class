# note04

# 내용 정리

## I. 객체 포인터

1. (Class) *(변수이름) 이렇게 작성하면 **포인터 변수**를 선언할 수 있다.
    - ex. Circle *p;
2. &(변수이름) 은 해당변수의 **주소값을 반환**한다.
    - ex. p = &donut;
3. (포인터변수)→멤버 이때 화살표는 포인터를 통해서 **해당주소의 맴버를 접근**할 수 있다.
    - ex.  p→getArea();

## II. 객체 배열

- 객체 배열 선언
    - 배열을 위한 **공간을 할당**한다.
        - ex.1 -  **int** n[3]; ⇒ **정수형** 배열
        - ex.2 - **Circle** c[3]; ⇒ **Circle 타입**의 배열
    - 각 원소 객체마다 **생성자를 실행**할 수 있다.
    - **매개 변수 있는 생성자를 호출할 수 없다.**
        - ex. Circle circleArray[3](5); // 오류
- 배열 소멸
    - 객체마다 **소멸자를 호출**한다.
    - 생성했던 순서의 **반대순**으로 소멸한다.

### 1. 객체 배열 생성

- **기본 생성자 호출시 주의할 점**

![Screenshot_2023-10-16-12-55-41-740.jpeg](note04%20b2de1d6ca31c4ed08569e9b9603d5397/Screenshot_2023-10-16-12-55-41-740.jpeg)

### 2. 객체 배열 초기화

- 배열의 각 원소 객체당 생성자 지정하는 방법이 있다.
    - ex. Circle circleArray[3] = **{ Circle(10), Circle(20), Circle() };**

## III. 2차원 배열

- 2차원 배열 선언할때
    - ex. Circle circles[2][3];
- 2차원 배열 선언과 초기화를 같이할떄
    - ex. Circle circles[2][3] = {{Circle(1), Circle(2), Circle(3)},
        
                                                 {Circle(4), Circle(5), Circle() }};
        
- 다른방식
    - ex.  circles[0][1].setRadius(2);
    circles[0][2].setRadius(3);
    circles[1][0].setRadius(4);
    circles[1][1].setRadius(5);
    circles[1][2].setRadius(6);

## III. 동적 메모리 할당 및 반환

- 전반적인 heap 구조 설명

![Screenshot_2023-10-16-13-33-38-925.jpeg](note04%20b2de1d6ca31c4ed08569e9b9603d5397/Screenshot_2023-10-16-13-33-38-925.jpeg)

- **정적** 할당
    - **변수 선언**을 통해 필요한 메모리 할당
        - 많은 양의 메모리는 배열 선언을 통해 할당
- **동적** 할당
    - 필요한 양이 **예측되지 않는 경우**. 프로그램 작성시 할당 받을 수 없
    음
        - 실행 중에 힙 메모리에서 할당
            - 힙(heap)으로부터 할당
                - 힙은 운영체제가 프로세스(프로그램)의 실행을 시작 시킬 때 동적 할당 공간으로 준 메모리 공간
- C 언어의 동적 메모리 할당 : **malloc()/free() 라이브러리 함수**
사용
- C++의 동적 메모리 할당/반환
    - **new 연산자**
        - 기본 타입 메모리 할당, 배열 할당, 객체 할당, 객체 배열 할당
        - 객체의 동적 생성 - 힙 메모리로부터 객체를 위한 메모리 할당 요청
        - 객체 할당 시 생성자 호출
    - **delete 연산자**
        - new로 할당 받은 메모리 반환
        - 객체의 동적 소멸 - 소멸자 호출 뒤 객체를 힙에 반환
        

### **기본 타입의 메모리 동적 할당 및 반환 과정**

![Screenshot_2023-10-16-13-43-47-628.jpeg](note04%20b2de1d6ca31c4ed08569e9b9603d5397/Screenshot_2023-10-16-13-43-47-628.jpeg)

### delete 사용 시 주의 사항

- **적절치 못한 포인터로 delete하면 실행 시간 오류 발생**
    - 동적으로 **할당 받지 않는 메모리 반환** – 오류
    - 동일한 메모리 **두 번 반환** - 오류

### 배열의 동적 할당 및 반환

- **delete []** 포인터변수로 배열을 반환한다. → 더이상 heap에 X

- int형 변수5개가 있는 배열의 주소를 p에 동적 할당한다.
    
    for문을 돌며 0부터 4까지 값을 넣는다. 
    
    사용이 끝난 배열을 delete [] p;로 반환한다.
    

![Untitled](note04%20b2de1d6ca31c4ed08569e9b9603d5397/Untitled.png)

- 동적 할당 **메모리 초기화 및 delete 시 유의 사항**

![Screenshot_2023-10-16-14-05-43-835.jpeg](note04%20b2de1d6ca31c4ed08569e9b9603d5397/Screenshot_2023-10-16-14-05-43-835.jpeg)

### 객체의 동적 생성 및 반환

![Screenshot_2023-10-16-14-08-46-820.jpeg](note04%20b2de1d6ca31c4ed08569e9b9603d5397/Screenshot_2023-10-16-14-08-46-820.jpeg)

### 동적 메모리 할당과 메모리 누수

![Screenshot_2023-10-16-14-23-02-898.jpeg](note04%20b2de1d6ca31c4ed08569e9b9603d5397/Screenshot_2023-10-16-14-23-02-898.jpeg)

## IV. this 포인터

- **포인터**, **객체 자신 포인터**를 가리킨다.
    - **클래스의 멤버 함수 내에서만** 사용된다.
    - 개발자가 선언하는 변수가 아니고, **컴파일러가 선언한 변수**
        - 멤버 함수에 컴파일러에 의해 **묵시적으로 삽입 선언되는 매개 변수**

### this가 필요한 경우

- 매개변수의 이름과 멤버 변수의 **이름이 같은 경우**
- 멤버 함수가 객체 **자신의 주소를 리턴할 때**
    - **연산자 중복 시에 매우 필요**

### this가 제약 사항

- **멤버 함수가 아닌 함수에서 this** 사용할 수 없다.
    - 객체와의 관련성이 없기 때문
- **static 멤버 함수에서 this** 사용할 수 없다.
    - 객체가 생기기 전에 static 함수 호출이 있을 수 있기 때문

### this 포인터의 실체 – 컴파일러에서 처리

![Untitled](note04%20b2de1d6ca31c4ed08569e9b9603d5397/Untitled%201.png)

# 예제 정리

## 예제 4-1  - 객체 포인터 선언 및 활용

```cpp
#include <iostream>
using namespace std;
class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	double getArea();
};
double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle donut;
	Circle pizza(30);
	// 객체 이름으로 멤버 접근
	cout << donut.getArea() << endl;
	// 객체 포인터로 멤버 접근
	Circle* p;
	p = &donut;
	cout << p->getArea() << endl; // donut의 getArea() 호출
	cout << (*p).getArea() << endl; // donut의 getArea() 호출
	p = &pizza;
	cout << p->getArea() << endl; // pizza의 getArea() 호출
	cout << (*p).getArea() << endl; // pizza의 getArea() 호출
}
```

![Screenshot_2023-10-16-12-29-05-799.jpeg](note04%20b2de1d6ca31c4ed08569e9b9603d5397/Screenshot_2023-10-16-12-29-05-799.jpeg)

- int형 변수의 포인터를 a로 선언한다. a는 c의 포인터이며, *a로 접근하여 20이란 값을 넣을경우 int형 변수 c에 20이 들어간다.

## 예제 4-2  - Circle 클래스의 배열 선언 및 활용

```cpp
#include <iostream>
using namespace std;
class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	double getArea();
};
double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle donut;
	Circle pizza(30);
	// 객체 이름으로 멤버 접근
	cout << donut.getArea() << endl;
	// 객체 포인터로 멤버 접근
	Circle* p;
	p = &donut;
	cout << p->getArea() << endl; // donut의 getArea() 호출
	cout << (*p).getArea() << endl; // donut의 getArea() 호출
	p = &pizza;
	cout << p->getArea() << endl; // pizza의 getArea() 호출
	cout << (*p).getArea() << endl; // pizza의 getArea() 호출
}
```

![Screenshot_2023-10-16-12-52-50-157.jpeg](note04%20b2de1d6ca31c4ed08569e9b9603d5397/Screenshot_2023-10-16-12-52-50-157.jpeg)

## 예제 4–3 - 객체 배열 초기화

```cpp
#include <iostream>
using namespace std;
class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	void setRadius(int r) { radius = r; }
	double getArea();
};
double Circle::getArea() {
	return 3.14 * radius * radius;
}
int main() {
	Circle circleArray[3] = { Circle(10), Circle(20), Circle() }; // Circle 배열 초기화
	for (int i = 0; i < 3; i++)
		cout << "Circle " << i << "의 면적은 " << circleArray[i].getArea() << endl;
}
```

## 예제 4-4 Circle 클래스의 2차원 배열 선언 및 활용

```cpp
#include <iostream>
using namespace std;
class Circle {
	int radius;
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	void setRadius(int r) { radius = r; }
	double getArea();
};
double Circle::getArea() {
	return 3.14 * radius * radius;
}

int main() {
	Circle circles[2][3];
	circles[0][0].setRadius(1);
	circles[0][1].setRadius(2);
	circles[0][2].setRadius(3);
	circles[1][0].setRadius(4);
	circles[1][1].setRadius(5);
	circles[1][2].setRadius(6);
	for (int i = 0; i < 2; i++) // 배열의 각 원소 객체의 멤버 접근
		for (int j = 0; j < 3; j++) {
			cout << "Circle [" << i << "," << j << "]의 면적은 ";
			cout << circles[i][j].getArea() << endl;
		}
}
```

## 예제 4-5 정수형 공간의 동적 할당 및 반환 예

```cpp
#include <iostream>
using namespace std;
int main() {
	int* p;
	p = new int;
	if (!p) {
		cout << "메모리를 할당할 수 없습니다.";
		return 0;
	}
	*p = 5; // 할당 받은 정수 공간에 5 삽입
	int n = *p;
	cout << "*p = " << *p << '\n';
	cout << "n = " << n << '\n';
	delete p;
}
```

## 예제 4–8 Circle 객체의 동적 생성과 반환 응용

```cpp
#include <iostream>
using namespace std;
class Circle {
	int radius;
public:
	Circle();
	Circle(int r);
	~Circle();
	void setRadius(int r) { radius = r; }
	double getArea() { return 3.14 * radius * radius; }
};
Circle::Circle() {
	radius = 1;
	cout << "생성자 실행 radius = " << radius << endl;
}
Circle::Circle(int r) {
	radius = r;
	cout << "생성자 실행 radius = " << radius << endl;
}
Circle::~Circle() {
	cout << "소멸자 실행 radius = " << radius << endl;
}

int main() {
	int radius;
	while (true) {
		cout << "정수 반지름 입력(음수이면 종료)>> ";
		cin >> radius;
		if (radius < 0) break; // 음수가 입력되어 종료한다.
		Circle* p = new Circle(radius); // 동적 객체 생성
		cout << "원의 면적은 " << p->getArea() << endl;
		delete p; // 객체 반환
	}
}
```