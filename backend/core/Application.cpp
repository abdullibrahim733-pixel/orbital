#include "Application.hpp"
#include "Window.hpp"
#include "Logger.hpp"

// Define member functions with fully-qualified names to ensure the
// Application symbol is resolved even if namespaces in the header differ.
Orbital::Application::Application()
{
    Logger::init();
    Logger::info("Orbital initialized...");
}

    Orbital::Application::~Application()
{
    Logger::info("Orbital shutting down...");
}

void Orbital::Application::run()
{
    Window window(1280, 720, "Orbital Engine");

    while (window.isOpen())
    {
        window.pollEvents();
        window.clear();
        window.display();
    }
}