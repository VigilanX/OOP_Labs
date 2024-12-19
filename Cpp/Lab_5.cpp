#include "Lab_5.h"
#include <iostream>
namespace lab_5 {
    //Конструктор для объявления строки литерой
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
            //std::cout << "\n! <x> должен быть меньше, чем <y> !";
            return;
        }
        if (x > len) {
            //std::cout << "\n! Введённый <x> превышает длину строки !";
            return;
        }
        if (x == 0) {
            //std::cout << "\n! Введённый <x> должен быть числом натуральным. <x> будет принят за 1 !\n";
            x = 1;
        }
        if (y > len) {
            //std::cout << "\n! Введённый <y> превышает длину строки. <y> будет принят за длину строки !\n";
            y = len;
        }
        for (int i = x - 1; i < y; i++) {
            std::cout << buf[i];
        }
    }

    //Метод сравнения строк
    unsigned STRING::Strcmp(STRING s2) {
        if (this->len == s2.len) {
            return 1;
        }
        else if (this->len > s2.len) {
            return 3;
        }
        return 2;
    }

    //Перегруженный метод сравнения строк
    void STRING::Strcmp(STRING s2, STRING s3) {
        if (this->len > s2.len && this->len > s3.len) {
            if (s2.len > s3.len) {
                std::cout << "\nСамая длиннная строка - s1, самая короткая строка - s3";
            }
            else {
                std::cout << "\nСамая длиннная строка - s1, самая короткая строка - s2";
            }
        }
        else if (s2.len > this->len && s2.len > s3.len) {
            if (this->len > s3.len) {
                std::cout << "\nСамая длиннная строка - s2, самая короткая строка - s3";
            }
            else {
                std::cout << "\nСамая длиннная строка - s2, самая короткая строка - s1";
            }
        }
        else if (s3.len > this->len && s3.len > s2.len) {
            if (this->len > s2.len) {
                std::cout << "\nСамая длиннная строка - s3, самая короткая строка - s2";
            }
            else {
                std::cout << "\nСамая длиннная строка - s3, самая короткая строка - s1";
            }
        }
    }

    //Перегрузка оператора сложения
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

    //Перегрузка оператора умножения
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

    //Перегрузка оператора присваивания
    STRING STRING::operator=(const STRING& str_to_copy) {
        //std::cout << "Копируем строку: " << &str_to_copy << " в " << this << '\n';
        if (&str_to_copy != this) // избегаем самоприсваивания
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

    //Перегрузка оператора присваивания по перемещению
    STRING STRING::operator*(STRING&& str_moved) {
        //std::cout << "Перемещаем данные из " << &str_moved << " в " << this << '\n';
        if (&str_moved != this) // избегаем самоприсваивания
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

    //Перегрузка функтора
    void STRING::operator()() {
        std::cout << "\nОбъект класса STRING с адресом: " << this << "\nХранит в себе строку: ";
        this->Print_at(1, this->len);
        std::cout << "\nСтрока имеет длину, равную: " << this->len;
    }
}