#include "matrix.hpp"
#include <iostream>
int main() {
    dsa::Matrix m1 =dsa::Matrix(4,3);
    dsa::Matrix m2 =dsa::Matrix(4,3);
    m1(0,0)=5;
    m2(0,0)=3;
    dsa::Matrix m3 = m1+m2;
    std::cout << m3(0,0);
    return 0;
}