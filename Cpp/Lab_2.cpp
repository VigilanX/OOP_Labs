#include "Lab_2.h"
#include <iostream>
#include <cstdlib>
namespace lab_2 {
    // �����������
    ThreeDimensionalArray::ThreeDimensionalArray(int x, int y, int z) {
        // ��������� �� ���������� �������, ����� �� ���� ������ ��������� ������
        if (x <= 0 || y <= 0 || z <= 0) {
            std::cout << ("������� ������� ������ ���� ��������������\n");
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
            //����� �������
            for (int k = 0; k < z; ++k) {
                std::cout << "���� " << k + 1 << ":\n";
                for (int i = 0; i < x; ++i) {
                    for (int j = 0; j < y; ++j) {
                        std::cout << array[i][j][k] << " ";
                    }
                    std::cout << "\n";
                }
            }
        }
    }

    // ����������� ��� ����
    ThreeDimensionalArray::ThreeDimensionalArray(int t) {
        // ��������� �� ���������� �������, ����� �� ���� ������ ��������� ������
        if (t <= 0) {
            std::cout << ("������� ������� ������ ���� ��������������\n");
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
            //����� �������
            for (int k = 0; k < z; ++k) {
                std::cout << "���� " << k + 1 << ":\n";
                for (int i = 0; i < x; ++i) {
                    for (int j = 0; j < y; ++j) {
                        std::cout << array[i][j][k] << " ";
                    }
                    std::cout << "\n";
                }
            }
            // std::cout << "\n ������� 2 ���� [0 1]: " << array[0][1][1];
        }
    }

    // ����� ��� ������ ������ ������
    void ThreeDimensionalArray::printMemorySize() {
        std::cout << "����� ������, ���������� ��������� ��������: " << x * y * z * sizeof(int) << " ����" << std::endl;
    }

    // ����� ��� ��������� �������� � �������
    void ThreeDimensionalArray::setValue(int i, int j, int k, int value) {
        if (i >= 0 && i < x && j >= 0 && j < y && k >= 0 && k < z) {
            array[i][j][k] = value;
        }
        else {
            std::cout << "������� ������� �� ������� �������";
        }
    }

    // ����� ��� ������������ ������
    ThreeDimensionalArray::~ThreeDimensionalArray() {
        for (int i = 0; i < x; ++i) {
            for (int j = 0; j < y; ++j) {
                free(array[i][j]);
            }
            free(array[i]);
        }
        free(array);
    }

    // �������� (������� �������� �� ���������)
    void ThreeDimensionalArray::GetSum() {
        int pir_sum = 0;
        std::cout << "\n";
        for (int k = 0; k < z; k++) {
            std::cout << "��� ���� " << k + 1 << ": ";
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
            std::cout << "\n�����: " << layer_sum << "\n";
        }
        std::cout << "\n����� ��������� ������ ��������: " << pir_sum << "\n";
    }
}