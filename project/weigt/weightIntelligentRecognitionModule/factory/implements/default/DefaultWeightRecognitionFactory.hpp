//
// Created by jiahan on 25-1-3.
//

#ifndef DEFAULTWEIGHTRECOGNITIONFACTORY_HPP
#define DEFAULTWEIGHTRECOGNITIONFACTORY_HPP
#include "../../abstract/AbstractWeightRecognitionFactory.hpp"


class DefaultWeightRecognitionFactory final : public AbstractWeightRecognitionFactory {
public:
    [[nodiscard]] std::unique_ptr<AbstractWeightRecognitionService> create() const override;
};


#endif //DEFAULTWEIGHTRECOGNITIONFACTORY_HPP
