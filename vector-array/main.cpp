#include <iostream>
#include <memory>
#include <vector>

#define MATRIX_HEIGHT 5
#define MATRIX_WIDTH 10

template <typename T>
void showMatrix(std::vector<std::vector<T>> matrix) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            std::cout << matrix[i][j] << '\t';
        }
        std::cout << std::endl;
    }
}

template <typename T>
std::vector<std::vector<T>> fillMatrix(std::vector<std::vector<T>> matrix, T data) {
    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {
            matrix[i][j] = data;
        }
    }
    return matrix;
}

template <typename T>
void fillMatrixByReference(std::shared_ptr<std::vector<std::vector<T>>> matrixPointer, T data) {
    auto &matrix = *matrixPointer;
    /*for (int i = 0; i < matrixPointer.operator*().size(); i++) {
        for (int j = 0; j < matrixPointer.operator*()[i].size(); j++) {
           matrixPointer.operator*()[i][j] = data;
        }
    }*/

    // Better code
    for (auto &row : matrix) {
        for (auto &elem : row) {
            elem = data;
        }
        std::cout << std::endl;
    }
}

template <typename T>
void showMatrixByReference(std::shared_ptr<std::vector<std::vector<T>>> matrixPointer) {
    auto &matrix = *matrixPointer;

    /*
    for (int i = 0; i < matrixPointer.operator*().size(); i++) {
        for (int j = 0; j < matrixPointer.operator*()[i].size(); j++) {
            std::cout << matrixPointer.operator*()[i][j] << '\t';
        }
        std::cout << std::endl;
    }
    */

    // Better code
    for (auto &row : matrix) {
        for (auto &elem : row) {
            std::cout << elem << '\t';
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector matrix(MATRIX_HEIGHT, std::vector<int>(MATRIX_WIDTH));
    std::cout << "Hello, World!" << std::endl;
    showMatrix(matrix);
    matrix = fillMatrix(matrix, 5);
    std::cout << "After fill with data:" << std::endl;
    showMatrix(matrix);
    // By reference pass
    auto passedPointer = std::make_shared<std::vector<std::vector<int> > >(matrix);
    std::cout << "Show by reference before value assignment:" << std::endl;
    showMatrixByReference(passedPointer);
    fillMatrixByReference(passedPointer, 10);
    std::cout << "Show by reference after value assignment:" << std::endl;
    showMatrixByReference(passedPointer);
    return 0;
}
