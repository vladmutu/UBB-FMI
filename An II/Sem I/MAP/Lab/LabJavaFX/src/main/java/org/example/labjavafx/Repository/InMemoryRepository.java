package org.example.labjavafx.Repository;

import org.example.labjavafx.Domain.Entity;
import org.example.labjavafx.Validators.Validator;

import java.util.HashMap;
import java.util.Map;
import java.util.Optional;

public class InMemoryRepository<ID, E extends Entity<ID>> implements Repository<ID, E> {
    private final Validator<E>validator;
    protected Map<ID, E> entities;

    public InMemoryRepository(Validator<E> v) {
        this.validator = v;
        this.entities = new HashMap<>();
    }

    @Override
    public Optional<E> findOne(ID id) {
        if(id == null) {
            throw new IllegalArgumentException("ID must not be null");
        }
        return Optional.ofNullable(entities.get(id));
    }

    @Override
    public Iterable<E> findAll() {
        return entities.values();
    }

    @Override
    public Optional<E> save(E entity) {
        if(entity == null) {
            throw new IllegalArgumentException("Entity must not be null");
        }
        validator.validate(entity);
        return Optional.ofNullable(entities.put(entity.getId(), entity));
    }

    @Override
    public Optional<E> delete(ID id) {
        if(id == null) {
            throw new IllegalArgumentException("ID must not be null");
        }
        return Optional.ofNullable(entities.remove(id));
    }

    @Override
    public Optional<E> update(E entity) {
        if(entity == null) {
            throw new IllegalArgumentException("Entity must not be null");
        }
        validator.validate(entity);
        if(entities.get(entity.getId()) != null) {
            entities.put(entity.getId(), entity);
            return Optional.empty();
        }
        return Optional.of(entity);
    }
}
