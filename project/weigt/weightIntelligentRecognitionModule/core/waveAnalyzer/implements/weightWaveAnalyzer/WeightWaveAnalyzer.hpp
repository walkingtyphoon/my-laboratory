//
// Created by jiahan on 24-12-25.
//

#ifndef WEIGHTWAVEANALYZER_HPP
#define WEIGHTWAVEANALYZER_HPP

#include "../../abstract/AbstractWaveAnalyzer.hpp"


class WeightWaveAnalyzer final: public AbstractWaveAnalyzer {
public:
    void setInputData(const std::vector<double> &inputData) override;

    auto findAllPeaks() -> std::vector<int> override;


    auto findAllValleys(const std::vector<int> &peakIndexes) -> std::vector<int> override;

private:

    std::vector<double> originalData;
};


#endif //WEIGHTWAVEANALYZER_HPP
