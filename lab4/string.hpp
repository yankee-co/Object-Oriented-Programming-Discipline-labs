#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <iostream>
#include <cstring>
#include <algorithm>

// Базовий клас для трансформації символів
template <typename T>
class Transformer {
public:
    virtual T operator()(const T& input) const = 0;
    virtual ~Transformer();
};

template <typename T>
class String {
private:
    T* data;
    size_t length;

public:
    String(); // Конструктор за замовченням
    String(const String& other); // Конструктор копіювання
    String(String&& other) noexcept; // Конструктор переміщення
    String(const T* str); // Конструктор ініціалізації з масиву символів
    String(size_t count, T value); // Ініціалізація шляхом повторення символу заданої кількості разів
    ~String(); // Деструктор

    size_t getLength() const; // Метод для отримання довжини рядка
    bool isEmpty() const; // Перевірка, чи є рядок порожнім
    void clear(); // Очищення рядка (робить його порожнім)
    T operator[](size_t index) const; // Оператор отримання символу за індексом
    T& operator[](size_t index); // Оператор для отримання/запису символу за індексом
    String substr(size_t startIndex, size_t substringLength) const;
    String& operator=(const T* cString); // Оператор присвоєння C-строки
    String& operator=(const String& other); // Оператор присвоєння копіювання
    String& operator=(String&& other) noexcept; // Оператор присвоєння переміщення
    String operator+(const String& other) const; // Конкатенація рядків
    String operator*(int factor) const; // Оператор множення рядка на ціле число (зліва)
    String& operator+=(T character); // Додавання одного символу до рядка (зліва)
    String& operator+=(const String& other); // Додавання одного символу до рядка (справа)
    bool operator==(const String& other) const; // Оператор порівняння рядків (рівність)
    bool operator!=(const String& other) const; // Оператор порівняння рядків (нерівність)
    bool operator<(const String& other) const; // Оператор порівняння рядків за лексикографічним порядком (менше)
    bool operator>(const String& other) const; // Оператор порівняння рядків за лексикографічним порядком (більше)
    bool operator<=(const String& other) const; // Оператор порівняння рядків за лексикографічним порядком (менше або рівне)
    bool operator>=(const String& other) const; // Оператор порівняння рядків за лексикографічним порядком (більше або рівне

    template <typename UnaryFunction> // Застосування трансформації на місці
    void transformInPlace(UnaryFunction&& func);

    template <typename UnaryFunction> // Трансформація рядка створенням нового рядка (динамічний поліморфізм)
    String transformCopy(UnaryFunction&& func) const;

    template <typename UnaryFunction> // Трансформація рядка створенням нового рядка (статичний поліморфізм)
    String transformCopyStatic(UnaryFunction&& func) const;

    template <typename U> // Функція створення рядка відповідного типу із масиву символів
    static String createFromStringArray(U* begin, U* end);

    template <typename U> // Функція створення рядка відповідного типу із масиву символів (тільки початок)
    static String createFromStringArray(U* begin);

    template <typename TransformerType> // Застосування трансформації за допомогою функціонального об'єкту
    void apply(const TransformerType& transformer);

    template <typename U> // Оператор множення рядка на ціле число (справа)
    friend String<U> operator*(int factor, const String<U>& str); 
    
    template <typename U> // Введення рядка з клавіатури
    friend std::istream& operator >>(std::istream& is, String<U>& str);

    template <typename U> // Оператор виводу
    friend std::ostream& operator <<(std::ostream& os, const String<U>& str);

    // Допоміжний метод для додавання символу в кінець рядка
    void pushBack(T character);

    // Допоміжний метод для додавання символів з іншого рядка в кінець
    void pushBack(const String& other);

    // Допоміжний метод для додавання символу в початок рядка
    void pushFront(T character);

};

#include "string.cpp"

#endif