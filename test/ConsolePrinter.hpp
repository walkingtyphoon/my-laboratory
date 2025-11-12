//
// Created by walking typhoon on 25-6-6.
//

#ifndef CONSOLEPRINTER_HPP
#define CONSOLEPRINTER_HPP

#include <memory>

#include "IPrinter.hpp"

class ConsolePrinter : public IPrinter {
public:
    ConsolePrinter();
    ~ConsolePrinter() override;

    void print(const char* message) override;

private:
    class Impl;
    std::unique_ptr<Impl> impl;
};



#endif //CONSOLEPRINTER_HPP
