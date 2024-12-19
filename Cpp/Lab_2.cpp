#include "Lab_2.h"
#include <iostream>
#include <cstdlib>
namespace lab_2 {
    // Конструктор
    ThreeDimensionalArray::ThreeDimensionalArray(int x, int y, int z) {
        // Проверяем на корректные размеры, чтобы не было ошибок выделения памяти
        if (x <= 0 || y <= 0 || z <= 0) {
            std::cout << ("Размеры массива должны быть положительными\n");
        }
        else {
            this->x = x;
            this->y = y;
            this->z = z;
            array = (int***)malloc(x * sizeof(int**));
            for (int i = 0; i < x; ++i) {
                array[i] = (int**)malloc(y * sizeof(int*));
                for (int j = 0; j < y; ++j) {
                    array[i][j] = (int*)malloc(z * sizeof(int));
                }
            }
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < y; j++) {
                    for (int k = 0; k < z; k++) {
                        array[i][j][k] = rand() % 10;;
                    }
                }
            }
            //Вывод массива
            for (int k = 0; k < z; ++k) {
                std::cout << "Слой " << k + 1 << ":\n";
                for (int i = 0; i < x; ++i) {
                    for (int j = 0; j < y; ++j) {
                        std::cout << array[i][j][k] << " ";
                    }
                    std::cout << "\n";
                }
            }
        }
    }

    // Конструктор для куба
    ThreeDimensionalArray::ThreeDimensionalArray(int t) {
        // Проверяем на корректные размеры, чтобы не было ошибок выделения памяти
        if (t <= 0) {
            std::cout << ("Размеры массива должны быть положительными\n");
        }
        else {
            this->x = t; this->y = t; this->z = t;
            array = (int***)malloc(x * sizeof(int**));
            for (int i = 0; i < x; ++i) {
                array[i] = (int**)malloc(y * sizeof(int*));
                for (int j = 0; j < y; ++j) {
                    array[i][j] = (int*)malloc(z * sizeof(int));
                }
            }
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < y; j++) {
                    for (int k = 0; k < z; k++) {
                        array[i][j][k] = rand() % 10;;
                    }
                }
            }
            //Вывод массива
            for (int k = 0; k < z; ++k) {
                std::cout << "Слой " << k + 1 << ":\n";
                for (int i = 0; i < x; ++i) {
                    for (int j = 0; j < y; ++j) {
                        std::cout << array[i][j][k] << " ";
                    }
                    std::cout << "\n";
                }
            }
            // std::cout << "\n Элемент 2 слоя [0 1]: " << array[0][1][1];
        }
    }

    // Метод для вывода объёма памяти
    void ThreeDimensionalArray::printMemorySize() {
        std::cout << "Объём памяти, занимаемый трёхмерным массивом: " << x * y * z * sizeof(int) << " байт" << std::endl;
    }

    // Метод для установки значения в массиве
    void ThreeDimensionalArray::setValue(int i, int j, int k, int value) {
        if (i >= 0 && i < x && j >= 0 && j < y && k >= 0 && k < z) {
            array[i][j][k] = value;
        }
        else {
            std::cout << "Индексы выходят за пределы массива";
        }
    }

    // Метод для освобождения памяти
    ThreeDimensionalArray::~ThreeDimensionalArray() {
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                free(array[i][j]);
            }
            free(array[i]);
        }
        free(array);
    }

    // Пирамида (ВКЛЮЧАЯ ЭЛЕМЕНТЫ НА ДИАГОНАЛИ)
    void ThreeDimensionalArray::GetSum() {
        int pir_sum = 0;
        std::cout << "\n";
        for (int k = 0; k < z; k++) {
            std::cout << "Для слоя " << k + 1 << ": ";
            int layer_sum = 0;
            for (int j = 0; j < y; j++) {
                for (int i = 0; i < x; i++) {
                    if ((j - i >= 0 and j + i >= x - 1) and (j - k >= 0 and j + k >= x - 1)) {
                        std::cout << array[j][i][k];
                        if (i != x - 1) { std::cout << " "; }
                        pir_sum += array[j][i][k];
                        layer_sum += array[j][i][k];
                    }
                }
                std::cout << "|";
            }
            std::cout << "\nСумма: " << layer_sum << "\n";
        }
        std::cout << "\nСумма элементов нижней пирамиды: " << pir_sum << "\n";
    }
}