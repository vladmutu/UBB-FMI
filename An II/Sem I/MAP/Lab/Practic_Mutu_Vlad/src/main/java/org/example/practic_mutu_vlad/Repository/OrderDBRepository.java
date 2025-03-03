package org.example.practic_mutu_vlad.Repository;

import org.example.practic_mutu_vlad.Domain.Order;
import org.example.practic_mutu_vlad.Domain.Validators.Validator;
import org.example.practic_mutu_vlad.Utils.Status;

import java.sql.*;
import java.time.LocalDateTime;
import java.util.HashSet;
import java.util.Optional;
import java.util.Set;

public class OrderDBRepository implements Repository<Integer, Order>{
    private String url;
    private String username;
    private String password;
    private Validator<Order> validator;

    public OrderDBRepository(String url, String username, String password, Validator<Order> validator) {
        this.url = url;
        this.username = username;
        this.password = password;
        this.validator = validator;
    }

    @Override
    public Optional<Order> findOne(Integer integer) {
        return Optional.empty();
    }

    @Override
    public Iterable<Order> findAll() {
        String query = "SELECT * FROM Orders";
        Set<Order> orders = new HashSet<>();
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement preparedStatement = connection.prepareStatement(query)) {
            ResultSet resultSet = preparedStatement.executeQuery();
            while (resultSet.next()) {
                Integer id = resultSet.getInt("id");
                Integer driverId = resultSet.getInt("driverid");
                Integer aux = resultSet.getInt("status");
                Status status;
                if(aux == 1) {
                    status = Status.PENDING;
                }
                else if(aux == 2) {
                    status = Status.IN_PROGRESS;
                }
                else {
                    status = Status.FINISHED;
                }
                LocalDateTime startDate = resultSet.getTimestamp("startdate").toLocalDateTime();
                Timestamp endDateAux = resultSet.getTimestamp("enddate");
                LocalDateTime endDate;
                if(endDateAux == null) {
                    endDate = null;
                }
                else {
                    endDate = endDateAux.toLocalDateTime();
                }
                String pickupAddress = resultSet.getString("pickupaddress");
                String destinationAddress = resultSet.getString("destinationaddress");
                String clientName = resultSet.getString("clientname");
                Order order = new Order(driverId, status, startDate, endDate, pickupAddress, destinationAddress, clientName);
                order.setId(id);
                orders.add(order);
            }
        }catch (SQLException e) {
            e.printStackTrace();
        }
        return orders;
    }

    @Override
    public Optional<Order> save(Order entity) {
        validator.validate(entity);
        String query = "INSERT INTO Orders(driverid, status, startdate, enddate, pickupaddress, destinationaddress, clientname) VALUES(?, ?, ?, ?, ?, ?, ?)";
        String query2 = "SELECT MAX(id) FROM Orders";
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement preparedStatement = connection.prepareStatement(query)) {
            preparedStatement.setInt(1, entity.getDriverId());
            switch (entity.getStatus()) {
                case PENDING -> preparedStatement.setInt(2, 1);
                case IN_PROGRESS -> preparedStatement.setInt(2, 2);
                case FINISHED -> preparedStatement.setInt(2, 3);
            }
            preparedStatement.setTimestamp(3, Timestamp.valueOf(entity.getStartDate()));
            preparedStatement.setNull(4, Types.TIMESTAMP);
            preparedStatement.setString(5, entity.getPickupAddress());
            preparedStatement.setString(6, entity.getDestinationAddress());
            preparedStatement.setString(7, entity.getClientName());
            preparedStatement.executeUpdate();
            PreparedStatement preparedStatement2 = connection.prepareStatement(query2);
            ResultSet resultSet = preparedStatement2.executeQuery();
            while(resultSet.next()) {
                entity.setId(resultSet.getInt(1));
            }
            return Optional.of(entity);
        }
        catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.empty();
    }

    @Override
    public Optional<Order> delete(Integer integer) {
        return Optional.empty();
    }

    @Override
    public Optional<Order> update(Order entity) {
        String query = "UPDATE Orders SET driverid = ?, status = ?, startdate = ?, enddate = ?, pickupaddress = ?, destinationaddress = ?, clientname = ? WHERE id = ?";
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement preparedStatement = connection.prepareStatement(query)) {
            preparedStatement.setInt(1, entity.getDriverId());
            switch (entity.getStatus()) {
                case PENDING -> preparedStatement.setInt(2, 1);
                case IN_PROGRESS -> preparedStatement.setInt(2, 2);
                case FINISHED -> preparedStatement.setInt(2, 3);
            }
            preparedStatement.setTimestamp(3, Timestamp.valueOf(entity.getStartDate()));
            preparedStatement.setNull(4, Types.TIMESTAMP);
            preparedStatement.setString(5, entity.getPickupAddress());
            preparedStatement.setString(6, entity.getDestinationAddress());
            preparedStatement.setString(7, entity.getClientName());
            preparedStatement.setInt(8, entity.getId());
            preparedStatement.executeUpdate();
        }
        catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.empty();
    }
}
