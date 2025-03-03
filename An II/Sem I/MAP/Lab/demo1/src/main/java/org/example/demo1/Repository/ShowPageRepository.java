package org.example.demo1.Repository;

import org.example.demo1.Domain.Entity;
import org.example.demo1.Domain.Show;
import org.example.demo1.Utils.Page;
import org.example.demo1.Utils.Pageable;

public interface ShowPageRepository<N extends Number, S extends Entity<Integer>> extends PagingRepository<Integer, Show> {
    Page<Show> findAllOnPage(Pageable pageable);
    Page<Show> findAllOnPageDesc(Pageable pageable, Integer id);
}
