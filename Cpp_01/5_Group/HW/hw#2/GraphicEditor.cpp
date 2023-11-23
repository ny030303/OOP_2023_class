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