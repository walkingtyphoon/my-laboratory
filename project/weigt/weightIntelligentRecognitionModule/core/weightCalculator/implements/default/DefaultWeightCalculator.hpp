//
// Created by jiahan on 25-1-2.
//

#ifndef DEFAULTWEIGHTCALCULATOR_HPP
#define DEFAULTWEIGHTCALCULATOR_HPP
#include "../../abstract/AbstractWeightCalculator.hpp"


class DefaultWeightCalculator final : public AbstractWeightCalculator {
public:
    [[nodiscard]] double calculate(const std::vector<std::vector<double>> &weights) const override;
};


#endif //DEFAULTWEIGHTCALCULATOR_HPP
