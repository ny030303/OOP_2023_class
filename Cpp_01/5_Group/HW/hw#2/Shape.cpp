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