package org.example.practic_mutu_vlad.Domain.Validators;

public class ValidationException extends RuntimeException {
    public ValidationException(String message) {
        super(message);
    }
}
