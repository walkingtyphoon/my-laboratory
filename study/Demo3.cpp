//
// Created by walkingtyphoon on 2025/11/29.
//
#include <iostream>

#include "concepts"

// 作为约束
template<typename T>
concept DeviceConcept = requires(T d)
{
    { d.start() } -> std::same_as<void>;
    { d.stop() } -> std::same_as<void>;
};

// 继承约束，调用子类函数
template<typename T>
class Device {
public:
    void start() {
        static_cast<T &>(*this).start();
    }

    void stop() {
        static_cast<T &>(*this).stop();
    }
};

// 子类
class IODevice {
public:
    void start() {
        std::cout << "123123";
    }

    void stop() {
        std::cout << "222222222222222222222222";
    }
};

class Test {
public:
    Device<IODevice> device;
};
