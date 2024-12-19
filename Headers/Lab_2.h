#include <iostream>
namespace lab_2 {
    void runDemo();
    class ThreeDimensionalArray {
    private:
        int x, y, z;    // ������� �������
        int*** array;   // ��������� ������
    public:
        // �����������
        ThreeDimensionalArray(int x, int y, int z);

        // ����������� ��� ����
        ThreeDimensionalArray(int t);

        // ����� ��� ������ ������ ������
        void printMemorySize();

        // ����� ��� ��������� �������� � �������
        void setValue(int i, int j, int k, int value);

        // ����� ��� ������������ ������
        ~ThreeDimensionalArray();

        // ����� ��� ������� ��������
        void GetSum();
    };
}
