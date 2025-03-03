package org.example.practic_mutu_vlad.Domain.Validators;

import org.example.practic_mutu_vlad.Domain.Driver;

public class DriverValidator implements Validator<Driver> {
    @Override
    public void validate(Driver entity) throws ValidationException {
        if(entity.getName().isEmpty() || entity.getId() == null) {
            throw new ValidationException("Driver is not valid!");
        }
    }
}
