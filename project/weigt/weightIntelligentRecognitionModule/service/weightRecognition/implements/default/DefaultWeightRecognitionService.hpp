//
// Created by jiahan on 25-1-3.
//

#ifndef DEFAULTWEIGHTRECOGNITIONSERVICE_HPP
#define DEFAULTWEIGHTRECOGNITIONSERVICE_HPP

#include <memory>

#include "../../abstract/AbstractWeightRecognitionService.hpp"

#include "../../../../core/cycleExtractor/abstract/AbstractCycleExtractor.hpp"
#include "../../../../core/dataProcessor/abstract/AbstractDataProcessor.hpp"
#include "../../../../core/waveAnalyzer/abstract/AbstractWaveAnalyzer.hpp"
#include "../../../../core/weightCalculator/abstract/AbstractWeightCalculator.hpp"
#include "../../../../scalingFactor/abstract/AbstractScalingFactorCalculator.hpp"

class DefaultWeightRecognitionService final : public AbstractWeightRecognitionService {
public:
    [[nodiscard]] double run(const std::vector<double> &input) override;

    DefaultWeightRecognitionService();

private:
    std::unique_ptr<AbstractDataProcessor> dataProcessor;


    std::unique_ptr<AbstractWaveAnalyzer> waveAnalyzer;


    std::unique_ptr<AbstractScalingFactorCalculator> scalingFactorCalculator;


    std::unique_ptr<AbstractWeightCalculator> weightCalculator;
};

#endif //DEFAULTWEIGHTRECOGNITIONSERVICE_HPP
