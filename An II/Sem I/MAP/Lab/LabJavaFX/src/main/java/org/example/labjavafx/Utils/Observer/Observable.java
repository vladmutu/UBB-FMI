package org.example.labjavafx.Utils.Observer;

import org.example.labjavafx.Utils.Events.Event;

public interface Observable<E extends Event> {
    void addObserver(Observer<E> observer);
    void removeObserver(Observer<E> observer);
    void notifyObservers(E event);
}
