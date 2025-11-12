//
// Created by jiahan on 25-1-3.
//

#include "DefaultWeightRecognitionFactory.hpp"

#include "../../../service/weightRecognition/implements/default/DefaultWeightRecognitionService.hpp"

std::unique_ptr<AbstractWeightRecognitionService> DefaultWeightRecognitionFactory::create() const {
    return std::make_unique<DefaultWeightRecognitionService>();
}
