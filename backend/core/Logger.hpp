#include <iostream>
#include <string>

namespace Orbital {
    class Logger
    {
        public:
            static void init();

            static void info(const std::string& message);
            static void warning(const std::string& message);
            static void error(const std::string& message);

    };
}