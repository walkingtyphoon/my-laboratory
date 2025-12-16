//
// Created by jiahan on 24-12-25.
//

#include "WeightDataProcessor.hpp"

#include <ranges>
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <fstream>

auto WeightDataProcessor::setOriginalData(const std::vector<double> &data) -> void {
    originalData.resize(data.size());
    std::ranges::copy(data, originalData.begin());
}

auto WeightDataProcessor::removeDuplicates() -> void {
    auto uniqueData = std::ranges::unique(originalData);

    originalData.erase(uniqueData.begin(), uniqueData.end());
}

//auto WeightDataProcessor::filterValidCycle(double threshold) -> std::vector<double> {
//    if (originalData.empty()) {
//        throw std::invalid_argument("WeightDataProcessor::filterValidCycle: empty data");
//    }
//
//    auto filteredData = originalData | std::ranges::views::filter([threshold](const auto &weight) {
//        return weight >= threshold;
//    });
//
//    return {filteredData.begin(), filteredData.end()};
//}
auto  WeightDataProcessor::filterValidCycle(double threshold) -> std::vector<double>{
    if (originalData.empty()) {
        throw std::invalid_argument("empty data");
    }

    size_t n = originalData.size();
    size_t startIdx = 0;
    size_t endIdx = n - 1;
    const int minConsecutive = 5;


    for (size_t i = 0; i <= n - minConsecutive; ++i) {
        bool valid = true;
        for (int j = 0; j < minConsecutive; ++j) {
            if (originalData[i + j] <= threshold) {
                valid = false;
                break;
            }
        }
        if (valid) {
            startIdx = i;
            break;
        }
    }

    // 找最后一个超过 threshold 的点
    for (size_t i = n - 1; i > startIdx; --i) {
        if (originalData[i] > threshold) {
            endIdx = i;
            break;
        }
    }

    // 校验
    if (startIdx >= endIdx || endIdx >= n) {
        throw std::invalid_argument("no valid wave range found");
    }

    auto result = std::vector(originalData.begin() + startIdx, originalData.begin() + endIdx + 1);

    return result;
}
