#include <iostream>
#include <tuple>;
#include "iomanip";
#include <fstream>;
namespace lab_7 {
    void runDemo();

    class STRING {
    public:
        //Конструктор для объявления строки литерой
        STRING(char what);

        //Конструктор копирования
        STRING(STRING& STR);

        //Метод для изменения строки областью памяти
        STRING Setstrt(char* what);

        //Метод для получения длины строки
        int Length();

        //Метод для вывода строки со знакоместа (x, y)
        void Print_at(unsigned x, unsigned y);

        //Перегрузка оператора ввода
        friend std::istream& operator>>(std::istream& is, STRING& str) {
            char temp[256];
            is >> temp;
            str.len = 0;
            while (temp[str.len] != '\0' && str.len < sizeof(temp) - 1) {
                str.len++;
            }
            delete[] str.buf;
            str.buf = new char[str.len + 1];
            for (int i = 0; i < str.len; ++i) {
                str.buf[i] = temp[i];
            }
            str.buf[str.len] = '\0';
            return is;
        }

        //Перегрузка оператора вывода
        friend std::ostream& operator<<(std::ostream& os, const STRING& str) {
            if (str.buf) {
                os << str.buf;
            }
            return os;
        }

    private:
        char* buf; //Буфер для хранения строки
        int len; //Длина строки
        //Вспомогательный метод для посчёта длины строки
        int GetLength(const char* str) {
            int length = 0;
            while (str[length] != '\0') {
                ++length;
            }
            return length;
        }
    };

    class DEMO {
    public:
        DEMO() { f1 = 0; f2 = 0; c = '\0'; i1 = 0; i2 = 0; }
        void SetFields();
        std::tuple<int, int, char, float, float> GetFields();
    private:
        float f1, f2;
        char c;
        int i1, i2;
    };

    class Manip {
    private:
        int base_value;
        int width_value;
        int precision_value;
        char fill_value;
    public:
        Manip(int setbase_value, int setwidth_value, int setprecision_value, char setfill_value, int number, std::ostream& output);
        Manip(int setbase_value, int setwidth_value, int setprecision_value, char setfill_value, double number, std::ostream& output);
    };
}
