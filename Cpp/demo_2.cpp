#include "Lab_2.h"
namespace lab_2 {
    void runDemo() {
        setlocale(LC_ALL, "ru");
        // ������������� ���������� ��������� �����
        std::srand(static_cast<unsigned int>(std::time(0)));
        setlocale(LC_ALL, "ru");
        int x = 0, y = 0, z = 0;
        /*
        // ���� �������� �������
        std::cout << "������� ������� ���������� ������� (x, y, z): ";
        std::cin >> x >> y >> z;
        // �������� ������� ������
        ThreeDimensionalArray arr(x, y, z);
        // ����� ������ ������, �������� ��������
        arr.printMemorySize();
        */
        // ���� �������� �������
        std::cout << "������� ����� ����� ���������� �������: ";
        std::cin >> x;
        // �������� ������� ������
        ThreeDimensionalArray arr(x);
        arr.GetSum();
    }
}