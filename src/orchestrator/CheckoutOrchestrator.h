#ifndef CHECKOUT_ORCHESTRATOR_H
#define CHECKOUT_ORCHESTRATOR_H

#include <unordered_map>
#include <string>
#include "../models/Order.h"
#include "../services/PaymentService.h"
#include "../services/InventoryService.h"
#include "../services/DeliveryService.h"

// Central orchestration engine
class CheckoutOrchestrator {
private:
    std::unordered_map<std::string, Order> processedOrders;

    PaymentService paymentService;
    InventoryService inventoryService;
    DeliveryService deliveryService;

    void compensate(Order& order);

public:
    bool processCheckout(const std::string& orderId,
                         const std::string& idempotencyKey);
};

#endif
