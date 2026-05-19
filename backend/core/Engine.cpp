#include "sim/SimulationEngine.hpp"
#include "sim/Components.hpp"
#include <spdlog/spdlog.h>

namespace sim {
    SimulationEngine::SimulationEngine() {
        spdlog::info("Simulation Engine Initialized.");
    }

    SimulationEngine::~SimulationEngine() = default;

    void SimulationEngine::initTestScenario() {
        auto entity = registry.create();
        registry.emplace<RigidBody>(entity, glm::vec2(0.0f, 0.0f), glm::vec2(0.0f, 0.0f), 150.0f);
        registry.emplace<Thruster>(entity, 50.0f, 500.0f, 300.0f, false, glm::vec2(1.0f, 0.0f));
        
        auto& computer = registry.emplace<FlightComputer>(entity);
        computer.currentState = AIState::APPROACH;
        computer.targetPosition = glm::vec2(1000.0f, 0.0f); 

        spdlog::info("Test Spacecraft spawned. Target set to (1000, 0).");
    }

    void SimulationEngine::tick(float dt) {
        updateFlightComputer(dt);
        updatePhysics(dt);
    }

    void SimulationEngine::updateFlightComputer(float /*dt*/) {
        // Logic will be expanded tomorrow
    }

    void SimulationEngine::updatePhysics(float dt) {
        auto view = registry.view<RigidBody, Thruster>();
        for (auto entity : view) {
            auto& body = view.get<RigidBody>(entity);
            auto& thruster = view.get<Thruster>(entity);

            if (thruster.isFiring && thruster.propellantMass > 0.0f) {
                float totalMass = body.dryMass + thruster.propellantMass;
                glm::vec2 force = thruster.thrustDirection * thruster.maxThrust;
                glm::vec2 acceleration = force / totalMass;
                
                body.velocity += acceleration * dt;
                thruster.propellantMass -= 0.1f * dt; 
            }
            body.position += body.velocity * dt;
        }
    }
}