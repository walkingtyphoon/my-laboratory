//
// Created by walking typhoon on 24-9-27.
//

#include <iostream>
#include <any>
#include <vector>
#include <string>
#include <spdlog/spdlog.h>

void storeDifferentTypes(std::vector<std::any>& values) {
    values.push_back(10); // 存储一个整数
    values.push_back(3.14); // 存储一个浮点数
    values.push_back(std::string("C++17 std::any")); // 存储一个字符串
    values.push_back(std::vector<int>()); // 存储一个字符串
}

void printAnyVector(const std::vector<std::any>& values) {
    for (const auto& value : values) {

        if (value.type() == typeid(int)) {
            std::cout << "int: " << std::any_cast<int>(value) << std::endl;
        }
        else if (value.type() == typeid(double)) {
            std::cout << "double: " << std::any_cast<double>(value) << std::endl;
        }
        else if (value.type() == typeid(std::string)) {
            std::cout << "string: " << std::any_cast<std::string>(value) << std::endl;
        }else if (value.type() == typeid(std::vector<int>)) {
            spdlog::info("vector type: {}",std::any_cast<std::vector<int>>(value).size());
        }
        else {
            std::cout << "Unknown type" << std::endl;
        }
    }
}

int main3() {
    std::vector<std::any> values;
    storeDifferentTypes(values);
    printAnyVector(values); // 输出存储的所有类型
    return 0;
}
