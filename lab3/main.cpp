#include "classes.hpp"
#include <typeinfo>

int main() {
    // Create a matrix
    int intValues[2][2] = {{1, 2}, {3, 4}};
    Matrix<int, 2, 2> matrix(intValues);
    // Perform operations with scalar values
    Matrix<int, 2, 2> resultAddScalar = matrix + 5;
    Matrix<int, 2, 2> resultSubtractScalar = matrix - 2;

    // Display results
    std::cout << "Matrix:\n";
    matrix.show_matrix();

    std::cout << "\nAdd Scalar:\n";
    resultAddScalar.show_matrix();

    std::cout << "\nSubtract Scalar:\n";
    resultSubtractScalar.show_matrix();

    Matrix<int, 2, 2> intMatrix(intValues);

    Matrix<float, 2, 2> floatMatrix = intMatrix.change_type<float>();

    std::cout << floatMatrix.at(1,1) << std::endl;

    Matrix<int, 2, 2> sum = matrix + intMatrix;

    sum.show_matrix();

    (intMatrix - 5).show_matrix();
    (intMatrix * 5).show_matrix();
    (floatMatrix / 5).show_matrix();
    (intMatrix + 5).show_matrix();
    (floatMatrix - intMatrix.at(0,1)).show_matrix();

    Matrix<int, 6, 4> scaledMatrix = matrix.scale<3, 2>();
    scaledMatrix.show_matrix();

    std::cout<<std::endl;
    
    int intValues2[6][6] = {{1, 2, 3, 4, 5, 6}, {5, 6, 7, 8, 5, 6}, {9, 10, 11, 12, 5, 6}, {13, 14, 15, 16, 5, 6}, {1, 2, 3, 4, 5, 6}, {1, 2, 3, 4, 5, 6}};
    Matrix<int, 6, 6> matrix2(intValues2);
    matrix2.show_matrix();
    
    std::cout << std::endl;
    
    // Get a submatrix using negative coordinates
    matrix2.image<1, 0, 2, 3>().show_matrix(); 
    std::cout << std::endl;
    matrix2.image<-4, -3, -1, -1>().show_matrix();

    char charValues1[2][2] = {{'a', 'b'},{'c', 'd'}}; 
    Matrix<char, 2, 2> char_matrix1(charValues1);

    char charValues2[2][2] = {{'e', 'f'},{'g', 'h'}};
    Matrix<char, 2, 2> char_matrix2(charValues2);

    std::cout << std::endl;
    concatenate_horizontally(char_matrix1, char_matrix2).show_matrix();

    std::cout << std::endl;
    concatenate_vertically(char_matrix1, char_matrix2).show_matrix();

    float floatValues3[2][2] = {{5, 6}, {7, 8}};
    Matrix <float, 2, 2> floatMatrix2(floatValues3);
    std::cout << std::endl;
    concatenate_horizontally(floatMatrix2, matrix).show_matrix();
    std::cout << std::endl;
    concatenate_vertically(floatMatrix2, matrix).show_matrix();
    
    std::cout << std::endl; 
    floatMatrix2.scale<1, 3>().show_matrix();

    // // Display the original and submatrix
    // std::cout << "Original Matrix:\n";
    // matrix2.show_matrix();

    // std::cout << "\nSubmatrix:\n";
    // submatrix.show_matrix();

    return 0;

}
