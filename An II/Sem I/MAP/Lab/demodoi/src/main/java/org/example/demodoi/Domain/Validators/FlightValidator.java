package org.example.demodoi.Domain.Validators;

import org.example.demodoi.Domain.Flight;

public class FlightValidator implements Validator<Flight> {
    @Override
    public void validate(Flight entity) throws ValidationException {
        if(entity.getFrom().isEmpty() || entity.getTo().isEmpty() ||
                entity.getDepartureTime() == null || entity.getLandingTime() == null ||
                entity.getDepartureTime() == null || entity.getSeats() < 0)
            throw new ValidationException("Zborul nu este valid");
    }
}
