//
// Created by jiahan on 25-1-2.
//

#include "DefaultWeightCalculator.hpp"

#include <algorithm>
#include <numeric>

double DefaultWeightCalculator::calculate(const std::vector<std::vector<double> > &weights) const {
    return std::transform_reduce(
        weights.begin(), weights.end(), 0.0, std::plus(),
        [](const auto &cycleData) {
            return *std::ranges::max_element(cycleData);
        }
    );
}
