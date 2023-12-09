# note10

# 내용 정리

## I. 텍스트 파일과 바이너리 파일

### 텍스트 파일

- 사람들이 사용하는 글자 혹은 문자들로만 구성되는 파일
- '\n', '\t' 등의 특수 문자도 포함
- 종류: txt 파일, HTML 파일, XML 파일, C++ 소스 파일, C 소스 파일, 자바 소스 파일
- 각 문자마다 문자 코드(이진수) 할당
    - ASCII 코드, 유니코드

![Screenshot_2023-12-04-12-02-08-360.jpeg](note10%20cee8e461cecb45e19db3083a1f07d296/Screenshot_2023-12-04-12-02-08-360.jpeg)

### 바이너리 파일

- 문자로 표현되지 않는 바이너리 데이터가 기록된 파일
- 이미지, 오디오, 그래픽, 컴파일된 코드… → 문자로 표현되지 않음
- 텍스트 파일의 각 바이트 -> 문자로 해석
- 종류: jpeg, bmp(이미지), mp3(오디오), hwp, doc, ppt(멀티미디어), obj, exe(컴파일된 코드)

⇒ **따라서 hwp 파일은 바이너리 파일이다.**

![Screenshot_2023-12-04-12-06-00-060.jpeg](note10%20cee8e461cecb45e19db3083a1f07d296/Screenshot_2023-12-04-12-06-00-060.jpeg)

### 파일 입출력 스트림

![Screenshot_2023-12-04-12-14-50-237.jpeg](note10%20cee8e461cecb45e19db3083a1f07d296/Screenshot_2023-12-04-12-14-50-237.jpeg)

### 파일 입출력 방식

![Screenshot_2023-12-04-12-17-05-149.jpeg](note10%20cee8e461cecb45e19db3083a1f07d296/Screenshot_2023-12-04-12-17-05-149.jpeg)

## II. 파일 모드(file mode)

- 파일 입출력에 대한 구체적인 작업 행태에 대한 지정
- 기존 파일의 데이터를 모두 지우고 쓸 것인지, 파일의 끝 부분에 쓸 것인지
- 텍스트 I/O 방식인지 바이너리 I/O 방식 인지

### 파일 모드 지정 – 파일 열 때

- open(“파일이름”, 파일모드)
- ifstream(“파일이름”, 파일모드),
- ofstream(“파일이름”, 파일모드)

![Untitled](note10%20cee8e461cecb45e19db3083a1f07d296/Untitled.png)

### 파일 모드 설정

![Screenshot_2023-12-04-12-49-23-730.jpeg](note10%20cee8e461cecb45e19db3083a1f07d296/Screenshot_2023-12-04-12-49-23-730.jpeg)

### get()과 EOF

**파일의 끝을 만나면 읽기를 멈춰야 한다. get()은 파일의 끝을 어떻게 인식할까?**

⇒ 파일의 끝에서 읽기를 시도하면 **get()은 EOF(-1값)를 리턴**한다.

![Untitled](note10%20cee8e461cecb45e19db3083a1f07d296/Untitled%201.png)

### 텍스트 파일의 라인 단위 읽기

**두 가지 방법**

- **stream의 getline(char* line, int n) 함수** 이용
    
    ```cpp
    char buf[81]; // 한 라인이 최대 80개의 문자로 구성된다고 가정
    ifstream fin("c:\\windows\\system.ini");
    **while(fin.getline(buf, 81)) {** // 한 라인이 최대 80개의 문자로 구성. 끝에 '\0' 문자 추가
    	... // 읽은 라인(buf[])을 활용하는 코드
    }
    ```
    
- **getline(ifstream& fin, string& line) 함수** 이용
    
    ```cpp
    string line;
    ifstream fin("c:\\windows\\system.ini");
    **while(getline(fin, line)) {** // 한 라인을 읽어 line에 저장. 파일 끝까지 반복
    ... // 읽은 라인(line)을 활용하는 코드 작성
    }
    ```
    

### 바이너리 I/O 방식

- 데이터의 바이너리 값을 그대로 파일에 저장하거나, 파일의 바이
너리 값을 그대로 읽어서 변수나 버퍼에 저장하는 방식
- 텍스트 파일이든 바이너리 파일이든 바이너리 I/O로 입출력가능
- ios::binary 모드 속성 사용
- 사용법
    
    ```cpp
    ifstream fin;
    fin.open("desert.jpg", ios::in | ios::binary); // 바이너리 I/O로 파일 읽기
    ofstream fout("desert.jpg", ios::out | ios::binary); // 바이너리 I/O로 파일 쓰기
    fstream fsin("desert.jpg", ios::in | ios::binary) // 바이너리 I/O로 파일 읽기
    ```
    

## III. 예외 처리와 C언어와의 링크 지정

### 실행 오류와 오류 처리

- 컴파일 오류
    - 문법에 맞지 않는 구문으로 인한 오류
- 실행 오류
    - 개발자의 **논리 오류**
    - **예외적**으로 **발생**하는 입력이나 **상황에 대한 대처가 없을 때** 발생하는 오류
    - 결과가 **틀리거나** 엉뚱한 코드 실행, 프로그램이 **비정상 종료**

### 예외와 예외 처리

- 실행 중, 프로그램 오동작이나 결과에 영향을 미치는 예상치 못한 상황 발생
- 예외 처리기
    - 예외 발생을 탐지하고 예외를 처리하는 코드
- 예외 처리 수준
    - 운영체제 수준 예외 처리
    - 응용프로그램 수준 예외 처리

### C++ 예외 처리 기본 형식

- try-throw-catch
    - try { } 블록
        - 예외가 발생할 가능성이 있는 코드를 묶음
    - throw 문
        - 발견된 예외를 처리하기 위해, 예외 발생을 알리는 문장
        - try { } 블록 내에서 이루어져야 함
    - catch() { } 블록
        - throw에 의해 발생한 예외를 처리하는 코드

```cpp
**try** { // 예외가 발생할 가능성이 있는 실행문. try {} 블록
..............................................................
예외를 발견한다면 {
**throw XXX;** // 예외 발생을 알림. XXX는 예외 값
}
예외를 발견한다면 {
**throw YYY;** // 예외 발생을 알림. YYY는 예외 값
}
}
**catch(처리할 예외 파라미터 선언)** { // catch { } 블록
예외 처리문
}
```

### try-throw-catch의 예외 처리 과정

![Untitled](note10%20cee8e461cecb45e19db3083a1f07d296/Untitled%202.png)

### throw와 catch의 예

![Untitled](note10%20cee8e461cecb45e19db3083a1f07d296/Untitled%203.png)

### C 프로그램의 컴파일과 링킹

![Untitled](note10%20cee8e461cecb45e19db3083a1f07d296/Untitled%204.png)

# 예제 정리

## 예제 12-1 키보드로 입력 받아 텍스트 파일 저장하기

```cpp
#include <iostream>
#include <fstream>
using namespace std;
int main() {
	char name[10], dept[20];
	int sid;
	// 키보드로부터 읽기
	cout << "이름>>";
	cin >> name; // 키보드에서 이름 입력 받음
	cout << "학번>>";
	cin >> sid; // 키보드에서 학번 입력 받음
	cout << "학과>>";
	cin >> dept; // 키보드에서 학과 입력 받음
	// 파일 열기. student.txt 파일을 열고, 출력 스트림 생성
	ofstream fout("c:\\temp\\student.txt");
	if (!fout) { // 열기 실패 검사
		cout << "c:\\temp\\student.txt 파일을 열 수 없다";
			return 0;
	}
	// 파일 쓰기
	fout << name << endl; // name 쓰기
	fout << sid << endl; // sid 쓰기
	fout << dept << endl; // dept 쓰기
	fout.close(); // 파일 닫기
}
```

```cpp
이름>>kitae
학번>>20131111
학과>>computer
```

## 예제 12-2 ifstream과 >> 연산자로 텍스트 파일 읽기

```cpp
#include <iostream>
#include <fstream>
using namespace std;
int main() {
	// 스트림 객체 생성 및 파일 열기
	ifstream fin;
	fin.open("c:\\temp\\student.txt");
	if (!fin) { // 파일 열기 실패 확인
		cout << "파일을 열 수 없다";
		return 0;
	}
	char name[10], dept[20];
	int sid;
	// 파일 읽기
	fin >> name; // 파일에 있는 문자열을 읽어서 name 배열에 저장
	fin >> sid; // 정수를 읽어서 sid 정수형 변수에 저장
	fin >> dept; // 문자열을 읽고 dept 배열에 저장
	// 읽은 텍스트를 화면에 출력
	cout << name << endl;
	cout << sid << endl;
	cout << dept << endl;
	fin.close(); // 파일 읽기를 마치고 파일을 닫는다.
}
```

```cpp
kitae
20131111
computer
```

## 예제 12-3 get()을 이용한 텍스트 파일 읽기

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	const char* file = "c\\windows\\system.ini";

	ifstream fin(file);
	if (!fin) {
		cout << file << "열기 오류" << endl;
		return 0;
	}
	int count = 0;
	int c;
	while ((c = fin.get()) != EOF){
		cout << (char)c;
	count++;
		}
cout << "읽은 바이트 수는" << count << endl;
fin.close();
}
```

```cpp
; for 16-bit app support
[386Enh]
woafont=dosapp.fon
EGA80WOA.FON=EGA80WOA.FON
EGA40WOA.FON=EGA40WOA.FON
CGA80WOA.FON=CGA80WOA.FON
CGA40WOA.FON=CGA40WOA.FON
[drivers]
wave=mmdrv.dll
timer=timer.drv
[mci]
읽은 바이트 수는 206
```

## 예제 12-4 텍스트 파일 연결

```cpp
#include <iostream>
#include <fstream>
using namespace std;int main() {
const char* firstFile = "c:\\temp\\student.txt";
const char* secondFile = "c:\\windows\\system.ini";

fstream fout(firstFile, ios::out | ios::app);
if (!fout) {		
cout << firstFile << "열기 오류";		
return 0;	
}	
fstream fin(secondFile, ios::in);
	if (!fin) {		
cout << secondFile << "열기 오류";		
return 0;	
}	
int c;	
while ((c = fin.get()) != EOF) {		
fout.put(c);	
}	
fin.close();	
fout.close();
}
```

## 예제 12-8 read()로 텍스트 파일을 바이너리 I/O로 읽기

```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	const char* file = "c\\windows\\system.ini";

	ifstream fin;
	fin.open(file, ios::in | ios::binary);
	if (!fin) {
		cout << "파일 읽기 오류";
		return 0;
	}

	int count = 0;
	char s[32];
	while (!fin. eof()) {
		fin.read(s, 32);
		int n = fin.gcount();
		cout.write(s, n);
		count += n;
	}
	cout << "읽은 바이트 수는" << count << endl;
	fin.close();
}
```

```cpp
; for 16-bit app support
[386Enh]
woafont=dosapp.fon
EGA80WOA.FON=EGA80WOA.FON
EGA40WOA.FON=EGA40WOA.FON
CGA80WOA.FON=CGA80WOA.FON
CGA40WOA.FON=CGA40WOA.FON
[drivers]
wave=mmdrv.dll
timer=timer.drv
[mci]
읽은 바이트 수는 219
```

## 예제 13-4 0으로 나누는 예외 처리

```cpp
#include <iostream>
using namespace std;
int main() {
	int n, sum, average;
	while (true) {
		cout << "합을 입력하세요>>";
		cin >> sum;
		cout << "인원수를 입력하세요>>";
		cin >> n;
		try {
			if (n <= 0) // 오류 탐지
				throw n; // 예외 발생. catch(int x) 블록으로 점프
			else
				average = sum / n;
		}
		catch (int x) {
			cout << "예외 발생!! " << x << "으로 나눌 수 없음" << endl;
			average = 0;
			cout << endl;
			continue;
		}
		cout << "평균 = " << average << endl << endl; // 평균 출력
	}
}
```

```cpp
합을 입력하세요>>15
인원수를 입력하세요>>5
평균 = 3

합을 입력하세요>>12
인원수를 입력하세요>>-3
예외 발생!! -3으로 나눌 수 없음

합을 입력하세요>>25
인원수를 입력하세요>>0
예외 발생!! 0으로 나눌 수 없음

합을 입력하세요>>15
인원수를 입력하세요>>2
평균 = 7

합을 입력하세요>>
```

## 예제 13-