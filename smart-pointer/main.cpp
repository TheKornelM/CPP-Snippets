#include <iostream>
#include <memory>

int main() {
    std::cout << "Hello, World!" << std::endl;
    std::unique_ptr<int> ptr (new int[5]);
    std::cout << ptr.get()[0] << std::endl;
    ptr.get()[0] = 10;
    std::cout << ptr.get()[0] << std::endl;
    std::cout << ptr.get()[5] << std::endl;
    return 0;
}
