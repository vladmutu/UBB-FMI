package org.example.demo1.Domain.Validators;

import org.example.demo1.Domain.User;

public class UserValidator implements Validator<User>{
    @Override
    public void validate(User entity) throws ServiceException {
        if(entity.getEmail().isEmpty() || entity.getName().isEmpty())
            throw new ValidationException("User-ul nu este valid");
    }
}
