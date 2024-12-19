#include <iostream>
#include <cstdarg>
namespace lab_6 {
    void runDemo();

    template <typename T>
    class Sequence_of_numbers {
    private:
        T* numbers;
        int seq_size;
    public:
        Sequence_of_numbers();
        Sequence_of_numbers(T* numbers, int seq_size);
        ~Sequence_of_numbers();
        void transformation();
        void getNumbers();
        int getSize();
        void addNumber(T number);
        void clear_arr();

        // ����� print_string
        void print_string(const char* format, ...);
    };

    template <typename T>
    void Sequence_of_numbers<T>::print_string(const char* format, ...) {
        va_list args;
        va_start(args, format);

        while (*format) {
            if (*format == '%') {
                ++format; // ���������� ������ '%'

                // ���������, ���� �� ��������
                int precision = -1; // -1 ��������, ��� �������� �� �������
                if (*format == '.') {
                    ++format;
                    precision = 0; // �������� ���� �������
                    while (*format >= '0' && *format <= '9') {
                        precision = precision * 10 + (*format - '0'); // ��������� ����� ����� '.'
                        ++format;
                    }
                }

                if (*format == 'd') { // ����� �����
                    int value = va_arg(args, int);
                    std::cout << value;
                }
                else if (*format == 'f') { // ����� � ��������� ������
                    double value = va_arg(args, double);
                    if (precision >= 0) {
                        std::cout.precision(precision);
                        std::cout << std::fixed;
                    }
                    std::cout << value;
                    if (precision >= 0) {
                        std::cout.unsetf(std::ios::fixed);
                        std::cout.precision(6);
                    }
                }
                else if (*format == 'c') { // ������
                    char value = static_cast<char>(va_arg(args, int));
                    std::cout << value;
                }
                else if (*format == 's') { // ������
                    const char* value = va_arg(args, const char*);
                    if (value) {
                        std::cout << value;
                    }
                    else {
                        std::cout << "(null)";
                    }
                }
                else {
                    // ���� ������������ �� ���������
                    std::cout << '%' << *format;
                }
            }
            else {
                std::cout << *format; // ������� ������� ������
            }
            ++format;
        }

        va_end(args);
    }

}
