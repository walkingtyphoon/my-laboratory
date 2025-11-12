//
// Created by jiahan on 24-12-25.
//

#ifndef ABSTRACTWAVEANALYZER_HPP
#define ABSTRACTWAVEANALYZER_HPP

#include <vector>

class AbstractWaveAnalyzer {
public:
    virtual void setInputData(const std::vector<double>& inputData) = 0;

    virtual auto findAllPeaks() -> std::vector<int> = 0;

    virtual auto findAllValleys(const std::vector<int> &peakIndexes) -> std::vector<int> = 0;

    virtual ~AbstractWaveAnalyzer();
};


#endif //ABSTRACTWAVEANALYZER_HPP
