#pragma once
#include <entt/entt.hpp>

namespace sim {
    class SimulationEngine {
        public:
            SimulationEngine();
            ~SimulationEngine();

            void initTestScenario();
            void tick(float dt);

        private:
            entt::registry registry;

            void updatePhysics(float dt);
            void updateFlightComputer(float dt);
    };
}