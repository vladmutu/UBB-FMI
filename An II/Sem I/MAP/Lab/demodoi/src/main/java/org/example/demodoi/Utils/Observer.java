package org.example.demodoi.Utils;


import org.example.demodoi.Domain.Entity;

public interface Observer<E extends Entity<Long>> {
    void update(E e);
}
