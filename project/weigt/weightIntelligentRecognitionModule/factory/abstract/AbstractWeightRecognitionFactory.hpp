//
// Created by jiahan on 25-1-3.
//

#ifndef ABSTRACTWEIGHTRECOGNITIONFACTORY_HPP
#define ABSTRACTWEIGHTRECOGNITIONFACTORY_HPP
#include <memory>

#include "../../service/weightRecognition/abstract/AbstractWeightRecognitionService.hpp"


class AbstractWeightRecognitionFactory {
public:
    virtual ~AbstractWeightRecognitionFactory();

    [[nodiscard]] virtual std::unique_ptr<AbstractWeightRecognitionService> create() const = 0;
};


#endif //ABSTRACTWEIGHTRECOGNITIONFACTORY_HPP
