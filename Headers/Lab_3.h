#include <iostream>
namespace lab_3 {
    void runDemo();
    class Just_Array {
    private:
        int N;    // ������� �������
        int* array;   // ������
    public:
        // �����������
        Just_Array(int N);

        //����� ��� ���������� �������
        void Conversion();

        //����� ��� ���������� �������
        void Beauti_Matrix();

        // ����� ��� ������������ ������
        ~Just_Array();
    };
}
