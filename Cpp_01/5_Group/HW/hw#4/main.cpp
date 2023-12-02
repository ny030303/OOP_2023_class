#include <iostream>

class CoffeeVendingMachine {
private:
    int coffee;
    int sugar;
    int cream;
    int water;
    int cup;

public:
    CoffeeVendingMachine() : coffee(3), sugar(3), cream(3), water(3), cup(3) {}

    void displayStatus() {
        std::cout << "---------��ǰ Ŀ�� ���Ǳ� �մϴ�.-----------" << std::endl;
        std::cout << "Coffee ";
        for (int i = 0; i < coffee; ++i)
            std::cout << "*";
        std::cout << std::endl;

        std::cout << "Sugar ";
        for (int i = 0; i < sugar; ++i)
            std::cout << "*";
        std::cout << std::endl;

        std::cout << "CREAM ";
        for (int i = 0; i < cream; ++i)
            std::cout << "*";
        std::cout << std::endl;

        std::cout << "Water ";
        for (int i = 0; i < water; ++i)
            std::cout << "*";
        std::cout << std::endl;

        std::cout << "Cup ";
        for (int i = 0; i < cup; ++i)
            std::cout << "*";
        std::cout << std::endl;
    }

    void makeCoffee(int choice) {
        switch (choice) {
        case 0:
            if (coffee > 0 && water > 0 && cup > 0) {
                std::cout << "���� Ŀ�� ���Խ��ϴ�~~" << std::endl;
                coffee--;
                water--;
                cup--;
            }
            else {
                std::cout << "��ᰡ �����մϴ�." << std::endl;
            }
            break;
        case 1:
            if (coffee > 0 && sugar > 0 && water > 0 && cup > 0) {
                std::cout << "���ִ� ����Ŀ�� ���Խ��ϴ�~~" << std::endl;
                coffee--;
                sugar--;
                water--;
                cup--;
            }
            else {
                std::cout << "��ᰡ �����մϴ�." << std::endl;
            }
            break;
        case 2:
            if (coffee > 0 && water > 0 && cup > 0) {
                std::cout << "��Ŀ�� ���Խ��ϴ�~~" << std::endl;
                coffee--;
                water--;
                cup--;
            }
            else {
                std::cout << "��ᰡ �����մϴ�." << std::endl;
            }
            break;
        case 3:
            coffee = sugar = cream = water = cup = 3;
            std::cout << "��� ���� ä��ϴ�.~~" << std::endl;
            break;
        case 4:
            std::cout << "�����մϴ�." << std::endl;
            break;
        default:
            std::cout << "�߸��� �����Դϴ�." << std::endl;
        }
    }
};

int main() {
    CoffeeVendingMachine vendingMachine;

    int choice = -1;
    while (choice != 4) {
        vendingMachine.displayStatus();

        std::cout << "���� Ŀ��:0, ���� Ŀ��:1, �� Ŀ��:2, ä���:3, ����:4>> ";
        std::cin >> choice;

        vendingMachine.makeCoffee(choice);
    }

    return 0;
}