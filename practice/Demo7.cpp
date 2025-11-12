//
// Created by jiahan on 25-1-2.
//
#include <iostream>
#include <cmath>
#include <ranges>
#include <vector>
#include <tuple>
#include <spdlog/spdlog.h>

struct Point {
    double x;
    double y;
};

[[nodiscard]] double distance2D(const Point &one, const Point &two) {
    return sqrt((two.x - one.x) * (two.x - one.x) + (two.y - one.y) * (two.y - one.y));
}

void printDistancesFromBase(const Point &base, const std::vector<Point> &points) {
    for (const auto &point: points) {
        spdlog::info("distance to {}", distance2D(base, point));
    }
}

constexpr Point ORIGIN{0, 0};


std::tuple<double, double, double> findFarthestPointFromOrigin(const std::vector<Point> &points) {
    if (points.empty()) {
        spdlog::warn("The points vector is empty.");
        return {0.0, 0.0, 0.0}; // 或者抛出 std::invalid_argument
    }

    double maxDistance = 0;

    std::tuple<double, double, double> bestFarthestPoint{0, 0, 0};


    for (const auto &point: points) {
        if (const auto distance = distance2D(ORIGIN, point); distance > maxDistance) {
            maxDistance = distance;

            bestFarthestPoint = {point.x, point.y, maxDistance};
        }
    }


    return bestFarthestPoint;
}

int ma222222in() {
    // 一些示例点
    const std::vector<Point> points = {
        {1.0, 2.0},
        {4.0, 6.0},
        {-3.0, 4.0},
        {10.0, 0.0}
    };

    printDistancesFromBase(ORIGIN, points);

    auto [x, y, dist] = findFarthestPointFromOrigin(points);

    spdlog::info("Farthest point from origin is {},{}, distance = {}", x, y, dist);

    return 0;
}
