#include "Lab_4.h"
namespace lab_4 {
    void runDemo() {
        setlocale(LC_ALL, "ru");
        char liter, liter1;
        while (true) {
            std::cout << "\n������� ������, ��� ������������� ������ (0 ����� �����): ";
            std::cin >> liter;
            if (liter == '0') {
                return;
            }
            // ������� ������ ������ STRING
            STRING str(liter);
            str.Setstrt((char*)"Testing");
            STRING str_2(liter);
            str_2.Setstrt((char*)"Something");
            // ������������ �����
            std::cout << "��������� ������: ";
            str.Print_at(1, 20);
            std::cout << "\n� ������: ";
            str_2.Print_at(1, 20);
            STRING* result = str.Concatenation(str_2);
            std::cout << "\n�������� ������: ";
            result->Print_at(1, 20);

            // ������� ������ ������ EnhancedString
            std::cout << "\n\n������� ������, ��� ������������� ������ (0 ����� �����): ";
            std::cin >> liter1;
            if (liter1 == '0') {
                return;
            }
            EnhancedString Estr(liter1);
            Estr.Setstrt(" Enhanced");
            EnhancedString Estr2('X');
            Estr2.Setstrt(" Anything");
            std::cout << "��������� ������: ";
            Estr.Print_at(0, 0);
            std::cout << "� ������: ";
            Estr2.Print_at(0, 0);
            Estr.Concatenation(Estr2);
            std::cout << "\n�������� ������: ";
            Estr.Print_at(0, 0);
            std::cout << "\n\n";

            delete result;
        }
    }
}