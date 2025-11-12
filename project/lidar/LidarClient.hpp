//
// Created by walking typhoon on 2025/11/12.
//

#ifndef MY_LABORATORY_LIDARCLIENT_HPP
#define MY_LABORATORY_LIDARCLIENT_HPP

#include "concept/ConnectableConcept.hpp"
#include <string>

template<ConnectableConcept ImplementClass>
class LidarClient {
public:
    void connectTo(const std::string &ip, short lidarDataPort, short);

    void parseReceiveData(const std::string &newData);

    void close();
};

#include "LidarClient.inl"

#endif //MY_LABORATORY_LIDARCLIENT_HPP
