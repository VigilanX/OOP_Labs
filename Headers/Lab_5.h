#include <iostream>
namespace lab_5 {
    void runDemo();
    class STRING {
    public:
        // ����������� �� ���������
        STRING() : buf(nullptr), len(0) {}

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

        //����� ��������� �����
        unsigned Strcmp(STRING s2);

        //������������� ����� ��������� �����
        void Strcmp(STRING s2, STRING s3);

        //���������� ��������� ��������
        STRING operator+(const STRING& other);

        //���������� ��������� ���������
        STRING operator*(int times);

        //���������� ��������� ������������
        STRING operator=(const STRING& str_to_copy);

        //���������� ��������� ������������ �� �����������
        STRING operator*(STRING&& str_moved);

        //���������� ��������
        void operator()();

        //���������� ��������� �����
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

        //���������� ��������� ������
        friend std::ostream& operator<<(std::ostream& os, const STRING& str) {
            if (str.buf) {
                os << str.buf;
            }
            return os;
        }

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
