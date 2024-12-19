#include <iostream>
namespace lab_1 {
	void runDemo();
    class STRING {
    public:
        //����������� ��� ���������� ������ �������
        STRING(char what);

        //����������� �����������
        STRING(STRING& STR);

        //����� ��� ��������� ������ �������� ������
        STRING Setstrt(char* what);

        //����� ��� ��������� ����� ������
        int Length();

        //����� ��� ������ ������ �� ���������� (x, y)
        void Print_at(unsigned x, unsigned y);

    private:
        char* buf; //����� ��� �������� ������
        int len; //����� ������
        //��������������� ����� ��� ������� ����� ������
        int GetLength(const char* str) {
            int length = 0;
            while (str[length] != '\0') {
                ++length;
            }
            return length;
        }
    };
}
