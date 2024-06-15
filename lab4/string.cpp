#include "string.hpp" 

template <typename T>
String<T>::String() : data(nullptr), length(0) {}

// Конструктор копіювання
template <typename T>
String<T>::String(const String& other) : length(other.length) {
    data = new T[length + 1]; // +1 для нульового символу
    std::memcpy(data, other.data, length * sizeof(T));
    data[length] = T(); // Нульовий символ
}

// Конструктор переміщення
template <typename T>
String<T>::String(String&& other) noexcept : data(other.data), length(other.length) {
    other.data = nullptr;
    other.length = 0;
}    

// Конструктор ініціалізації з масиву символів
template <typename T>
String<T>::String(const T* str) : length(std::strlen(str)) {
    try {
        data = new T[length + 1]; // +1 для нульового символу
        std::memcpy(data, str, length * sizeof(T));
        data[length] = T(); // Нульовий символ
    } catch (const std::bad_alloc& e) {
        // Handle the exception here, you can print an error message
        // or take any appropriate action
        std::cerr << "Error: Failed to allocate memory for String: " << e.what() << std::endl;
        // Re-throw the exception to indicate the failure
        throw;
    }
}

// Ініціалізація шляхом повторення символу заданої кількості разів
template <typename T>
String<T>::String(size_t count, T value) : length(count) {
    try {
        data = new T[length + 1]; // +1 для нульового символу
        for (size_t i = 0; i < length; ++i) {
            data[i] = value;
        }
        data[length] = T(); // Нульовий символ
    } catch (const std::bad_alloc& e) {
        // Handle the exception here, e.g., print an error message
        std::cerr << "Error: Failed to allocate memory for String: " << e.what() << std::endl;
        // Re-throw the exception to indicate the failure
        throw;
    }
}

// Метод для отримання довжини рядка
template <typename T>
size_t String<T>::getLength() const {
    return length;
}

// Перевірка, чи є рядок порожнім
template <typename T>
bool String<T>::isEmpty() const {
    return length == 0;
}

// Очищення рядка (робить його порожнім)
template <typename T>
void String<T>::clear() {
    delete[] data;
    data = nullptr;
    length = 0;
}

// Оператор отримання символу за індексом
template <typename T>
T String<T>::operator[](size_t index) const {
    return data[index];
}

// Оператор для отримання/запису символу за індексом
template <typename T>
T& String<T>::operator[](size_t index) {
    if (index < length) {
        return data[index];
    }
    // Додаємо нульові символи до вказаного індексу
    while (length <= index) {
        pushBack(T());
    }
    return data[index];
}

// Отримання підрядка
template <typename T>
String<T> String<T>::substr(size_t startIndex, size_t substringLength) const {
    try {
        if (startIndex >= length) {
            // Початковий індекс за межами рядка
            return String();
        }

        size_t actualLength = std::min(substringLength, length - startIndex);
        String result;
        result.data = new T[actualLength + 1]; // +1 для нульового символу
        result.length = actualLength;

        std::memcpy(result.data, data + startIndex, actualLength * sizeof(T));
        result.data[actualLength] = T(); // Нульовий символ

        return result;
    } catch (const std::bad_alloc& e) {
        // Handle the exception here, e.g., print an error message
        std::cerr << "Error: Failed to allocate memory for substring: " << e.what() << std::endl;
        // Re-throw the exception to indicate the failure
        throw;
    }
}


// Конкатенація рядків
template <typename T>
String<T> String<T>::operator+(const String& other) const {
    String result;
    result.length = length + other.length;
    result.data = new T[result.length + 1]; // +1 для нульового символу

    std::memcpy(result.data, data, length * sizeof(T));
    std::memcpy(result.data + length, other.data, other.length * sizeof(T));
    result.data[result.length] = T(); // Нульовий символ

    return result;
}

// Оператор множення рядка на ціле число (зліва)
template <typename T>
String<T> String<T>::operator*(int factor) const {
    if (factor <= 0) {
        return String(); // Повертає порожній рядок при множенні на 0 або менше
    }

    String result;
    result.length = length * factor;
    result.data = new T[result.length + 1]; // +1 для нульового символу

    for (int i = 0; i < factor; ++i) {
        std::memcpy(result.data + i * length, data, length * sizeof(T));
    }
    result.data[result.length] = T(); // Нульовий символ

    return result;
}

// Оператор присвоєння C-строки
template <typename T>
String<T>& String<T>::operator=(const T* cString) {
    // Assuming cString is a null-terminated string
    length = std::char_traits<T>::length(cString);
    delete[] data;
    data = new T[length + 1]; // +1 for the null character
    std::memcpy(data, cString, length * sizeof(T));
    data[length] = T(); // Null character
    return *this;
}

// Оператор присвоєння копіювання
template <typename T>
String<T>& String<T>::operator=(const String& other) {
    if (this != &other) {
        delete[] data;
        length = other.length;
        data = new T[length + 1]; // +1 для нульового символу
        std::memcpy(data, other.data, length * sizeof(T));
        data[length] = T(); // Нульовий символ
    }
    return *this;
}

// Оператор присвоєння переміщення
template <typename T>
String<T>& String<T>::operator=(String&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        length = other.length;
        other.data = nullptr;
        other.length = 0;
    }
    return *this;
}


// Оператор множення рядка на ціле число (справа)
template <typename T>
String<T> operator*(int factor, const String<T>& str) {
    return str * factor;
}

// Додавання одного символу до рядка (зліва)
template <typename T>
String<T>& operator+=(String<T>& str, T character) {
    str.pushFront(character);
    return str;
}
// Додавання одного символу до рядка (справа)
template <typename T>
String<T>& operator+=(String<T>& str, const String<T>& other) {
    str.pushBack(other);
    return str;
}

// Оператор порівняння рядків (рівність)
template <typename T>
bool operator==(const String<T>& lhs, const String<T>& rhs) {
    return (lhs.getLength() == rhs.getLength()) && (std::memcmp(lhs.data, rhs.data, lhs.getLength() * sizeof(T)) == 0);
}

// Оператор порівняння рядків (нерівність)
template <typename T>
bool operator!=(const String<T>& lhs, const String<T>& rhs) {
    return !(lhs == rhs);
}

// Оператор порівняння рядків за лексикографічним порядком (менше)
template <typename T>
bool operator<(const String<T>& lhs, const String<T>& rhs) {
    return std::lexicographical_compare(lhs.data, lhs.data + lhs.getLength(), rhs.data, rhs.data + rhs.getLength());
}

// Оператор порівняння рядків за лексикографічним порядком (більше)
template <typename T>
bool operator>(const String<T>& lhs, const String<T>& rhs) {
    return rhs < lhs;
}

// Оператор порівняння рядків за лексикографічним порядком (менше або рівне)
template <typename T>
bool operator<=(const String<T>& lhs, const String<T>& rhs) {
    return !(rhs < lhs);
}

// Оператор порівняння рядків за лексикографічним порядком (більше або рівне)
template <typename T>
bool operator>=(const String<T>& lhs, const String<T>& rhs) {
    return !(lhs < rhs);
}


// Здійснення трансформації на місці
template <typename T>
template <typename UnaryFunction>
void String<T>::transformInPlace(UnaryFunction&& func) {
    for (size_t i = 0; i < length; ++i) {
        data[i] = func(data[i]);
    }
}

// Трансформація рядка створенням нового рядка (динамічний поліморфізм)
template <typename T>
template <typename UnaryFunction>
String<T> String<T>::transformCopy(UnaryFunction&& func) const {
    try {
        String result(*this);
        result.transformInPlace(std::forward<UnaryFunction>(func));
        return result;
    } catch (const std::exception& e) {
        // Обробка виключення та виведення повідомлення про помилку
        std::cerr << "Error during transformation: " << e.what() << std::endl;
        // Викидаємо виключення назад
        throw;
    }
}

// Трансформація рядка створенням нового рядка (статичний поліморфізм)
template <typename T>
template <typename UnaryFunction>
String<T> String<T>::transformCopyStatic(UnaryFunction&& func) const {
    try {
        String result(*this);
        result.transformInPlaceStatic(std::forward<UnaryFunction>(func));
        return result;
    } catch (const std::exception& e) {
        // Handle the exception and provide meaningful information
        std::cerr << "Error during transformation: " << e.what() << std::endl;
        throw;
    } catch (...) {
        // Handle unexpected exceptions (not derived from std::exception)
        std::cerr << "Unknown error during transformation." << std::endl;
        throw;
    }
}


// Функція створення рядка відповідного типу із масиву символів
template <typename T>
template <typename U>
String<T> String<T>::createFromStringArray(U* begin, U* end) {
    size_t arrayLength = end - begin;
    String result;
    result.length = arrayLength;
    result.data = new T[result.length + 1]; // +1 для нульового символу
    std::memcpy(result.data, begin, arrayLength * sizeof(U));
    result.data[result.length] = T(); // Нульовий символ
    return result;
}

// Функція створення рядка відповідного типу із масиву символів (тільки початок)
template <typename T>
template <typename U>
String<T> String<T>::createFromStringArray(U* begin) {
    size_t arrayLength = std::strlen(begin);
    String result;
    result.length = arrayLength;
    result.data = new T[result.length + 1]; // +1 для нульового символу
    std::memcpy(result.data, begin, arrayLength * sizeof(U));
    result.data[result.length] = T(); // Нульовий символ
    return result;
}

// Застосування трансформації за допомогою функціонального об'єкту
template <typename T>
template <typename TransformerType>
void String<T>::apply(const TransformerType& transformer) {
    transformInPlace([&transformer](T& element) { return transformer(element); });
}

template <typename T>
std::istream& operator>>(std::istream& is, String<T>& str) {
    char buffer[256]; // Тимчасовий буфер для введення
    is.getline(buffer, 256);
    str = buffer;
    return is;
}

// Оператор виводу
template <typename T>
std::ostream& operator<<(std::ostream& os, const String<T>& str) {
    os << str.data;
    return os;
}

// Допоміжний метод для додавання символу в кінець рядка
template <typename T>
void String<T>::pushBack(T character) {
    try {
        T* newData = new T[length + 2]; // +2 для нового символу і нульового символу
        std::memcpy(newData, data, length * sizeof(T));
        newData[length] = character;
        newData[length + 1] = T(); // Нульовий символ
        delete[] data;
        data = newData;
        ++length;
    } catch (const std::bad_alloc& e) {
        // Обробка винятку при виникненні помилки виділення пам'яті
        std::cerr << "Error during pushBack: " << e.what() << std::endl;
        // Викидаємо виняток назад
        throw;
    }
}

// Допоміжний метод для додавання символів з іншого рядка в кінець
template <typename T>
void String<T>::pushBack(const String& other) {
    try {
        T* newData = new T[length + other.length + 1]; // +1 для нульового символу
        std::memcpy(newData, data, length * sizeof(T));
        std::memcpy(newData + length, other.data, other.length * sizeof(T));
        newData[length + other.length] = T(); // Нульовий символ
        delete[] data;
        data = newData;
        length += other.length;
    } catch (const std::bad_alloc& e) {
        // Обробка винятку при виникненні помилки виділення пам'яті
        std::cerr << "Error during pushBack: " << e.what() << std::endl;
        // Викидаємо виняток назад
        throw;
    }
}

// Допоміжний метод для додавання символу в початок рядка
template <typename T>
void String<T>::pushFront(T character) {
    try {
        T* newData = new T[length + 2]; // +2 для нового символу і нульового символу
        newData[0] = character;
        std::memcpy(newData + 1, data, length * sizeof(T));
        newData[length + 1] = T(); // Нульовий символ
        delete[] data;
        data = newData;
        length++;
    } catch (const std::bad_alloc& e) {
        // Обробка винятку при виникненні помилки виділення пам'яті
        std::cerr << "Error during pushFront: " << e.what() << std::endl;
        // Викидаємо виняток назад
        throw;
    }
}

// Деструктор
template <typename T>
String<T>::~String() {
    delete[] data;
}

