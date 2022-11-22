#include <iostream>
#include <string>

namespace ENA {

    class Log {
    public:
        Log() = default;
        Log(const Log&) = delete;
        Log& operator=(const Log&) = delete;

        static void info(const std::string message) {
            std::cout << "[INFO] " << message << std::endl;
        }
        static void warn(const std::string message) {
            std::cout << "[WARNING] " << message << std::endl;
        }
        static void error(const std::string message) {
            std::cout << "[ERROR] " << message << std::endl;
        }
        static void debug(const std::string message) {
            std::cout << "[DEBUG] " << message << std::endl;
        }
    };

}