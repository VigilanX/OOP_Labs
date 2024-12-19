#include "Lab_7.h"
#include <iostream>
#include <tuple>;
namespace lab_7 {
    //����������� ��� ���������� ������ �������
    STRING::STRING(char what) {
        len = 1;
        buf = new char[len + 1];
        buf[0] = what;
        buf[1] = '\0';
    }

    STRING::STRING(STRING& STR) {
        buf = STR.buf;
        len = STR.len;
    }

    //����� ��� ��������� ������ �������� ������
    STRING STRING::Setstrt(char* what) {
        int len_what = GetLength(what);
        if (len_what > len) {
            delete[] buf;
            len = len_what;
            buf = new char[len + 1];
            for (int i = 0; i < len; ++i) {
                buf[i] = what[i];
            }
            buf[len] = '\0';
            return *this;
        }
        else {
            for (int i = 0; i < len_what; ++i) {
                buf[i] = what[i];
            }
            return *this;
        }
    }

    //����� ��� ��������� ����� ������
    int STRING::Length() {
        return len;
    }

    //����� ��� ������ ������ �� ���������� (x, y)
    void STRING::Print_at(unsigned x, unsigned y) {
        if (x > y) {
            std::cout << "\n! <x> ������ ���� ������, ��� <y> !";
            return;
        }
        if (x > len) {
            std::cout << "\n! �������� <x> ��������� ����� ������ !";
            return;
        }
        if (x == 0) {
            std::cout << "\n! �������� <x> ������ ���� ������ �����������. <x> ����� ������ �� 1 !\n";
            x = 1;
        }
        if (y > len) {
            std::cout << "\n! �������� <y> ��������� ����� ������. <y> ����� ������ �� ����� ������ !\n";
            y = len;
        }
        for (int i = x - 1; i < y; i++) {
            std::cout << buf[i];
        }
    }

    //����� DEMO
    void DEMO::SetFields() {
        std::cout << "\n������� i1 (int): ";
        while (!(std::cin >> i1) || std::cin.peek() != '\n') {
            std::cout << "������! ������� ����� ����� (int): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "������� f1 (float): ";
        while (!(std::cin >> f1)) {
            std::cout << "������! ������� ����� � ��������� ������ (float): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "������� c (char): ";
        while (!(std::cin >> c)) {
            std::cout << "������! ������� ������ (char): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "������� f2 (float): ";
        while (!(std::cin >> f2)) {
            std::cout << "������! ������� ����� � ��������� ������ (float): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "������� i2 (int): ";
        while (!(std::cin >> i2) || std::cin.peek() != '\n') {
            std::cout << "������! ������� ����� ����� (int): ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    std::tuple<int, int, char, float, float> DEMO::GetFields() {
        std::tuple<int, int, char, float, float> sequence;
        sequence = std::make_tuple(i2, i1, c, f1, f2);
        return sequence;
    }

    Manip::Manip(int setbase_value, int setwidth_value, int setprecision_value, char setfill_value, int number, std::ostream& output) {
        base_value = setbase_value;
        width_value = setwidth_value;
        precision_value = setprecision_value;
        fill_value = setfill_value;
        //���������� ��� ������
        double fractional, integer;
        int IntegerPart, IntIndex = 0;
        int filling_length;
        char IntResult[32];
        char Result[32];
        fractional = modf(number, &integer);
        IntegerPart = (int)integer;
        if (base_value > 1) {
            while (IntegerPart > 0) {
                IntResult[IntIndex++] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[IntegerPart % base_value];
                IntegerPart /= base_value;
            }
            for (int i = 0; i < IntIndex; i++) {
                Result[i] = IntResult[IntIndex - i - 1];
            }
            if (IntIndex >= width_value) {
                for (int i = 0; i < IntIndex; i++) {
                    output << Result[i];
                }
            }
            else {
                filling_length = width_value - IntIndex;
                for (int i = 0; i < filling_length; i++) {
                    output << setfill_value;
                }
                for (int i = 0; i < IntIndex; i++) {
                    output << Result[i];
                }
            }
        }
        else {
            std::cout << "\n! �������� ���� �� !\n";
        }
    }

    Manip::Manip(int setbase_value, int setwidth_value, int setprecision_value, char setfill_value, double number, std::ostream& output) {
        base_value = setbase_value;
        width_value = setwidth_value;
        precision_value = setprecision_value;
        fill_value = setfill_value;
        //���������� ��� ������
        double fractional, integer;
        int IntegerPart, IntIndex = 0;
        int filling_length;
        char IntResult[32];
        char Result[32];
        //��� ������� �����
        char FractionalResult[32];
        int FractionalIndex = 0;
        double frac_fractional, frac_integer;
        int iterac = 0;
        fractional = modf(number, &integer);
        IntegerPart = (int)integer;
        if (base_value > 1) {
            while (IntegerPart > 0) {
                IntResult[IntIndex++] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[IntegerPart % base_value];
                IntegerPart /= base_value;
            }
            for (int i = 0; i < IntIndex; i++) {
                Result[i] = IntResult[IntIndex - i - 1];
            }
            frac_fractional = modf(fractional, &frac_integer);
            while (frac_fractional != 0 && iterac < 10) {
                fractional *= base_value;
                int digit = static_cast<int>(fractional);
                FractionalResult[FractionalIndex++] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"[digit];
                fractional -= digit;
                frac_fractional = modf(fractional, &frac_integer);
                iterac++;
            }
            if (FractionalIndex > precision_value) {
                FractionalIndex = precision_value;
            }
            if (IntIndex + FractionalIndex + 1 >= width_value && FractionalIndex != 0) {
                for (int i = 0; i < IntIndex; i++) {
                    output << Result[i];
                }
                output << ".";
                for (int i = 0; i < FractionalIndex; i++) {
                    output << FractionalResult[i];
                }
            }
            else if (IntIndex + FractionalIndex + 1 < width_value && FractionalIndex != 0) {
                filling_length = width_value - IntIndex - 1 - FractionalIndex;
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
            else if (IntIndex < width_value && FractionalIndex == 0) {
                filling_length = width_value - IntIndex;
                for (int i = 0; i < filling_length; i++) {
                    output << '*';
                }
                for (int i = 0; i < IntIndex; i++) {
                    output << Result[i];
                }
            }
            else if (IntIndex > width_value && FractionalIndex == 0) {
                for (int i = 0; i < IntIndex; i++) {
                    output << Result[i];
                }
            }
        }
        else {
            std::cout << "\n! �������� ���� �� !\n";
        }
    }
}