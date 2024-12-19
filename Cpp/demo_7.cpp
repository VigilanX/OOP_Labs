#include "Lab_7.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <math.h>

void ToHex(float value, int width, int precision, std::ostream& output) {
    double fractional, integer;
    fractional = modf(value, &integer);
    int IntegerPart = (int)integer;
    char IntResult[32];
    int IntIndex = 0;
    while (IntegerPart > 0) {
        IntResult[IntIndex++] = "0123456789ABCDEF"[IntegerPart % 16];
        IntegerPart /= 16;
    }
    char Result[32];
    for (int i = 0; i < IntIndex; i++) {
        Result[i] = IntResult[IntIndex - i - 1];
    }
    char FractionalResult[32];
    int FractionalIndex = 0;
    double frac_fractional, frac_integer;
    frac_fractional = modf(fractional, &frac_integer);
    int iterac = 0;
    while (frac_fractional != 0 && iterac < 10) {
        fractional *= 16;
        int digit = static_cast<int>(fractional);
        FractionalResult[FractionalIndex++] = "0123456789ABCDEF"[digit];
        fractional -= digit;
        frac_fractional = modf(fractional, &frac_integer);
        iterac++;
    }
    if (FractionalIndex > precision) {
        FractionalIndex = precision;
    }
    if (IntIndex + FractionalIndex + 1 >= width && FractionalIndex != 0) {
        for (int i = 0; i < IntIndex; i++) {
            output << Result[i];
        }
        output << ".";
        for (int i = 0; i < FractionalIndex; i++) {
            output << FractionalResult[i];
        }
    }
    else if (IntIndex + FractionalIndex + 1 < width && FractionalIndex != 0) {
        int filling_length = width - IntIndex - 1 - FractionalIndex;
        for (int i = 0; i < filling_length; i++) {
            output << '*';
        }
        for (int i = 0; i < IntIndex; i++) {
            output << Result[i];
        }
        output << ".";
        for (int i = 0; i < FractionalIndex; i++) {
            output << FractionalResult[i];
        }
    }
    else if (IntIndex < width && FractionalIndex == 0) {
        int filling_length = width - IntIndex;
        for (int i = 0; i < filling_length; i++) {
            output << '*';
        }
        for (int i = 0; i < IntIndex; i++) {
            output << Result[i];
        }
    }
    else if (IntIndex > width && FractionalIndex == 0) {
        for (int i = 0; i < IntIndex; i++) {
            output << Result[i];
        }
    }
}

namespace lab_7 {
    void runDemo() {
        setlocale(LC_ALL, "ru");
        bool f = true; int N = 0;
        STRING str(' ');
        DEMO Seq;
        std::tuple<int, int, char, float, float> my_seq;
        int width = 5, fractional_1 = 1, fractional_2 = 2, fractional_3 = 3;
        std::ofstream outputFile("output.txt");
        /*
        int numInt = 113;
        double numFloat = 52.7;
        std::cout << "Число: " << numInt;
        for (int i = 1; i < 36; i++) {
            std::cout << "\nДля " << std::setw(2) << i + 1 << " СС: ";
            Manip(i + 1, 10, 0, '+', numInt, std::cout);
        }
        std::cout << "\n\nЧисло: " << numFloat;
        for (int i = 1; i < 36; i++) {
            std::cout << "\nДля " << std::setw(2) << i + 1 << " СС: ";
            Manip(i + 1, 10, 3, '+', numFloat, std::cout);
        }
        */
        while (f) {
            std::cout << "\n\n================================================\n 1 | Задать строку и вывести её\n================================================";
            std::cout << "\n 2 | Задать значения и выполнить преобразования\n================================================";
            std::cout << "\n 3 | Выйти из программы\n================================================";
            std::cout << "\n| Выберите действие: "; std::cin >> N;
            switch (N)
            {
            case 1:
                std::cout << "\n1) Введите текст для инициализации строки (без пробелов): ";
                std::cin >> str;
                std::cout << "Введённая строка, выведенная через '<<': " << str;
                break;
            case 2:
                Seq.SetFields();
                //i2 i1 c f1 f2
                my_seq = Seq.GetFields();
                std::cout << std::setfill('*');
                outputFile << std::setfill('*');
                std::cout << "\nРезультат преобразования, в соответствии с заданием:\n";
                //i2
                Manip(16, width, 0, '*', std::get<1>(my_seq), std::cout); std::cout << std::endl;
                Manip(16, width, 0, '*', std::get<1>(my_seq), outputFile); outputFile << std::endl;
                //i1
                //std::cout << std::setw(width) << std::right << std::hex << std::get<0>(my_seq) << std::endl;
                //outputFile << std::setw(width) << std::right << std::hex << std::get<0>(my_seq) << std::endl;
                Manip(16, width, 0, '*', std::get<0>(my_seq), std::cout); std::cout << std::endl;
                Manip(16, width, 0, '*', std::get<0>(my_seq), outputFile); outputFile << std::endl;
                //c
                std::cout << std::setw(width) << std::right << std::get<2>(my_seq) << std::endl;
                outputFile << std::setw(width) << std::right << std::get<2>(my_seq) << std::endl;
                //f1
                //ToHex(std::get<3>(my_seq), width, fractional_1, std::cout);
                //ToHex(std::get<3>(my_seq), width, fractional_1, outputFile);
                Manip(16, width, fractional_1, '*', std::get<3>(my_seq), std::cout); std::cout << std::endl;
                Manip(16, width, fractional_1, '*', std::get<3>(my_seq), outputFile); outputFile << std::endl;
                Manip(16, width, fractional_2, '*', std::get<3>(my_seq), std::cout); std::cout << std::endl;
                Manip(16, width, fractional_2, '*', std::get<3>(my_seq), outputFile); outputFile << std::endl;
                Manip(16, width, fractional_3, '*', std::get<3>(my_seq), std::cout); std::cout << std::endl;
                Manip(16, width, fractional_3, '*', std::get<3>(my_seq), outputFile); outputFile << std::endl;
                //f2
                Manip(16, width, fractional_1, '*', std::get<4>(my_seq), std::cout); std::cout << std::endl;
                Manip(16, width, fractional_1, '*', std::get<4>(my_seq), outputFile); outputFile << std::endl;
                Manip(16, width, fractional_2, '*', std::get<4>(my_seq), std::cout); std::cout << std::endl;
                Manip(16, width, fractional_2, '*', std::get<4>(my_seq), outputFile); outputFile << std::endl;
                Manip(16, width, fractional_3, '*', std::get<4>(my_seq), std::cout); std::cout << std::endl;
                Manip(16, width, fractional_3, '*', std::get<4>(my_seq), outputFile); outputFile << std::endl;
                outputFile.close();
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