# hw#2

#과제 내용

교제 P471 의 10번 문제를 프로그래밍하여 제출 하시오.

### 교제 p471 - 10번

![Untitled](hw#2%2093e08af154ba4f2f84d7870954d19ec9/Untitled.png)

### 폴더 구조

![Untitled](hw#2%2093e08af154ba4f2f84d7870954d19ec9/Untitled%201.png)

### 코드:

main.cpp

```cpp
#include <iostream>
#include "GraphicEditor.h"

using namespace std;
int main() {
	GraphicEditor* gEdt = new GraphicEditor;
	gEdt->init();
}
```

GraphicEditor.h

```cpp
#include "Shape.h"

class GraphicEditor {
	int size;
	Shape* pStart;
	Shape* pLast;
public:
	GraphicEditor() {
		size = 0;
		pStart = NULL;
		pLast = NULL;
	}

	void addItem(int idx);
	void removeItem(int idx);
	void printAll();
	void init();
	
	void ifNew(int n);
	bool del(int n);
};
```

GraphicEditor.cpp

```cpp
#include <iostream>
#include "GraphicEditor.h"
#include "Shape.h"
#include "Line.h"
#include "Rect.h"
#include "Circle.h"
#include "UI.h"

using namespace std;
void GraphicEditor::addItem(int idx) {
	Shape* p = NULL;
	if (idx == 1) {
		p = new Line();
	}
	else if (idx == 2) {
		p = new Circle();
	}
	else if (idx == 3) {
		p = new Rect();
	}

	if (this->pStart == NULL) {
		this->pStart = p;
		this->pLast = p;
		return;
	}
	(this->pLast)->add(p);// 제일 끝 값이 추가될 객체를 가리키도록
	pLast = pLast->getNext(); // plast에 추가한 객체 포인터 담기
}

void GraphicEditor::removeItem(int idx) {
	Shape* pre = this->pStart;
	Shape* temp = this->pStart;
	if (this->pStart == NULL) {
		cout << "도형이 없습니다!" << endl;
		return;
	}
	for (int i =1; i < idx; i++) {
		pre = temp;
		temp = temp->getNext();
	}
	if (temp == this->pStart) {
		this->pStart = temp->getNext();
		delete temp;
	} else {
		pre->add(temp->getNext());
		delete temp;
	}

}
void GraphicEditor::printAll() {
	Shape* temp = this->pStart;
	int i = 1;
	while (temp != NULL) {
		cout << i++ << ": ";
		temp->paint();
		temp = temp->getNext();
	}
}
void GraphicEditor::init() {
	cout << "그래픽 에디터입니다." << endl;
	while (true) {
		int num;
		num = UI::getMenu();
		switch (num) {
		case 1: {
			num = UI::printToInsert();
			ifNew(num);
			break;
		}
		case 2: {
			if (pStart == NULL) {
				cout << "List Empty\n";
				break;
			}
			num = UI::printToDelete();
			del(num);
			break;
		}
		case 3: {
			Shape* p = pStart;
			int i = 0;
			if (p == NULL)
				cout << "List Empty\n";
			else
				while (p != NULL) {
					cout << i << ": ";
					p->paint();
					p = p->getNext();
					i++;
				}
			break;
		}
		case 4: {
			exit(0);
		}
		default:
			cout << "메뉴를 잘못 선택하셨습니다.\n";
		}
	}
}

void GraphicEditor::ifNew(int n) {
	switch (n) {
	case 1: {
		if (this->size == 0) {
			pStart = new Line();
			pLast = pStart;
		}
		else
			pLast = pLast->add(new Line());
		this->size++;
		break;
	}
	case 2: {
		if (this->size == 0) {
			pStart = new Circle();
			pLast = pStart;
		}
		else
			pLast = pLast->add(new Circle());
		this->size++;
		break;
	}
	case 3: {
		if (this->size == 0) {
			pStart = new Rect();
			pLast = pStart;
		}
		else
			pLast = pLast->add(new Rect());
		this->size++;
		break;
	}
	default:
		cout << "메뉴를 잘못 선택하셨습니다.\n";
	}
}

bool GraphicEditor::del(int n) {
	int k = 0;
	Shape* target_node = this->pStart;
	Shape* priv_node = NULL;
	if (n == 0) {
		pStart = pStart->getNext();
		delete target_node;
	}
	else {
		while ((target_node != NULL) && (k < n)) {
			priv_node = target_node;
			target_node = target_node->getNext();
			k++;
		}
		if (target_node == NULL) {
			cout << "없는 노드입니다.\n";
			return false;
		}
		else {
			priv_node->setNext(target_node);
			delete target_node;
		}
	}
	this->size--;
	return true;
};
```

Shape.h

```cpp
#pragma once

class Shape {
	Shape* next;
protected:
	virtual void draw() = 0;
public:
	Shape() { next = NULL; }
	virtual ~Shape() { }
	void paint();
	Shape* add(Shape* p);
	Shape* getNext();
	void setNext(Shape* p);
};
```

Shape.cpp

```cpp
#include <iostream>
#include "Shape.h"
using namespace std;
void Shape::paint() {
	draw();
}
void Shape::draw() {
	cout << "Shape" << endl;
}

Shape* Shape::add(Shape* p) {
	this->next = p;
	return p;
}
Shape* Shape::getNext() { return this->next; }
void Shape::setNext(Shape* p) { this->next = p->next; }
```

UI.h

```cpp
#include <iostream>
using namespace std;
class UI {
protected:
public:
	static int getMenu();
	static int printToInsert();
	static int printToDelete();
};
```

UI.cpp

```cpp
#include "UI.h"

int UI::getMenu() {
	int key;
	cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >>";
	cin >> key;
	return key;
}
int UI::printToInsert() {
	int key;
	cout << "선:1, 원:2, 사각형:3 >>";
	cin >> key;
	return key;
}
int UI::printToDelete() {
	int key;
	cout << "삭제하고자 하는 도형의 인덱스 >>";
	cin >> key;
	return key;
}
```

Circle.h

```cpp
#include "Shape.h"
class Circle : public Shape {
protected:
	virtual void draw();
};
```

Circle.cpp

```cpp
#include <iostream>
#include "Circle.h"
using namespace std;
void Circle::draw() {
	cout << "Circle" << endl;
}
```

Line.h

```cpp
#include "Shape.h"
class Line : public Shape {
protected:
	virtual void draw();
};
```

Line.cpp

```cpp
#include <iostream>
#include "Line.h"
using namespace std;
void Line::draw() {
	cout << "Line" << endl;
}
```

Rect.h

```cpp
#include "Shape.h"
class Rect : public Shape {
protected:
	virtual void draw();
};
```

Rect.cpp

```cpp
#include <iostream>
#include "Rect.h"
using namespace std;
void Rect::draw() {
	cout << "Rectangle" << endl;
}
```

결과:

![Untitled](hw#2%2093e08af154ba4f2f84d7870954d19ec9/Untitled%202.png)