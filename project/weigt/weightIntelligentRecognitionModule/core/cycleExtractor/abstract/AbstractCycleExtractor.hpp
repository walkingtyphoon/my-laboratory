//
// Created by jiahan on 24-12-25.
//

#ifndef ABSTRACTCYCLEEXTRACTOR_HPP
#define ABSTRACTCYCLEEXTRACTOR_HPP

#include <vector>


class AbstractCycleExtractor {
public:
    virtual auto extractorCycles() -> std::vector<std::vector<double>> = 0;


    virtual ~AbstractCycleExtractor();
};


#endif //ABSTRACTCYCLEEXTRACTOR_HPP
