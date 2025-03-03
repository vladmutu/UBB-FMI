package Domain.Validators;


import Domain.Utilizator;

public class UtilizatorValidator implements Validator<Utilizator> {
    @Override
    public void validate(Utilizator entity) throws ServiceException {
        //TODO: implement method validate
        if(entity.getFirstName().isEmpty() || entity.getLastName().isEmpty())
            throw new ValidationException("Utilizatorul nu este valid");
    }
}
