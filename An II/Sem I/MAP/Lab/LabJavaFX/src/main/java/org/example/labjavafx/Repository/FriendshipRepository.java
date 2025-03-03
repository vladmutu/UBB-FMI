package org.example.labjavafx.Repository;

import org.example.labjavafx.Domain.Friendship;
import org.example.labjavafx.Validators.Validator;

import java.time.LocalDateTime;
import java.util.Formatter;

public class FriendshipRepository extends AbstractFileRepository<Long, Friendship> {
    public FriendshipRepository(Validator<Friendship> validator, String filename) {
        super(validator, filename);
    }

    @Override
    public Friendship lineToEntity(String line) {
        String[] splitted = line.split(";");
        Friendship f = new Friendship(Long.parseLong(splitted[1]), Long.parseLong(splitted[2]), LocalDateTime.parse(splitted[3]));
        f.setId(Long.parseLong(splitted[0]));
        f.setPending(Boolean.parseBoolean(splitted[4]));
        return f;
    }

    @Override
    public String entityToLine(Friendship f) {
        return f.getId() + ";" + f.getId1() + ";" + f.getId2() + ";" + f.getDate() + ";" + f.isPending();
    }
}
