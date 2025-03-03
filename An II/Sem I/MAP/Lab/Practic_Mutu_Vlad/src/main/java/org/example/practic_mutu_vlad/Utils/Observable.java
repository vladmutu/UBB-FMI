package org.example.practic_mutu_vlad.Utils;

import org.example.practic_mutu_vlad.Domain.Entity;

public interface Observable<E extends Entity<Integer>> {
    void addObserver(Observer<E> observer);
    void removeObserver(Observer<E> observer);
    void notifyObservers(E event);
}

