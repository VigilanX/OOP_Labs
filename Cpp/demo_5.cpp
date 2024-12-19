#include "Lab_5.h"
namespace lab_5 {
    void runDemo() {
        setlocale(LC_ALL, "ru");
        int N = -1;
        STRING str1(' ');
        str1.Setstrt((char*)"String");
        STRING str2(' ');
        str2.Setstrt((char*)"String Mid");
        STRING str3(' ');
        str3.Setstrt((char*)"String Long");
        bool f = true;
        STRING* str_array = new STRING[100];
        int arr_size = 3;
        str_array[0] = str1;
        str_array[1] = str2;
        str_array[2] = str3;
        while (f) {
            std::cout << "\n\n======================\n1) ������� ������\n";
            std::cout << "2) �������� ������\n";
            std::cout << "3) �������� ������\n";
            std::cout << "4) ������������� ������\n";
            std::cout << "5) �������� ������\n";
            std::cout << "6) ������������ �������\n";
            std::cout << "7) ������ ����� ������\n";
            std::cout << "8) ������� ��� ��������� ������\n";
            std::cout << "9) ����� �� ���������\n======================";
            std::cout << "\n| �������� ��������: "; std::cin >> N;
            int s1 = 0, s2 = 0, s3 = 0;
            STRING result1(' ');
            STRING result2(' ');
            STRING new_str(' ');
            switch (N)
            {
            case 1:
                for (int i = 0; i < arr_size; i++) {
                    std::cout << "\n������ " << i + 1 << ": " << str_array[i];
                }
                std::cout << "\n������� ����� ������ ����� ������� �������: ";
                std::cin >> s1; std::cin >> s2;
                if (s1 == 1 && s2 == 1) {
                    result1 = str1 + str1;
                    result1.Print_at(0, result1.Length());
                }
                else if (s1 == 1 && s2 == 2) {
                    result1 = str1 + str2;
                    result1.Print_at(0, result1.Length());
                }
                else if (s1 == 1 && s2 == 3) {
                    result1 = str1 + str3;
                    result1.Print_at(0, result1.Length());
                }
                else if (s1 == 2 && s2 == 1) {
                    result1 = str2 + str1;
                    result1.Print_at(0, result1.Length());
                }
                else if (s1 == 2 && s2 == 2) {
                    result1 = str2 + str2;
                    result1.Print_at(0, result1.Length());
                }
                else if (s1 == 2 && s2 == 3) {
                    result1 = str2 + str3;
                    result1.Print_at(0, result1.Length());
                }
                else if (s1 == 3 && s2 == 1) {
                    result1 = str3 + str1;
                    result1.Print_at(0, result1.Length());
                }
                else if (s1 == 3 && s2 == 2) {
                    result1 = str3 + str2;
                    result1.Print_at(0, result1.Length());
                }
                else if (s1 == 3 && s2 == 3) {
                    result1 = str3 + str3;
                    result1.Print_at(0, result1.Length());
                }
                else {
                    std::cout << "\n ������������ ������ ����� !";
                }
                break;
            case 2:
                for (int i = 0; i < arr_size; i++) {
                    std::cout << "\n������ " << i + 1 << ": " << str_array[i];
                }
                std::cout << "\n������� ����� ������ �������� � �� ����� �����: ";
                int s, k; std::cin >> s >> k;
                if (s == 1) {
                    result2 = str1 * k;
                    result2.Print_at(0, result2.Length());
                }
                else if (s == 2) {
                    result2 = str2 * k;
                    result2.Print_at(0, result2.Length());
                }
                else if (s == 3) {
                    result2 = str3 * k;
                    result2.Print_at(0, result2.Length());
                }
                else {
                    std::cout << "\n ������������ ������ ����� !";
                }
                break;
            case 3:
                for (int i = 0; i < arr_size; i++) {
                    std::cout << "\n������ " << i + 1 << ": " << str_array[i];
                }
                std::cout << "\n������� ����� ������ �������� (��� ���� ����� - ��������� ���� 0; '1 2 3' - ��� ��������� ���� �����): ";
                std::cin >> s1 >> s2 >> s3;
                if (s1 == 1 && s2 == 2 && s3 == 0) {
                    std::cout << "��������� ���������: " << str1.Strcmp(str2);
                }
                else if (s1 == 1 && s2 == 3 && s3 == 0) {
                    std::cout << "��������� ���������: " << str1.Strcmp(str3);
                }
                else if (s1 == 2 && s2 == 1 && s3 == 0) {
                    std::cout << "��������� ���������: " << str2.Strcmp(str1);
                }
                else if (s1 == 2 && s2 == 3 && s3 == 0) {
                    std::cout << "��������� ���������: " << str2.Strcmp(str3);
                }
                else if (s1 == 3 && s2 == 1 && s3 == 0) {
                    std::cout << "��������� ���������: " << str3.Strcmp(str1);
                }
                else if (s1 == 3 && s2 == 2 && s3 == 0) {
                    std::cout << "��������� ���������: " << str3.Strcmp(str2);
                }
                else if (s1 == 1 && s2 == 2 && s3 == 3) {
                    std::cout << "��������� ���������: "; str1.Strcmp(str2, str3);
                }
                else {
                    std::cout << "\n ������������ ������ ����� !";
                }
                break;
            case 4:
                for (int i = 0; i < arr_size; i++) {
                    std::cout << "\n������ " << i + 1 << ": " << str_array[i];
                }
                std::cout << "\n������� ����� ������ ���������: ";
                std::cin >> s1;
                std::cout << "\n������� ����� ������ ��������� ����� ��������: ";
                std::cin >> s2;
                if (s1 > arr_size or s2 > arr_size) {
                    std::cout << "\n ������������ ������ ����� !";
                    break;
                }
                str_array[s2 - 1] = str_array[s1 - 1];
                std::cout << "\n" << str_array[s2 - 1] << "\t" << str_array[s1 - 1];
                break;
            case 5:
                for (int i = 0; i < arr_size; i++) {
                    std::cout << "\n������ " << i + 1 << ": " << str_array[i];
                }
                std::cout << "\n������� ����� ������ ������������: ";
                std::cin >> s1;
                std::cout << "\n������� � ����� ������ ������������ ����� ��������: ";
                std::cin >> s2;
                if (s1 > arr_size or s2 > arr_size) {
                    std::cout << "\n ������������ ������ ����� !";
                    break;
                }
                str_array[s2 - 1] = std::move(str_array[s1 - 1]);
                std::cout << "\n" << str_array[s2 - 1] << "\t" << str_array[s1 - 1];
                break;
            case 6:
                for (int i = 0; i < arr_size; i++) {
                    std::cout << "\n������ " << i + 1 << ": " << str_array[i];
                }
                std::cout << "\n������� ��� ����� ������ ������������ �������: ";
                std::cin >> s1;
                if (s1 > arr_size) {
                    std::cout << "\n������������ ������ ����� !";
                    break;
                }
                str_array[s1 - 1]();
                break;
            case 7:
                std::cout << "\n������� ����� ������:";
                std::cin >> new_str;
                str_array[arr_size] = new_str;
                arr_size++;
                break;
            case 8:
                std::cout << "\n��� ��������� ������:";
                for (int i = 0; i < arr_size; i++) {
                    std::cout << "\n������ " << i + 1 << ": " << str_array[i];
                }
                break;
            case 9:
                f = false;
                break;
            default:
                break;
            }
        }
    }
}