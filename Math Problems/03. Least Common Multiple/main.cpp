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

unsigned long long int leastCommonMulptiple(unsigned int leftNum, unsigned int rightNum) {
    return (long long)leftNum * (long long)rightNum / greatestCommonDivisor(leftNum, rightNum);
}

unsigned long long int leastCommonMulptiple(const std::vector<unsigned int>& numbers) {
    unsigned long long int result = 1;
    for (auto number : numbers) {
        result = leastCommonMulptiple(result, number);

    }
    return result;
}

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& array) {
    for (auto& arrayItem : array) {
        is >> arrayItem;
    }
    return is;
}

int main() {
    size_t numbersSize = 0;
    std::cin >> numbersSize;

    const std::vector<unsigned int> numbers = [numbersSize] {
        std::vector<unsigned int> result(numbersSize);
        std::cin >> result;
        return result;
    }();

    std::cout << leastCommonMulptiple(numbers);
    return 0;
}
