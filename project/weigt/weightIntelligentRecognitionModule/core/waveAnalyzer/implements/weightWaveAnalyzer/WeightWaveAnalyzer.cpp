//
// Created by jiahan on 24-12-25.
//

#include "WeightWaveAnalyzer.hpp"

#include <limits>
#include <ranges>
#include <stdexcept>

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
        auto beforePeakIndex = peakIndexes.at(i);

        const auto afterPeakIndex = peakIndexes.at(i + 1);


        double min = std::numeric_limits<double>::max();


        while (beforePeakIndex < afterPeakIndex) {
            if (min > originalData.at(beforePeakIndex)) {
                min = originalData.at(beforePeakIndex);
            }

            beforePeakIndex++;
        }

        if (min != std::numeric_limits<double>::max()) {
            if (const auto valleyIndexIterator = std::ranges::find(originalData, min);
                valleyIndexIterator != originalData.end()) {
                const auto valleyIndex = std::distance(originalData.begin(), valleyIndexIterator);
                valleysData.push_back(static_cast<int>(valleyIndex));
            }
        }
    }

    const auto lastPeak = originalData.at(peakIndexes.back());

    const auto lastElement = originalData.at(peakIndexesSize);

    if (lastPeak != lastElement) {
        auto beforePeakIndex = peakIndexes.back();

        const auto afterPeakIndex = originalData.size();


        double min = std::numeric_limits<double>::max();


        while (beforePeakIndex != afterPeakIndex) {
            if (min > originalData.at(beforePeakIndex)) {
                min = originalData.at(beforePeakIndex);
            }
            beforePeakIndex++;
        }

        if (min != std::numeric_limits<double>::max()) {
            if (const auto valleyIndexIterator = std::ranges::find(originalData, min);
                valleyIndexIterator != originalData.end()) {
                const auto valleyIndex = std::distance(originalData.begin(), valleyIndexIterator);
                valleysData.push_back(static_cast<int>(valleyIndex));
            }
        }
    }

    if (not valleysData.empty()) {
        return valleysData;
    }

    return {};
}
