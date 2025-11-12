//
// Created by walking typhoon on 24-9-28.
//
#include <future>
#include <iostream>
#include <thread>
#include <spdlog/spdlog.h>

// 计算阶乘的函数
unsigned long long factorial(const int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

auto count(const int n, std::promise<unsigned long long>&& promise) {
    const auto result = factorial(n);

    promise.set_value(result);
}

int main6(int argc, char* argv[]) {
    int simulationUserInputData{10};

    std::promise<unsigned long long> promise;

    auto future = promise.get_future();

    std::thread countThread(count,simulationUserInputData, std::move(promise));

    countThread.join();

    spdlog::info("result {}", future.get());
}
