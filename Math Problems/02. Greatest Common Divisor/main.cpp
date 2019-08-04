#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

unsigned int greatestCommonDivisor(unsigned int leftNum, unsigned int rightNum) {
    while (leftNum && rightNum) {
        leftNum %= rightNum;
        std::swap(leftNum, rightNum);
    }
    return leftNum + rightNum;
}

int main() {
    unsigned int leftNumber, rightNumber;
    std::cin >> leftNumber >> rightNumber;

    std::cout << greatestCommonDivisor(leftNumber, rightNumber);

    return 0;
}
