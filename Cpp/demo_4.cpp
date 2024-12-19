#include "Lab_4.h"
namespace lab_4 {
    void runDemo() {
        setlocale(LC_ALL, "ru");
        char liter, liter1;
        while (true) {
            std::cout << "\nВведите литеру, для инициализации строки (0 чтобы выйти): ";
            std::cin >> liter;
            if (liter == '0') {
                return;
            }
            // Создаем объект класса STRING
            STRING str(liter);
            str.Setstrt((char*)"Testing");
            STRING str_2(liter);
            str_2.Setstrt((char*)"Something");
            // Конкатенация строк
            std::cout << "Соединяем строку: ";
            str.Print_at(1, 20);
            std::cout << "\nи строку: ";
            str_2.Print_at(1, 20);
            STRING* result = str.Concatenation(str_2);
            std::cout << "\nПолучаем строку: ";
            result->Print_at(1, 20);

            // Создаем объект класса EnhancedString
            std::cout << "\n\nВведите литеру, для инициализации строки (0 чтобы выйти): ";
            std::cin >> liter1;
            if (liter1 == '0') {
                return;
            }
            EnhancedString Estr(liter1);
            Estr.Setstrt(" Enhanced");
            EnhancedString Estr2('X');
            Estr2.Setstrt(" Anything");
            std::cout << "Соединяем строку: ";
            Estr.Print_at(0, 0);
            std::cout << "и строку: ";
            Estr2.Print_at(0, 0);
            Estr.Concatenation(Estr2);
            std::cout << "\nПолучаем строку: ";
            Estr.Print_at(0, 0);
            std::cout << "\n\n";

            delete result;
        }
    }
}