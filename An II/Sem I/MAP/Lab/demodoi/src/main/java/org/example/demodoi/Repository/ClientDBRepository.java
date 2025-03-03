package org.example.demodoi.Repository;

import org.example.demodoi.Domain.Client;
import org.example.demodoi.Domain.Ticket;
import org.example.demodoi.Domain.Validators.Validator;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.util.Optional;

public class ClientDBRepository implements ClientRepository<Long, Client>{
    private String url;
    private String username;
    private String password;
    private Validator<Client> validator;

    public ClientDBRepository(String url, String username, String password, Validator<Client> validator) {
        this.url = url;
        this.username = username;
        this.password = password;
        this.validator = validator;
    }

    @Override
    public Optional<Client> findOne(Long aLong) {
        return Optional.empty();
    }

    @Override
    public Iterable<Client> findAll() {
        return null;
    }

    @Override
    public Optional<Client> save(Client entity) {
        return Optional.empty();
    }

    @Override
    public Optional<Client> delete(Long aLong) {
        return Optional.empty();
    }

    @Override
    public Optional<Client> update(Client entity) {
        return Optional.empty();
    }


    @Override
    public Client getOneByUsername(String username) {
        String query = "SELECT * FROM Clients WHERE username = ?";
        try(Connection connection = DriverManager.getConnection(url, this.username, password);
            PreparedStatement preparedStatement = connection.prepareStatement(query)
        ) {
            preparedStatement.setString(1, username);
            ResultSet resultSet = preparedStatement.executeQuery();
            while (resultSet.next()) {
                Long id = resultSet.getLong("id");
                String username1 = resultSet.getString("username");
                String name = resultSet.getString("name");
                Client client = new Client(username1, name);
                client.setId(id);
                return client;
            }
        }catch (Exception e) {
            e.printStackTrace();
        }
        return null;
    }
}
