#ifndef TRANSACTION_STATE_H
#define TRANSACTION_STATE_H

// Represents the lifecycle of a checkout transaction
enum class TransactionState {
    CREATED,
    PAYMENT_COMPLETED,
    INVENTORY_RESERVED,
    DELIVERY_SCHEDULED,
    COMPLETED,
    FAILED
};

#endif
