# note08

# 내용 정리

## 함수 중복의 약점

```cpp
...

void myswap(int& a, int& b) {
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}
void myswap(double & a, double & b) {
	double tmp;
	tmp = a;
	a = b;
	b = tmp;
}
...
```

함수 중복을 피하기 위해 + 어디서든 사용하기 위해 일반화 시킨다.

## I. 일반화와 템플릿

### 제네릭(generic) 또는 일반화

- 일반화 시키기 위한 기법

### 템플릿이란

- 함수나 클래스를 일반화하는 C++ 도구이다.
- **template** 키워드로 함수나 클래스 선언한다.
    - 변수나 매개 변수의 타입만 다르고, **코드 부분이 동일한 함수**를 일반화시킴
- **제네릭** 타입 - 일반화를 위한 **데이터 타입**

![Untitled](note08%20acbfa4e8d139463a85b32e38f1d11298/Untitled.png)

### 구체화

- 템플릿의 **제네릭 타입**에 **구체적인 타입 지정**한다.
- 템플릿 함수로부터 구체화된 함수의 소스 코드 생성한다.

![Screenshot_2023-11-20-12-12-06-424.jpeg](note08%20acbfa4e8d139463a85b32e38f1d11298/Screenshot_2023-11-20-12-12-06-424.jpeg)

### 구체화 오류

- 타입 지정 시 주의해야 한다.

```cpp
template <class T> void myswap(T & a, T & b) 
// 두 변수 a, b는 타입이 동일해야한다.
```

- 컴파일 오류. 템플릿으로부터 **myswap(int &, double &)** 함수를 구체화할 수 없다.

### 템플릿 장단점

- 장점
    - 함수 코드의 재사용이 가능하다
- 단점
    - 포팅에 취약하다. (컴파일러에 따라 지원하지 않을 수 있음)
    - 컴파일 오류 메시지 빈약하고, 디버깅에 많은 어려움이 있다

### 제네릭 프로그래밍

- 일반화 프로그래밍이라고도 부른다.
- **제네릭 함수**나 **제네릭 클래스**를 활용하는 **프로그래밍 기법**
- C++에서 **STL(Standard Template Library)** 제공

### 배열을 출력하는 print() 템플릿 함수(제네릭 함수)의 문제점

```cpp
#include <iostream>
using namespace std;
template <class T>
void **print(T array [], int n) {**
	for(int i=0; i<n; i++)
	cout << array[i] << '\t';
	cout << endl;
}
void **print(char array [], int n)** { // char 배열을 출력하기 위한 함수 중복
	for(int i=0; i<n; i++)
	cout << (int)array[i] << '\t'; // array[i]를 int 타입으로 변환하여 정수 출력
	cout << endl;
}
int main() {
	int x[] = {1,2,3,4,5};
	double d[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
	**print(x, 5);
	print(d, 5);**
	char c[5] = {1, 2, 3, 4, 5};
	**print(c, 5);**
}
```

### 문제가 뭘까?

위처럼 템플릿과 선언된 함수가 중복될때 템플릿 함수가 아닌, 작성된 **print(char array [], int n) 가 실행된다.**

⇒ **중복된 print() 함수가 우선 바인딩**

### 제네릭 클래스 만들기

![Screenshot_2023-11-20-13-21-11-854.jpeg](note08%20acbfa4e8d139463a85b32e38f1d11298/Screenshot_2023-11-20-13-21-11-854.jpeg)

## II. C++ 표준 템플릿 라이브러리, STL

- **표준 템플릿 라이브러리**이다,
- 많은 **제네릭 클래스**와 **제네릭 함수** 포함되어 있다.

### STL의 구성

- **컨테이너 – 템플릿 클래스**
    - 데이터를 담아두는 자료 구조를 표현한 **클래스**
    - ex. 리스트, 큐, 스택, 맵, 셋, 벡터
- **iterator – 컨테이너 원소에 대한 포인터**
    - 컨테이너의 원소들을 순회하면서 **접근하기 위해** 만들어진 **컨테이너 원소
    에 대한 포인터**
- **알고리즘 – 템플릿 함수**
    - 컨테이너 원소에 대한 **복사, 검색, 삭제, 정렬** 등의 기능을 구현한 템플릿
    함수

### 헤더파일

- vector 클래스를 사용하려면 #include <vector>
- list 클래스를 사용하려면 #include <list>

### 이름공간

- STL이 선언된 이름 공간은 std

### vector 컨테이너

- **가변 길이 배열**을 구현한 **제네릭 클래스**이다.
    - 백터 길이에 대한 고민을 할 필요 없게 해준다.
- 벡터에 저장된 원소는 **인덱스로 접근 가능**

![Untitled](note08%20acbfa4e8d139463a85b32e38f1d11298/Untitled%201.png)

### iterator

- 반복자라고도 부른다.
- **컨테이너의 원소**를 가리키는 **포인터**
- 선언 방법

```cpp
vector<int>::iterator it;
it = v.begin();
```

![Untitled](note08%20acbfa4e8d139463a85b32e38f1d11298/Untitled%202.png)

### map 컨테이너

- **(‘키’, ‘값’)의 쌍**을 원소로 저장하는 **제네릭 컨테이너**
- #include <map> 필요
- 예시

```cpp
// 맵 생성
Map<string, string> dic; // 키는 영어 단어, 값은 한글 단어

// 원소 저장
dic.insert(make_pair("love", "사랑")); // ("love", "사랑") 저장
dic["love"] = "사랑"; // ("love", "사랑") 저장

// 원소 검색
string kor = dic["love"]; // kor은 "사랑“
string kor = dic.at("love“); // kor은 "사랑"
```

### STL 알고리즘

- 템플릿 함수이다.
- **전역 함수**이다.
    - STL 컨테이너 **클래스의 멤버 함수가 아님**
- **iterator와 함께** 작동한다.
- #include <algorithm> 필요하다.

### auto를 이용하여 쉬운 변수 선언

- 복잡한 변수 선언을 간소하게, 긴 타입 선언 시 오타 줄임
- C++11부터 auto 선언의 의미 수정 : 컴파일러에게 **변수선언문**에서
추론하여 **타입을 자동 선언하도록 지시**

```cpp
auto pi = 3.14; // 3.14가 실수이므로 pi는 double 타입으로 선언됨
auto n = 3; // 3이 정수이므로 n을 int 타입으로
auto *p = &n; // 변수 p는 int* 타입으로 추론
```

# 예제 정리

## 예제 10-1 제네릭 myswap() 함수 만들기

```cpp
#include <iostream>
using namespace std;
class Circle {
int radius;
public:
Circle(int radius = 1) { this->radius = radius; }
int getRadius() { return radius; }
};
template <class T>
void myswap(T& a, T& b) {
T tmp;
tmp = a;
a = b;
b = tmp;
}
int main() {
int a = 4, b = 5;
myswap(a, b);
cout << "a=" << a << ", " << "b=" << b << endl;
double c = 0.3, d = 12.5;
myswap(c, d);
cout << "c=" << c << ", " << "d=" << d << endl;
Circle donut(5), pizza(20);
myswap(donut, pizza);
cout << "donut반지름=" << donut.getRadius() << ", ";
cout << "pizza반지름=" << pizza.getRadius() << endl;
}
```

```cpp
a=5, b=4
c=12.5, d=0.3
donut반지름=20, pizza반지름=5
```

## 예제 10-2 큰 값을 리턴하는 bigger() 함수만들기 연습

```cpp
#include <iostream>
using namespace std;
template <class T>
T bigger(T a, T b) {
if (a > b)
return a;
else
return b;
}
int main() {
int a = 20, b = 50;
char c = 'a', d = 'z';
cout << "bigger(20, 50)의 결과는 " << bigger(a, b) << endl;
cout << "bigger('a', 'z')의 결과는 " << bigger(c, d) << endl;
}
```

```cpp
bigger(20, 50)의 결과는 50
bigger('a', 'z')의 결과는 z
```

## 예제 10-3 배열의 합을 구하여 리턴하는 제네릭add() 함수 만들기 연습

```cpp
#include <iostream>
using namespace std;
template <class T>
T add(T data[], int n) { // 배열 data에서 n개의 원소를 합한 결과를 리턴
T sum = 0;
for (int i = 0; i < n; i++) {
sum += data[i];
}
return sum; // sum와 타입과 리턴 타입이 모두 T로 선언되어 있음
}
int main() {
int x[] = { 1,2,3,4,5 };
double d[] = { 1.2, 2.3, 3.4, 4.5, 5.6, 6.7 };
cout << "sum of x[] = " << add(x, 5) << endl; // 배열 x와 원소 5개의 합을 계산
cout << "sum of d[] = " << add(d, 6) << endl; // 배열 d와 원소 6개의 합을 계산
}
```

```cpp
sum of x[] = 15
sum of d[] = 23.7
```

## 예제 10-4 배열을 복사하는 제네릭 함수 mcopy() 함수 만들기 연습

```cpp
#include <iostream>
using namespace std;
// 두 개의 제네릭 타입 T1, T2를 가지는 copy()의 템플릿
template <class T1, class T2>
void mcopy(T1 src [], T2 dest [], int n) { // src[]의 n개 원소를 dest[]에 복사하는 함수
for(int i=0; i<n; i++)
dest[i] = (T2)src[i]; // T1 타입의 값을 T2 타입으로 변환한다.
}
int main() {
int x[] = {1,2,3,4,5};
double d[5];
char c[5] = {'H', 'e', 'l', 'l', 'o'}, e[5];
mcopy(x, d, 5); // int x[]의 원소 5개를 double d[]에 복사
mcopy(c, e, 5); // char c[]의 원소 5개를 char e[]에 복사
for(int i=0; i<5; i++) cout << d[i] << ' '; // d[] 출력
cout << endl;
for(int i=0; i<5; i++) cout << e[i] << ' '; // e[] 출력
cout << endl;
}
```

```cpp
1 2 3 4 5
H e l l o
```

## 예제 10-5 템플릿 함수보다 중복 함수가 우선

```cpp
#include <iostream>
using namespace std;
template <class T>
void print(T array [], int n) {
for(int i=0; i<n; i++)
cout << array[i] << '\t';
cout << endl;
}
void print(char array [], int n) { // char 배열을 출력하기 위한 함수 중복
for(int i=0; i<n; i++)
cout << (int)array[i] << '\t'; // array[i]를 int 타입으로 변환하여 정수 출력
cout << endl;
}
int main() {
int x[] = {1,2,3,4,5};
double d[5] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
print(x, 5);
print(d, 5);
char c[5] = {1,2,3,4,5};
print(c, 5);
}
```

```cpp
1 2 3 4 5
1.1 2.2 3.3 4.4 5.5
1 2 3 4 5
```

## 예제 10-6 제네릭 스택 클래스 만들기

```cpp
#include <iostream>
using namespace std;
template <class T>
class MyStack {
int tos;// top of stack
T data[100]; // T 타입의 배열. 스택의 크기는 100
public:
MyStack();
void push(T element); // element를 data [] 배열에 삽입
T pop(); // 스택의 탑에 있는 데이터를 data[] 배열에서 리턴
};
template <class T>
MyStack<T>::MyStack() { // 생성자
tos = -1; // 스택은 비어 있음
}
template <class T>
void MyStack<T>::push(T element) {
if (tos == 99) {
cout << "stack full";
return;
}
tos++;
data[tos] = element;
}
template <class T>
T MyStack<T>::pop() {
T retData;
if (tos == -1) {
cout << "stack empty";
return 0; // 오류 표시
}
retData = data[tos--];
return retData;
}
int main() {
MyStack<int> iStack; // int 만 저장하는 스택
iStack.push(3);
cout << iStack.pop() << endl;
MyStack<double> dStack; // double 만 저장하는 스택
dStack.push(3.5);
cout << dStack.pop() << endl;
MyStack<char>* p = new MyStack<char>(); // char만 저장하는 스택
p->push('a');
cout << p->pop() << endl;
delete p;
}
```

```cpp
3
3.5
a
```

## 예제 10-8 두 개의 제네릭 타입을 가진 클래스 만들기

```cpp
#include <iostream>
using namespace std;
template <class T1, class T2> // 두 개의 제네릭 타입 선언
class GClass {
T1 data1;
T2 data2;
public:
GClass();
void set(T1 a, T2 b);
void get(T1 &a, T2 &b);
};
template <class T1, class T2>
GClass<T1, T2>::GClass() {
data1 = 0; data2 = 0;
}
template <class T1, class T2>
void GClass<T1, T2>::set(T1 a, T2 b) {
data1 = a; data2 = b;
}
template <class T1, class T2>
void GClass<T1, T2>::get(T1 & a, T2 & b) {
a = data1; b = data2;
}
int main() {
int a;
double b;
GClass<int, double> x;
x.set(2, 0.5);
x.get(a, b);
cout << "a=" << a << '\t' << "b=" << b << endl;
char c;
float d;
GClass<char, float> y;
y.set('m', 12.5);
y.get(c, d);
cout << "c=" << c << '\t' << "d=" << d << endl;
}
```

```cpp
a=2 b=0.5
c=m d=12.5
```

## 예제 10-9 vector 컨테이너 활용하기

```cpp
#include <iostream>
#include <vector>
using namespace std;
int main() {
vector<int> v;
v.push_back(1);
v.push_back(2);
v.push_back(3);
for (int i = 0; i < v.size(); i++)
cout << v[i] << " ";
cout << endl;
v[0] = 10;
int n = v[2];
[v.at](http://v.at/)(2) = 5;
for (int i = 0; i < v.size(); i++)
cout << v[i] << " ";
cout << endl;
}
```

```cpp
1 2 3
10 2 5
```

## 예제 10-11 iterator를 사용하여 vector의 모든 원소에 2 곱하기

```cpp
#include <iostream>
#include <vector>
using namespace std;
int main() {
vector<int> v; // 정수 벡터 생성
v.push_back(1);
v.push_back(2);
v.push_back(3);
vector<int>::iterator it; // 벡터 v의 원소에 대한 포인터 it 선언
for(it=v.begin(); it != v.end(); it++) { // iterator를 이용하여 모든 원소 탐색
int n = *it; // it가 가리키는 원소 값 리턴
n = n*2; // 곱하기 2
*it = n; // it가 가리키는 원소에 값 쓰기
}
for(it=v.begin(); it != v.end(); it++) // 벡터 v의 모든 원소 출력
cout << *it << ' ';
cout << endl;
}
```

```cpp
2 4 6
```