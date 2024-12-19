#include "Lab_6.h"
#include <iostream>
namespace lab_6 {
#include "Lab_2.h"
#include <iostream>

    template <typename T>
    Sequence_of_numbers<T>::Sequence_of_numbers() {
        this->numbers = new T[0];
        this->seq_size = 0;
    }

    template <typename T>
    Sequence_of_numbers<T>::Sequence_of_numbers(T* numbers, int size) {
        this->seq_size = size;
        this->numbers = new T[size];
        for (int i = 0; i < size; i++) {
            this->numbers[i] = numbers[i];
        }
    }

    template <typename T>
    Sequence_of_numbers<T>::~Sequence_of_numbers() {
        delete[] numbers;
    }

    template <typename T>
    void Sequence_of_numbers<T>::transformation() {
        T* negative = new T[seq_size];
        T* positive = new T[seq_size];
        int n_k = 0;
        int p_k = 0;
        for (int i = 0; i < seq_size; ++i) {
            if (numbers[i] < 0) {
                negative[n_k] = numbers[i];
                n_k++;
            }
            else {
                positive[p_k] = numbers[i];
                p_k++;
            }
        }
        T* reverse_positive = new T[p_k + 1];
        for (int i = 0; i < p_k; i++) {
            reverse_positive[i] = positive[p_k - i - 1];
        }
        for (int i = 0; i < seq_size; i++) {
            if (i < n_k) {
                numbers[i] = negative[i];
            }
            else {
                numbers[i] = reverse_positive[i - n_k];
            }
        }
        delete[] negative;
        delete[] positive;
        delete[] reverse_positive;
    }

    template <typename T>
    void Sequence_of_numbers<T>::getNumbers() {
        for (int i = 0; i < seq_size; i++) {
            std::cout << numbers[i] << " ";
        }
    }

    template <typename T>
    int Sequence_of_numbers<T>::getSize() {
        return seq_size;
    }

    template <typename T>
    void Sequence_of_numbers<T>::addNumber(T number) {
        seq_size = seq_size + 1;
        T* new_numbers = new T[seq_size];
        for (int i = 0; i < seq_size - 1; i++) {
            new_numbers[i] = numbers[i];
        }
        new_numbers[seq_size - 1] = number;
        delete[] numbers;
        numbers = new_numbers;
    }

    template <typename T>
    void Sequence_of_numbers<T>::clear_arr() {
        delete[] numbers;
        this->numbers = new T[0];
        this->seq_size = 0;
    }

    // явна€ инстанциаци€ шаблонов
    template class Sequence_of_numbers<int>;
    template class Sequence_of_numbers<double>;


}