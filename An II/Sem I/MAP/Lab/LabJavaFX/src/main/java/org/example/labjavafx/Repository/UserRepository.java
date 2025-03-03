package org.example.labjavafx.Repository;

import org.example.labjavafx.Domain.User;
import org.example.labjavafx.Validators.Validator;

public class UserRepository extends AbstractFileRepository<Long, User>{
    public UserRepository(Validator<User> validator,String filename) {
        super(validator,filename);
    }

    @Override
    public User lineToEntity(String line) {
        String[] splitted = line.split(";");
        User u = new User(splitted[1], splitted[2], splitted[3], splitted[4]);
        u.setId(Long.parseLong(splitted[0]));
        return u;
    }

    @Override
    public String entityToLine(User u) {
        return u.getId() + ";" + u.getFirstName() + ";" + u.getLastName();
    }
}
