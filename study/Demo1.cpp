//
// Created by walking typhoon on 25-5-27.
//
#include <iostream>
#include <cstring>

void greet() {
    char name[32];
    std::cout << "Enter your name: ";
    std::cin >> name;  // <-- 溢出点在这里，没有检查长度
    std::cout << "Hello, " << name << "!" << std::endl;
}

int mainzxczxc() {
    greet();
    std::cout << "Program finished.\n";
    return 0;
}
