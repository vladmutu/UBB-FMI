package org.example.demo1.Repository;

import org.example.demo1.Domain.Entity;
import org.example.demo1.Utils.Page;
import org.example.demo1.Utils.Pageable;

public interface PagingRepository<ID, E extends Entity<ID>> extends Repository<ID,E> {
    Page<E> findAllOnPage(Pageable pageable);
}
