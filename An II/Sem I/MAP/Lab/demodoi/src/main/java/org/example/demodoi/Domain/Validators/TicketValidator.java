package org.example.demodoi.Domain.Validators;

import org.example.demodoi.Domain.Ticket;

public class TicketValidator implements Validator<Ticket> {
    @Override
    public void validate(Ticket entity) throws ValidationException {
        if(entity.getFlightId() < 0 || entity.getUsername().isEmpty() || entity.getPurchaseTime() == null)
            throw new ValidationException("Biletul nu este valid");

    }
}
