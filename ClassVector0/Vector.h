#include <iostream>
#include <stdexcept> // определения стандартных исключений.

class Vector {
private:
    int* data;      // Указатель на массив элементов
    size_t length;  // Длина вектора

public:
    // Конструктор по умолчанию
    Vector() : data(nullptr), length(0) {}

    // Конструктор с параметром (длина)
    explicit Vector(size_t size) : length(size) {
        if (size == 0) {
            throw std::invalid_argument("Size must be greater than 0");
        }
        data = new int[size]();  // Инициализация нулями
    }

    // Конструктор с параметрами (длина и значение)
    Vector(size_t size, int value) : length(size) {
        if (size == 0) {
            throw std::invalid_argument("Size must be greater than 0");
        }
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = value;
        }
    }

    // Конструктор копирования
    Vector(const Vector& other) : length(other.length) {
        data = new int[length];
        for (size_t i = 0; i < length; ++i) {
            data[i] = other.data[i];
        }
    }

    // Конструктор инициализации
    Vector(const int* arr, size_t size) : length(size) {
        if (size == 0) {
            throw std::invalid_argument("Size must be greater than 0");
        }
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = arr[i];
        }
    }

    // Оператор присваивания
    Vector& operator=(const Vector& other) {
        if (this == &other) {
            return *this; // само-присваивание
        }

        delete[] data; // Освобождаем старую память
        length = other.length;
        data = new int[length];
        for (size_t i = 0; i < length; ++i) {
            data[i] = other.data[i];
        }

        return *this;
    }

    // Оператор сложения
    Vector operator+(const Vector& other) const {
        if (length != other.length) {
            throw std::invalid_argument("Vectors must be of the same length");
        }

        Vector result(length);
        for (size_t i = 0; i < length; ++i) {
            result.data[i] = data[i] + other.data[i];
        }

        return result;
    }

    // Метод print
    void print() const {
        for (size_t i = 0; i < length; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    // Оператор сравнения ==
    bool operator==(const Vector& other) const {
        if (length != other.length) {
            return false;
        }
        for (size_t i = 0; i < length; ++i) {
            if (data[i] != other.data[i]) {
                return false;
            }
        }
        return true;
    }

    // Оператор []
    int& operator[](size_t index) {
        if (index == 0 || index > length) { // Запрет доступа к 0-му элементу
            throw std::out_of_range("Index must be greater than 0 and less than or equal to length");
        }
        return data[index - 1];  // Возврат элемента с учетом смещения
    }

    const int& operator[](size_t index) const {
        if (index == 0 || index > length) { // Запрет доступа к 0-му элементу
            throw std::out_of_range("Index must be greater than 0 and less than or equal to length");
        }
        return data[index - 1];  // Возврат элемента с учетом смещения
    }

    // Метод size
    size_t size() const {
        return length;
    }

    // Деструктор
    ~Vector() {
        delete[] data;
    }
};
