//
// Created by jiahan on 25-1-3.
//

#include "DefaultWeightRecognitionService.hpp"

#include "../../../../core/cycleExtractor/implements/weightCycleExtractor/WeightCycleExtractor.hpp"
#include "../../../../core/dataProcessor/implements/weightDataProcessor/WeightDataProcessor.hpp"
#include "../../../../core/waveAnalyzer/implements/weightWaveAnalyzer/WeightWaveAnalyzer.hpp"
#include "../../../../core/weightCalculator/implements/default/DefaultWeightCalculator.hpp"
#include "../../../../scalingFactor/implements/weight/default/WeightDefaultScalingFactorCalculator.hpp"

double DefaultWeightRecognitionService::run(const std::vector<double> &input) {

    dataProcessor->setOriginalData(input);

    auto allCycle = dataProcessor->filterValidCycle(0.1);

    const int validCycleSize = static_cast<int>(allCycle.size());
    const auto factor = scalingFactorCalculator->calculate(validCycleSize);

    dataProcessor->removeDuplicates();
    allCycle = dataProcessor->filterValidCycle(0.1);

    waveAnalyzer->setInputData(allCycle);

    auto allPeakIndexes = waveAnalyzer->findAllPeaks();
    auto allValleysIndex = waveAnalyzer->findAllValleys(allPeakIndexes);

    const std::unique_ptr<AbstractCycleExtractor> cycleExtractor = std::make_unique<WeightCycleExtractor>(
        allCycle, allPeakIndexes, allValleysIndex);

    const auto allCycleData = cycleExtractor->extractorCycles();

    const auto sum = weightCalculator->calculate(allCycleData);

    return sum * factor;
}

DefaultWeightRecognitionService::DefaultWeightRecognitionService() {
    dataProcessor = std::make_unique<WeightDataProcessor>();

    scalingFactorCalculator = std::make_unique<WeightDefaultScalingFactorCalculator>();

    waveAnalyzer = std::make_unique<WeightWaveAnalyzer>();

    weightCalculator = std::make_unique<DefaultWeightCalculator>();
}
