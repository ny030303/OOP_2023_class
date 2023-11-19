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