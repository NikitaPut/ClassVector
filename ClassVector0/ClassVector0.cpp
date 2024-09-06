#include <iostream>
#include "Vector.h"

int main() {
    // Создание вектора по умолчанию
    Vector v1;
    std::cout << "Vector v1 (default): ";
    v1.print();

    // Создание вектора заданной длины, заполненного нулями
    Vector v2(5);
    std::cout << "Vector v2 (length 5, zeros): ";
    v2.print();

    // Создание вектора заданной длины, заполненного заданным значением
    Vector v3(5, 3);
    std::cout << "Vector v3 (length 5, filled with 3): ";
    v3.print();

    // Создание вектора из массива
    int arr[] = { 1, 2, 3, 4, 5 };
    Vector v4(arr, 5);
    std::cout << "Vector v4 (initialized from array): ";
    v4.print();

    // Копирование вектора
    Vector v5 = v4;
    std::cout << "Vector v5 (copy of v4): ";
    v5.print();

    // Присваивание вектора
    v1 = v3;
    std::cout << "Vector v1 (after assignment from v3): ";
    v1.print();

    // Сложение векторов
    Vector v6 = v3 + v4;
    std::cout << "Vector v6 (v3 + v4): ";
    v6.print();

    // Сравнение векторов
    std::cout << "v3 == v4: " << (v3 == v4 ? "true" : "false") << std::endl;
    std::cout << "v5 == v4: " << (v5 == v4 ? "true" : "false") << std::endl;

    // Доступ к элементам через оператор []
    try {
        std::cout << "v4[2]: " << v4[2] << std::endl;
        v4[2] = 10;
    }
    catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    // Проверка размера вектора
    std::cout << "Size of v4: " << v4.size() << std::endl;

    return 0;
}
