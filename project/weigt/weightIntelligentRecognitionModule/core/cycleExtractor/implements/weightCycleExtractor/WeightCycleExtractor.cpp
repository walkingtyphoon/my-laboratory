//
// Created by jiahan on 24-12-25.
//

#include "WeightCycleExtractor.hpp"

#include <spdlog/spdlog.h>
#include <iostream>

WeightCycleExtractor::WeightCycleExtractor(const std::vector<double> &inputData, const std::vector<int> &peaks,
                                           const std::vector<int> &valleys) : validCycleData(inputData),
                                                                              peakIndexes(peaks),
                                                                              valleyIndexes(valleys) {
}

auto WeightCycleExtractor::extractorCycles() -> std::vector<std::vector<double> > {
    const int peakTotal = static_cast<int>(peakIndexes.size());

    const int valleyTotal = static_cast<int>(valleyIndexes.size());

    if (valleyTotal == 0) {
        spdlog::warn("未找到波谷，跳过周期提取");
        return {};
    }

    std::vector<std::vector<double> > allCycleData;

    std::vector<double> currentCycle;


    int valleyElementIndex{0};

    for (int i = 0; i < peakTotal; ++i) {

        const auto peakIndex = peakIndexes.at(i);

        const auto peak = validCycleData.at(peakIndex);


        const auto valleyIndex = valleyIndexes.at(valleyElementIndex);

        const auto valley = validCycleData.at(valleyIndex);


        currentCycle.push_back(peak);

        currentCycle.push_back(valley);

        if (peak - valley > peak * 1.0 / 2.0) {

            allCycleData.push_back(currentCycle);

            currentCycle.clear();
        }


        if (valleyElementIndex != valleyTotal - 1) {
            valleyElementIndex++;
        } else {
            spdlog::warn("波谷数据已用完");
            spdlog::info("已达到末尾");
            break;
        }

    }

    return allCycleData;
}
