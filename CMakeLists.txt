cmake_minimum_required(VERSION 3.20) # 推荐使用较高版本的 CMake

project(my-laboratory)

# 设置 C++23 标准
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# 源文件列表
set(SOURCES
    practice/Demo1.cpp
    practice/Demo2.cpp
    practice/Demo3.cpp
    practice/Demo4.cpp
    practice/Demo5.cpp
    practice/Demo6.cpp
    project/Demo1.cpp
)

# 创建可执行文件
add_executable(my-laboratory ${SOURCES})

# 引入 spdlog 库
find_package(spdlog REQUIRED)
target_link_libraries(my-laboratory PRIVATE spdlog::spdlog)

# 如果需要，添加额外的包含目录（如 spdlog 的头文件路径）
target_include_directories(my-laboratory PRIVATE ${SPDLOG_INCLUDE_DIR})

# 确保编译器支持 C++23
target_compile_features(my-laboratory PUBLIC cxx_std_23)
