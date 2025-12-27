# Distributed Checkout Orchestrator (Mini Saga Engine)

## Overview
This project implements a simplified checkout orchestration engine inspired by
real-world digital purchase systems such as eBooks and subscription platforms.
It coordinates multiple decoupled services using a state-machine-driven Saga
pattern to ensure consistency and reliability in the presence of failures.

The focus of this project is backend system design, transaction handling,
and engineering correctness rather than UI or deployment.

---

## Key Features
- State-machine-based checkout workflow
- Saga pattern with compensating transactions
- Idempotent request handling
- Failure recovery and rollback logic
- Modular, object-oriented C++ design

---

## Architecture
The system consists of:
- CheckoutOrchestrator: coordinates the overall workflow
- PaymentService: handles payment processing and rollback
- InventoryService: manages inventory reservation
- DeliveryService: schedules and cancels delivery

Each service is decoupled and coordinated through the orchestrator.

---

## Technologies Used
- C++
- STL (unordered_map, vector)
- Object-Oriented Design
- In-Memory Data Structures

---

## How to Build and Run

### Build
```bash
g++ src/main.cpp src/orchestrator/CheckoutOrchestrator.cpp -o checkout

