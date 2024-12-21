#include <algorithm>
#include <fstream>
#include <iostream>
#include <numeric>
#include <ranges>
#include <vector>
#include <spdlog/spdlog.h>

std::vector<float> readLogData(const std::string &filePath) {
    std::vector<float> data;
    std::ifstream inputFile(filePath);

    if (!inputFile.is_open()) {
        std::cerr << "无法打开文件: " << filePath << std::endl;
        return data;
    }

    float value;
    while (inputFile >> value) {
        data.push_back(value);
    }

    spdlog::info("original Data size is {}", data.size());

    inputFile.close();
    return data;
}

auto removeDuplicates(std::vector<float> &data) {
    auto newRange = std::ranges::unique(data);

    data.erase(newRange.begin(), newRange.end());
}

auto findAllCycle(const std::vector<float> &data) -> std::vector<float> {
    if (data.empty()) return {};

    auto filtered = data
                    | std::ranges::views::filter([](const auto &weight) {
                        return weight >= 0.1;
                    });

    return {filtered.begin(), filtered.end()};
}

auto findAllPeaks(const std::vector<float> &data) -> std::vector<int> {
    if (data.size() <= 1) {
        return {};
    }

    auto filtered = std::views::iota(1, static_cast<int>(data.size() - 1))
                    | std::views::filter([=](const int i) {
                        return data[i] > data[i - 1] && data[i] > data[i + 1];
                    });

    return {filtered.begin(), filtered.end()};
}

auto getAllWeightDataUnit(const std::vector<int> &peakIndexes,
                          const std::vector<float> &allCycleData) -> std::vector<std::vector<float> > {
    if (allCycleData.empty()) {
        throw std::invalid_argument("传递的周期数据为空");
    }

    if (peakIndexes.empty()) {
        throw std::invalid_argument("传递的峰值索引为空");
    }

    if (allCycleData.size() < 5) {
        throw std::invalid_argument("传递的周期数据，不足以收集周围数据，至少大于等于7");
    }


    std::vector<std::vector<float> > peaksData;

    for (const auto &peakIndex: peakIndexes) {
        std::vector<float> peakData;

        peakData.push_back(allCycleData[peakIndex]);

        auto leftEndIndex = peakIndex - 2;

        while (leftEndIndex != peakIndex) {
            peakData.push_back(allCycleData[leftEndIndex++]);
        }

        auto rightEndIndex = peakIndex + 2;

        while (rightEndIndex != peakIndex) {
            peakData.push_back(allCycleData[rightEndIndex--]);
        }

        peaksData.push_back(peakData);
    }

    return peaksData;
}

float computeWeight(const std::vector<int> &peakIndexes,
                    const std::vector<float> &allCycleData) {
    return std::transform_reduce(
               peakIndexes.begin(), peakIndexes.end(), 0.0f, std::plus(),
               [&allCycleData](const int index) { return allCycleData.at(index); }) / static_cast<float>(peakIndexes.
               size());
}

auto findAllValleys(const std::vector<int> &peakIndexes, const std::vector<float> &allCycle) -> std::vector<int> {
    const auto peakIndexesSize = peakIndexes.size();

    if (peakIndexes.empty() or peakIndexes.size() == 1) {
        throw std::invalid_argument("波峰的索引数据为空或者不规范");
    }

    if (allCycle.empty() or allCycle.size() == 2) {
        throw std::invalid_argument("周期数据为空或者数据量不足");
    }

    std::vector<int> valleysData;


    for (int i = 0; i < peakIndexesSize - 1; ++i) {
        auto beforePeakIndex = peakIndexes.at(i);

        const auto afterPeakIndex = peakIndexes.at(i + 1);


        float min = std::numeric_limits<float>::max();


        while (beforePeakIndex < afterPeakIndex) {
            if (min > allCycle.at(beforePeakIndex)) {
                min = allCycle.at(beforePeakIndex);
            }

            beforePeakIndex++;
        }

        if (min != std::numeric_limits<float>::max()) {
            if (const auto valleyIndexIterator = std::ranges::find(allCycle, min);
                valleyIndexIterator != allCycle.end()) {
                const auto valleyIndex = std::distance(allCycle.begin(), valleyIndexIterator);
                valleysData.push_back(static_cast<int>(valleyIndex));
            }
        }
    }

    if (not valleysData.empty()) {
        return valleysData;
    }

    return {};
}

int main() {
    std::vector<float> originalData = readLogData("./重量数据/推车机快速/A5.log");

    removeDuplicates(originalData);

    auto allCycle = findAllCycle(originalData);

    spdlog::info("去重后数据总量为:{}",allCycle.size());



    for (const auto &weight: allCycle) {
        std::cout << weight << std::endl;
    }


    const auto allPeakIndexes = findAllPeaks(allCycle);


    for (const auto &peakIndex: allPeakIndexes) {
        spdlog::info("波峰位置 {},元素 {}", peakIndex, allCycle.at(peakIndex));
    }

    spdlog::info("-----------------------");

    const auto allValleysIndex = findAllValleys(allPeakIndexes, allCycle);

    /*
    for (const auto &valleyIndex: allValleysIndex) {
        spdlog::info("波谷位置 {},元素 {}", valleyIndex, allCycle.at(valleyIndex));
    }
    */


    auto totalWeight = computeWeight(allPeakIndexes, allCycle);

    /*
    spdlog::info("总KN为:{}", totalWeight);
    spdlog::info("总重量为:{}", totalWeight * 1000 / 9.8);
    */

    return 0;
}
