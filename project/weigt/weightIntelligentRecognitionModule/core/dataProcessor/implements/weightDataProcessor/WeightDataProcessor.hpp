//
// Created by jiahan on 24-12-25.
//

#ifndef WERIGHTDATAPROCESSOR_HPP
#define WERIGHTDATAPROCESSOR_HPP
#include "../../abstract/AbstractDataProcessor.hpp"


class WeightDataProcessor final : public AbstractDataProcessor {
public:
    auto setOriginalData(const std::vector<double> &data) -> void override;

    auto removeDuplicates() -> void override;

    auto filterValidCycle(double threshold) -> std::vector<double> override;
private:

    std::vector<double> originalData;
};


#endif //WERIGHTDATAPROCESSOR_HPP
