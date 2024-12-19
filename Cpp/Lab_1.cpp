#include "Lab_1.h"
#include <iostream>
namespace lab_1 {
    //Конструктор для объявления строки литерой
    STRING::STRING(char what) {
        len = 1;
        buf = new char[len + 1];
        buf[0] = what;
        buf[1] = '\0';
    }

    STRING::STRING(STRING& STR) {
        //std::cout << "\n! Был вызван конструктор копирования для присвоения данных объекта " << &STR << " объекту " << this << " !\n";
        buf = STR.buf;
        len = STR.len;
        //std::cout << "Скопировано от объекта " << &STR << " :\nБуфер = " << STR.buf << " \nДлина строки = " << STR.len;
        //std::cout << "\n! Конструктор завершил свою работу !\n";
    }

    //Метод для изменения строки областью памяти
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

    //Метод для получения длины строки
    int STRING::Length() {
        return len;
    }

    //Метод для вывода строки со знакоместа (x, y)
    void STRING::Print_at(unsigned x, unsigned y) {
        if (x > y) {
            std::cout << "\n! <x> должен быть меньше, чем <y> !";
            return;
        }
        if (x > len) {
            std::cout << "\n! Введённый <x> превышает длину строки !";
            return;
        }
        if (x == 0) {
            std::cout << "\n! Введённый <x> должен быть числом натуральным. <x> будет принят за 1 !\n";
            x = 1;
        }
        if (y > len) {
            std::cout << "\n! Введённый <y> превышает длину строки. <y> будет принят за длину строки !\n";
            y = len;
        }
        for (int i = x - 1; i < y; i++) {
            std::cout << buf[i];
        }
    }
}