#include "string.hpp"

int main() {
    String<char> str1("Hello");   // Рядок із масиву символів
    String<char> str2;

    // Занесення даних через присвоєння
    str2 = "World";

    std::cout << "str1: " << str1 << std::endl;  // Виводить "Hello"
    std::cout << "str2: " << str2 << std::endl;  // Виводить "World"

    std::cout << "Is str1 empty? " << (str1.isEmpty() ? "Yes" : "No") << std::endl;
    std::cout << "Is str2 empty? " << (str2.isEmpty() ? "Yes" : "No") << std::endl;

    str1 = str2; // Оператор присвоєння копіювання
    std::cout << "str1: " << str1.getLength() << " characters" << std::endl;

    str2.clear(); // Очищення рядка
    std::cout << "Is str2 empty after clear? " << (str2.isEmpty() ? "Yes" : "No") << std::endl; // Yes

    String<char> str = "abc";

    // Трансформація рядка на місці
    str.transformInPlace([](char& c) { return std::toupper(c); });
    std::cout << "Transformed in place: " << str << std::endl; // "ABC"

    // Трансформація рядка створенням нового рядка
    String<char> transformedCopy = str.transformCopy([](char c) { return std::tolower(c); });
    std::cout << "Transformed copy: " << transformedCopy << std::endl; // "abc"

    // Функція створення рядка відповідного типу із масиву символів
    char array[] = "Hello";
    String<char> newStr = String<char>::createFromStringArray(array, array + std::strlen(array));
    std::cout << "Created from array: " << newStr << std::endl; // "Hello"

    // Test the String class and the substr method
    String<char> originalString("Hello, World!");
    std::cout << "Original String: " << originalString << std::endl;

    // Test substr method
    size_t startIndex = 7;
    size_t substringLength = 5;
    String<char> substring = originalString.substr(startIndex, substringLength);
    
    std::cout << "Substring: " << substring << std::endl;

    // Введення рядка з клавіатури
    String<char> userInput;
    std::cout << "Enter a string: ";
    std::cin >> userInput;
    std::cout << "You entered: " << userInput << std::endl;

    userInput = userInput * 0;
    std::cout << "userInput after *0: " << userInput << std::endl;

    return 0;
}