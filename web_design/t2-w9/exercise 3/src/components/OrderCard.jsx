import React from "react";

export default function OrderCard({ order, onUpdateQuantity }) {
  function handleDecrement() {
    if (order.quantity > 0) {
      onUpdateQuantity(order.product, order.quantity - 1);
    }
  }

  function handleIncrement() {
    onUpdateQuantity(order.product, order.quantity + 1);
  }

  return (
    <div className="order">
      <div>
        <h4>{order.product}</h4>
        <small>${order.price.toFixed(2)}</small>
      </div>

      <div className="order-quantity">
        <div className="order-button" onClick={handleDecrement}>-</div>
        <h4>{order.quantity}</h4>
        <div className="order-button" onClick={handleIncrement}>+</div>
      </div>
    </div>
  );
}
