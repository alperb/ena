#pragma once
#include <iostream>
#include <string>

class Logger {
public:
    static void Log(const std::string& message){
        std::cout << message << std::endl;
    }
};