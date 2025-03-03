package org.example.practic_mutu_vlad.Domain.Validators;

import org.example.practic_mutu_vlad.Domain.Order;

public class OrderValidator implements Validator<Order> {
    @Override
    public void validate(Order entity) throws ValidationException {
         if(entity.getStatus() == null) {
             throw new ValidationException("Order is not valid!");
         }
    }
}
