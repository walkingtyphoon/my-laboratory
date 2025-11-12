//
// Created by jiahan on 25-1-3.
//

#include "WeightRecognitionModule.hpp"

#include "factory/implements/default/DefaultWeightRecognitionFactory.hpp"

std::unique_ptr<AbstractWeightRecognitionFactory> & WeightRecognitionModule::getFactory()  {
    static std::unique_ptr<AbstractWeightRecognitionFactory> factory = std::make_unique<
        DefaultWeightRecognitionFactory>();
    return factory;
}
double WeightRecognitionModule::run(const std::vector<double> &inputData) {
    const auto service = getFactory()->create();
    return service->run(inputData);
}
