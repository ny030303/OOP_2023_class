# note02

# 설명 정리

## I. print 확인 코드

---

```
#include <iostream>

int main() {
    std::cout << "Hello world \n";
    return 0;
}
```

1. <iostream> 헤더파일을 사용함
    
    iostream은 cout, cin, <<, >>등을 사용할 수 있게한다.
    
2. std::cout 이렇게 사용함. -> ostream 클래스에서 구현됨.

---

## 예제 2-2 -> 이후 c로 작성해보기

```
#include <iostream>
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
```

## II. namespace란

---

함수이름이 같을 때 충돌의 문제

-> namespace로 이름공간을 만들어서 같은 함수이름 충돌문제 등을 해결할 수 있음.

### 1. std란

std: c++ 표준에서 정의한 namespace

### + using으로 std를 생략할 수도 있다. (ex.)

```
using std::cout; // cout에 대해서만 std:: 생략
...................................
cout << "Hello" << std::endl; // std::cout에서 std:: 생략
```

```
using namespace std; // std 이름 공간에 선언된 모든 이름에 std:: 생략
...................................
cout << "Hello" << endl; // std:: 생략
```

## 예제 2-3 -> 이후 c로 작성해보기

---

```
#include <iostream>

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
```

### 2. cin이란

입력 버퍼를 내장함.

- >> 연산자
    
    enter키로 구분하여 버퍼에서 변수를 넘김.
    
    ![Untitled](note02%20d59ffc9064614ea7a8d13bfd8b4498bd/Untitled.png)
    
    ### 3. endl
    
    - 버퍼를 비울떄, 끝낼때 사용된다. (생략이 가능하다.)
    
    ## III. C++ 문자열
    
    ---
    
    - ‘\0’으로 끝나면 문자 배열이다.
    
    ```jsx
    char name1[6] = {'G', 'r', 'a', 'c', 'e', '\0'}; // name1은 문자열 “Grace”
    char name2[5] = {'G', 'r', 'a', 'c', 'e'}; // name2는 문자열이 아니고 단순 문자 배열
    ```
    
    - string 클래스를 사용한다.
        - <string>헤더 파일에 선언 되어있음.
    
    ## 예제 2-4
    
    ---
    
    ```
    #include <iostream>
    
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
    ```
    
    → 이때 빈칸을 만나면 그냥 종료되버린다.
    
    ## 예제 2-5
    
    ---
    
    pwd[4] ⇒ 입력받을 배열
    
    pwdres[4] ⇒ 정답
    
    failed ⇒ 비밀번호가 틀렸는지 체크할 변수 (0, 1 구분)
    
    i ⇒ 정답 char 값을 체크할때 idx 값
    
    foreach문을 돌면서 일일히 하나씩 비교후 틀렸다면 틀림을 출력하고 foreach문을 나간다.
    
    맨 마지막에 failed로 전체적으로 맞았는지 틀렸는지를 체크 하고
    
    그에맞는 결과를 출력한다.
    
    ```
    #include <iostream>
    
    using namespace std;
    
    int main() {
    	while (true)
    	{
    		char pwd[4]; // 비번 담을 배열 선언
    		char pwdres[4] = "c++"; // 비번 담을 배열 선언
    		cout << "비밀번호를 입력합니다" << endl;
    		cin >> pwd;
    
    		int failed = 0;
    		int i = 0;
    		for (char text : pwdres) {
    				if (failed == 0) {
    					cout << "text: " << text << ", utext: " << i+pwd << endl;
    					if (text != *(i + pwd)) {
    						cout << "비밀번호 틀림 "  << endl;
    						failed = 1;
    						break;
    					}
    					i++;
    				} else break;
    		}
    		if (failed == 0) {
    			cout << "암호맞음 -> 종료" << endl;
    			break;
    		}
    	}
    	
    }
    ```
    
    ## p90쪽 8번 문제 (세미콜론으로 구분)
    
    ---
    
    ```
    #include <iostream>
    
    using namespace std;
    
    int main() {
    	char names[20]; // 입력 배열 선언 ㅁㅁㅁ;ㅁ;ㅁ;
    	char namesres[20] = { NULL }; // 담을 배열 ㅁㅁㅁ
    	cout << "5명의 이름을 ';'으로 표시하세요. " << endl;
    	cin >> names;
    
    	int i = 0, cnt = 0;
    	for (char text : names)
    	{	
    		if (text == ';') {
    			cout << cnt << ": " << namesres << endl;
    			cnt++;
    			namesres[20] = "";
    			i = 0;
    		} else {
    			*(namesres + i) = text;
    			i++;
    		}
    		//cout << text << endl;
    	}
    		
    }
    ```