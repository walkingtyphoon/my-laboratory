//
// Created by jiahan on 24-12-30.
//
#include <Eigen/Dense>
#include <spdlog/spdlog.h>

int main21() {
    // 数据点
    Eigen::VectorXd x(30), y(30);
    x << 341, 406, 528, 538, 556, 294, 291, 275, 265, 264, 235, 254, 226, 227, 247,
            425, 336, 424, 328, 319, 300, 289, 261, 258, 232, 259, 270,
            272, 300, 265;

    y << 0.921146307, 0.966925413, 0.905353377, 0.9555005, 0.935126962, 0.91592968, 0.926421167, 0.945375817,
            0.948496027, 0.921144796, 0.962789095, 0.943823397, 0.930587894, 0.934114285, 0.987592223, 1.031420805,
            0.929708499, 1.045466091, 1.083406105, 1.029610195, 1.049379569, 1.028460058, 0.972911644,
            1.056602178, 1.054355704, 1.082132716, 1.045467653, 1.002556108, 1.010411402, 0.982694841;


    // 构造 A 矩阵和 b 向量
    Eigen::MatrixXd A(x.size(), 3); // A 矩阵
    A.col(0) = x.array().square(); // 第一列是 x^2
    A.col(1) = x; // 第二列是 x
    A.col(2) = Eigen::VectorXd::Ones(x.size()); // 第三列是常数 1
    Eigen::VectorXd b = y;

    // 最小二乘法求解
    Eigen::VectorXd coeffs = A.colPivHouseholderQr().solve(b);

    // 拟合结果
    double a = coeffs(0); // 二次项系数
    double b_coeff = coeffs(1); // 一次项系数
    double c = coeffs(2); // 常数项

    // 输出拟合公式
    spdlog::info("拟合公式: f(x) = {} * x^2 + {} * x + {}", a, b_coeff, c);

    // 测试计算
    double new_x = 341;
    double fitted_y = a * new_x * new_x + b_coeff * new_x + c;
    spdlog::info("当数据总量 x = {} 时，计算出的校准因子 f(x) = {}", new_x, fitted_y);

    // 缩放后的数据
    double observed_data = 622.0510204;
    spdlog::info("缩放后的数据为: {}", fitted_y * observed_data);

    return 0;
}
