//
// Created by jiahan on 25-1-3.
//

#ifndef ABSTRACTWEIGHTRECOGNITIONSERVICE_HPP
#define ABSTRACTWEIGHTRECOGNITIONSERVICE_HPP
#include <vector>


class AbstractWeightRecognitionService {

public:

    [[nodiscard]] virtual double run(const std::vector<double> &input) = 0;

    virtual ~AbstractWeightRecognitionService() ;
};



#endif //ABSTRACTWEIGHTRECOGNITIONSERVICE_HPP
