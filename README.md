# orbital
## Autonomous Swarm Robotics Operating System

orbital is a distributed swarm robotics mission-control platform designed for managing autonomous agricultural robots over WiFi networks.

The system provides:
- real-time swarm telemetry
- mission assignment
- robot fleet management
- live ESP32 camera streaming
- OTA firmware deployment
- zone monitoring
- emergency control systems
- mission scripting through `.orbital` files

orbital is engineered as:
- a robotics infrastructure platform
- a distributed systems project
- an advanced modern C++ backend engine
- a real-time telemetry dashboard
- a foundation for future autonomous agricultural robotics

---

# Vision

Modern agriculture will increasingly depend on:
- autonomous robotic fleets
- precision farming
- distributed sensor systems
- intelligent mission scheduling
- live telemetry infrastructure

orbital explores how decentralized robotic systems can coordinate, monitor, and execute agricultural tasks efficiently through a scalable mission-control architecture.

---

# Core Features

# Swarm Mission Control

Manage multiple robots simultaneously:
- assign missions
- monitor status
- coordinate tasks
- deploy updates
- track positions live

---

# Real-Time Telemetry

Each robot streams:
- coordinates
- battery status
- WiFi signal strength
- current task
- temperature
- uptime
- mission progress

---

# Live Swarm Map

Visualize:
- robot positions
- movement trails
- active zones
- restricted zones
- mission regions

---

# Emergency Control System

Industrial-grade safety controls:
- global emergency stop
- robot isolation
- connection monitoring
- out-of-zone alerts
- mission abort system

---

# OTA Update System

Push updates simultaneously to all robots:
- firmware updates
- mission scripts
- configuration changes
- networking settings

---

# ESP32 Camera Streaming

Each robot can stream:
- live field video
- navigation feed
- operational monitoring

via:
- WiFi
- MJPEG streams
- browser dashboard

---

# `.orbital` Mission Files

Custom mission scripting language.

Example:

```orbital
MISSION FieldAlpha

ZONE NORTH_FIELD
BOUNDS 0 0 100 100

ROBOT orbital-01
TASK PLANT
TARGET NORTH_FIELD

ROBOT orbital-02
TASK WEED_REMOVE
TARGET NORTH_FIELD
```

Mission files allow:
- reusable swarm operations
- automation
- fleet coordination
- reproducible tasks

---

# System Architecture

```text
                ┌────────────────────┐
                │ Browser Dashboard  │
                │ React + Tailwind   │
                └─────────┬──────────┘
                          │
                    WebSockets
                          │
                ┌─────────▼──────────┐
                │  orbital C++ Engine│
                │ Mission Runtime    │
                │ Swarm Controller   │
                │ Telemetry Core     │
                └─────────┬──────────┘
                          │
                     WiFi / LAN
                          │
       ┌───────────────────┼───────────────────┐
       │                   │                   │
 ┌─────▼─────┐      ┌─────▼─────┐      ┌─────▼─────┐
 │ orbital-01│      │ orbital-02│      │ orbital-03│
 │ ESP32 Bot │      │ ESP32 Bot │      │ ESP32 Bot │
 └───────────┘      └───────────┘      └───────────┘
```

---

# Technology Stack

# Backend Engine
- C++20
- WebSockets
- EnTT ECS
- CrowCPP / Drogon
- multithreading
- JSON serialization

---

# Frontend Dashboard
- React
- TypeScript
- TailwindCSS
- Vite

---

# Firmware
- ESP32
- PlatformIO
- AsyncTCP
- ESPAsyncWebServer

---

# Networking
- WiFi LAN
- WebSockets
- OTA update pipeline

---

# Advanced Engineering Concepts

orbital is designed to teach and demonstrate:

## Systems Programming
- distributed systems
- asynchronous networking
- multithreading
- telemetry infrastructure

## Advanced C++
- ECS architecture
- RAII
- move semantics
- smart pointers
- serialization
- concurrency

## Robotics Infrastructure
- mission coordination
- robot fleet management
- fail-safe systems
- OTA firmware deployment

---

# Repository Structure

```text
orbital/
├── backend/
├── frontend/
├── firmware/
├── missions/
├── simulations/
├── docs/
├── tests/
└── assets/
```

---

# Current MVP Scope

The first production milestone includes:

✅ swarm dashboard  
✅ robot tracking  
✅ WebSocket communication  
✅ mission assignment  
✅ `.orbital` parser  
✅ telemetry visualization  
✅ emergency stop system  
✅ OTA updates  
✅ ESP32 connectivity  
✅ live camera streams  

---

# NOT Included In MVP

To avoid overengineering, the MVP intentionally excludes:

❌ AI weed detection  
❌ SLAM mapping  
❌ ROS2 integration  
❌ advanced autonomy  
❌ cloud infrastructure  
❌ machine learning  
❌ drone coordination  

These systems may be explored in future versions.

---

# Installation

# Backend

## Requirements

### Arch Linux

```bash
sudo pacman -S cmake ninja gcc git gdb ccache
```

---

# Clone Repository

```bash
git clone https://github.com/yourusername/orbital.git
cd orbital
```

---

# Build Backend

```bash
mkdir build
cd build

cmake -G Ninja ..
ninja
```

---

# Run Backend

```bash
./orbital-engine
```

---

# Frontend Setup

```bash
cd frontend

npm install
npm run dev
```

Frontend runs at:

```text
http://localhost:5173
```

---

# ESP32 Firmware

## Robot Core

```bash
cd firmware/robot-core
pio run
pio run --target upload
```

---

# Development Goals

# Phase 1
Core engine + dashboard

# Phase 2
Networking + telemetry

# Phase 3
Mission runtime + parser

# Phase 4
Swarm coordination

# Phase 5
OTA + live streams

# Phase 6
Simulation and replay system

---

# Why This Project Exists

orbital is designed to explore how low-cost robotics infrastructure can improve:
- precision agriculture
- automation accessibility
- autonomous farming systems
- distributed robotics coordination

especially in environments where scalable industrial robotics systems remain inaccessible.

---

# Long-Term Vision

Future versions may include:
- AI crop analysis
- autonomous navigation
- computer vision
- swarm intelligence
- ROS2 interoperability
- cloud mission synchronization
- GPS-assisted geofencing
- autonomous charging systems

---

# Engineering Philosophy

orbital is not designed as:
- a toy robot controller
- a basic IoT dashboard
- a simple ESP32 app

It is designed as:
- robotics infrastructure
- mission-control software
- a scalable distributed systems platform

The robots are replaceable.

The infrastructure is the product.

---

# Screenshots

> Screenshots, diagrams, telemetry views, and robot demonstrations will be added as development progresses.

---

# Contributing

Contributions, feedback, and architecture discussions are welcome.

---

# License

MIT License

---

# Author

Developed by Ibrahim under Version Extreme Cooperation.

Focused on:
- robotics
- distributed systems
- agricultural automation
- embedded systems
- swarm intelligence
- autonomous infrastructure
