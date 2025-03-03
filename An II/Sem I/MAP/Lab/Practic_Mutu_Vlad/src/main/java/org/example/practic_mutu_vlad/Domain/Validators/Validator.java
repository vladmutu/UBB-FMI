package org.example.practic_mutu_vlad.Domain.Validators;

public interface Validator<T> {
    void validate(T entity) throws ServiceException;
}
