package org.example.labjavafx.Repository;

import org.example.labjavafx.Domain.Entity;
import org.example.labjavafx.Utils.Pageable.Page;
import org.example.labjavafx.Utils.Pageable.Pageable;

public interface PagingRepository<ID, E extends Entity<ID>> extends Repository<ID,E> {
    Page<E> findAllOnPage(Pageable pageable, ID id);
}
