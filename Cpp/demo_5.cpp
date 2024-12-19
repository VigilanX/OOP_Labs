#include "Lab_5.h"
namespace lab_5 {
    void runDemo() {
        setlocale(LC_ALL, "ru");
        int N = -1;
        STRING str1(' ');
        str1.Setstrt((char*)"String");
        STRING str2(' ');
        str2.Setstrt((char*)"String Mid");
        STRING str3(' ');
        str3.Setstrt((char*)"String Long");
        bool f = true;
        STRING* str_array = new STRING[100];
        int arr_size = 3;
        str_array[0] = str1;
        str_array[1] = str2;
        str_array[2] = str3;
        while (f) {
            std::cout << "\n\n======================\n1) Сложить строки\n";
            std::cout << "2) Умножить строку\n";
            std::cout << "3) Сравнить строки\n";
            std::cout << "4) Переприсвоить строки\n";
            std::cout << "5) Заменить строку\n";
            std::cout << "6) Использовать функтор\n";
            std::cout << "7) Ввести новую строку\n";
            std::cout << "8) Вывести все доступные строки\n";
            std::cout << "9) Выйти из программы\n======================";
            std::cout << "\n| Выберите действие: "; std::cin >> N;
            int s1 = 0, s2 = 0, s3 = 0;
            STRING result1(' ');
            STRING result2(' ');
            STRING new_str(' ');
            switch (N)
            {
            case 1:
                for (int i = 0; i < arr_size; i++) {
                    std::cout << "\nСтрока " << i + 1 << ": " << str_array[i];
                }
                std::cout << "\nВведите через пробел какие строчки сложить: ";
                std::cin >> s1; std::cin >> s2;
                if (s1 == 1 && s2 == 1) {
                    result1 = str1 + str1;
                    result1.Print_at(0, result1.Length());
                }
                else if (s1 == 1 && s2 == 2) {
                    result1 = str1 + str2;
                    result1.Print_at(0, result1.Length());
                }
                else if (s1 == 1 && s2 == 3) {
                    result1 = str1 + str3;
                    result1.Print_at(0, result1.Length());
                }
                else if (s1 == 2 && s2 == 1) {
                    result1 = str2 + str1;
                    result1.Print_at(0, result1.Length());
                }
                else if (s1 == 2 && s2 == 2) {
                    result1 = str2 + str2;
                    result1.Print_at(0, result1.Length());
                }
                else if (s1 == 2 && s2 == 3) {
                    result1 = str2 + str3;
                    result1.Print_at(0, result1.Length());
                }
                else if (s1 == 3 && s2 == 1) {
                    result1 = str3 + str1;
                    result1.Print_at(0, result1.Length());
                }
                else if (s1 == 3 && s2 == 2) {
                    result1 = str3 + str2;
                    result1.Print_at(0, result1.Length());
                }
                else if (s1 == 3 && s2 == 3) {
                    result1 = str3 + str3;
                    result1.Print_at(0, result1.Length());
                }
                else {
                    std::cout << "\n Некорректные номера строк !";
                }
                break;
            case 2:
                for (int i = 0; i < arr_size; i++) {
                    std::cout << "\nСтрока " << i + 1 << ": " << str_array[i];
                }
                std::cout << "\nВведите какую строку умножить и на какое число: ";
                int s, k; std::cin >> s >> k;
                if (s == 1) {
                    result2 = str1 * k;
                    result2.Print_at(0, result2.Length());
                }
                else if (s == 2) {
                    result2 = str2 * k;
                    result2.Print_at(0, result2.Length());
                }
                else if (s == 3) {
                    result2 = str3 * k;
                    result2.Print_at(0, result2.Length());
                }
                else {
                    std::cout << "\n Некорректные номера строк !";
                }
                break;
            case 3:
                for (int i = 0; i < arr_size; i++) {
                    std::cout << "\nСтрока " << i + 1 << ": " << str_array[i];
                }
                std::cout << "\nВведите какие строки сравнить (для двух строк - последний ввод 0; '1 2 3' - для сравнения всех строк): ";
                std::cin >> s1 >> s2 >> s3;
                if (s1 == 1 && s2 == 2 && s3 == 0) {
                    std::cout << "Результат сравнения: " << str1.Strcmp(str2);
                }
                else if (s1 == 1 && s2 == 3 && s3 == 0) {
                    std::cout << "Результат сравнения: " << str1.Strcmp(str3);
                }
                else if (s1 == 2 && s2 == 1 && s3 == 0) {
                    std::cout << "Результат сравнения: " << str2.Strcmp(str1);
                }
                else if (s1 == 2 && s2 == 3 && s3 == 0) {
                    std::cout << "Результат сравнения: " << str2.Strcmp(str3);
                }
                else if (s1 == 3 && s2 == 1 && s3 == 0) {
                    std::cout << "Результат сравнения: " << str3.Strcmp(str1);
                }
                else if (s1 == 3 && s2 == 2 && s3 == 0) {
                    std::cout << "Результат сравнения: " << str3.Strcmp(str2);
                }
                else if (s1 == 1 && s2 == 2 && s3 == 3) {
                    std::cout << "Результат сравнения: "; str1.Strcmp(str2, str3);
                }
                else {
                    std::cout << "\n Некорректные номера строк !";
                }
                break;
            case 4:
                for (int i = 0; i < arr_size; i++) {
                    std::cout << "\nСтрока " << i + 1 << ": " << str_array[i];
                }
                std::cout << "\nВведите Какую строку присвоить: ";
                std::cin >> s1;
                std::cout << "\nВведите Какой строке присвоить новое значение: ";
                std::cin >> s2;
                if (s1 > arr_size or s2 > arr_size) {
                    std::cout << "\n Некорректные номера строк !";
                    break;
                }
                str_array[s2 - 1] = str_array[s1 - 1];
                std::cout << "\n" << str_array[s2 - 1] << "\t" << str_array[s1 - 1];
                break;
            case 5:
                for (int i = 0; i < arr_size; i++) {
                    std::cout << "\nСтрока " << i + 1 << ": " << str_array[i];
                }
                std::cout << "\nВведите Какую строку перезаписать: ";
                std::cin >> s1;
                std::cout << "\nВведите в Какую строку перезаписать новое значение: ";
                std::cin >> s2;
                if (s1 > arr_size or s2 > arr_size) {
                    std::cout << "\n Некорректные номера строк !";
                    break;
                }
                str_array[s2 - 1] = std::move(str_array[s1 - 1]);
                std::cout << "\n" << str_array[s2 - 1] << "\t" << str_array[s1 - 1];
                break;
            case 6:
                for (int i = 0; i < arr_size; i++) {
                    std::cout << "\nСтрока " << i + 1 << ": " << str_array[i];
                }
                std::cout << "\nВведите для какой строки использовать функтор: ";
                std::cin >> s1;
                if (s1 > arr_size) {
                    std::cout << "\nНекорректные номера строк !";
                    break;
                }
                str_array[s1 - 1]();
                break;
            case 7:
                std::cout << "\nВведите новую строку:";
                std::cin >> new_str;
                str_array[arr_size] = new_str;
                arr_size++;
                break;
            case 8:
                std::cout << "\nВсе доступные строки:";
                for (int i = 0; i < arr_size; i++) {
                    std::cout << "\nСтрока " << i + 1 << ": " << str_array[i];
                }
                break;
            case 9:
                f = false;
                break;
            default:
                break;
            }
        }
    }
}