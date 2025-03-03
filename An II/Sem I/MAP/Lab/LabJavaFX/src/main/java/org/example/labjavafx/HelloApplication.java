package org.example.labjavafx;

import javafx.application.Application;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.stage.Stage;
import org.example.labjavafx.Controllers.StartWindow;
import org.example.labjavafx.Domain.Friendship;
import org.example.labjavafx.Domain.User;
import org.example.labjavafx.Repository.FriendshipDBRepository;
import org.example.labjavafx.Repository.MessageDBRepository;
import org.example.labjavafx.Repository.UserDBRepository;
import org.example.labjavafx.Service.Service;
import org.example.labjavafx.Validators.FriendshipValidator;
import org.example.labjavafx.Validators.ServiceException;
import org.example.labjavafx.Validators.UserValidator;
import org.example.labjavafx.Validators.Validator;

import java.io.IOException;
import java.util.Objects;

public class HelloApplication extends Application {
    private UserDBRepository userDBRepository;
    private FriendshipDBRepository friendshipDBRepository;
    private MessageDBRepository messageDBRepository;
    private Service service;
    @Override
    public void start(Stage primaryStage) throws IOException {

        // Set up the repositories
        userDBRepository = new UserDBRepository("jdbc:postgresql://localhost:5432/labfx", "postgres", "vldm19", new UserValidator());
        friendshipDBRepository = new FriendshipDBRepository("jdbc:postgresql://localhost:5432/labfx", "postgres", "vldm19", new FriendshipValidator());
        messageDBRepository = new MessageDBRepository(userDBRepository, "jdbc:postgresql://localhost:5432/labfx", "postgres", "vldm19");
        service = new Service(userDBRepository, friendshipDBRepository, messageDBRepository);
        FXMLLoader loader  = new FXMLLoader(HelloApplication.class.getResource("start-window.fxml"));
        Scene scene = new Scene(loader.load());
        StartWindow startWindow = loader.getController();
        startWindow.setService(service);
        // Set up the primary stage
        primaryStage.setScene(scene);
        primaryStage.setTitle("Login");
        primaryStage.show();

    }

    public static void main(String[] args) {
        launch();
    }
}