#include <iostream>
#include <stdexcept> // îïðåäåëåíèÿ ñòàíäàðòíûõ èñêëþ÷åíèé.

class Vector {
private:
    int* data;      // Óêàçàòåëü íà ìàññèâ ýëåìåíòîâ
    size_t length;  // Äëèíà âåêòîðà

public:
    // Êîíñòðóêòîð ïî óìîë÷àíèþ
    Vector() : data(nullptr), length(0) {}

    // Êîíñòðóêòîð ñ ïàðàìåòðîì (äëèíà)
    explicit Vector(size_t size) : length(size) {
        if (size == 0) {
            throw std::invalid_argument("Size must be greater than 0");
        }
        data = new int[size]();  // Èíèöèàëèçàöèÿ íóëÿìè
    }

    // Êîíñòðóêòîð ñ ïàðàìåòðàìè (äëèíà è çíà÷åíèå)
    Vector(size_t size, int value) : length(size) {
        if (size == 0) {
            throw std::invalid_argument("Size must be greater than 0");
        }
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = value;
        }
    }

    // Êîíñòðóêòîð êîïèðîâàíèÿ
    Vector(const Vector& other) : length(other.length) {
        data = new int[length];
        for (size_t i = 0; i < length; ++i) {
            data[i] = other.data[i];
        }
    }

    // Êîíñòðóêòîð èíèöèàëèçàöèè
    Vector(const int* arr, size_t size) : length(size) {
        if (size == 0) {
            throw std::invalid_argument("Size must be greater than 0");
        }
        data = new int[size];
        for (size_t i = 0; i < size; ++i) {
            data[i] = arr[i];
        }
    }

    // Îïåðàòîð ïðèñâàèâàíèÿ
    Vector& operator=(const Vector& other) {
    if (this == &other) {
        return *this; // само-присваивание
    }

    // Если размерности не совпадают, выделяем новую память
    if (length != other.length) {
        delete[] data;
        length = other.length;
        data = new int[length];
    }

    // Копируем данные напрямую
    for (size_t i = 0; i < length; ++i) {
        data[i] = other.data[i];
    }

    return *this;
}

    // Îïåðàòîð ñëîæåíèÿ
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

    // Ìåòîä print
    void print() const {
        for (size_t i = 0; i < length; ++i) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
    }

    // Îïåðàòîð ñðàâíåíèÿ ==
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

    // Îïåðàòîð []
    int& operator[](size_t index) {
        if (index == 0 || index > length) { // Çàïðåò äîñòóïà ê 0-ìó ýëåìåíòó
            throw std::out_of_range("Index must be greater than 0 and less than or equal to length");
        }
        return data[index - 1];  // Âîçâðàò ýëåìåíòà ñ ó÷åòîì ñìåùåíèÿ
    }

    const int& operator[](size_t index) const {
        if (index == 0 || index > length) { // Çàïðåò äîñòóïà ê 0-ìó ýëåìåíòó
            throw std::out_of_range("Index must be greater than 0 and less than or equal to length");
        }
        return data[index - 1];  // Âîçâðàò ýëåìåíòà ñ ó÷åòîì ñìåùåíèÿ
    }

    // Ìåòîä size
    size_t size() const {
        return length;
    }

    // Äåñòðóêòîð
    ~Vector() {
        delete[] data;
    }
};
