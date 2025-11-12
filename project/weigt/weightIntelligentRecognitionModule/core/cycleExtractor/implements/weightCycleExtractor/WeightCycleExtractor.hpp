//
// Created by jiahan on 24-12-25.
//

#ifndef WEIGHTCYCLEEXTRACTOR_HPP
#define WEIGHTCYCLEEXTRACTOR_HPP

#include "../../abstract/AbstractCycleExtractor.hpp"


class WeightCycleExtractor final : public AbstractCycleExtractor {
public:
    WeightCycleExtractor(const std::vector<double> &inputData,
                         const std::vector<int> &peaks,
                         const std::vector<int> &valleys);


    auto extractorCycles() -> std::vector<std::vector<double> > override;

private:
    const std::vector<double> &validCycleData;


    const std::vector<int> &peakIndexes;

    const std::vector<int> &valleyIndexes;
};


#endif //WEIGHTCYCLEEXTRACTOR_HPP
