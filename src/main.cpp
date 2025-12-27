#include <iostream>
#include "orchestrator/CheckoutOrchestrator.h"

int main() {
    CheckoutOrchestrator orchestrator;

    std::string orderId = "ORDER_001";
    std::string idempotencyKey = "KEY_123";

    bool success = orchestrator.processCheckout(orderId, idempotencyKey);

    if (success)
        std::cout << "Checkout completed successfully.\n";
    else
        std::cout << "Checkout failed.\n";

    return 0;
}
