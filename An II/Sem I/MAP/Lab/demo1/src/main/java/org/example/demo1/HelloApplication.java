package org.example.demo1;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;
import org.example.demo1.Domain.User;
import org.example.demo1.Domain.Validators.ShowValidator;
import org.example.demo1.Domain.Validators.UserValidator;
import org.example.demo1.GUI.AdminWindow;
import org.example.demo1.Repository.ShowDBRepository;
import org.example.demo1.Repository.UserDBRepository;
import org.example.demo1.Service.Service;

import java.io.IOException;

public class HelloApplication extends Application {
    private ShowDBRepository showDBRepository;
    private UserDBRepository userDBRepository;
    private Service service;

    @Override
    public void start(Stage primaryStage) throws IOException {
        userDBRepository = new UserDBRepository("jdbc:postgresql://localhost:5432/demounu", "postgres", "vldm19", new UserValidator());
        showDBRepository = new ShowDBRepository("jdbc:postgresql://localhost:5432/demounu", "postgres", "vldm19", new ShowValidator());
        service = new Service(userDBRepository, showDBRepository);
        FXMLLoader loader  = new FXMLLoader(HelloApplication.class.getResource("admin-window.fxml"));
        Scene scene = new Scene(loader.load());
        AdminWindow adminWindow = loader.getController();
        adminWindow.setService(service);
        Stage adminStage = new Stage();
        adminStage.setScene(scene);
        adminStage.setTitle("Admin Window");
        adminStage.show();

        for (User u : userDBRepository.findAll()) {
            FXMLLoader loader1 = new FXMLLoader(HelloApplication.class.getResource("user-window.fxml"));
            Scene scene1 = new Scene(loader1.load());
            Stage userStage = new Stage();
            userStage.setScene(scene1);
            userStage.setTitle("User Window " + u.getId());
            UserWindow userWindow = loader1.getController();
            userWindow.setServiceAndUserAndStage(service, u, userStage);
            service.addObserver(userWindow);
            userStage.show();
        }
    }

    public static void main(String[] args) {
        launch();
    }
}