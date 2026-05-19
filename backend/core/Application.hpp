#pragma once

namespace Orbital {
    class Application
    {
        public:
            Application();
            ~Application();

            void run();

        private:
            bool running = true;
    };

}