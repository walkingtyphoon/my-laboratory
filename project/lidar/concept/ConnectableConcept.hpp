//
// Created by walking typhoon on 2025/11/12.
//

#ifndef MY_LABORATORY_CONNECTABLECONCEPT_HPP
#define MY_LABORATORY_CONNECTABLECONCEPT_HPP

#include <concepts>
#include <string>

template<typename ImplementClass>
concept ConnectableConcept = requires(ImplementClass implementClass, const std::string &newData)
{
    {
        implementClass.parseReceiveData(newData)
    } -> std::same_as<void>;
};

#endif //MY_LABORATORY_CONNECTABLECONCEPT_HPP
