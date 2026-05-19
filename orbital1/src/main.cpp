#include <spdlog/spdlog.h>
#include "sim/SimulationEngine.hpp"

int main() {
    spdlog::set_level(spdlog::level::debug);
    spdlog::info("Orbital1 booting sequence started.");

    sim::SimulationEngine Engine;
    engine.initTestScenario();

    float fixedDeltaTime = 0.05f;
    
    spdlog::info("running the simmulion loop... ");
    for (int i = 0; i < 100; ++i){
        engine.tick(fixedDeltaTime);
    };

    spdlog::info("orbital simmulation complete shutting down.");
    return 0;
}