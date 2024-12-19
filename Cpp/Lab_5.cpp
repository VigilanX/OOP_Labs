#include "Lab_5.h"
#include <iostream>
namespace lab_5 {
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
            //std::cout << "\n! <x> ������ ���� ������, ��� <y> !";
            return;
        }
        if (x > len) {
            //std::cout << "\n! �������� <x> ��������� ����� ������ !";
            return;
        }
        if (x == 0) {
            //std::cout << "\n! �������� <x> ������ ���� ������ �����������. <x> ����� ������ �� 1 !\n";
            x = 1;
        }
        if (y > len) {
            //std::cout << "\n! �������� <y> ��������� ����� ������. <y> ����� ������ �� ����� ������ !\n";
            y = len;
        }
        for (int i = x - 1; i < y; i++) {
            std::cout << buf[i];
        }
    }

    //����� ��������� �����
    unsigned STRING::Strcmp(STRING s2) {
        if (this->len == s2.len) {
            return 1;
        }
        else if (this->len > s2.len) {
            return 3;
        }
        return 2;
    }

    //������������� ����� ��������� �����
    void STRING::Strcmp(STRING s2, STRING s3) {
        if (this->len > s2.len && this->len > s3.len) {
            if (s2.len > s3.len) {
                std::cout << "\n����� �������� ������ - s1, ����� �������� ������ - s3";
            }
            else {
                std::cout << "\n����� �������� ������ - s1, ����� �������� ������ - s2";
            }
        }
        else if (s2.len > this->len && s2.len > s3.len) {
            if (this->len > s3.len) {
                std::cout << "\n����� �������� ������ - s2, ����� �������� ������ - s3";
            }
            else {
                std::cout << "\n����� �������� ������ - s2, ����� �������� ������ - s1";
            }
        }
        else if (s3.len > this->len && s3.len > s2.len) {
            if (this->len > s2.len) {
                std::cout << "\n����� �������� ������ - s3, ����� �������� ������ - s2";
            }
            else {
                std::cout << "\n����� �������� ������ - s3, ����� �������� ������ - s1";
            }
        }
    }

    //���������� ��������� ��������
    STRING STRING::operator+(const STRING& other) {
        STRING result(' ');
        result.len = this->len + other.len;
        result.buf = new char[result.len + 1];
        for (int i = 0; i < result.len; i++) {
            if (i < this->len) {
                result.buf[i] = this->buf[i];
            }
            else {
                result.buf[i] = other.buf[i - this->len];
            }
        }
        result.buf[result.len] = '\0';
        return result;
    }

    //���������� ��������� ���������
    STRING STRING::operator*(int times) {
        STRING result(' ');
        if (times <= 0) return result;
        result.len = len * times;
        result.buf = new char[result.len + 1];
        for (int k = 0; k < times; k++) {
            for (int i = 0; i < this->len; i++) {
                result.buf[i + this->len * k] = this->buf[i];
            }
        }
        result.buf[result.len] = '\0';
        return result;
    }

    //���������� ��������� ������������
    STRING STRING::operator=(const STRING& str_to_copy) {
        //std::cout << "�������� ������: " << &str_to_copy << " � " << this << '\n';
        if (&str_to_copy != this) // �������� ����������������
        {
            delete[] this->buf;
            len = str_to_copy.len;
            buf = new char[len + 1];
            for (int i = 0; i < len; i++) {
                buf[i] = str_to_copy.buf[i];
            }
            buf[len] = '\0';
        }
        return *this;
    }

    //���������� ��������� ������������ �� �����������
    STRING STRING::operator*(STRING&& str_moved) {
        //std::cout << "���������� ������ �� " << &str_moved << " � " << this << '\n';
        if (&str_moved != this) // �������� ����������������
        {
            delete[] buf;
            len = str_moved.len;
            buf = new char[len + 1];
            for (int i = 0; i < len; i++) {
                buf[i] = str_moved.buf[i];
            }
            buf[len] = '\0';
            str_moved.buf = nullptr;
            str_moved.len = 0;
        }
        return *this;
    }

    //���������� ��������
    void STRING::operator()() {
        std::cout << "\n������ ������ STRING � �������: " << this << "\n������ � ���� ������: ";
        this->Print_at(1, this->len);
        std::cout << "\n������ ����� �����, ������: " << this->len;
    }
}