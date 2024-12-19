#include <iostream>
namespace lab_5 {
    void runDemo();
    class STRING {
    public:
        // Конструктор по умолчанию
        STRING() : buf(nullptr), len(0) {}

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

        //Метод сравнения строк
        unsigned Strcmp(STRING s2);

        //Перегруженный метод сравнения строк
        void Strcmp(STRING s2, STRING s3);

        //Перегрузка оператора сложения
        STRING operator+(const STRING& other);

        //Перегрузка оператора умножения
        STRING operator*(int times);

        //Перегрузка оператора присваивания
        STRING operator=(const STRING& str_to_copy);

        //Перегрузка оператора присваивания по перемещению
        STRING operator*(STRING&& str_moved);

        //Перегрузка функтора
        void operator()();

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

}
