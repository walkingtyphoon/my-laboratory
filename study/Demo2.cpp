#include <functional>
#include <iostream>
#include <ostream>

class Device {
public:
    std::function<void(int)> process;

    void setProcess(const std::function<void(int)> &newProcessFunction) {
        process = newProcessFunction;
    }

    void start() const {
        for (int i = 0; i < 100; ++i) {
            process(i);
        }
    }
};


int m2323ain(int argc, char *argv[]) {
    Device device;

    device.setProcess([](const int i) {
        std::cout << i << std::endl;
    });

    device.start();
}
