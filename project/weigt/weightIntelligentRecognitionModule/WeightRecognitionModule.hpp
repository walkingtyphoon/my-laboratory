//
// Created by jiahan on 25-1-3.
//

#ifndef WEIGHTRECOGNITIONMODULE_HPP
#define WEIGHTRECOGNITIONMODULE_HPP
#include <memory>
#include <vector>

#include "factory/abstract/AbstractWeightRecognitionFactory.hpp"

namespace WeightRecognitionModule {
    inline std::unique_ptr<AbstractWeightRecognitionFactory>& getFactory();

    inline double run(const std::vector<double> &inputData) ;
};


#endif //WEIGHTRECOGNITIONMODULE_HPP
