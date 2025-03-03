package org.example.demodoi.Repository;

import org.example.demodoi.Domain.Entity;

public interface TicketRepository<ID, E extends Entity<ID>> extends Repository<ID, E> {
    Iterable<E> findByClient(String username);
}
