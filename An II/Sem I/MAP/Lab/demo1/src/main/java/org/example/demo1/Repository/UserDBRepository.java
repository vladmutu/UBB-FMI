package org.example.demo1.Repository;

import org.example.demo1.Domain.User;
import org.example.demo1.Domain.Validators.Validator;

import javax.naming.ldap.PagedResultsResponseControl;
import java.sql.*;
import java.util.HashSet;
import java.util.Optional;
import java.util.Set;

public class UserDBRepository implements Repository<Integer, User> {
    private String url;
    private String username;
    private String password;
    private Validator<User> validator;

    public UserDBRepository(String url, String username, String password, Validator<User> validator) {
        this.url = url;
        this.username = username;
        this.password = password;
        this.validator = validator;
    }

    @Override
    public Optional<User> findOne(Integer id) {
        String query = "SELECT * FROM users WHERE id = ?";
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement preparedStatement = connection.prepareStatement(query)){
            preparedStatement.setLong(1, id);
            ResultSet resultSet = preparedStatement.executeQuery();
            while(resultSet.next()) {
                String email = resultSet.getString("email");
                String name = resultSet.getString("name");
                User user = new User(email,name);
                user.setId(id);
                return Optional.of(user);
            }
        }catch (SQLException e){
            e.printStackTrace();
        }
        return Optional.empty();
    }

    @Override
    public Iterable<User> findAll() {
        String query = "SELECT * FROM Users";
        Set<User> users = new HashSet<>();
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement preparedStatement = connection.prepareStatement(query)){
            ResultSet resultSet = preparedStatement.executeQuery();
            while (resultSet.next()) {
                Integer id = resultSet.getInt("id");
                String email = resultSet.getString("email");
                String name = resultSet.getString("name");
                User user = new User(email, name);
                user.setId(id);
                users.add(user);
            }
        }catch (SQLException e){
            e.printStackTrace();
        }
        return users;
    }

    @Override
    public Optional<User> save(User entity) {
        return Optional.empty();
    }

    @Override
    public Optional<User> delete(Integer integer) {
        return Optional.empty();
    }

    @Override
    public Optional<User> update(User entity) {
        return Optional.empty();
    }
}
