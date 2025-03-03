package org.example.demodoi.Domain.Validators;

import org.example.demodoi.Domain.Client;

public class ClientValidator implements Validator<Client> {
    @Override
    public void validate(Client entity) throws ServiceException {
        if(entity.getName().isEmpty() || entity.getUsername().isEmpty())
            throw new ValidationException("Clientul nu este valid");
    }
}
