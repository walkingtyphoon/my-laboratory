cmake_minimum_required(VERSION 3.24) # 推荐使用较高版本的 CMake

project(my-laboratory)

# 设置 C++23 标准
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SourceCodeFolder practice project study test)

foreach (folder ${SourceCodeFolder})
    file(GLOB_RECURSE CPP_FILES "${folder}/*.cpp")
    file(GLOB_RECURSE H_FILES "${folder}/*.h")
    file(GLOB_RECURSE HPP_FILES "${folder}/*.hpp")
    file(GLOB_RECURSE INL_FILES "${folder}/*.inl")
    file(GLOB_RECURSE UI_FILES "${folder}/*.ui")

    list(APPEND ALL_CPP ${CPP_FILES})
    list(APPEND ALL_H ${H_FILES})
    list(APPEND ALL_HPP ${HPP_FILES})
    list(APPEND ALL_INL ${INL_FILES})
    list(APPEND ALL_UI ${UI_FILES})
endforeach ()

set(SOURCE_FILES ${ALL_CPP} ${ALL_H} ${ALL_HPP} ${ALL_INL} ${ALL_UI})

# 创建可执行文件
add_executable(my-laboratory ${SOURCE_FILES})

# 引入 spdlog 库
find_package(spdlog REQUIRED)

find_package(Eigen3 REQUIRED) # 自动找到 Eigen 库


target_link_libraries(my-laboratory PRIVATE
        spdlog::spdlog
        Eigen3::Eigen
)

# 如果需要，添加额外的包含目录（如 spdlog 的头文件路径）
target_include_directories(my-laboratory PRIVATE ${SPDLOG_INCLUDE_DIR})

# 确保编译器支持 C++23
target_compile_features(my-laboratory PUBLIC cxx_std_23)
