#include "Lab_2.h"
namespace lab_2 {
    void runDemo() {
        setlocale(LC_ALL, "ru");
        // Инициализация генератора случайных чисел
        std::srand(static_cast<unsigned int>(std::time(0)));
        setlocale(LC_ALL, "ru");
        int x = 0, y = 0, z = 0;
        /*
        // Ввод размеров массива
        std::cout << "Введите размеры трёхмерного массива (x, y, z): ";
        std::cin >> x >> y >> z;
        // Создание объекта класса
        ThreeDimensionalArray arr(x, y, z);
        // Вывод объёма памяти, занятого массивом
        arr.printMemorySize();
        */
        // Ввод размеров массива
        std::cout << "Введите длину ребра трёхмерного массива: ";
        std::cin >> x;
        // Создание объекта класса
        ThreeDimensionalArray arr(x);
        arr.GetSum();
    }
}