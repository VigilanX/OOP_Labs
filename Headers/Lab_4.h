#include <iostream>
namespace lab_4 {
    void runDemo();
    class STRING {
    public:
        STRING() { buf = nullptr; len = 0; }

        // ����������� ��� ���������� ������ �������
        STRING(char what);

        // ����� ��� ��������� ������ �������� ������
        virtual STRING& Setstrt(const char* what);

        // ����� ��� ��������� ����� ������
        virtual int Length();

        // ����� ��� ������ ������ �� ���������� (x, y)
        virtual void Print_at(unsigned x, unsigned y);

        //����� ������������ �����
        virtual STRING* Concatenation(STRING& other);

        // ����������
        ~STRING();

    protected:
        char* buf;
        int len;
        // ��������������� ����� ��� ������� ����� ������
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
        // �����������
        EnhancedString(char what);

        // ����� ��� ��������� ������ �������� ������
        STRING& Setstrt(const char* what) override;

        // ����� ��� ������ ����� ������
        int Length() override;

        // ����� ��� ������ ������ �� ���������� (x, y)
        void Print_at(unsigned x, unsigned y) override;

        //����� ������������ �����
        STRING* Concatenation(STRING& other) override;

        // ����������
        ~EnhancedString();
    };
}
