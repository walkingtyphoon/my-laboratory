#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

// 计算加权平均值
double weighted_average(const std::vector<double>& values, const std::vector<int>& time_diff, double alpha) {
    double weighted_sum = 0.0;
    double weight_sum = 0.0;
    
    // 计算加权和（假设时间差为1）
    for (size_t i = 0; i < values.size(); ++i) {
        double weight = exp(-alpha * time_diff[i]);
        weighted_sum += values[i] * weight;
        weight_sum += weight;
    }

    return weighted_sum / weight_sum;
}

// 计算误差（这里使用均方误差MSE）
double compute_error(const std::vector<double>& observed, const std::vector<double>& actual, double alpha) {
    double error = 0.0;
    // 创建一个时间差数组，假设数据按顺序排列
    std::vector<int> time_diff(observed.size());
    for (size_t i = 0; i < observed.size(); ++i) {
        time_diff[i] = i;  // 时间差递增，假设数据按时间顺序排列
    }

    // 计算误差
    for (size_t i = 0; i < observed.size(); ++i) {
        double predicted = weighted_average(observed, time_diff, alpha);  // 根据alpha计算加权平均
        error += std::pow(predicted - actual[i], 2);  // MSE
    }
    return error / observed.size();
}

int main() {
    // 假设的观察数据和真实数据
    const std::vector observed_values = {558.177551, 567.8112245, 558.177551, 567.8112245, 608.3336735};  // 示例数据
    const std::vector<double> actual_values = {690, 690, 576, 576, 648};   // 真实数据
    
    // 不同的alpha值
    const std::vector alphas = {0.1, 0.2, 0.3, 0.5, 1.0};
    
    double best_alpha = 0.0;
    double min_error = std::numeric_limits<double>::infinity();

    // 计算不同alpha下的加权平均误差
    for (double alpha : alphas) {
        double error = compute_error(observed_values, actual_values, alpha);

        std::cout << "Alpha: " << alpha << ", Error: " << error << std::endl;

        if (error < min_error) {
            min_error = error;
            best_alpha = alpha;
        }
    }

    // 输出最佳的alpha值
    std::cout << "最佳alpha值: " << best_alpha << std::endl;
    
    return 0;
}
