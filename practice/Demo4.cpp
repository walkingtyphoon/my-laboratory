//
// Created by walking typhoon on 24-9-28.
//
#include <iostream>
#include <vector>
#include <tuple>
#include <numeric>
#include <algorithm>
#include <optional>
#include <spdlog/spdlog.h>

std::optional<std::tuple<int, int, double>> minMaxAvg(const std::vector<int>& numbers) {
    if (numbers.empty()) {
        return std::nullopt;
    }

    const auto min = std::ranges::min_element(numbers);
    const auto max = std::ranges::max_element(numbers);
    const auto avg = std::accumulate(numbers.begin(), numbers.end(), 0.0) / static_cast<double>(numbers.size());

    return std::make_tuple(*min, *max, avg);
}

int main4() {
    const std::vector nums = {1, 2, 3, 4, 5, 6, 7};

    // 使用结构化绑定

    if (auto result = minMaxAvg(nums)) {
        auto [minValue, maxValue, avgValue] = *result;

        spdlog::info("Minimum value is {}", minValue);

        spdlog::info("Maximum value is {}", maxValue);

        spdlog::info("Average value is {:.2f}", avgValue);
    }
    else {
        spdlog::warn("Failed to find min and max values");
    }

    return 0;
}
