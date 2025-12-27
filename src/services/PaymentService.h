#ifndef PAYMENT_SERVICE_H
#define PAYMENT_SERVICE_H

// Simulates a payment service
class PaymentService {
public:
    bool processPayment() {
        return true; // simulate success
    }

    void rollbackPayment() {
        // simulate refund
    }
};

#endif
