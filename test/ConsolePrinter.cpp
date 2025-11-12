//
// Created by walking typhoon on 25-6-6.
//

#include "ConsolePrinter.hpp"
#include <iostream>

// 内部实现类定义
class ConsolePrinter::Impl {
public:
    void printImpl(const char* msg) {
        std::cout << "[ConsolePrinter] " << msg << std::endl;
    }
};

// 构造/析构/实现方法
ConsolePrinter::ConsolePrinter()
    : impl(std::make_unique<Impl>()) {}

ConsolePrinter::~ConsolePrinter() = default;

void ConsolePrinter::print(const char* message) {
    impl->printImpl(message);
}
