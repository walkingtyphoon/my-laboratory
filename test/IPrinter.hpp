//
// Created by walking typhoon on 25-6-6.
//

#ifndef IPRINTER_HPP
#define IPRINTER_HPP

#pragma once

class IPrinter {
public:
    virtual ~IPrinter() = default;
    virtual void print(const char* message) = 0;
};

#endif //IPRINTER_HPP
