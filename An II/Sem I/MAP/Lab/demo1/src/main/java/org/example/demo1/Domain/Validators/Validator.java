package org.example.demo1.Domain.Validators;

public interface Validator<T> {
    void validate(T entity) throws ServiceException;
}
