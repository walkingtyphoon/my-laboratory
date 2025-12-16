//
// Created by jiahan on 2025/10/29.
//

#include "AllWeightCycleExtractor.h"

#include <spdlog/spdlog.h>


AllWeightCycleExtractor::AllWeightCycleExtractor(const std::vector<double> &inputData, const std::vector<int> &peaks,
                                                 const std::vector<int> &valleys) : validCycleData(inputData),
                                                                                    peakIndexes(peaks),
                                                                                    valleyIndexes(valleys) {
}

auto AllWeightCycleExtractor::extractorCycles() -> std::vector<std::vector<double> > {

    const int peakTotal = static_cast<int>(peakIndexes.size());

    const int valleyTotal = static_cast<int>(valleyIndexes.size());

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


        if (valleyIndex > peakIndex) {
            spdlog::info("Peak index {}", peakIndex);
            spdlog::info("Valley index {}", valleyIndex);
            return {};
        }

    }

    return allCycleData;
}