#include "sim/SimulationEngine.hpp"
#include "sim/Components.hpp"
#include <spdlog/spdlog.h>

namespace sim {

    SimulationEngine::SimulationEngine() {
        spdlog::info("Simulation Engine Initialized.");
    }

    SimulationEngine::~SimulationEngine() = default;

    void SimulationEngine::initTestScenario() {
        // Create our first spacecraft entity!
        auto entity = registry.create();
        
        registry.emplace<RigidBody>(entity, glm::vec2(0.0f, 0.0f), glm::vec2(0.0f, 0.0f), 150.0f);
        registry.emplace<Thruster>(entity, 50.0f, 500.0f, 300.0f);
        
        auto& computer = registry.emplace<FlightComputer>(entity);
        computer.currentState = AIState::APPROACH;
        computer.targetPosition = glm::vec2(1000.0f, 0.0f); // Asteroid is 1km away

        spdlog::info("Test Spacecraft spawned. Target set to (1000, 0).");
    }

    void SimulationEngine::tick(float dt) {
        updateFlightComputer(dt);
        updatePhysics(dt);
    }

    void SimulationEngine::updateFlightComputer(float /*dt*/) {
        // The "Mind": This system will read the FlightComputer state 
        // and decide when to set Thruster.isFiring = true.
        // We will build this logic tomorrow!
    }

    void SimulationEngine::updatePhysics(float dt) {
        auto view = registry.view<RigidBody, Thruster>();

        for (auto entity : view) {
            auto& body = view.get<RigidBody>(entity);
            auto& thruster = view.get<Thruster>(entity);

            float totalMass = body.dryMass + thruster.propellantMass;

            // F = ma -> a = F/m
            glm::vec2 acceleration(0.0f);
            
            if (thruster.isFiring && thruster.propellantMass > 0.0f) {
                // Calculate thrust force
                glm::vec2 force = thruster.thrustDirection * thruster.maxThrust;
                acceleration = force / totalMass;
                
                // Burn propellant (Simplified linear burn rate for now)
                thruster.propellantMass -= 0.1f * dt; 
                if (thruster.propellantMass < 0.0f) thruster.propellantMass = 0.0f;
            }

            // Semi-Implicit Euler Integration
            body.velocity += acceleration * dt;
            body.position += body.velocity * dt;
        }
    }

} // namespace sim