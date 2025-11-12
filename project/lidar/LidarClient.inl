//
// Created by walking typhoon on 2025/11/12.
//

#include "LidarClient.hpp"

template<ConnectableConcept ImplementClass>
void LidarClient<ImplementClass>::connectTo(const std::string &ip, short lidarDataPort, short) {
}

template<ConnectableConcept ImplementClass>
void LidarClient<ImplementClass>::parseReceiveData(const std::string &newData) {
    static_cast<ImplementClass*>(this)->receiveData(newData);
}

template<ConnectableConcept ImplementClass>
void LidarClient<ImplementClass>::close() {
}
