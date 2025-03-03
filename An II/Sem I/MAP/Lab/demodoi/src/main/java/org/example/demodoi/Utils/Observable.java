package org.example.demodoi.Utils;

import org.example.demodoi.Domain.Entity;

public interface Observable<E extends Entity<Long>> {
    void addObserver(Observer<E> observer);
    void removeObserver(Observer<E> observer);
    void notifyObservers(E event);
}
