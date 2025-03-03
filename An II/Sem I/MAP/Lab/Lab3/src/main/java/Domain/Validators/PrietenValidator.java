package Domain.Validators;

import Domain.Prieten;

public class PrietenValidator implements Validator<Prieten> {
    @Override
    public void validate(Prieten entity) throws ServiceException {
        if (entity.getUser1ID() == null || entity.getUser2ID() == null) {
            throw new ValidationException("Id-ul nu poate fi null");
        }
        if (entity.getUser1ID().equals(entity.getUser2ID())) {
            throw new ValidationException("Id-urile trebuie sa fie diferite");
        }
    }
}
