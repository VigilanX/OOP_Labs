#include <iostream>
namespace lab_1 {
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
