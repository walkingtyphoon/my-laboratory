#include <iostream>

int main12312312() {
    int x = 42;
    std::cout << "Before: " << x << "\n";

    asm volatile (
        "movl $666, %0;" // 直接把666塞进x
        : "=r" (x)       // 输出
        :                // 无输入
        : "memory"       // 内存可能受影响
    );

    std::cout << "After: " << x << "\n";
    return 0;
}