#include <iostream>
#include <vector>
#include "Shape.h"
#include "Circle.h"
#include "Line.h"
#include "Rect.h"

using namespace std;

int main() {
	vector<Shape*> v;
	int n;
	cout << "그래픽 에디터입니다." << endl;
	while (true)
	{
		cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
		cin >> n;
		if (n == 1) {
			cout << "선: 1, 원:2, 사각형:3 >> ";
			cin >> n;
			switch (n) {
			case 1: v.push_back(new Line); break;
			case 2: v.push_back(new Circle); break;
			case 3: v.push_back(new Rect); break;
			}
		}
		else if (n == 2) {
			cout << "삭제하고자 하는 도형의 인덱스 >> ";
			cin >> n;
			vector<Shape*>::iterator it = v.begin();
			it += n;
			it = v.erase(it);
		}
		else if (n == 3) {
			for (int i = 0; i < v.size(); i++) {
				cout << i << " : ";
				v[i]->paint();
			}
		}
		else if (n == 4) break;


	}
}