#include "Lab_3.h"
#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <iomanip> //для setw
namespace lab_3 {
    // Конструктор
    Just_Array::Just_Array(int N) {
        std::srand(static_cast<unsigned int>(std::time(0)));
        setlocale(LC_ALL, "ru");
        // Проверяем на корректные размеры, чтобы не было ошибок выделения памяти
        if (N <= 0) {
            std::cout << ("Размер последовательности должен быть положительным\n");
        }
        else {
            std::cout << ("Сгенерированная последовательность случайных чисел:\n");
            this->N = N;
            array = new int[N];
            for (int i = 0; i < N; ++i) {
                array[i] = rand() % 10 - 5;
                std::cout << array[i] << " ";
            }
        }
    }

    //Метод для задания
    void Just_Array::Conversion() {
        int* Negative = new int[this->N];
        int* Positive = new int[this->N];
        int Nk = 0, Pk = 0;
        for (int i = 0; i < this->N; i++) {
            if (this->array[i] < 0) {
                Negative[Nk] = this->array[i]; Nk++;
            }
            else {
                Positive[Pk] = this->array[i]; Pk++;
            }
        }
        std::cout << "\nПоследовательность после изменений:\n";
        for (int i = 0; i < this->N; i++) {
            if (i < Nk) {
                array[i] = Negative[i];
            }
            else {
                array[i] = Positive[i - Nk];
            }
            std::cout << array[i] << " ";
        }
        delete[] Negative;
        delete[] Positive;
    }

    //Быстрая сортировка
    void swap(int arr[], int pos1, int pos2) {
        int temp;
        temp = arr[pos1];
        arr[pos1] = arr[pos2];
        arr[pos2] = temp;
    }

    int partition(int arr[], int low, int high, int pivot) {
        int i = low;
        int j = low;
        while (i <= high) {
            if (arr[i] > pivot) {
                i++;
            }
            else {
                swap(arr, i, j);
                i++;
                j++;
            }
        }
        return j - 1;
    }

    void quickSort(int arr[], int low, int high) {
        if (low < high) {
            int pivot = arr[high];
            int pos = partition(arr, low, high, pivot);

            quickSort(arr, low, pos - 1);
            quickSort(arr, pos + 1, high);
        }
    }

    //Проверка нулей
    bool Is_Zero_Coords(int arr[], int N, int i, int j) {
        int t = 0;
        while (t < N) {
            if (arr[t] == i && arr[t + 1] == j) {
                return true;
            }
            else {
                t = t + 2;
            }
        }
        return false;
    }

    //Метод для защиты
    void Just_Array::Beauti_Matrix() {
        int* Negative = new int[this->N];
        int* Positive = new int[this->N];
        int Nk = 0, Pk = 0;
        //На случай нуля в исходной посл-ти (его не заменять)
        bool Is_Zero_Here = false;
        int* Zero_Coords = new int[this->N * 2];
        for (int i = 0; i < this->N * 2; i++) {
            Zero_Coords[i] = -1;
        }
        int ZeroK = 0;
        //Средние значения
        double Avg_N = 0, Avg_P = 0;
        for (int i = 0; i < this->N; i++) {
            if (this->array[i] < 0) {
                Negative[Nk] = this->array[i]; Nk++; Avg_N += this->array[i];
            }
            else {
                Positive[Pk] = this->array[i]; Pk++; Avg_P += this->array[i];
                if (this->array[i] == 0) {
                    Is_Zero_Here = true;
                }
            }
        }
        if (Nk != 0) { Avg_N = Avg_N / Nk; Avg_N = std::ceil(Avg_N * 10.0) / 10.0; }
        if (Pk != 0) { Avg_P = Avg_P / Pk; Avg_P = std::ceil(Avg_P * 10.0) / 10.0; }
        double** Matrix = new double* [this->N];
        for (int i = 0; i < this->N; i++) {
            Matrix[i] = new double[this->N];
            for (int j = 0; j < this->N; j++) {
                Matrix[i][j] = 0;
            }
        }
        quickSort(Negative, 0, Nk - 1);
        std::cout << "\nNegative: ";
        for (int j = 0; j < Nk; j++) {
            std::cout << Negative[j] << " ";
        }
        quickSort(Positive, 0, Pk - 1);
        std::cout << "\nPositive: ";
        for (int j = 0; j < Pk; j++) {
            std::cout << Positive[j] << " ";
        }
        std::cout << "\nAvg_N = " << Avg_N << "\tAvg_P = " << Avg_P << "\n";
        //Заполнение отрицательными
        for (int i = 0; i < Nk; i++) {
            if (i == this->N - 1) {
                Matrix[1][0] = Negative[i];
            }
            else {
                Matrix[0][i] = Negative[i];
            }
        }
        //Заполнение положительными
        for (int i = 0; i < Pk; i++) {
            if (i == this->N - 1) {
                Matrix[this->N - 2][this->N - 1] = Positive[i];
                if (Positive[i] == 0) {
                    Zero_Coords[ZeroK] = this->N - 2; ZeroK++;
                    Zero_Coords[ZeroK] = this->N - 1; ZeroK++;
                }
            }
            else {
                Matrix[this->N - 1][(this->N - 1) - i] = Positive[i];
                if (Positive[i] == 0) {
                    Zero_Coords[ZeroK] = this->N - 1; ZeroK++;
                    Zero_Coords[ZeroK] = (this->N - 1) - i; ZeroK++;
                }
            }
        }
        //Заполнение остальных ячеек
        for (int i = 0; i < this->N; i++) {
            for (int j = 0; j < this->N; j++) {
                if ((Matrix[i][j] == 0) && (i + j < this->N - 1)) {
                    Matrix[i][j] = Avg_N;
                }
                else if ((Matrix[i][j] == 0) && (i + j > this->N - 1) && (Is_Zero_Coords(Zero_Coords, this->N * 2, i, j) == false)) {
                    Matrix[i][j] = Avg_P;
                }
            }
        }
        //Вывод матрицы
        std::cout << "\n\n";
        for (int i = 0; i < this->N; i++) {
            for (int j = 0; j < this->N; j++) {
                std::cout << std::setw(5) << Matrix[i][j] << " ";
            }
            std::cout << "\n";
        }
    };

    // Метод для освобождения памяти
    Just_Array::~Just_Array() {
        delete[]array;
    }
}