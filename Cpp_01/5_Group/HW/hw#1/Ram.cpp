#include <iostream>
using namespace std;
#include "Ram.h" 

Ram::Ram()
{
}

Ram::~Ram() {
	cout << "�޸� ���ŵ�" << endl;
}

char Ram::read(int address)
{
	return mem[address];
}

void Ram::write(int address, char value)
{
	mem[address] = value;
}