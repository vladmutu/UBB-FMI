package org.example.demodoi;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;
import org.example.demodoi.Controllers.LoginWindow;
import org.example.demodoi.Domain.Ticket;
import org.example.demodoi.Domain.Validators.ClientValidator;
import org.example.demodoi.Domain.Validators.FlightValidator;
import org.example.demodoi.Domain.Validators.TicketValidator;
import org.example.demodoi.Repository.ClientDBRepository;
import org.example.demodoi.Repository.FlightDBRepository;
import org.example.demodoi.Repository.TicketDBRepository;
import org.example.demodoi.Service.Service;

import java.io.IOException;

public class HelloApplication extends Application {
    private ClientDBRepository clientDBRepository;
    private TicketDBRepository ticketDBRepository;
    private FlightDBRepository flightDBRepository;
    private Service service;

    @Override
    public void start(Stage stage) throws IOException {
        clientDBRepository = new ClientDBRepository("jdbc:postgresql://localhost:5432/demodoi", "postgres", "vldm19", new ClientValidator());
        ticketDBRepository = new TicketDBRepository("jdbc:postgresql://localhost:5432/demodoi", "postgres", "vldm19", new TicketValidator());
        flightDBRepository = new FlightDBRepository("jdbc:postgresql://localhost:5432/demodoi", "postgres", "vldm19", new FlightValidator());
        service = new Service(ticketDBRepository, clientDBRepository, flightDBRepository);
        FXMLLoader loader = new FXMLLoader(HelloApplication.class.getResource("login-window.fxml"));
        Scene scene = new Scene(loader.load());
        LoginWindow loginWindow = loader.getController();
        loginWindow.setService(service);
        stage.setScene(scene);
        stage.setTitle("Login Window");
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}