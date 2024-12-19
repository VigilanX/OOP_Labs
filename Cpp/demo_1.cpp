#include "Lab_1.h"
namespace lab_1 {
	void runDemo() {
        setlocale(LC_ALL, "ru");
        std::cout << "1) Введите литеру, для инициализации строки: ";
        char liter; std::cin >> liter;
        STRING str(liter);
        std::cout << "Получена строка: ";
        str.Print_at(1, 1);

        std::cout << "\n\n2) Теперь заменим строку областью памяти, которая содержит слово <Testing> и выведем обновлённую строку: ";
        str.Setstrt((char*)"Testing");
        std::cout << "\nВывод для x = 1, y = 7: "; str.Print_at(1, 7);
        std::cout << "\nЗаменим часть строки областью памяти, которая содержит слово <OOPS> и выведем обновлённую строку: ";
        str.Setstrt((char*)"OOPS");
        std::cout << "\nВывод для x = 1, y = 7: "; str.Print_at(1, 7);
        std::cout << "\nЗаменим всю строчку областью памяти, которая содержит слово <VeryLongWord> и выведем обновлённую строку: ";
        str.Setstrt((char*)"VeryLongWord");
        std::cout << "\nВывод для x = 1, y = 12: "; str.Print_at(1, 12);
        std::cout << "\n\nПротестируем различные параметры вывода:\n";
        std::cout << "\nВывод для x = 20, y = 12: "; str.Print_at(20, 12);
        std::cout << "\nВывод для x = 0, y = 12: "; str.Print_at(0, 12);
        std::cout << "\nВывод для x = 1, y = 20: "; str.Print_at(1, 20);
        std::cout << "\nВывод для x = 1, y = 5: "; str.Print_at(1, 5);
        std::cout << "\n\n3) Получим длину итоговой строки: " << str.Length() << std::endl;
	}
}