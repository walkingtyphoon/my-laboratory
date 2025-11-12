//
// Created by jiahan on 25-1-2.
//

#ifndef WEIGHTDEFAULTSCALINGFACTORCALCULATOR_HPP
#define WEIGHTDEFAULTSCALINGFACTORCALCULATOR_HPP
#include "../../../abstract/AbstractScalingFactorCalculator.hpp"


class WeightDefaultScalingFactorCalculator : public AbstractScalingFactorCalculator {
public:
    [[nodiscard]] double calculate(int x) const override;
};


#endif //WEIGHTDEFAULTSCALINGFACTORCALCULATOR_HPP
