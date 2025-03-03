package org.example.demodoi.Controllers;

import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.stage.Stage;
import org.example.demodoi.Domain.Client;
import org.example.demodoi.HelloApplication;
import org.example.demodoi.Service.Service;

import java.io.IOException;

public class LoginWindow {
    private Service service;
    private Client user;
    public TextField username;
    public Button loginButton;

    public void setService(Service service) {
        this.service = service;
    }

    public void login(ActionEvent actionEvent) throws IOException {
        user = service.login(username.getText());
        if (user != null) {
            System.out.println("Login successful!");
            FXMLLoader loader = new FXMLLoader(HelloApplication.class.getResource("main-window.fxml"));
            Scene scene = new Scene(loader.load());
            Stage stage = new Stage();
            MainWindow mainWindow = loader.getController();
            service.addObserver(mainWindow);
            mainWindow.setServiceAndUser(service,user);
            stage.setScene(scene);
            stage.setTitle("Main Window");
            stage.show();

        } else {
            Dialog dialog = new Dialog();
            ButtonType closeButton = new ButtonType("Close", ButtonBar.ButtonData.OK_DONE);
            dialog.getDialogPane().getButtonTypes().add(closeButton);
            dialog.setContentText("Invalid username");
            dialog.showAndWait();
        }
    }
}
