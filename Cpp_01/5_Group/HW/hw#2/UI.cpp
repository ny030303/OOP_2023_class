#include "UI.h"

int UI::getMenu() {
	int key;
	cout << "����:1, ����:2, ��κ���:3, ����:4 >>";
	cin >> key;
	return key;
}
int UI::printToInsert() {
	int key;
	cout << "��:1, ��:2, �簢��:3 >>";
	cin >> key;
	return key;
}
int UI::printToDelete() {
	int key;
	cout << "�����ϰ��� �ϴ� ������ �ε��� >>";
	cin >> key;
	return key;
}