package org.example.practic_mutu_vlad;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;
import org.example.practic_mutu_vlad.Controllers.DispecerWindow;
import org.example.practic_mutu_vlad.Controllers.DriverWindow;
import org.example.practic_mutu_vlad.Domain.Driver;
import org.example.practic_mutu_vlad.Domain.Order;
import org.example.practic_mutu_vlad.Domain.Validators.DriverValidator;
import org.example.practic_mutu_vlad.Domain.Validators.OrderValidator;
import org.example.practic_mutu_vlad.Repository.DriverDBRepository;
import org.example.practic_mutu_vlad.Repository.OrderDBRepository;
import org.example.practic_mutu_vlad.Repository.Repository;
import org.example.practic_mutu_vlad.Service.Service;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class HelloApplication extends Application {
    private Repository<Integer, Order> orderRepository;
    private Repository<Integer, Driver> driverRepository;
    private Service service;

    @Override
    public void start(Stage stage) throws IOException {
        orderRepository = new OrderDBRepository("jdbc:postgresql://localhost:5432/practic", "postgres", "vldm19", new OrderValidator());
        driverRepository = new DriverDBRepository("jdbc:postgresql://localhost:5432/practic", "postgres", "vldm19", new DriverValidator());
        service = new Service(orderRepository, driverRepository);

        FXMLLoader loader1 = new FXMLLoader(HelloApplication.class.getResource("dispecer-window.fxml"));
        Scene scene1 = new Scene(loader1.load());
        Stage dispecerStage = new Stage();
        dispecerStage.setScene(scene1);
        dispecerStage.setTitle("Dispecer Window");
        DispecerWindow dispecerWindow = loader1.getController();
        dispecerWindow.setService(service);
        dispecerStage.show();

        for(Driver driver: driverRepository.findAll()) {
            FXMLLoader loader = new FXMLLoader(HelloApplication.class.getResource("driver-window.fxml"));
            Scene scene = new Scene(loader.load());
            Stage driverStage = new Stage();
            driverStage.setScene(scene);
            driverStage.setTitle("Driver Window " + driver.getId());
            DriverWindow driverWindow = loader.getController();
            driverWindow.setServiceAndDriverAndStage(service, driver, driverStage);
            service.addObserver(driverWindow);
            driverStage.show();
        }


    }

    public static void main(String[] args) {
        launch();
    }
}