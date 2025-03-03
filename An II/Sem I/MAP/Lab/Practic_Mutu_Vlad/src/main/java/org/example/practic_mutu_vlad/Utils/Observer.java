package org.example.practic_mutu_vlad.Utils;

import org.example.practic_mutu_vlad.Domain.Entity;

public interface Observer<E extends Entity<Integer>> {
    void update(E e);
}