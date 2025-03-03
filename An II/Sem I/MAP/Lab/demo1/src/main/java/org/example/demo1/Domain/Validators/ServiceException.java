package org.example.demo1.Domain.Validators;

public class ServiceException extends RuntimeException {
    public ServiceException(String message) {
        super(message);
    }
}
