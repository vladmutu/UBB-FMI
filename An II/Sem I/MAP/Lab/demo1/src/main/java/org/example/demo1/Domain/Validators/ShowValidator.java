package org.example.demo1.Domain.Validators;

import org.example.demo1.Domain.Show;

public class ShowValidator implements Validator<Show>{
    @Override
    public void validate(Show entity) throws ServiceException {
        if(entity.getName().isEmpty() || entity.getCreationDate() == null ||
                entity.getStartDate() == null || entity.getDurationMinutes() < 1 || entity.getNumberOfSeats() < 1)
            throw new ValidationException("Show-ul nu este valid");
    }
}
