//
// Created by jiahan on 25-1-2.
//

#ifndef ABSTRACTSCALINGFACTORCALCULATOR_HPP
#define ABSTRACTSCALINGFACTORCALCULATOR_HPP


class AbstractScalingFactorCalculator {
public:
    [[nodiscard]] virtual double calculate(int x) const = 0;

    virtual ~AbstractScalingFactorCalculator();
};


#endif //ABSTRACTSCALINGFACTORCALCULATOR_HPP
