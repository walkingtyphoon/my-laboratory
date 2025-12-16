//
// Created by jiahan on 2025/10/29.
//

#ifndef ALLWEIGHTCYCLEEXTRACTOR_H
#define ALLWEIGHTCYCLEEXTRACTOR_H

#include "../../abstract/AbstractCycleExtractor.hpp"


class AllWeightCycleExtractor : public AbstractCycleExtractor {
public:
    auto extractorCycles() -> std::vector<std::vector<double> > override;


    AllWeightCycleExtractor(const std::vector<double> &inputData,
                            const std::vector<int> &peaks,
                            const std::vector<int> &valleys);

private:
    const std::vector<double> &validCycleData;


    const std::vector<int> &peakIndexes;

    const std::vector<int> &valleyIndexes;
};

#endif //ALLWEIGHTCYCLEEXTRACTOR_H
