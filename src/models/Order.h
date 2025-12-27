#ifndef ORDER_H
#define ORDER_H

#include <string>
#include "TransactionState.h"

// Order model representing a checkout request
struct Order {
    std::string orderId;
    std::string idempotencyKey;
    TransactionState state;

    // ✅ Default constructor (required by STL containers)
    Order() : state(TransactionState::CREATED) {}

    // Parameterized constructor
    Order(const std::string& id, const std::string& key)
        : orderId(id), idempotencyKey(key), state(TransactionState::CREATED) {}
};

#endif
