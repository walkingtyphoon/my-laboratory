//
// Created by jiahan on 25-1-2.
//

#include "WeightUnitConverter.hpp"

double WeightUnitConverter::convertKNtoKG(const double weightInKN) {
    return weightInKN * 1000 / 9.8;
}
