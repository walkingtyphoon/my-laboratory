//
// Created by jiahan on 25-1-2.
//

#include "WeightDefaultScalingFactorCalculator.hpp"

#include "../../../types/scalingCoefficients/WeightScalingCoefficients.hpp"

using namespace WeightScalingCoefficients;

double WeightDefaultScalingFactorCalculator::calculate(const int x) const {
    return A * x * x - B * x + C;
}
