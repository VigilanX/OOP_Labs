#include "Lab_3.h"
namespace lab_3 {
    void runDemo() {
        // Инициализация генератора случайных чисел
        std::srand(static_cast<unsigned int>(std::time(0)));
        setlocale(LC_ALL, "ru");
        int N = 0;
        while (true) {
            std::cout << "Введите длину последовательности (0 чтобы выйти): ";
            std::cin >> N;
            if (N == 0) {
                return;
            }
            Just_Array A(N);
            A.Beauti_Matrix();
            std::cout << "\n\n";
        }
    }
}