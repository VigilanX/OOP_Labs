#include <iostream>
namespace lab_2 {
    void runDemo();
    class ThreeDimensionalArray {
    private:
        int x, y, z;    // Размеры массива
        int*** array;   // Трёхмерный массив
    public:
        // Конструктор
        ThreeDimensionalArray(int x, int y, int z);

        // Конструктор для куба
        ThreeDimensionalArray(int t);

        // Метод для вывода объёма памяти
        void printMemorySize();

        // Метод для установки значения в массиве
        void setValue(int i, int j, int k, int value);

        // Метод для освобождения памяти
        ~ThreeDimensionalArray();

        // Метод для решения пирамиды
        void GetSum();
    };
}
