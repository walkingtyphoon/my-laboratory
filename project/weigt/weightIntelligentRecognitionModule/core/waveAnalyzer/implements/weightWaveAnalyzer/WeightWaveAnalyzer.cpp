//
// Created by jiahan on 24-12-25.
//


#include "WeightWaveAnalyzer.hpp"

#include <limits>
#include <ranges>
#include <stdexcept>
#include <bits/ranges_algobase.h>

void WeightWaveAnalyzer::setInputData(const std::vector<double> &inputData) {
    originalData.resize(inputData.size());
    std::ranges::copy(inputData, originalData.begin());
}

auto WeightWaveAnalyzer::findAllPeaks() -> std::vector<int> {
    if (originalData.size() <= 1) {
        throw std::invalid_argument("输入的数据为空，请检查数据输入。");
    }

    auto filtered = std::views::iota(1, static_cast<int>(originalData.size() - 1))
                    | std::views::filter([this](const int i) {
                        const auto less = originalData.at(i) > originalData.at(i - 1);

                        const auto greater = originalData.at(i) > originalData.at(i + 1);

                        return less and greater;
                    });

    return {filtered.begin(), filtered.end()};
}

auto WeightWaveAnalyzer::findAllValleys(const std::vector<int> &peakIndexes) -> std::vector<int> {
    const auto peakIndexesSize = peakIndexes.size();

    if (peakIndexes.empty() or peakIndexes.size() == 1) {
        throw std::invalid_argument("波峰的索引数据为空或者不规范");
    }

    if (originalData.empty() or originalData.size() == 2) {
        throw std::invalid_argument("周期数据为空或者数据量不足");
    }

    std::vector<int> valleysData;

    for (int i = 0; i < peakIndexesSize - 1; ++i) {
        const auto beforePeakIndex = peakIndexes.at(i);
        const auto afterPeakIndex = peakIndexes.at(i + 1);

        double min = std::numeric_limits<double>::max();
        int minIndex = beforePeakIndex;

        // 仅在当前两峰之间搜索波谷
        for (auto idx = beforePeakIndex; idx < afterPeakIndex; ++idx) {
            const auto value = originalData.at(idx);
            if (value < min) {
                min = value;
                minIndex = static_cast<int>(idx);
            }
        }

        if (min != std::numeric_limits<double>::max()) {
            valleysData.push_back(minIndex);
        }
    }

    const auto lastPeakIndex = peakIndexes.back();
    // 若末尾还有下降趋势，则在最后一个波峰到序列末尾寻找波谷
    if (lastPeakIndex < static_cast<int>(originalData.size() - 1)) {
        double min = std::numeric_limits<double>::max();
        int minIndex = lastPeakIndex;

        for (auto idx = lastPeakIndex; idx < static_cast<int>(originalData.size()); ++idx) {
            const auto value = originalData.at(idx);
            if (value < min) {
                min = value;
                minIndex = static_cast<int>(idx);
            }
        }

        if (min != std::numeric_limits<double>::max()) {
            valleysData.push_back(minIndex);
        }
    }

    if (not valleysData.empty()) {
        return valleysData;
    }

    return {};
}
