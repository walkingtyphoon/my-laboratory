#include <iostream>
#include <optional>
#include <ranges>

#include <spdlog/spdlog.h>
//
// Created by walking typhoon on 24-9-26.
//


auto findFirstEven(const std::vector<int>& numbers) -> std::optional<int> {
    auto firstEven = std::ranges::views::filter(numbers, [](const int number) {
        return number % 2 == 0;
    });

    auto iterator = firstEven.begin();

    if (iterator != firstEven.end()) {
        return *iterator;
    }

    return std::nullopt;
}


int main2(int argc, char* argv[]) {
    std::vector<int> nums = {1, 3, 5, 7, 4, 9};
    auto result = findFirstEven(nums);

    if (result) {
        std::cout << "First even number is: " << result.value() << std::endl;
    }
    else {
        std::cout << "No even number found" << std::endl;
    }
}
