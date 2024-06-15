// classes.cpp

template <typename TYPE, int ROWS, int COLUMNS>
Matrix<TYPE, ROWS, COLUMNS>::Matrix() {
    // Default constructor
    allocate_memory();
    fill_with_char(0); // Initializing with zero or any default value
}

template <typename TYPE, int ROWS, int COLUMNS>
Matrix<TYPE, ROWS, COLUMNS>::Matrix(const TYPE matrix[ROWS][COLUMNS]) {
    // Constructor to initialize with a 2D array
    allocate_memory();
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            _matrix[i][j] = matrix[i][j];
        }
    }
}

template <typename TYPE, int ROWS, int COLUMNS>
Matrix<TYPE, ROWS, COLUMNS>::Matrix(TYPE ch) {
    // Constructor to fill the matrix with a given character
    allocate_memory();
    fill_with_char(ch);
}

template <typename TYPE, int ROWS, int COLUMNS>
Matrix<TYPE, ROWS, COLUMNS>::Matrix(const Matrix& other) {
    // Constructor to copy another matrix
    allocate_memory();
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            _matrix[i][j] = other._matrix[i][j];
        }
    }
}

template <typename TYPE, int ROWS, int COLUMNS>
Matrix<TYPE, ROWS, COLUMNS>::~Matrix() {
    // Destructor to free dynamically allocated memory
    for (int i = 0; i < ROWS; ++i) {
        delete[] _matrix[i];
    }
    delete[] _matrix;
}

template <typename TYPE, int ROWS, int COLUMNS>
void Matrix<TYPE, ROWS, COLUMNS>::show_matrix() const {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            std::cout << _matrix[i][j] << " ";
        }
        std::cout << '\n';
    }
}

template <typename TYPE, int ROWS, int COLUMNS>
void Matrix<TYPE, ROWS, COLUMNS>::allocate_memory() {
    // Helper method to allocate memory for the matrix
    _matrix = new TYPE*[ROWS];
    for (int i = 0; i < ROWS; ++i) {
        _matrix[i] = new TYPE[COLUMNS];
    }
}

template <typename TYPE, int ROWS, int COLUMNS>
void Matrix<TYPE, ROWS, COLUMNS>::fill_with_char(TYPE ch) {
    // Helper method to fill the matrix with a given character
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            _matrix[i][j] = ch;
        }
    }
}

template <typename TYPE, int ROWS, int COLUMNS>
template <typename NEW_TYPE>
void Matrix<TYPE, ROWS, COLUMNS>::change_data(const NEW_TYPE newData[ROWS][COLUMNS]) {
    // Check if the sizes match before updating
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            _matrix[i][j] = static_cast<TYPE>(newData[i][j]);
        }
    }
}

template <typename TYPE, int ROWS, int COLUMNS>
TYPE& Matrix<TYPE, ROWS, COLUMNS>::at(int row, int col) {
    row = (row < 0) ? ROWS + row : row;
    col = (col < 0) ? COLUMNS + col : col;

    if (row < 0 || row >= ROWS || col < 0 || col >= COLUMNS) {
        throw std::out_of_range("Matrix index out of bounds");
    }

    return _matrix[row][col];
}

template <typename TYPE, int ROWS, int COLUMNS>
const TYPE& Matrix<TYPE, ROWS, COLUMNS>::at(int row, int col) const {
    row = (row < 0) ? ROWS + row : row;
    col = (col < 0) ? COLUMNS + col : col;

    if (row < 0 || row >= ROWS || col < 0 || col >= COLUMNS) {
        throw std::out_of_range("Matrix index out of bounds");
    }

    return _matrix[row][col];
}

template <typename TYPE, int ROWS, int COLUMNS>
std::pair<int, int> Matrix<TYPE, ROWS, COLUMNS>::resolution() const {
    // Method to get the resolution (number of rows and columns) of the matrix
    return std::make_pair(ROWS, COLUMNS);
}

template <typename TYPE, int ROWS, int COLUMNS>
template <typename NEW_TYPE>
Matrix<NEW_TYPE, ROWS, COLUMNS> Matrix<TYPE, ROWS, COLUMNS>::change_type() const {
    Matrix<NEW_TYPE, ROWS, COLUMNS> result;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            result.at(i, j) = static_cast<NEW_TYPE>(_matrix[i][j]);
        }
    }
    return result;
}

// Overloaded operators

template <typename TYPE, int ROWS, int COLUMNS>
Matrix<TYPE, ROWS, COLUMNS> Matrix<TYPE, ROWS, COLUMNS>::operator+(const TYPE scalar) const {
    Matrix result;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            result._matrix[i][j] = _matrix[i][j] + scalar;
        }
    }
    return result;
}

template <typename TYPE, int ROWS, int COLUMNS>
Matrix<TYPE, ROWS, COLUMNS> Matrix<TYPE, ROWS, COLUMNS>::operator-(const TYPE scalar) const {
    Matrix result;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            result._matrix[i][j] = _matrix[i][j] - scalar;
        }
    }
    return result;
}

template <typename TYPE, int ROWS, int COLUMNS>
Matrix<TYPE, ROWS, COLUMNS> Matrix<TYPE, ROWS, COLUMNS>::operator+(const Matrix& other) const {
    Matrix result;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            result._matrix[i][j] = _matrix[i][j] + other._matrix[i][j];
        }
    }
    return result;
}

template <typename TYPE, int ROWS, int COLUMNS>
Matrix<TYPE, ROWS, COLUMNS> Matrix<TYPE, ROWS, COLUMNS>::operator-(const Matrix& other) const {
    Matrix result;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            result._matrix[i][j] = _matrix[i][j] - other._matrix[i][j];
        }
    }
    return result;
}

template <typename TYPE, int ROWS, int COLUMNS>
Matrix<TYPE, ROWS, COLUMNS> Matrix<TYPE, ROWS, COLUMNS>::operator*(const TYPE scalar) const {
    Matrix result;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            result._matrix[i][j] = _matrix[i][j] * scalar;
        }
    }
    return result;
}

template <typename TYPE, int ROWS, int COLUMNS>
Matrix<TYPE, ROWS, COLUMNS> Matrix<TYPE, ROWS, COLUMNS>::operator/(const TYPE scalar) const {
    if (scalar == 0) {
        throw std::invalid_argument("Division by zero");
    }

    Matrix result;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            result._matrix[i][j] = _matrix[i][j] / scalar;
        }
    }
    return result;
}

template <typename TYPE, int ROWS, int COLUMNS>
Matrix<TYPE, ROWS, COLUMNS> Matrix<TYPE, ROWS, COLUMNS>::operator*(const Matrix& other) const {
    Matrix result;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            result._matrix[i][j] = _matrix[i][j] * other._matrix[i][j];
        }
    }
    return result;
}

template <typename TYPE, int ROWS, int COLUMNS>
Matrix<TYPE, ROWS, COLUMNS> Matrix<TYPE, ROWS, COLUMNS>::operator/(const Matrix& other) const {
    Matrix result;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            if (other._matrix[i][j] == 0) {
                throw std::invalid_argument("Division by zero");
            }
            result._matrix[i][j] = _matrix[i][j] / other._matrix[i][j];
        }
    }
    return result;
}

// Template method to scale the matrix
template <typename TYPE, int ROWS, int COLUMNS>
template <int SCALE_ROWS, int SCALE_COLUMNS>
Matrix<TYPE, ROWS * SCALE_ROWS, COLUMNS * SCALE_COLUMNS> Matrix<TYPE, ROWS, COLUMNS>::scale() const {
    Matrix<TYPE, ROWS * SCALE_ROWS, COLUMNS * SCALE_COLUMNS> result;

    for (int i = 0; i < ROWS * SCALE_ROWS; ++i) {
        for (int j = 0; j < COLUMNS * SCALE_COLUMNS; ++j) {
            result.at(i, j) = _matrix[i / SCALE_ROWS][j / SCALE_COLUMNS];
        }
    }

    return result;
}

// Function to horizontally mirror a matrix
template <typename TYPE, int ROWS, int COLUMNS>
Matrix<TYPE, ROWS, COLUMNS> Matrix<TYPE, ROWS, COLUMNS>::horizontal_mirror() const {
    Matrix<TYPE, ROWS, COLUMNS> result;

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            result.at(i, j) = _matrix[i][COLUMNS - 1 - j];
        }
    }

    return result;
}

// Function to vertically mirror a matrix
template <typename TYPE, int ROWS, int COLUMNS>
Matrix<TYPE, ROWS, COLUMNS> Matrix<TYPE, ROWS, COLUMNS>::vertical_mirror() const {
    Matrix<TYPE, ROWS, COLUMNS> result;

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            result.at(i, j) = _matrix[ROWS - 1 - i][j];
        }
    }

    return result;
}

// Assuming that _matrix is a TYPE** pointer to a 2D array
template <typename TYPE, int ROWS, int COLUMNS>
Matrix<TYPE, ROWS, COLUMNS> Matrix<TYPE, ROWS, COLUMNS>::copy_matrix() const {
    // Allocate memory for a new matrix
    Matrix<TYPE, ROWS, COLUMNS> matrix_copy;

    // Copy the elements from _matrix to matrix_copy
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLUMNS; ++j) {
            matrix_copy.at(i, j) = _matrix[i][j];
        }
    }

    return matrix_copy;
}


// Template method to get a part of the matrix
template <typename TYPE, int ROWS, int COLUMNS>
template <int topLeftRow, int topLeftCol, int bottomRightRow, int bottomRightCol>
Matrix<TYPE, bottomRightRow - topLeftRow + 1, bottomRightCol - topLeftCol + 1> Matrix<TYPE, ROWS, COLUMNS>::image() const {
    
    Matrix<TYPE, bottomRightRow - topLeftRow + 1, bottomRightCol - topLeftCol + 1> result;
    Matrix<TYPE, ROWS, COLUMNS> mirrored_matrix = this -> copy_matrix();
    bool mirror = false;

    int pos_topLeftRow;

    if (topLeftRow < 0) {pos_topLeftRow = topLeftRow + ROWS;} 
    else {pos_topLeftRow = topLeftRow;}

    int pos_topLeftCol;

    if (topLeftCol < 0) {pos_topLeftCol = topLeftCol + COLUMNS;}
    else {pos_topLeftCol = topLeftCol;}

    int pos_bottomRightRow;

    if (bottomRightRow < 0) {pos_bottomRightRow = bottomRightRow + ROWS;}
    else {pos_bottomRightRow = bottomRightRow;}

    int pos_bottomRightCol;

    if (bottomRightCol < 0) {pos_bottomRightCol = bottomRightCol + COLUMNS;}
    else {pos_bottomRightCol = bottomRightCol;}

    if (pos_topLeftCol > pos_bottomRightCol){
        mirrored_matrix = mirrored_matrix.vertical_mirror();
    } 

    if (pos_topLeftRow > pos_bottomRightRow){
        mirrored_matrix = mirrored_matrix.horizontal_mirror();
    }

    // Assuming that the Matrix class has a method to access individual elements, like `at(row, col)`
    for (int i = 0; i <= pos_bottomRightRow - pos_topLeftRow; ++i) {
        for (int j = 0; j <= pos_bottomRightCol - pos_topLeftCol; ++j) {
            result.at(i, j) = mirrored_matrix.at(pos_topLeftRow + i, pos_topLeftCol + j);
        }
    }

    return result;
}

template <typename TYPE1, typename TYPE2, int ROWS1, int COLUMNS1, int ROWS2, int COLUMNS2>
Matrix<TYPE1, ROWS1 + ROWS2, COLUMNS1> concatenate_horizontally(const Matrix<TYPE1, ROWS1, COLUMNS1>& mat1, const Matrix<TYPE2, ROWS2, COLUMNS2>& mat2) {
    static_assert(COLUMNS1 == COLUMNS2, "Matrix columns must be equal for horizontal concatenation");

    Matrix<TYPE1, ROWS1 + ROWS2, COLUMNS1> result;

    for (int i = 0; i < ROWS1; ++i) {
        for (int j = 0; j < COLUMNS1; ++j) {
            result.at(i, j) = mat1.at(i, j);
        }
    }

    for (int i = 0; i < ROWS2; ++i) {
        for (int j = 0; j < COLUMNS2; ++j) {
            result.at(i + ROWS1, j) = static_cast<TYPE1>(mat2.at(i, j));
        }
    }

    return result;
}

template <typename TYPE1, typename TYPE2, int ROWS1, int COLUMNS1, int ROWS2, int COLUMNS2>
Matrix<TYPE1, ROWS1, COLUMNS1 + COLUMNS2> concatenate_vertically(const Matrix<TYPE1, ROWS1, COLUMNS1>& mat1, const Matrix<TYPE2, ROWS2, COLUMNS2>& mat2) {
    static_assert(ROWS1 == ROWS2, "Matrix rows must be equal for vertical concatenation");

    Matrix<TYPE1, ROWS1, COLUMNS1 + COLUMNS2> result;

    for (int i = 0; i < ROWS1; ++i) {
        for (int j = 0; j < COLUMNS1; ++j) {
            result.at(i, j) = mat1.at(i, j);
        }

        for (int j = 0; j < COLUMNS2; ++j) {
            result.at(i, j + COLUMNS1) = static_cast<TYPE1>(mat2.at(i, j));
        }
    }

    return result;
}
