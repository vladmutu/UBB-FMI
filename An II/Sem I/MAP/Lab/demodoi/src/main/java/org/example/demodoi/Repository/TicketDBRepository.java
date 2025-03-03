package org.example.demodoi.Repository;

import org.example.demodoi.Domain.Ticket;
import org.example.demodoi.Domain.Validators.Validator;

import java.sql.*;
import java.time.LocalDateTime;
import java.util.HashSet;
import java.util.Optional;
import java.util.Set;

public class TicketDBRepository implements TicketRepository<Long, Ticket> {
    private String url;
    private String username;
    private String password;
    private Validator<Ticket> validator;

    public TicketDBRepository(String url, String username, String password, Validator<Ticket> validator) {
        this.url = url;
        this.username = username;
        this.password = password;
        this.validator = validator;
    }

    @Override
    public Optional<Ticket> findOne(Long id) {
        String query = "SELECT * FROM Tickets WHERE id = ?";
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement preparedStatement = connection.prepareStatement(query)
        ) {
            preparedStatement.setLong(1, id);
            ResultSet resultSet = preparedStatement.executeQuery();
            while (resultSet.next()) {
                String username = resultSet.getString("username");
                Long flightId = resultSet.getLong("flightid");
                LocalDateTime purchaseTime = resultSet.getTimestamp("purchasetime").toLocalDateTime();
                Ticket ticket = new Ticket(username, flightId, purchaseTime);
                ticket.setId(id);
                return Optional.of(ticket);
            }
        }catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.empty();
    }

    @Override
    public Iterable<Ticket> findAll() {
        Set<Ticket> tickets = new HashSet<>();
        String query = "SELECT * FROM Tickets";
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement preparedStatement = connection.prepareStatement(query)
        ) {
            ResultSet resultSet = preparedStatement.executeQuery();
            while (resultSet.next()) {
                Long id = resultSet.getLong("id");
                String username = resultSet.getString("username");
                Long flightId = resultSet.getLong("flightid");
                LocalDateTime purchaseTime = resultSet.getTimestamp("purchasetime").toLocalDateTime();
                Ticket ticket = new Ticket(username, flightId, purchaseTime);
                ticket.setId(id);
                tickets.add(ticket);
            }
            return tickets;
        }catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }

    @Override
    public Optional<Ticket> save(Ticket entity) {
        validator.validate(entity);
        String query = "INSERT INTO Tickets(username, flightid, purchasetime) VALUES(?, ?, ?)";
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement preparedStatement = connection.prepareStatement(query)
        ) {
            preparedStatement.setString(1, entity.getUsername());
            preparedStatement.setLong(2, entity.getFlightId());
            preparedStatement.setTimestamp(3, Timestamp.valueOf(entity.getPurchaseTime()));
            preparedStatement.executeUpdate();
            return Optional.empty();
        }catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.of(entity);
    }

    @Override
    public Optional<Ticket> delete(Long aLong) {
        return Optional.empty();
    }

    @Override
    public Optional<Ticket> update(Ticket entity) {
        return Optional.empty();
    }

    @Override
    public Iterable<Ticket> findByClient(String username) {
        String query = "SELECT * FROM Tickets WHERE username = ?";
        Set<Ticket> tickets = new HashSet<>();
        try (Connection connection = DriverManager.getConnection(url, this.username, password);
             PreparedStatement preparedStatement = connection.prepareStatement(query)
        ) {
            preparedStatement.setString(1, username);
            ResultSet resultSet = preparedStatement.executeQuery();
            while (resultSet.next()) {
                Long id = resultSet.getLong("id");
                Long flightId = resultSet.getLong("flightid");
                LocalDateTime purchaseTime = resultSet.getTimestamp("purchasetime").toLocalDateTime();
                Ticket ticket = new Ticket(username, flightId, purchaseTime);
                ticket.setId(id);
                tickets.add(ticket);
            }
            return tickets;
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }
}
