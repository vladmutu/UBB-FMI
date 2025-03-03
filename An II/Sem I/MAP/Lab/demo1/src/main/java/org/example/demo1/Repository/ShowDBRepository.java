package org.example.demo1.Repository;

import org.example.demo1.Domain.Show;
import org.example.demo1.Domain.Validators.Validator;
import org.example.demo1.Utils.Page;
import org.example.demo1.Utils.Pageable;

import java.sql.*;
import java.time.LocalDateTime;
import java.util.*;

public class ShowDBRepository implements ShowPageRepository<Integer, Show> {
    private String url;
    private String username;
    private String password;
    private Validator<Show> validator;

    public ShowDBRepository(String url, String username, String password, Validator<Show> validator) {
        this.url = url;
        this.username = username;
        this.password = password;
        this.validator = validator;
    }

    @Override
    public Page<Show> findAllOnPage(Pageable pageable) {
        List<Show> shows = new ArrayList<>();
        String query = "SELECT * FROM Shows ORDER BY startDate LIMIT ? OFFSET ?";
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setInt(1, pageable.getPageSize());
            statement.setInt(2, pageable.getPageSize() * pageable.getPageNumber());
            ResultSet resultSet = statement.executeQuery();
            while(resultSet.next()) {
                Integer idAux = resultSet.getInt("id");
                String name = resultSet.getString("name");
                Integer durationMinutes = resultSet.getInt("durationminutes");
                Timestamp startDateAux = resultSet.getTimestamp("startdate");
                LocalDateTime startDate = startDateAux.toLocalDateTime();
                Integer numberOfSeats = resultSet.getInt("numberofseats");
                Timestamp creationDateAux = resultSet.getTimestamp("creationdate");
                LocalDateTime creationDate = creationDateAux.toLocalDateTime();
                Show show = new Show(name, durationMinutes, startDate, numberOfSeats, creationDate);
                show.setId(idAux);
                shows.add(show);
            }

            return new Page<>(shows, shows.size());
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }

    @Override
    public Page<Show> findAllOnPageDesc(Pageable pageable, Integer id) {
        List<Show> shows = new ArrayList<>();
        String query = "SELECT * FROM Shows ORDER BY creationdate DESC LIMIT ? OFFSET ?";
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setInt(1, pageable.getPageSize());
            statement.setInt(2, pageable.getPageSize() * pageable.getPageNumber());
            ResultSet resultSet = statement.executeQuery();
            while(resultSet.next()) {
                Integer idAux = resultSet.getInt("id");
                String name = resultSet.getString("name");
                Integer durationMinutes = resultSet.getInt("durationminutes");
                Timestamp startDateAux = resultSet.getTimestamp("startdate");
                LocalDateTime startDate = startDateAux.toLocalDateTime();
                Integer numberOfSeats = resultSet.getInt("numberofseats");
                Timestamp creationDateAux = resultSet.getTimestamp("creationdate");
                LocalDateTime creationDate = creationDateAux.toLocalDateTime();
                Show show = new Show(name, durationMinutes, startDate, numberOfSeats, creationDate);
                show.setId(idAux);
                shows.add(show);
            }

            return new Page<>(shows, shows.size());
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return null;
    }

    @Override
    public Optional<Show> findOne(Integer id) {
        String query = "SELECT * FROM Shows WHERE id = ?";
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setInt(1, id);
            ResultSet resultSet = statement.executeQuery();
            if(resultSet.next()) {
                Integer auxid = resultSet.getInt("id");
                String name = resultSet.getString("name");
                Integer durationMinutes = resultSet.getInt("durationminutes");
                Timestamp startDateAux = resultSet.getTimestamp("startdate");
                LocalDateTime startDate = startDateAux.toLocalDateTime();
                Integer numberOfSeats = resultSet.getInt("numberofseats");
                Timestamp creationDateAux = resultSet.getTimestamp("creationdate");
                LocalDateTime creationDate = creationDateAux.toLocalDateTime();
                Show show = new Show(name, durationMinutes, startDate, numberOfSeats, creationDate);
                show.setId(auxid);
                return Optional.of(show);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.empty();
    }

    @Override
    public Iterable<Show> findAll() {
        String query = "SELECT * FROM Shows ORDER BY startdate";
        Set<Show> shows = new HashSet<>();
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement statement = connection.prepareStatement(query);
            ResultSet resultSet = statement.executeQuery()) {
            while(resultSet.next()) {
                Integer id = resultSet.getInt("id");
                String name = resultSet.getString("name");
                Integer durationMinutes = resultSet.getInt("durationminutes");
                Timestamp startDateAux = resultSet.getTimestamp("startdate");
                LocalDateTime startDate = startDateAux.toLocalDateTime();
                Integer numberOfSeats = resultSet.getInt("numberofseats");
                Timestamp creationDateAux = resultSet.getTimestamp("creationdate");
                LocalDateTime creationDate = creationDateAux.toLocalDateTime();
                Show show = new Show(name, durationMinutes, startDate, numberOfSeats, creationDate);
                show.setId(id);
                shows.add(show);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return shows;
    }

    @Override
    public Optional<Show> save(Show entity) {
        validator.validate(entity);
        String query = "INSERT INTO Shows(name, durationminutes, startdate, numberofseats, creationdate) VALUES(?, ?, ?, ?, ?)";
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement preparedStatement = connection.prepareStatement(query)
        ){
            preparedStatement.setString(1, entity.getName());
            preparedStatement.setInt(2, entity.getDurationMinutes());
            preparedStatement.setTimestamp(3, Timestamp.valueOf(entity.getStartDate()));
            preparedStatement.setInt(4, entity.getNumberOfSeats());
            preparedStatement.setTimestamp(5, Timestamp.valueOf(entity.getCreationDate()));
            int result = preparedStatement.executeUpdate();
            if (result > 0) {
                try (ResultSet generatedKeys = preparedStatement.getGeneratedKeys()) {
                    if (generatedKeys.next()) {
                        entity.setId(generatedKeys.getInt(1));
                    }
                }
                return Optional.empty();
            }
        }catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.empty();
    }



    @Override
    public Optional<Show> delete(Integer integer) {
        return Optional.empty();
    }


    @Override
    public Optional<Show> update(Show entity) {
        String query1 = "SELECT numberofseats FROM Shows WHERE id = ?";
        String query2 = "UPDATE Shows SET numberofseats = ? WHERE id = ?";
        try(Connection connection = DriverManager.getConnection(url, username, password);
            PreparedStatement statement1 = connection.prepareStatement(query1);
            PreparedStatement statement2 = connection.prepareStatement(query2)) {
            statement1.setInt(1, entity.getId());
            ResultSet resultSet = statement1.executeQuery();
            if(resultSet.next()) {
                Integer numberofseats = resultSet.getInt("numberofseats");
                numberofseats--;
                statement2.setInt(1, numberofseats);
                statement2.setInt(2, entity.getId());
                statement2.executeUpdate();
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return Optional.empty();
    }
}
