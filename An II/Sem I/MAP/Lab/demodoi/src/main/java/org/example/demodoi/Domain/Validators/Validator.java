package org.example.demodoi.Domain.Validators;

public interface Validator <T> {
    void validate(T entity) throws ValidationException;
}