# hw#1

#과제 내용

교제 P156 의 12번 문제를 프로그래밍하여 제출 하시오.

### 교제 p156 - 12번

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/e95c42dc-313f-4f4c-b7c7-e4e32f0dbb9b/5766d217-8eea-4c2c-9c1c-8823dcb22f38/Untitled.png)

### 실제 폴더 구조

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/e95c42dc-313f-4f4c-b7c7-e4e32f0dbb9b/392aa292-053e-4e6f-8a0f-b0c43c0e3fbc/Untitled.png)

### 실행결과

![Untitled](https://prod-files-secure.s3.us-west-2.amazonaws.com/e95c42dc-313f-4f4c-b7c7-e4e32f0dbb9b/038dc1f0-e5dc-493b-bf3e-e03c5a8914c7/Untitled.png)

### 소스파일

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