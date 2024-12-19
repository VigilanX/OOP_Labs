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
		std::cout << "1) Реализация класса STRING <-> Lab_1\n";
		std::cout << "2) Трёхмерный массив указателей <-> Lab_2\n";
		std::cout << "3) Работа с последовательностью <-> Lab_3\n";
		std::cout << "4) Наследование от STRING <-> Lab_4\n";
		std::cout << "5) Перегрузка операторов <-> Lab_5\n";
		std::cout << "6) Шаблоны классов и функций <-> Lab_6\n";
		std::cout << "7) Потоковый ввод/вывод <-> Lab_7\n";
		std::cout << "0) Выйти\n";
		std::cout << "=========================================\n Выберите какую программу загрузить: ";
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
			std::cout << "\n! Выход !\n";
			return 0;
		default:
			std::cout << "\n! Некорректный ввод !\n";
		}
	}
}