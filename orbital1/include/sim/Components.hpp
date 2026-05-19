#pragma once
#include <glm/glm.hpp>

namespace sim {

    struct RigidBody {
        glm::vec2 position{0.0f, 0.0f};
        glm::vec2 velocity{0.0f, 0.0f};
        float dryMass = 100.0f;
    };

    struct Thruster {
        float propellantMass = 50.0f;
        float maxThrust = 500.0f;
        float specificImpulse = 300.0f;
        bool isFiring = false; // Fixed typo here
        glm::vec2 thrustDirection{0.0f, 0.0f};
    };

    enum class AIState {
        IDLE,
        APPROACH,
        BRAKE,
        STATION_KEEP
    };

    struct FlightComputer {
        AIState currentState = AIState::IDLE;
        glm::vec2 targetPosition{0.0f, 0.0f}; // This must be exactly here
    };

} // namespace sim