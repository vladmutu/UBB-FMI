package org.example.demodoi.Repository;

import org.example.demodoi.Domain.Flight;
import org.example.demodoi.Domain.Ticket;
import org.example.demodoi.Domain.Validators.Validator;

import java.sql.*;
import java.time.LocalDateTime;
import java.util.HashSet;
import java.util.Optional;
import java.util.Set;

public class FlightDBRepository implements Repository<Long, Flight> {
    private String url;
    private String username;
    private String password;
    private Validator<Flight> validator;

    public FlightDBRepository(String url, String username, String password, Validator<Flight> validator) {
        this.url = url;
        this.username = username;
        this.password = password;
        this.validator = validator;
    }

    @Override
    public Optional<Flight> findOne(Long id) {
        String query = "SELECT * FROM Flights WHERE id = ?";
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement preparedStatement = connection.prepareStatement(query)
        ) {
            preparedStatement.setLong(1, id);
            ResultSet resultSet = preparedStatement.executeQuery();
            while (resultSet.next()) {
                String from = resultSet.getString("from");
                String to = resultSet.getString("to");
                LocalDateTime departureTime = resultSet.getTimestamp("departuretime").toLocalDateTime();
                LocalDateTime arrivalTime = resultSet.getTimestamp("arrivaltime").toLocalDateTime();
                int seats = resultSet.getInt("seats");
                Flight flight = new Flight(from, to, departureTime, arrivalTime, seats);
                flight.setId(id);
                return Optional.of(flight);
            }
        }catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.empty();
    }

    @Override
    public Iterable<Flight> findAll() {
        Set<Flight> flights = new HashSet<>();
        String query = "SELECT * FROM Flights";
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement preparedStatement = connection.prepareStatement(query)
        ) {
            ResultSet resultSet = preparedStatement.executeQuery();
            while (resultSet.next()) {
                Long id = resultSet.getLong("id");
                String from = resultSet.getString("from");
                String to = resultSet.getString("to");
                LocalDateTime departureDate = resultSet.getTimestamp("departuretime").toLocalDateTime();
                LocalDateTime arrivalDate = resultSet.getTimestamp("landingtime").toLocalDateTime();
                int seats = resultSet.getInt("seats");
                Flight flight = new Flight(from, to, departureDate, arrivalDate, seats);
                flight.setId(id);
                flights.add(flight);
            }
            return flights;
        }catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }

    @Override
    public Optional<Flight> save(Flight entity) {
        return Optional.empty();
    }

    @Override
    public Optional<Flight> delete(Long aLong) {
        return Optional.empty();
    }

    @Override
    public Optional<Flight> update(Flight entity) {
        return Optional.empty();
    }
}
