// classes.hpp

#ifndef CLASSES_HPP
#define CLASSES_HPP

#include <iostream>

template <typename TYPE, int ROWS, int COLUMNS>
class Matrix {
private:
    TYPE** _matrix; // Pointer to a dynamic 2D array

public:
    // Default constructor
    Matrix();

    // Constructor to initialize with a 2D array
    Matrix(const TYPE matrix[ROWS][COLUMNS]);

    // Constructor to fill the matrix with a given character
    Matrix(TYPE ch);

    // Constructor to copy another matrix
    Matrix(const Matrix& other);

    // Destructor to free dynamically allocated memory
    ~Matrix();

    void show_matrix() const;

    template <typename NEW_TYPE>
    void change_data(const NEW_TYPE newData[ROWS][COLUMNS]);

    template <typename NEW_TYPE>
    Matrix<NEW_TYPE, ROWS, COLUMNS> change_type() const;

    // Access matrix element using coordinates
    TYPE& at(int row, int col);

    // Overloaded const version for const objects
    const TYPE& at(int row, int col) const;

    std::pair<int, int> resolution() const;

    // Helper method to fill the matrix with a given character
    void fill_with_char(TYPE ch);

    // Overloaded operators
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;

    Matrix operator+(const TYPE scalar) const;
    Matrix operator-(const TYPE scalar) const;
   
    Matrix operator*(const Matrix& other) const;
    Matrix operator/(const Matrix& other) const;

    Matrix operator*(const TYPE scalar) const;
    Matrix operator/(const TYPE scalar) const;
    
    // Template method to scale the matrix
    template <int SCALE_ROWS, int SCALE_COLUMNS>
    Matrix<TYPE, ROWS * SCALE_ROWS, COLUMNS * SCALE_COLUMNS> scale() const;

    Matrix<TYPE, ROWS, COLUMNS> copy_matrix() const;

    Matrix horizontal_mirror() const;

    // Function to vertically mirror a matrix
    Matrix vertical_mirror() const;

    // Template method to get a part of the matrix
    template <int topLeftRow, int topLeftCol, int bottomRightRow, int bottomRightCol>
    Matrix<TYPE, bottomRightRow - topLeftRow + 1, bottomRightCol - topLeftCol + 1> image() const;

private:
    // Helper method to allocate memory for the matrix
    void allocate_memory();
};

// Horizontal concatenation of two matrices
    template <typename TYPE1, typename TYPE2, int ROWS1, int COLUMNS1, int ROWS2, int COLUMNS2>
    Matrix<TYPE1, ROWS1 + ROWS2, COLUMNS1> concatenate_horizontally(const Matrix<TYPE1, ROWS1, COLUMNS1>& mat1, const Matrix<TYPE2, ROWS2, COLUMNS2>& mat2);

    template <typename TYPE1, typename TYPE2, int ROWS1, int COLUMNS1, int ROWS2, int COLUMNS2>
    Matrix<TYPE1, ROWS1, COLUMNS1 + COLUMNS2> concatenate_vertically(const Matrix<TYPE1, ROWS1, COLUMNS1>& mat1, const Matrix<TYPE2, ROWS2, COLUMNS2>& mat2);

#include "classes.cpp"

#endif
