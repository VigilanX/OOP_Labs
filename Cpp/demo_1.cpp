#include "Lab_1.h"
namespace lab_1 {
	void runDemo() {
        setlocale(LC_ALL, "ru");
        std::cout << "1) ������� ������, ��� ������������� ������: ";
        char liter; std::cin >> liter;
        STRING str(liter);
        std::cout << "�������� ������: ";
        str.Print_at(1, 1);

        std::cout << "\n\n2) ������ ������� ������ �������� ������, ������� �������� ����� <Testing> � ������� ���������� ������: ";
        str.Setstrt((char*)"Testing");
        std::cout << "\n����� ��� x = 1, y = 7: "; str.Print_at(1, 7);
        std::cout << "\n������� ����� ������ �������� ������, ������� �������� ����� <OOPS> � ������� ���������� ������: ";
        str.Setstrt((char*)"OOPS");
        std::cout << "\n����� ��� x = 1, y = 7: "; str.Print_at(1, 7);
        std::cout << "\n������� ��� ������� �������� ������, ������� �������� ����� <VeryLongWord> � ������� ���������� ������: ";
        str.Setstrt((char*)"VeryLongWord");
        std::cout << "\n����� ��� x = 1, y = 12: "; str.Print_at(1, 12);
        std::cout << "\n\n������������ ��������� ��������� ������:\n";
        std::cout << "\n����� ��� x = 20, y = 12: "; str.Print_at(20, 12);
        std::cout << "\n����� ��� x = 0, y = 12: "; str.Print_at(0, 12);
        std::cout << "\n����� ��� x = 1, y = 20: "; str.Print_at(1, 20);
        std::cout << "\n����� ��� x = 1, y = 5: "; str.Print_at(1, 5);
        std::cout << "\n\n3) ������� ����� �������� ������: " << str.Length() << std::endl;
	}
}