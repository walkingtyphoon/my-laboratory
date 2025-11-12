//
// Created by jiahan on 24-12-25.
//

#include "WeightCycleExtractor.hpp"

#include <spdlog/spdlog.h>

WeightCycleExtractor::WeightCycleExtractor(const std::vector<double> &inputData, const std::vector<int> &peaks,
                                           const std::vector<int> &valleys) : validCycleData(inputData),
                                                                              peakIndexes(peaks),
                                                                              valleyIndexes(valleys) {
}

auto WeightCycleExtractor::extractorCycles() -> std::vector<std::vector<double> > {
    // 获取波峰索引数据的大小
    const int peakTotal = static_cast<int>(valleyIndexes.size());

    // 获取波谷索引的大小
    const int valleyTotal = static_cast<int>(peakIndexes.size());


    // 记录所有的周期数据
    std::vector<std::vector<double> > allCycleData;

    // 当前的周期数据
    std::vector<double> currentCycle;


    // 波谷的索引
    int valleyElementIndex{0};

    // 遍历所有的波峰数据
    for (int i = 0; i < peakTotal; ++i) {
        // 获取一个波峰的索引
        const auto peakIndex = peakIndexes.at(i);

        // 获取一个波峰数据
        const auto peak = validCycleData.at(peakIndex);


        // 获取一个波谷的索引
        const auto valleyIndex = valleyIndexes.at(valleyElementIndex);

        // 根据索引获取波谷数据
        const auto valley = validCycleData.at(valleyIndex);

        // 放入波峰进入当前周期
        currentCycle.push_back(peak);

        // 如果不是，则将当前的波谷数据加入周期数据中用于后期处理
        currentCycle.push_back(valley);

        // 判断当前的波峰和波谷之间的差值是否为其1/2
        if (peak - valley > peak * 1.0 / 2.0) {
            // 如果是的话就上传当前周期
            allCycleData.push_back(currentCycle);
            // 清空当前存储周期数据的容器
            currentCycle.clear();
        }

        // 确保波谷的索引不会超出实际的大小
        if (valleyElementIndex != valleyTotal) {
            valleyElementIndex++;
        }

        if (valleyIndex == validCycleData.size() - 1) {
            spdlog::info("已达到末尾");
            break;
        }
    }

    return allCycleData;
}
