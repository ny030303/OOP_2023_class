# note06

# 내용 정리

## I. C++에서의 상속

- **클래스 사이**에서 **상속관계**를 정의한다.
- **기본 클래스**(부모)의 **속성**과 **기능**을 **파생 클래스**(자식)에 **물려주는 것**이다.
    - 기본 클래스(base class) - 상속해주는 클래스. 부모 클래스
    - 파생 클래스(derived class) – 상속받는 클래스. 자식 클래스
        - 기능과 속성을 **물려받고** **자신만의 속성 및 기능**을 **추가**하여 개발함.

![Screenshot_2023-11-06-12-11-59-978.jpeg](note06%200d115c3c400345f3b1504e9755327847/Screenshot_2023-11-06-12-11-59-978.jpeg)

### 목적 및 장점

- 계층적 분류
- 관리의 용이함
- 재사용과 확장을 통한 소프트웨어 생산성 향상

### 상속 관계로 클래스의 간결화 사례

- **하이어라키 구조**(계층 구조)

![Screenshot_2023-11-06-12-26-32-665.jpeg](note06%200d115c3c400345f3b1504e9755327847/Screenshot_2023-11-06-12-26-32-665.jpeg)

### 상속 선언 하는 방법

- Person: **기본** 클래스
- Student: **파생** 클래스

- Student: **기본** 클래스
- StudentWorker: **파생** 클래스

```cpp
class Student : public Person {
	// Person을 상속받는 Student 선언
.....
};
class StudentWorker : public Student {
	// Student를 상속받는 StudentWorker 선언
.....
};
```

## II. 상속과 객체 포인터

### 업 캐스팅

- **파생 클래스** **포인터**가 **기본 클래스** **포인터**에 치환되는 것

![Screenshot_2023-11-06-13-10-57-351.jpeg](note06%200d115c3c400345f3b1504e9755327847/Screenshot_2023-11-06-13-10-57-351.jpeg)

### 다운 캐스팅

- **기본 클래스**의 **포인터**가 **파생 클래스**의 **포인터**에 치환되는 것

![Screenshot_2023-11-06-13-15-15-298.jpeg](note06%200d115c3c400345f3b1504e9755327847/Screenshot_2023-11-06-13-15-15-298.jpeg)

## III. protected 접근 지정

- private 멤버
    - 선언된 클래스 **내에서만 접근** 가능
    - 파생 클래스에서도 기본 클래스의 private 멤버 **직접 접근 불가**
- public 멤버
    - 선언된 클래스나 외부 어떤 클래스, **모든 외부 함수에 접근** 허용
    - 파생 클래스에서 기본 클래스의 public 멤버 접근 가능
- protected 멤버
    - 선언된 클래스에서 접근 가능
    - **파생 클래스에서만 접근 허용** → 파생 클래스가 아닌 다른 클래스나 외부 함수에서는 protected 멤버를 접근할 수 없다.

![Screenshot_2023-11-06-13-44-55-780.jpeg](note06%200d115c3c400345f3b1504e9755327847/Screenshot_2023-11-06-13-44-55-780.jpeg)

### 생성자 실행 순서

![Screenshot_2023-11-06-13-45-51-568.jpeg](note06%200d115c3c400345f3b1504e9755327847/Screenshot_2023-11-06-13-45-51-568.jpeg)

### 특별하게 명시하지 않으면 묵시적으로 기본클래스(부모)의 기본 생성자를 호출한다.

![Screenshot_2023-11-06-13-50-56-075.jpeg](note06%200d115c3c400345f3b1504e9755327847/Screenshot_2023-11-06-13-50-56-075.jpeg)

## IV. 상속의 종류 - 상속 지정

- 상속받은 클래스 **멤버**의 **접근방법을 지정**할 수 있다.

![Screenshot_2023-11-06-14-01-24-353.jpeg](note06%200d115c3c400345f3b1504e9755327847/Screenshot_2023-11-06-14-01-24-353.jpeg)

## V. 다중 상속

- 상속받고자 하는 **기본 클래스를 나열**한다.
    - **class 파생 클래스 : public  기본 클래스1, public 기본 클래스2**

![Screenshot_2023-11-06-14-14-34-350.jpeg](note06%200d115c3c400345f3b1504e9755327847/Screenshot_2023-11-06-14-14-34-350.jpeg)

### 다중상속의 문제점

→ 예시의 **BaseIO의 mode가 어디쪽 mode인지 모호해진다.**

![Screenshot_2023-11-06-14-21-11-659.jpeg](note06%200d115c3c400345f3b1504e9755327847/Screenshot_2023-11-06-14-21-11-659.jpeg)

### 해결책

### 가상 상속

- 파생 클래스의 선언문에서 기본 클래스 앞에 **virtual로 선언**한다.
- 파생 클래스의 객체가 생성될 때 기본 클래스의 멤버는 **오직 한
번만 생성**
    - 기본 클래스의 멤버가 **중복하여 생성되는 것을 방지**

```cpp
class In : virtual public BaseIO { // In 클래스는 BaseIO 클래스를 가상 상속함
...
};
class Out : virtual public BaseIO { // Out 클래스는 BaseIO 클래스를 가상 상속함
...
};
```

# 예제 정리

## 예제 8-1

```cpp
#include <iostream>
#include <string>
using namespace std;
// 2차원 평면에서 한 점을 표현하는 클래스 Point 선언
class Point {
int x, y; //한 점 (x,y) 좌표값
public:
void set(int x, int y) { this->x = x; this->y = y; }
void showPoint() {
cout << "(" << x << "," << y << ")" << endl;
}
};
class ColorPoint : public Point { // 2차원 평면에서 컬러점을 표현하는 클래스 ColorPoint.Point를 상속받음
string color;// 점의 색 표현
public:
void setColor(string color) { this->color = color; }
void showColorPoint();
};
void ColorPoint::showColorPoint() {
cout << color << ":";
showPoint(); // Point의 showPoint() 호출
}
int main() {
Point p; // 기본 클래스의 객체 생성
ColorPoint cp; // 파생 클래스의 객체 생성
cp.set(3, 4); // 기본 클래스의 멤버 호출
cp.setColor("Red"); // 파생 클래스의 멤버 호출
cp.showColorPoint(); // 파생 클래스의 멤버 호출
}
```

## 예제 8-2

```cpp
#include <iostream>
#include <string>
using namespace std;
class Point {
protected:
int x, y; //한 점 (x,y) 좌표값
public:
void set(int x, int y);
void showPoint();
};
void Point::set(int x, int y) {
this->x = x;
this->y = y;
}
void Point::showPoint() {
cout << "(" << x << "," << y << ")" << endl;
}
class ColorPoint : public Point {
string color;
public:
void setColor(string color);
void showColorPoint();
bool equals(ColorPoint p);
};
void ColorPoint::setColor(string color) {
this->color = color;
}
void ColorPoint::showColorPoint() {
cout << color << ":";
showPoint(); // Point 클래스의 showPoint() 호출
}
bool ColorPoint::equals(ColorPoint p) {
if (x == p.x && y == p.y && color == p.color)
return true;
else
return false;
}
int main() {
Point p; // 기본 클래스의 객체 생성
p.set(2, 3);
p.x = 5; //오류(protected 멤버로 선언된 x,y를 접근하기 때문에 오류 발생)
p.y= 5; //오류(protected 멤버로 선언된 x,y를 접근하기 때문에 오류 발생)
p.showPoint();
ColorPoint cp; // 파생 클래스의 객체 생성
cp.x = 10; //오류(protected 멤버로 선언된 x,y를 접근하기 때문에 오류 발생)
cp.y = 10; //오류(protected 멤버로 선언된 x,y를 접근하기 때문에 오류 발생)
cp.setColor("Red");
cp.showColorPoint();
ColorPoint cp2;
cp2.set(3, 4);
cp2.setColor("Red");
cout << ((cp.equals(cp2)) ? "true" : "false");
}
```

## 예제 8-3

```cpp
#include <iostream>
#include <string>
using namespace std;
class TV {
int size; // 스크린 크기
public:
TV() { size = 20; }
TV(int size) { this->size = size; }
int getSize() { return size; }
};
class WideTV : public TV { // TV를 상속받는 WideTV
bool videoIn;
public:
WideTV(int size, bool videoIn) : TV(size) {
this->videoIn = videoIn;
}
bool getVideoIn() { return videoIn; }
};
class SmartTV : public WideTV { // WideTV를 상속받는 SmartTV
string ipAddr; // 인터넷 주소
public:
SmartTV(string ipAddr, int size) : WideTV(size, true) {
this->ipAddr = ipAddr;
}
string getIpAddr() { return ipAddr; }
};
int main() {
// 32 인치 크기에 "192.0.0.1"의 인터넷 주소를 가지는 스마트 TV 객체 생성
SmartTV htv("192.0.0.1", 32);
cout << "size=" << htv.getSize() << endl;
cout << "videoIn=" << boolalpha << htv.getVideoIn() << endl;
cout << "IP="htv.getIpAddr() << endl;
}
```

## 예제 8-4

```cpp
#include <iostream>
using namespace std;
class Base {
int a;
protected:
void setA(int a) { this->a = a; }
public:
void showA() { cout << a; }
};
class Derived : private Base {
int b;
protected:
void setB(int b) { this->b = b; }
public:
void showB() { cout << b; }
};
int main() {
Derived x;
~~x.a = 5;
x.setA(10);
x.showA();
x.b = 10;
x.setB(10);~~ //오류
x.showB();
}
```

## 예제 8-5

```cpp
#include <iostream>
using namespace std;
class Base {
int a;
protected:
void setA(int a) { this->a = a; }
public:
void showA() { cout << a; }
};
class Derived : protected Base {
int b;
protected:
void setB(int b) { this->b = b; }
public:
void showB() { cout << b; }
};
int main() {
Derived x;
~~x.a = 5;
x.setA(10);
x.showA();~~ //protected로 변경했기 때문에 오류
~~x.b = 10;
x.setB(10);~~ //오류
x.showB(); //고유 public이기 때문에 어디서든 접근 가능하기 때문에 오류가 나지 않음
}
```

## 예제 8-7

```cpp
#include <iostream>
using namespace std;
class Adder {
protected:
int add(int a, int b) { return a + b; }
};
class Subtractor {
protected:
int minus(int a, int b) { return a - b; }
};
//다중상속
class Calculator : public Adder, public Subtractor {
public:
int calc(char op, int a, int b);
};
int Calculator::calc(char op, int a, int b) {
int res = 0;
switch (op) {
case '+': res = add(a, b); break;
case '-': res = minus(a, b); break;
}
return res;
}
int main() {
Calculator handCalculator;
cout << "2 + 4 = "
<< handCalculator.calc('+', 2, 4) << endl;
cout << "100 - 8 = "
<< handCalculator.calc('-', 100, 8) << endl;
}
```