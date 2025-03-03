package org.example.labjavafx.Utils.Observer;

import org.example.labjavafx.Utils.Events.Event;

public interface Observer<E extends Event> {
    void update(E e);
}