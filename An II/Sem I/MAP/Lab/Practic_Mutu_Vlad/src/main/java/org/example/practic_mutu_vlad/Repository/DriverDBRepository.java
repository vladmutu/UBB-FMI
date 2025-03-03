package org.example.practic_mutu_vlad.Repository;

import org.example.practic_mutu_vlad.Domain.Driver;
import org.example.practic_mutu_vlad.Domain.Validators.Validator;

import java.sql.*;
import java.util.HashSet;
import java.util.Optional;
import java.util.Set;

public class DriverDBRepository implements Repository<Integer, Driver> {
    private String url;
    private String username;
    private String password;
    private Validator<Driver> validator;

    public DriverDBRepository(String url, String username, String password, Validator<Driver> validator) {
        this.url = url;
        this.username = username;
        this.password = password;
        this.validator = validator;
    }

    @Override
    public Optional<Driver> findOne(Integer integer) {
        return Optional.empty();
    }

    @Override
    public Iterable<Driver> findAll() {
        String query = "SELECT * FROM Drivers";
        Set<Driver> drivers = new HashSet<>();
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement preparedStatement = connection.prepareStatement(query))
        {
            ResultSet resultSet = preparedStatement.executeQuery();
            while(resultSet.next()){
                Integer id = resultSet.getInt("id");
                String name = resultSet.getString("name");
                Driver driver = new Driver(name);
                driver.setId(id);
                drivers.add(driver);
            }
            return drivers;
        }catch (SQLException e){
            e.printStackTrace();
        }
        return null;
    }

    @Override
    public Optional<Driver> save(Driver entity) {
        return Optional.empty();
    }

    @Override
    public Optional<Driver> delete(Integer integer) {
        return Optional.empty();
    }

    @Override
    public Optional<Driver> update(Driver entity) {
        return Optional.empty();
    }
}
