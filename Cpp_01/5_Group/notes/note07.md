# note07

# 내용 정리

## 상속 관계에서의 함수 재정의 - 복습

```cpp
#include <iostream>
using namespace std;
class Base {
public:
	void f() { cout << "Base::f() called" << endl; }
};
class Derived : public Base {
public:
	void f() { cout << "Derived::f() called" << endl; }
};
void main() {
	Derived d, *pDer;
	pDer = &d;
	pDer->f(); // Derived::f() 호출
	Base* pBase;
	pBase = pDer; // 업캐스팅
	pBase->f(); // Base::f() 호출
}
```

⇒ 함수가 중복 될 경우, 다음과 같이 **업캐스팅**을 하여 각각 다른 함수를 사용할  수 있다.

## I. 가상 함수와 오버라이딩

### 가상 함수(virtual function)

- **virtual** 키워드로 선언된 **멤버 함수**이다.
- 컴파일러에게 함수에 대한 호출 바인딩을 **실행 시간까지 미루도록 지시**

### 함수 오버라이딩(function overriding)

- 파생 클래스에서 기본 클래스의 가상 함수와 동일한 이름의 함수 선
언하는 것
    - 이는 기본 클래스의 동일한 함수는 사용하지 않는다는 것
- 파생 클래스에서 오버라이딩한 함수가 호출되도록 **동적 바인딩**

### 재정의와 오버라이딩

**재정의**: **동등한 호출기회**를 갖는 **n가지 이상의 함수가 존재**하는 것.

**오버라이딩**: 두 함수가 존재하지만 기본 클래스의 함수는 존재감을 잃고 **항상 파생 클래스가 호출** 되는 것. → **대신 기본클래스의 함수를 가상 함수(virtual)로 만들어야 파생클래스에 오버라이딩이 된다.**

오버라이딩 사례

```cpp
class Base {
public:
	virtual void f() { cout << "Base::f() called" << endl; }
};
class Derived : public Base {
public:
	void f() { cout << "Derived::f() called" << endl; }
};
```

오버라이딩 사례2

```cpp
class Base {
public:
	virtual void f() { cout << "Base::f() called" << endl; }
};
class Derived : public Base {
public:
	virtual void f() { cout << "Derived::f() called" << endl; }
};
```

## II. 동적 바인딩

- 기본 클래스에 대한 포인터로 가상 함수를 호출하는 경우
- 객체 내에 오버라이딩한 파생 클래스의 함수를 찾아 실행된다.
    - 실행 중에 이루어진다.

![Untitled](note07%209793d2de99424e40b0fd3633e4660881/Untitled.png)

⇒ 예시

```cpp
#include <iostream>
using namespace std;
class Shape {
public:
void paint() {
	draw();
}
virtual void draw() {
cout << "Shape::draw() called" << endl;
}
};
class Circle : public Shape {
public:
virtual void draw() {
	cout << "Circle::draw() called" << endl;
}
};
int main() {
	Shape *pShape = new Circle(); // 업캐스팅
	pShape->paint();
	delete pShape;
}
```

결과 ⇒  Circle::draw() called

이유? : 위 코드는 파생클래스 생성자로 생성하여 기본 클래스로 업캐스팅 됐다. 이때 기본 클래스가 된 객체의 paint()를 호출하면 기본클래스의 paint()가 실행 될 거라 예상할 수 있지만, 실제 실행은 이전에 **파생 클래스 Circle의 paint()가 호출된다.** 기본에 shape의 virtual 함수로 정의된 draw()는 **파생 클래스 생성자로 객체 생성할 때 동적 바인딩** 됐다는 것을 확인할 수 있다. 

![Untitled](note07%209793d2de99424e40b0fd3633e4660881/Untitled%201.png)

## III. 오버라이딩 특징

- 오버라이딩의 성공 조건: **가상 함수 이름, 매개 변수 타입과 개수, 리턴 타입이 모두 일치**

![Untitled](note07%209793d2de99424e40b0fd3633e4660881/Untitled%202.png)

![Untitled](note07%209793d2de99424e40b0fd3633e4660881/Untitled%203.png)

### 상속이 반복되는 경우

⇒ 이 때도 가상함수로써 동적 바인딩이 된다.

(ex. 9-3 예제)

### 범위 지정 연산자(::)

- 정적 바인딩 지시하는 연산자이다.
- **기본클래스::가상함수()** 형태로 기본 클래스의 가상 함수를 정적
바인딩으로 호출

![Untitled](note07%209793d2de99424e40b0fd3633e4660881/Untitled%204.png)

## IV. 가상 소멸자

- 소멸자를 virtual 키워드로 선언한다.
- 소멸자를 호출하면 동적 바인딩 발생한다.
    - 가상 소멸자 경우
        - ~Base() 소멸자 호출(ex. delete p)
        - ~Derived() 실행
        - ~Base() 실행

## 오버로딩과 함수 재정의, 오버라이딩 비교

![Screenshot_2023-11-13-13-25-55-194.jpeg](note07%209793d2de99424e40b0fd3633e4660881/Screenshot_2023-11-13-13-25-55-194.jpeg)

## V. 가상 함수와 오버라이딩 활용 사례

### 1) 가상 함수를 가진 기본 클래스의 목적

- 클래스 간의 관계를 설계할 때 이런 형태를 사용한다.

![Screenshot_2023-11-13-13-34-33-548.jpeg](note07%209793d2de99424e40b0fd3633e4660881/Screenshot_2023-11-13-13-34-33-548.jpeg)

### 2) 가상 함수 오버라이딩

- 파생 클래스마다 다르게 구현하는 다형성

```cpp
void Circle::draw() { cout << "Circle" << endl; }
void Rect::draw() { cout << "Rectangle" << endl; }
void Line::draw() { cout << "Line" << endl; }
```

### 3) 동적 바인딩 실행 : 파생 클래스의 가상 함수실행

![main() 함수가 실행될 때 구성된 객체의 연결](note07%209793d2de99424e40b0fd3633e4660881/Untitled%205.png)

main() 함수가 실행될 때 구성된 객체의 연결

### 4) 기본 클래스의 포인터 활용

- 기본 클래스의 포인터로 파생 클래스 접근

## VI. 추상 클래스

### **순수 가상 함수**

- 코드가 없고 선언만 있는 가상 멤버 함수
    - **멤버 함수의 원형=0**;으로 선언

```cpp
class Shape {
public:
	virtual void draw()=0; // 순수 가상 함수 선언
};
```

### 추상 클래스란?

- **최소한 하나의 순수 가상 함수**를 가진 **클래스**

```cpp
class Shape { // Shape은 추상 클래스
Shape *next;
public:
	void paint() {
		draw();
	}
	virtual void draw() = 0; // 순수 가상 함수
};

void Shape::paint() {
	draw(); // 순수 가상 함수라도 호출은 할 수 있다.
}
```

### 추상 클래스의 특징

- 온전한 클래스가 아니므로 객체 생성 불가능
- 추상 클래스의 포인터는 선언 가능

### 추상 클래스의 목적

- 추상 클래스의 인스턴스를 생성할 목적 아니다.
- 순수 가상 함수를 통해 파생 클래스에서 구현할 함수의 형태(원형)을
보여주는 **인터페이스 역할**
- 추상 클래스의 모든 멤버 함수를 순수 가상 함수로 선언할 필요 없다.

![Screenshot_2023-11-13-14-06-52-685.jpeg](note07%209793d2de99424e40b0fd3633e4660881/Screenshot_2023-11-13-14-06-52-685.jpeg)

# 예제 정리

## 예제 9-2

```cpp
#include <iostream> //오버라이딩
using namespace std;
class Base {
public:
virtual void f() { cout << "Base::f() called" << endl; }
};
class Derived : public Base {
public:
virtual void f() { cout << "Derived::f() called" << endl; }
};
int main() {
Derived d, * pDer;
pDer = &d;
pDer->f(); // Derived::f() 호출
Base* pBase;
pBase = pDer; // 업 캐스팅
pBase->f(); // 동적 바인딩 발생!! Derived::f() 실행
}
```

```jsx
Derived::f() called
Derived::f() called
```

```cpp
#include <iostream> //함수 재정의 
using namespace std;
class Base {
public:
void f() { cout << "Base::f() called" << endl; }
};
class Derived : public Base {
public:
void f() { cout << "Derived::f() called" << endl; }
};
int main() {
Derived d, * pDer;
pDer = &d;
pDer->f(); // Derived::f() 호출
Base* pBase;
pBase = pDer; // 업 캐스팅
pBase->f(); // 동적 바인딩 발생!! Derived::f() 실행
}
```

```cpp
Derived::f() called
Base::f() called
```

## 예제 9-3

```cpp
#include <iostream>
using namespace std;
class Base {
public:
virtual void f() { cout << "Base::f() called" << endl; }
};
class Derived : public Base {
public:
void f() { cout << "Derived::f() called" << endl; }
};
class GrandDerived : public Derived {
public:
void f() { cout << "GrandDerived::f() called" << endl; }
};
int main() {
GrandDerived g;
Base* bp;
Derived* dp;
GrandDerived* gp;
bp = dp = gp = &g;
bp->f();
dp->f();
gp->f();
}
```

```cpp
GrandDerived::f() called
GrandDerived::f() called
GrandDerived::f() called
```

## 예제 9-4

```cpp
#include <iostream>
using namespace std;
class Shape {
public:
virtual void draw() {
cout << "--Shape--";
}
};
class Circle : public Shape {
public:
virtual void draw() {
Shape::draw(); // 기본 클래스의 draw() 호출
cout << "Circle" << endl;
}
};
int main() {
Circle circle;
Shape * pShape = &circle;
pShape->draw();
pShape->Shape::draw();
}
```

```cpp
-Shape--Circle
--Shape--
```

## 예제 9-6

```cpp
#include <iostream>
using namespace std;
class Base {
public:
virtual ~Base() { cout << "~Base()" << endl; }
};
class Derived : public Base {
public:
virtual ~Derived() { cout << "~Derived()" << endl; }
};
int main() {
Derived* dp = new Derived();
Base* bp = new Derived();
delete dp; // Derived의 포인터로 소멸
delete bp; // Base의 포인터로 소멸
}
```

```cpp
~Derived()
~Base()
~Derived()
~Base()
```

## 예제 9-7

```cpp
#include <iostream>
using namespace std;
class Calculator {
void input() {
cout << "정수 2 개를 입력하세요>> ";
cin >> a >> b;
}
protected:
int a, b;
virtual int calc(int a, int b) = 0; // 두 정수의 합 리턴
public:
void run() {
input();
cout << "계산된 값은 " << calc(a, b) << endl;
}
};
int main() {
Adder adder;
Subtractor subtractor;
adder.run();
subtractor.run();
}
class Adder : public Calculator {
protected:
int calc(int a, int b) { // 순수 가상 함수 구현
return a + b;
}
};
class Subtractor : public Calculator {
protected:
int calc(int a, int b) { // 순수 가상 함수 구현
return a - b;
}
};
```