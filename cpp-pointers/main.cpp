#include <iostream>
#include <array>


int main() {
    std::cout << "Hello, World!" << std::endl;
    int a = 10;
    std::cout << &a << std::endl;
    int *ptr = &a;
    std::cout << ptr << std::endl;
    int b = 20;
    ptr = &b;
    std::cout << ptr << std::endl;

    /*std::array<int,5> arr {1,2,3,4,5};
    std::cout << "Array length:" << arr.size() << std::endl;
    std::cout << &arr[0] << std::endl;
    std::cout << &arr[1] << std::endl;*/

    std::cout << "Matrix:" << std::endl;
    // loop
    int **matrix;
    std::cout << "Matrix pointer az allokalas elott: " << matrix << std::endl;
    matrix = new int*[10];
    std::cout << "Matrix pointer memoria cime: " << matrix << std::endl;
    std::cout << "Matrix pointerben tarolt cim " << *matrix << std::endl;
    //std::cout << "Feltoltes elott:" << std::endl;
    //std::cout << matrix[1] << std::endl;
    //std::cout << matrix[2] << std::endl;

    #define MATRIX_LENGTH 3

    std::cout << "NULL-ra allitas utan:" << std::endl;
    for(int i = 0; i < MATRIX_LENGTH; i++) {
        std::cout << "matrix[" << i << "]:" << std::endl;
        std::cout << "NULL-ra allitas elott: "<< matrix[i] << std::endl;
        matrix[i] = nullptr;
        std::cout << "NULL-ra allitas utan: "<< matrix[i] << std::endl;
        matrix[i] = new int[MATRIX_LENGTH];
        std::cout << "Memoria allokalas utan: " << matrix[i] << std::endl;
        for(int j = 0; j < MATRIX_LENGTH; j++) {
            std::cout << "matrix[" << i << "][" << j << "] memoriacime: " << &matrix[i][j] << std::endl;
        }
    }
    std::cout << "Matrix pointerben tarolt cim az allokalas utan: " << *matrix << std::endl;

    delete matrix;

    return 0;
}
