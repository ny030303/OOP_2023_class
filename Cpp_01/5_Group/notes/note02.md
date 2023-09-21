설명 정리
=============

I. print 확인 코드
-------------

<pre><code>#include &lt;iostream&gt;

int main() {
	std::cout << "Hello world \n";
	return 0;
}
</code></pre>

1. &lt;iostream&gt; 헤더파일을 사용함 <br>
iostream은 cout, cin, <<, >>등을 사용할 수 있게한다.
<br>


2. std::cout 이렇게 사용함. -> ostream 클래스에서 구현됨.
---
예제 2-2 -> 이후 c로 작성해보기
-------------

<pre><code>#include &lt;iostream&gt;
double area(int r); // 함수의 원형 선언
double area(int r) { // 함수 구현
	return 3.14 * r * r; // 반지름 r의 원면적 리턴
}
int main() {
	int n = 3;
	char c = '#';
	std::cout << c << 5.5 << '-' << n << "hello" << true << std::endl;
	std::cout << "n + 5 = " << n + 5 << '\n';
	std::cout << "면적은 " << area(n); // 함수 area()의 리턴 값 출력
}
</code></pre>

----------------------
 II. namespace란
-------------
함수이름이 같을때 충돌의 문제<br>
-> namespace로 이름공간을 만들어서 같은 함수이름 충돌문제 등을 해결할 수 있음.
<br>
<br>

### std란
std: c++ 표준에서 정의한 namespace

### + std를 생략할 수도 있다. (ex.)
 <pre><code>using std::cout; // cout에 대해서만 std:: 생략
...................................
cout << "Hello" << std::endl; // std::cout에서 std:: 생략
</code></pre>
<pre><code>using namespace std; // std 이름 공간에 선언된 모든 이름에 std:: 생략
...................................
cout << "Hello" << endl; // std:: 생략
</code></pre>

----
예제 2-3 -> 이후 c로 작성해보기
-------------

<pre><code>#include &lt;iostream&gt;
using namespace std;
int main() {
cout << "너비를 입력하세요>>";
int width;
cin >> width; // 키보드로부터 너비를 읽어 width 변수에 저장
cout << "높이를 입력하세요>>";
int height;
cin >> height; // 키보드로부터 높이를 읽어 height 변수에 저장
int area = width*height; // 사각형의 면적 계산
cout << "면적은 " << area << "\n"; // 면적을 출력하고 다음 줄로 넘어감
} 
</code></pre>