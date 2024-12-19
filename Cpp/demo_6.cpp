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
            std::cout << "\n\n==================================================\n 1 | ������ ������������������ ����� �����\n==================================================";
            std::cout << "\n 2 | ������ ������������������ ������������ �����\n==================================================";
            std::cout << "\n 3 | ����� �� ���������\n==================================================";
            std::cout << "\n| �������� ��������: "; std::cin >> N;
            Seq_Int.clear_arr();
            Seq_Double.clear_arr();
            switch (N)
            {
            case 1:
                std::cout << "\n������� ����� ������������������: ";
                std::cin >> size;
                for (int i = 0; i < size; i++) {
                    std::cout << i + 1 << "-� �������: ";
                    std::cin >> x_int;
                    Seq_Int.addNumber(x_int);
                }
                std::cout << "\n�������� ������������������ ����� �����: ";
                Seq_Int.getNumbers();
                std::cout << "\n������������������ ����� ���������: ";
                Seq_Int.transformation();
                Seq_Int.getNumbers();
                break;
            case 2:
                std::cout << "\n������� ����� ������������������: ";
                std::cin >> size;
                for (int i = 0; i < size; i++) {
                    std::cout << i + 1 << "-� �������: ";
                    std::cin >> x_double;
                    Seq_Double.addNumber(x_double);
                }
                std::cout << "\n�������� ������������������ ������������ �����: ";
                Seq_Double.getNumbers();
                std::cout << "\n������������������ ����� ���������: ";
                Seq_Double.transformation();
                Seq_Double.getNumbers();
                break;
            case 3:
                f = false;
                break;
            default:
                std::cout << "\n������������ ���� !";
                break;
            }
        }
    }
}