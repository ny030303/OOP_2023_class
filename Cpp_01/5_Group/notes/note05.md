# note05

# -문제 풀이-

![20231030_120830.jpg](note05%200c5c9e447dfc4e73b55fe1b94f7b0102/20231030_120830.jpg)

![Screenshot_2023-10-30-14-15-36-595.jpeg](note05%200c5c9e447dfc4e73b55fe1b94f7b0102/Screenshot_2023-10-30-14-15-36-595.jpeg)

# 내용 정리

## I. 프렌드 함수

- **friend** 라는 키워드로 클래스 내에 선언된 함수이다.
- 클래스의 멤버로 선언하기에는 무리가 있고, 클래스의 모든 멤버를 **자유
롭게 접근할 수 있는** 일부 **외부 함수** 작성 해야 할 때 쓰인다.

### 1. 프렌드 함수가 되는 세가지

- 전역 함수 : **클래스 외부**에 선언된 전역 함수
- 다른 클래스의 멤버 함수 : 다른 클래스의 **특정 멤버 함수**
- 다른 클래스 전체 : 다른 클래스의 **모든 멤버 함수**

### 2. 프렌드 선언 방법

1. **외부 함수 equals()**를 Rect 클래스에 프렌드로 선언

```cpp
class Rect { // Rect 클래스 선언
	...
		friend bool **equals(Rect r, Rect s);**
};
```

2. RectManager **클래스의 equals() 멤버 함수**를 Rect 클래스에 프렌드로 선언

```cpp
class Rect {
	.............
	friend bool **RectManager::equals(Rect r, Rect s);**
};
```

3. **RectManager 클래스**의 **모든 멤버 함수**를 Rect 클래스에 프렌드로 선언

```cpp
class Rect {
	.............
	**friend RectManager;**
};
```

## II. 연산자 중복

+ 기호의 사례

- + 기호를 숫자와 물체에 적용할 수 있음으로써 용도가 중복으로 사용된다.
- cpp에 정의되지 않은 객체와 객체의 연산을 할 수 있다.
- 다형성을 가진다.

- 정수 더하기
    
    ```cpp
    int a=2, b=3, c;
    c = a + b; // + 결과 5. 정수가 피연산자일 때 2와 3을 더하기
    ```
    
- 문자열 합치기
    
    ```cpp
    string a="C", c;
    c = a + "++“; // + 결과 “C++". 문자열이 피연산자일 때 두 개의 문자열 합치기
    ```
    
- 색 섞기
    
    ```cpp
    Color a(BLUE), b(RED), c;
    c = a + b; // c = VIOLET. a, b의 두 색을 섞은 새로운 Color 객체 c
    ```
    
- 배열 합치기
    
    ```cpp
    SortedArray a(2,5,9), b(3,7,10), c;
    c = a + b; // c = {2,3,5,7,9,10}. 정렬된 두 배열을 결합한(merge) 새로운 배열 생성
    ```
    

### 1. 연산자 중복의 특징

- C++에 **본래 있는 연산자**만 **중복 가능**
- 피 연산자 타입이 다른 새로운 연산 정의
- 연산자는 **함수 형태**로 구현
- 반드시 **클래스와 관계를 가짐**
- **피연산자의 개수**를 **바꿀 수 없음**
- 연산의 **우선 순위 변경 안됨**
- 모든 연산자가 **중복 가능하지 않음**

### 2. 연산자 함수 구현 방법

1. 클래스의 멤버 함수로 구현

2. 외부 함수로 구현하고 클래스에 프렌드 함수로 선언

- 리턴타입 **operator**연산자(매개변수리스트);

### 단항 연산자 중복

- 연산자가 하나 뿐인 연산자
- 연산자 중복 방식은 이항 연산자의 경우와 거의 유사함
- 단항 연산자 종류
    - **전위** 연산자(prefix operator)
        - !op, ~op, ++op, --op
        
        ![Untitled](note05%200c5c9e447dfc4e73b55fe1b94f7b0102/Untitled.png)
        
    - **후위** 연산자(postfix operator)
        - op++, op—
        
        ![Untitled](note05%200c5c9e447dfc4e73b55fe1b94f7b0102/Untitled%201.png)
        

# 예제 정리

## 예제 7–1 프렌드 함수 만들기

```cpp
#include <iostream>
using namespace std;

class Rect;
bool equals(Rect r, Rect s); // equals() 함수 선언
class Rect { // Rect 클래스 선언
	int width, height;
public:
	Rect(int width, int height) { this->width = width; this->height = height; }
	friend bool equals(Rect r, Rect s);
};
bool equals(Rect r, Rect s) { // 외부 함수
	if (r.width == s.width && r.height == s.height) return true;
	else return false;
}

int main() {
	Rect a(3, 4), b(4, 5);
	if (equals(a, b)) cout << "equal" << endl;
	else cout << "not equal" << endl;
}
```

## 예제 7–2 다른 클래스의 멤버 함수를 프렌드로 선언

```cpp
#include <iostream>
using namespace std;
class Rect;
class RectManager { // RectManager 클래스 선언
public:
	bool equals(Rect r, Rect s);
};
class Rect { // Rect 클래스 선언
	int width, height;
public:
	Rect(int width, int height) { this->width = width; this->height = height; }
	friend bool RectManager::equals(Rect r, Rect s);
};
bool RectManager::equals(Rect r, Rect s) {
	if (r.width == s.width && r.height == s.height) return true;
	else return false;
}
int main() {
	Rect a(3, 4), b(3, 4);
	RectManager man;
	if (man.equals(a, b)) cout << "equal" << endl;
	else cout << "not equal" << endl;
}
```

## 예제 7–3 다른 클래스 전체를 프렌드로 선언

```cpp
#include <iostream>
using namespace std;
class Rect;
class RectManager { // RectManager 클래스 선언
public:
	bool equals(Rect r, Rect s);
	void copy(Rect& dest, Rect& src);
};
class Rect { // Rect 클래스 선언
	int width, height;
public:
	Rect(int width, int height) { this->width = width; this->height = height; }
	friend RectManager;
};
bool RectManager::equals(Rect r, Rect s) { // r과 s가 같으면 true 리턴
	if (r.width == s.width && r.height == s.height) return true;
	else return false;
}
void RectManager::copy(Rect& dest, Rect& src) { // src를 dest에 복사
	dest.width = src.width; dest.height = src.height;
}
int main() {
	Rect a(3, 4), b(5, 6);
	RectManager man;
	man.copy(b, a); // a를 b에 복사한다.
	if (man.equals(a, b)) cout << "equal" << endl;
	else cout << "not equal" << endl;
}
```

## 예제 7-8 전위 ++ 연산자 작성

```cpp
#include <iostream>
using namespace std;
class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick; this->punch = punch;
	}
	void show();
	Power& operator++ (); // 전위 ++ 연산자 함수 선언
};
void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}
Power& Power::operator++() {
	kick++;
	punch++;
	return *this; // 변경된 객체 자신(객체 a)의 참조 리턴
}
int main() {
	Power a(3, 5), b;
	a.show();
	b.show();
	b = ++a; // 전위 ++ 연산자 사용
	a.show();
	b.show();
}
```

## 예제 7-10 후위 ++ 연산자 작성

```cpp
#include <iostream>
using namespace std;
class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick; this->punch = punch;
	}
	void show();
	Power operator++ (int x); // 후위 ++ 연산자 함수 선언
};
void Power::show() {
	cout << "kick=" << kick << ','
		<< "punch=" << punch << endl;
}
Power Power::operator++(int x) {
	Power tmp = *this; // 증가 이전 객체 상태를 저장
	kick++;
	punch++;
	return tmp; // 증가 이전 객체 상태 리턴
}

int main() {
	Power a(3, 5), b;
	a.show();
	b.show();
	b = a++; // 후위 ++ 연산자 사용
	a.show(); // a의 파워는 1 증가됨
	b.show(); // b는 a가 증가되기 이전 상태를 가짐
}
```

## 예제 7-11 2+a를 위한 + 연산자 함수를 프렌드로 작성

```cpp
#include <iostream>
using namespace std;
class Power {
	int kick;
	int punch;
public:
	Power(int kick = 0, int punch = 0) {
		this->kick = kick; this->punch = punch;
	}
	void show();
	friend Power operator+(int op1, Power op2); // 프렌드 선언
};
void Power::show() {
	cout << "kick=" << kick << ',' << "punch=" << punch << endl;
}
Power operator+(int op1, Power op2) {
	Power tmp; // 임시 객체 생성
	tmp.kick = op1 + op2.kick; // kick 더하기
	tmp.punch = op1 + op2.punch; // punch 더하기
	return tmp; // 임시 객체 리턴
}

int main() {
	Power a(3, 5), b;
	a.show();
	b.show();
	b = 2 + a; // 파워 객체 더하기 연산
	a.show();
	b.show();
}
```

![Untitled](note05%200c5c9e447dfc4e73b55fe1b94f7b0102/Untitled%202.png)