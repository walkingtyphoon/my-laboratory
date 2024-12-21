//
// Created by walking typhoon on 24-9-28.
//
#include <future>
#include <spdlog/spdlog.h>

// 计算范围的和
int sumRange(const int begin, const int end) {
    return end * (end + 1) / 2 - (begin - 1) * begin / 2;
}

int main5() {

    // 启动异步任务
    auto future1 = std::async(std::launch::async, sumRange, 0, 100);
    auto future2 = std::async(std::launch::async, sumRange, 101, 200);
    auto future3 = std::async(std::launch::async, sumRange, 201, 300);

    try {
        // 获取结果
        const auto result = future1.get() + future2.get() + future3.get();
        spdlog::info("Total Result: {}", result);
    } catch (const std::exception& e) {
        spdlog::error("Error occurred: {}", e.what());
    }

    return 0;
}
