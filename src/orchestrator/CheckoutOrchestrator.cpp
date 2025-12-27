#include "CheckoutOrchestrator.h"

// Rollback logic for failed transactions
void CheckoutOrchestrator::compensate(Order& order) {
    if (order.state >= TransactionState::DELIVERY_SCHEDULED)
        deliveryService.cancelDelivery();

    if (order.state >= TransactionState::INVENTORY_RESERVED)
        inventoryService.releaseInventory();

    if (order.state >= TransactionState::PAYMENT_COMPLETED)
        paymentService.rollbackPayment();

    order.state = TransactionState::FAILED;
}

// Main checkout flow
bool CheckoutOrchestrator::processCheckout(const std::string& orderId,
                                           const std::string& idempotencyKey) {
    // Idempotency check
    if (processedOrders.count(idempotencyKey)) {
        return processedOrders[idempotencyKey].state == TransactionState::COMPLETED;
    }

    Order order(orderId, idempotencyKey);

    if (!paymentService.processPayment()) {
        compensate(order);
        return false;
    }
    order.state = TransactionState::PAYMENT_COMPLETED;

    if (!inventoryService.reserveInventory()) {
        compensate(order);
        return false;
    }
    order.state = TransactionState::INVENTORY_RESERVED;

    if (!deliveryService.scheduleDelivery()) {
        compensate(order);
        return false;
    }
    order.state = TransactionState::DELIVERY_SCHEDULED;

    order.state = TransactionState::COMPLETED;
    processedOrders[idempotencyKey] = order;

    return true;
}
