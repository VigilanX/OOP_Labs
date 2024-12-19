#include <iostream>
namespace lab_4 {
    void runDemo();
    class STRING {
    public:
        STRING() { buf = nullptr; len = 0; }

        // Конструктор для объявления строки литерой
        STRING(char what);

        // Метод для изменения строки областью памяти
        virtual STRING& Setstrt(const char* what);

        // Метод для получения длины строки
        virtual int Length();

        // Метод для вывода строки со знакоместа (x, y)
        virtual void Print_at(unsigned x, unsigned y);

        //Метод конкатенации строк
        virtual STRING* Concatenation(STRING& other);

        // Деструктор
        ~STRING();

    protected:
        char* buf;
        int len;
        // Вспомогательный метод для посчёта длины строки
        int GetLength(const char* str) {
            int length = 0;
            while (str[length] != '\0') {
                ++length;
            }
            return length;
        }
    };


    class EnhancedString : public STRING {
    public:
        // Конструктор
        EnhancedString(char what);

        // Метод для изменения строки областью памяти
        STRING& Setstrt(const char* what) override;

        // Метод для вывода длины строки
        int Length() override;

        // Метод для вывода строки со знакоместа (x, y)
        void Print_at(unsigned x, unsigned y) override;

        //Метод конкатенации строк
        STRING* Concatenation(STRING& other) override;

        // Деструктор
        ~EnhancedString();
    };
}
