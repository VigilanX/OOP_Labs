#include "Lab_4.h"
#include <iostream>
#include <cstdlib>
namespace lab_4 {
    // Конструктор для объявления строки литерой
    STRING::STRING(char what) {
        len = 1;
        buf = new char[len + 1];
        buf[0] = what;
        buf[1] = '\0';
    }

    // Метод для изменения строки областью памяти
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

    // Метод для получения длины строки
    int STRING::Length() {
        return len;
    }

    // Метод для вывода строки со знакоместа (x, y)
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

    //Метод конкатенации строк
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

    // Деструктор
    STRING::~STRING() {
        if (buf != nullptr) {
            delete[]buf;
            buf = nullptr;
        }
    }


    // Класс EnhancedString
    // Конструктор
    EnhancedString::EnhancedString(char what) {
        len = 1;
        buf = new char[len + 1];
        buf[0] = what;
        buf[1] = '\0';
    };

    // Метод для изменения строки областью памяти
    STRING& EnhancedString::Setstrt(const char* what) {
        int len_what = GetLength(what);
        char* new_buf = new char[len + len_what + 1];
        // Копируем текущую строку в новый буфер
        for (int i = 0; i < len; i++) {
            new_buf[i] = buf[i];
        }
        // Копируем новую строку после текущей
        for (int i = 0; i < len_what; i++) {
            new_buf[len + i] = what[i];
        }
        new_buf[len + len_what] = '\0';
        delete[] buf;
        buf = new_buf;
        len = len + len_what;
        return *this;
    }

    // Метод для вывода длины строки
    int EnhancedString::Length() {
        std::cout << "Длина строки равна = " << len;
        return len;
    };

    // Метод для вывода строки со знакоместа (x, y)
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

    //Метод конкатенации строк
    STRING* EnhancedString::Concatenation(STRING& other) {
        int OtherLenght = other.Length();
        // Пробуем привести other к типу EnhancedString
        EnhancedString* enhancedOther = dynamic_cast<EnhancedString*>(&other);
        // Если приведение успешно, используем его буфер
        char* otherBuf = (enhancedOther != nullptr) ? enhancedOther->buf : nullptr;
        // Проверяем, есть ли буфер у другой строки
        if (otherBuf == nullptr) {
            // Если буфера нет, возвращаем текущий объект или обрабатываем ошибку
            return nullptr; // Или можно выбросить исключение
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

    // Деструктор
    EnhancedString::~EnhancedString() {
        if (buf != nullptr) {
            delete[]buf;
            buf = nullptr;
        }
    };
}