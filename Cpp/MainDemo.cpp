#include <iostream>
#include "lab_1.h"
#include "lab_2.h"
#include "lab_3.h"
#include "lab_4.h"
#include "lab_5.h"
#include "lab_6.h"
#include "lab_7.h"

int main() {
	setlocale(LC_ALL, "Rus");

	int N = 0;
	while (true) {
		std::cout << "\n=========================================\n";
		std::cout << "1) ���������� ������ STRING <-> Lab_1\n";
		std::cout << "2) ��������� ������ ���������� <-> Lab_2\n";
		std::cout << "3) ������ � ������������������� <-> Lab_3\n";
		std::cout << "4) ������������ �� STRING <-> Lab_4\n";
		std::cout << "5) ���������� ���������� <-> Lab_5\n";
		std::cout << "6) ������� ������� � ������� <-> Lab_6\n";
		std::cout << "7) ��������� ����/����� <-> Lab_7\n";
		std::cout << "0) �����\n";
		std::cout << "=========================================\n �������� ����� ��������� ���������: ";
		std::cin >> N;

		switch (N) {
		case 1:
			lab_1::runDemo();
			break;
		case 2:
			lab_2::runDemo();
			break;
		case 3:
			lab_3::runDemo();
			break;
		case 4:
			lab_4::runDemo();
			break;
		case 5:
			lab_5::runDemo();
			break;
		case 6:
			lab_6::runDemo();
			break;
		case 7:
			lab_7::runDemo();
			break;
		case 0:
			std::cout << "\n! ����� !\n";
			return 0;
		default:
			std::cout << "\n! ������������ ���� !\n";
		}
	}
}