package org.example.demodoi.Repository;

import org.example.demodoi.Domain.Entity;

public interface ClientRepository<ID, E extends Entity<ID>> extends Repository<ID, E> {
    E getOneByUsername(String username);
}
