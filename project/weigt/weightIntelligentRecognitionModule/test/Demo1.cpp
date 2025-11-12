#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <spdlog/spdlog.h>

#include "../core/cycleExtractor/abstract/AbstractCycleExtractor.hpp"
#include "../core/cycleExtractor/implements/weightCycleExtractor/WeightCycleExtractor.hpp"
#include "../core/dataProcessor/abstract/AbstractDataProcessor.hpp"
#include "../core/dataProcessor/implements/weightDataProcessor/WeightDataProcessor.hpp"
#include "../core/waveAnalyzer/abstract/AbstractWaveAnalyzer.hpp"
#include "../core/waveAnalyzer/implements/weightWaveAnalyzer/WeightWaveAnalyzer.hpp"
#include "../core/weightCalculator/abstract/AbstractWeightCalculator.hpp"
#include "../core/weightCalculator/implements/default/DefaultWeightCalculator.hpp"
#include "../scalingFactor/abstract/AbstractScalingFactorCalculator.hpp"
#include "../scalingFactor/implements/weight/default/WeightDefaultScalingFactorCalculator.hpp"
#include "../tools/weightConverter/WeightUnitConverter.hpp"

std::vector<double> readLogData(const std::string &filePath) {
    std::vector<double> data;
    std::ifstream inputFile(filePath);

    if (!inputFile.is_open()) {
        std::cerr << "无法打开文件: " << filePath << std::endl;
        return data;
    }

    double value;
    while (inputFile >> value) {
        data.push_back(value);
    }

    spdlog::info("original Data size is {}", data.size());

    inputFile.close();
    return data;
}


int main2() {
    const std::vector<double> originalData = readLogData("./重量数据/手动快速/01.log");


    const std::unique_ptr<AbstractDataProcessor> dataProcessor = std::make_unique<WeightDataProcessor>();

    dataProcessor->setOriginalData(originalData);

    auto allCycle = dataProcessor->filterValidCycle(0.1);

    int validCycleSize = static_cast<int>(allCycle.size());

    spdlog::info("不去重后的原始数据有:{}个", validCycleSize);


    const std::unique_ptr<AbstractScalingFactorCalculator> scalingFactorCalculator = std::make_unique<
        WeightDefaultScalingFactorCalculator>();

    const auto factor = scalingFactorCalculator->calculate(validCycleSize);

    dataProcessor->removeDuplicates();

    allCycle = dataProcessor->filterValidCycle(0.1);

    spdlog::info("去重后的数据为:{}", allCycle.size());


    for (const auto cycle: allCycle) {
        std::cout << cycle << std::endl;
    }


    const std::unique_ptr<AbstractWaveAnalyzer> waveAnalyzer = std::make_unique<WeightWaveAnalyzer>();

    waveAnalyzer->setInputData(allCycle);

    const auto allPeakIndexes = waveAnalyzer->findAllPeaks();
    std::cout << "波峰" << std::endl;

    for (int peak_index: allPeakIndexes) {
        std::cout << allCycle.at(peak_index) << std::endl;
    }

    std::cout << "波谷" << std::endl;


    const auto allValleysIndex = waveAnalyzer->findAllValleys(allPeakIndexes);


    for (int valleys_index: allValleysIndex) {
        std::cout << allCycle.at(valleys_index) << std::endl;
    }


    const std::unique_ptr<AbstractCycleExtractor> cycleExtractor = std::make_unique<WeightCycleExtractor>(
        allCycle, allPeakIndexes, allValleysIndex);

    const auto allCycleData = cycleExtractor->extractorCycles();
    std::cout << "周期数据" << std::endl;

    for (const auto unitCycle: allCycleData) {
        for (const auto cycle: unitCycle) {
            std::cout << cycle << std::endl;
        }
        std::cout << std::endl;
    }


    const std::unique_ptr<AbstractWeightCalculator> weightCalculator = std::make_unique<DefaultWeightCalculator>();

    const auto sum = weightCalculator->calculate(allCycleData);

    const auto weightOfKN = sum * factor;

    const auto weightOfKG = WeightUnitConverter::convertKNtoKG(weightOfKN);


    spdlog::info("总重量为:{}KG", weightOfKG);

    return 0;
}
