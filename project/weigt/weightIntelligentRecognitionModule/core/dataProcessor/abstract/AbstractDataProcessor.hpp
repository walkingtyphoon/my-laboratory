//
// Created by jiahan on 24-12-25.
//

#ifndef ABSTRACTDATAPROCESSOR_HPP
#define ABSTRACTDATAPROCESSOR_HPP

#include <vector>


class AbstractDataProcessor {
public:

    virtual auto setOriginalData(const std::vector<double>& data) ->void = 0;

    virtual auto removeDuplicates() -> void = 0;

    virtual auto filterValidCycle(double threshold) -> std::vector<double> = 0;


    virtual ~AbstractDataProcessor();
};



#endif //ABSTRACTDATAPROCESSOR_HPP
