package org.example.labjavafx.Repository;

import org.example.labjavafx.Domain.Entity;
import org.example.labjavafx.Domain.Friendship;
import org.example.labjavafx.Utils.Pageable.Page;
import org.example.labjavafx.Utils.Pageable.Pageable;

public interface FriendshipPageRepository<L extends Number, F extends Entity<Long>> extends PagingRepository<Long, Friendship> {
    Page<Friendship> findAllOnPage(Pageable pageable, Long id);
}
