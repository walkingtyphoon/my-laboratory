//
// Created by walking typhoon on 24-9-20.
//

#include <iostream>
#include <vector>
#include <ranges>

int main1() {
    std::vector numbers = {1, 2, 3, 4, 5};

    auto evens = numbers | std::views::filter([](const int n) { return n % 2 == 0; });

    for (const int &n : evens) {
        std::cout << n << " ";  // 输出 2 4
    }

    return 0;
}
