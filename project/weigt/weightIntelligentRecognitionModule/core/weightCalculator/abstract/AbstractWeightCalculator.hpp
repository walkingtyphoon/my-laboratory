//
// Created by jiahan on 25-1-2.
//

#ifndef ABSTRACTWEIGHTCALCULATOR_HPP
#define ABSTRACTWEIGHTCALCULATOR_HPP

#include <vector>


class AbstractWeightCalculator {
public:
    [[nodiscard]] virtual double calculate(const std::vector<std::vector<double>> &weights) const = 0;

    virtual ~AbstractWeightCalculator();
};


#endif //ABSTRACTWEIGHTCALCULATOR_HPP
