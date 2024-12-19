#include "Lab_4.h"
#include <iostream>
#include <cstdlib>
namespace lab_4 {
    // ����������� ��� ���������� ������ �������
    STRING::STRING(char what) {
        len = 1;
        buf = new char[len + 1];
        buf[0] = what;
        buf[1] = '\0';
    }

    // ����� ��� ��������� ������ �������� ������
    STRING& STRING::Setstrt(const char* what) {
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

    // ����� ��� ��������� ����� ������
    int STRING::Length() {
        return len;
    }

    // ����� ��� ������ ������ �� ���������� (x, y)
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

    //����� ������������ �����
    STRING* STRING::Concatenation(STRING& other) {
        char* new_buf = new char[len + other.Length() + 1];
        for (int i = 0; i < this->len; i++) {
            new_buf[i] = buf[i];
        }
        for (int i = this->len; i < len + other.Length(); i++) {
            new_buf[i] = other.buf[i - this->len];
        }
        new_buf[len + other.Length()] = '\0';
        this->Setstrt(new_buf);
        STRING* result = new STRING('A');
        result->Setstrt(new_buf);
        return result;
    }

    // ����������
    STRING::~STRING() {
        if (buf != nullptr) {
            delete[]buf;
            buf = nullptr;
        }
    }


    // ����� EnhancedString
    // �����������
    EnhancedString::EnhancedString(char what) {
        len = 1;
        buf = new char[len + 1];
        buf[0] = what;
        buf[1] = '\0';
    };

    // ����� ��� ��������� ������ �������� ������
    STRING& EnhancedString::Setstrt(const char* what) {
        int len_what = GetLength(what);
        char* new_buf = new char[len + len_what + 1];
        // �������� ������� ������ � ����� �����
        for (int i = 0; i < len; i++) {
            new_buf[i] = buf[i];
        }
        // �������� ����� ������ ����� �������
        for (int i = 0; i < len_what; i++) {
            new_buf[len + i] = what[i];
        }
        new_buf[len + len_what] = '\0';
        delete[] buf;
        buf = new_buf;
        len = len + len_what;
        return *this;
    }

    // ����� ��� ������ ����� ������
    int EnhancedString::Length() {
        std::cout << "����� ������ ����� = " << len;
        return len;
    };

    // ����� ��� ������ ������ �� ���������� (x, y)
    void EnhancedString::Print_at(unsigned x, unsigned y) {
        if (x > 0) {
            for (int i = 0; i < x; i++) {
                std::cout << "\n";
            }
        }
        if (y > 0) {
            for (int j = 0; j < y - 1; j++) {
                std::cout << " ";
            }
        }
        for (int i = 0; i < len; i++) {
            std::cout << buf[i];
        }
        std::cout << "\n";
    };

    //����� ������������ �����
    STRING* EnhancedString::Concatenation(STRING& other) {
        int OtherLenght = other.Length();
        // ������� �������� other � ���� EnhancedString
        EnhancedString* enhancedOther = dynamic_cast<EnhancedString*>(&other);
        // ���� ���������� �������, ���������� ��� �����
        char* otherBuf = (enhancedOther != nullptr) ? enhancedOther->buf : nullptr;
        // ���������, ���� �� ����� � ������ ������
        if (otherBuf == nullptr) {
            // ���� ������ ���, ���������� ������� ������ ��� ������������ ������
            return nullptr; // ��� ����� ��������� ����������
        }
        char* new_buf = new char[len + OtherLenght + 1];
        for (int i = 0; i < this->len; i++) {
            new_buf[i] = buf[i];
            if (new_buf[i] >= 'a' && new_buf[i] <= 'z') {
                new_buf[i] = new_buf[i] - ('a' - 'A');
            }
        }
        for (int i = this->len; i < len + OtherLenght; i++) {
            new_buf[i] = otherBuf[i - this->len];
            if (new_buf[i] >= 'a' && new_buf[i] <= 'z') {
                new_buf[i] = new_buf[i] - ('a' - 'A');
            }
        }
        new_buf[len + OtherLenght] = '\0';
        len = len + OtherLenght + 1;
        buf = new_buf;
        STRING* result = new EnhancedString('A');
        result->Setstrt(new_buf);
        return result;
    };

    // ����������
    EnhancedString::~EnhancedString() {
        if (buf != nullptr) {
            delete[]buf;
            buf = nullptr;
        }
    };
}