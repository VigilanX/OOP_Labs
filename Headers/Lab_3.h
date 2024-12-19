#include <iostream>
namespace lab_3 {
    void runDemo();
    class Just_Array {
    private:
        int N;    // Размеры массива
        int* array;   // Массив
    public:
        // Конструктор
        Just_Array(int N);

        //Метод для выполнения задания
        void Conversion();

        //Метод для выполнения задания
        void Beauti_Matrix();

        // Метод для освобождения памяти
        ~Just_Array();
    };
}
