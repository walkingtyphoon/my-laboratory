//
// Created by jiahan on 24-12-25.
//

#include "WeightDataProcessor.hpp"

#include <ranges>
#include <stdexcept>
#include <algorithm>

auto WeightDataProcessor::setOriginalData(const std::vector<double> &data) -> void {
    originalData.resize(data.size());
    std::ranges::copy(data, originalData.begin());
}

auto WeightDataProcessor::removeDuplicates() -> void {
    auto uniqueData = std::ranges::unique(originalData);

    originalData.erase(uniqueData.begin(), uniqueData.end());
}

auto WeightDataProcessor::filterValidCycle(double threshold) -> std::vector<double> {
    if (originalData.empty()) {
        throw std::invalid_argument("WeightDataProcessor::filterValidCycle: empty data");
    }

    auto filteredData = originalData | std::ranges::views::filter([threshold](const auto &weight) {
        return weight >= threshold;
    });

    return {filteredData.begin(), filteredData.end()};
}
