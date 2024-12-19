#include "Lab_6.h"
namespace lab_6 {
    void runDemo() {
        setlocale(LC_ALL, "ru");
        int N = 1;
        int size = 0;
        int x_int = 0;
        double x_double = 0;
        bool f = true;
        Sequence_of_numbers<int> Seq_Int;
        Sequence_of_numbers<double> Seq_Double;
        double* doubleNumbers = new double();
        while (f) {
            std::cout << "\n\n==================================================\n 1 | Ввести последовательность Целых чисел\n==================================================";
            std::cout << "\n 2 | Ввести последовательность Вещественных чисел\n==================================================";
            std::cout << "\n 3 | Выйти из программы\n==================================================";
            std::cout << "\n| Выберите действие: "; std::cin >> N;
            Seq_Int.clear_arr();
            Seq_Double.clear_arr();
            switch (N)
            {
            case 1:
                std::cout << "\nВведите длину последовательности: ";
                std::cin >> size;
                for (int i = 0; i < size; i++) {
                    std::cout << i + 1 << "-й элемент: ";
                    std::cin >> x_int;
                    Seq_Int.addNumber(x_int);
                }
                std::cout << "\nПолучена последовательность целых чисел: ";
                Seq_Int.getNumbers();
                std::cout << "\nПоследовательность после изменений: ";
                Seq_Int.transformation();
                Seq_Int.getNumbers();
                break;
            case 2:
                std::cout << "\nВведите длину последовательности: ";
                std::cin >> size;
                for (int i = 0; i < size; i++) {
                    std::cout << i + 1 << "-й элемент: ";
                    std::cin >> x_double;
                    Seq_Double.addNumber(x_double);
                }
                std::cout << "\nПолучена последовательность вещественных чисел: ";
                Seq_Double.getNumbers();
                std::cout << "\nПоследовательность после изменений: ";
                Seq_Double.transformation();
                Seq_Double.getNumbers();
                break;
            case 3:
                f = false;
                break;
            default:
                std::cout << "\nНекорректный ввод !";
                break;
            }
        }
    }
}