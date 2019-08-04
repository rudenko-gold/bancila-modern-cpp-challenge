#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

std::vector<int> fillFromOneTo(int upperBound) {
    std::vector<int> result(upperBound);
    for (size_t i = 0; i < result.size(); ++i) {
        result[i] = i + 1;
    }
    return result;
}

int main() {
    size_t upperBound;
    std::cin >> upperBound;
    std::vector<int> numbers = fillFromOneTo(upperBound);

    auto rangeEnd = std::partition(numbers.begin(), numbers.end(), [](int value) {
        return (value % 5 == 0) || (value % 3 == 0);
    });

    std::cout << std::accumulate(numbers.begin(), rangeEnd, 0);

    return 0;
}
