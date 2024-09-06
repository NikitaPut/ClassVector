#include <iostream>
#include <stdexcept> // ����������� ����������� ����������.

class Vector {
private:
    int* data;      // ��������� �� ������ ���������
    size_t length;  // ����� �������

public:
    // ����������� �� ���������
    Vector() : data(nullptr), length(0) {}

    // ����������� � ���������� (�����)
    explicit Vector(size_t size) : length(size) {
        if (size == 0) {
            throw std::invalid_argument("Size must be greater than 0");
        }
        data = new int[size]();  // ������������� ������
    }

    // ����������� � ����������� (����� � ��������)
    Vector(size_t size, int value) : length(size) {
        if (size == 0) {
            throw std::invalid_argument("Size must be greater than 0");
        }
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = value;
        }
    }

    // ����������� �����������
    Vector(const Vector& other) : length(other.length) {
        data = new int[length];
        for (size_t i = 0; i < length; ++i) {
            data[i] = other.data[i];
        }
    }

    // ����������� �������������
    Vector(const int* arr, size_t size) : length(size) {
        if (size == 0) {
            throw std::invalid_argument("Size must be greater than 0");
        }
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = arr[i];
        }
    }

    // �������� ������������
    Vector& operator=(const Vector& other) {
        if (this == &other) {
            return *this; // ����-������������
        }

        delete[] data; // ����������� ������ ������
        length = other.length;
        data = new int[length];
        for (size_t i = 0; i < length; ++i) {
            data[i] = other.data[i];
        }

        return *this;
    }

    // �������� ��������
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

    // ����� print
    void print() const {
        for (size_t i = 0; i < length; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    // �������� ��������� ==
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

    // �������� []
    int& operator[](size_t index) {
        if (index == 0 || index > length) { // ������ ������� � 0-�� ��������
            throw std::out_of_range("Index must be greater than 0 and less than or equal to length");
        }
        return data[index - 1];  // ������� �������� � ������ ��������
    }

    const int& operator[](size_t index) const {
        if (index == 0 || index > length) { // ������ ������� � 0-�� ��������
            throw std::out_of_range("Index must be greater than 0 and less than or equal to length");
        }
        return data[index - 1];  // ������� �������� � ������ ��������
    }

    // ����� size
    size_t size() const {
        return length;
    }

    // ����������
    ~Vector() {
        delete[] data;
    }
};
