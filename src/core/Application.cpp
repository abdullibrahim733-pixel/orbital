#include "Application.hpp"
#include "window.hpp"
#include "Logger.hpp"

namespace Orbital {
    Application::Application()
    {
        Logger::init();
        Logger::info("Orbital initialized...");
    }

    Application::~Application()
    {
        Logger::info("Orbital shutting down...");
    }

    void Application::run()
    {
        Window window(1280, 720, "Orbital Engine");

        while (window.isOpen())
        {
            window.pollEvents();
            window.clear();
            window.display();
        }
    }
}