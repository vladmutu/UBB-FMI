package Repository;

import Domain.Prieten;
import Domain.Validators.Validator;
import Repository.Repository;

import java.sql.*;
import java.util.*;

public class PrietenieDBRepository implements Repository<Long, Prieten> {
    private String url;
    private String username;
    private String password;
    private Validator<Prieten> validator;

    public PrietenieDBRepository(String url, String username, String password, Validator<Prieten> validator) {
        this.url = url;
        this.username = username;
        this.password = password;
        this.validator = validator;
    }

    @Override
    public Optional<Prieten> findOne(Long id) {
        String query = "SELECT * FROM friendships WHERE id = ?";
        try (Connection connection = DriverManager.getConnection(url, username, password);
             PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setLong(1, id);
            ResultSet resultSet = statement.executeQuery();
            if (resultSet.next()) {
                Long user_id1 = resultSet.getLong("user1");
                Long user_id2 = resultSet.getLong("user2");

                Prieten prietenie = new Prieten(user_id1, user_id2);
                prietenie.setId(id);
                return Optional.of(prietenie);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.empty();
    }

    @Override
    public Iterable<Prieten> findAll() {
        Set<Prieten> friendships = new HashSet<>();
        try (Connection connection = DriverManager.getConnection(url, username, password);
             PreparedStatement statement = connection.prepareStatement("SELECT * FROM friendships");
             ResultSet resultSet = statement.executeQuery()) {

            while (resultSet.next()) {
                Long id = resultSet.getLong("id");
                Long user_id1 = resultSet.getLong("user1");
                Long user_id2 = resultSet.getLong("user2");

                Prieten prietenie = new Prieten(user_id1, user_id2);
                prietenie.setId(id);
                friendships.add(prietenie);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return friendships;
    }

    @Override
    public Optional<Prieten> save(Prieten entity) {
        validator.validate(entity);
        String query = "INSERT INTO friendships (id, user1, user2) VALUES (?, ?, ?)";
        try (Connection connection = DriverManager.getConnection(url, username, password);
             PreparedStatement statement = connection.prepareStatement(query, Statement.RETURN_GENERATED_KEYS)) {
            statement.setLong(1, entity.getId());
            statement.setLong(2, entity.getUser1ID());
            statement.setLong(3, entity.getUser2ID());

            int result = statement.executeUpdate();
            if (result > 0) {
                try (ResultSet generatedKeys = statement.getGeneratedKeys()) {
                    if (generatedKeys.next()) {
                        entity.setId(generatedKeys.getLong(1));
                    }
                }
                return Optional.empty();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.of(entity);
    }

    @Override
    public Optional<Prieten> delete(Long id) {
        String query = "DELETE FROM friendships WHERE id = ?";
        try (Connection connection = DriverManager.getConnection(url, username, password);
             PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setLong(1, id);
            int result = statement.executeUpdate();
            if (result > 0) return Optional.of(new Prieten(-1L, -1L));
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.empty();
    }

    @Override
    public Optional<Prieten> update(Prieten entity) {
        validator.validate(entity);
        String query = "UPDATE friendships SET user1 = ?, user2 = ? WHERE id = ?";
        try (Connection connection = DriverManager.getConnection(url, username, password);
             PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setLong(1, entity.getUser1ID());
            statement.setLong(2, entity.getUser2ID());
            statement.setLong(3, entity.getId());

            int result = statement.executeUpdate();
            if (result > 0) return Optional.empty();
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.of(entity);
    }
}
