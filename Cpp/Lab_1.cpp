#include "Lab_1.h"
#include <iostream>
namespace lab_1 {
    //����������� ��� ���������� ������ �������
    STRING::STRING(char what) {
        len = 1;
        buf = new char[len + 1];
        buf[0] = what;
        buf[1] = '\0';
    }

    STRING::STRING(STRING& STR) {
        //std::cout << "\n! ��� ������ ����������� ����������� ��� ���������� ������ ������� " << &STR << " ������� " << this << " !\n";
        buf = STR.buf;
        len = STR.len;
        //std::cout << "����������� �� ������� " << &STR << " :\n����� = " << STR.buf << " \n����� ������ = " << STR.len;
        //std::cout << "\n! ����������� �������� ���� ������ !\n";
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
}