package org.example.labjavafx.Controllers;

import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.image.ImageView;
import javafx.stage.Stage;
import org.example.labjavafx.Domain.User;
import org.example.labjavafx.Service.Service;
import org.example.labjavafx.Utils.Events.UserEntityChangeEvent;
import org.example.labjavafx.Utils.Observer.Observer;

import java.io.IOException;

public class ProfileView implements Observer<UserEntityChangeEvent> {
    public Label greetingLabel;
    public Button buttonFriends;
    public Button buttonMessages;
    public Button buttonLogOut;
    public Button editProfile;
    public Button deleteProfile;
    public ImageView friendRequestNotification;

    private Service service;

    private User user;

    private int friendRequestCount;

    public void setServiceAndUser(Service service, User user) {
        this.service = service;
        this.user = user;
        String firstName = user.getFirstName();
        firstName = firstName.substring(0, 1).toUpperCase() + firstName.substring(1);
        greetingLabel.setText("Welcome back " + firstName);
        service.addObserver(this);
        friendRequestCount = service.getFriendRequests(user.getId()).size();
        if (friendRequestCount == 0) {
            friendRequestNotification.setVisible(false);
            friendRequestNotification.setManaged(false);
        } else {
            friendRequestNotification.setVisible(true);
            friendRequestNotification.setManaged(true);
        }
    }

    @Override
    public void update(UserEntityChangeEvent userEntityChangeEvent) {
        friendRequestCount = service.getFriendRequests(user.getId()).size();
        if (friendRequestCount == 0) {
            friendRequestNotification.setVisible(false);
            friendRequestNotification.setManaged(false);
        } else {
            friendRequestNotification.setVisible(true);
            friendRequestNotification.setManaged(true);
        }
    }

    public void handleLogOut(ActionEvent actionEvent) {
        ((Stage) ((Button) actionEvent.getSource()).getScene().getWindow()).close();
    }

    public void handleEditProfile(ActionEvent actionEvent) {
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/org/example/labjavafx/update-user.fxml"));
            Parent root = loader.load();
            Stage stage = new Stage();
            UpdateUser updateUser = loader.getController();
            updateUser.setService(service, user);
            update(null);
            stage.setTitle("Update User");
            stage.setScene(new Scene(root));
            stage.show();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void handleDeleteProfile(ActionEvent actionEvent) {
        service.removeUser(user.getId());
        Dialog dialog = new Dialog();
        dialog.setContentText("User deleted");
        ButtonType closeButton = new ButtonType("Close", ButtonBar.ButtonData.OK_DONE);
        dialog.getDialogPane().getButtonTypes().add(closeButton);
        dialog.showAndWait();
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/org/example/labjavafx/start-window.fxml"));
            Parent root = loader.load();
            Stage stage = new Stage();
            StartWindow startWindow = loader.getController();
            startWindow.setService(service);
            stage.setTitle("Login");
            stage.setScene(new Scene(root));
            stage.show();
            ((Stage) ((Button) actionEvent.getSource()).getScene().getWindow()).close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void handleGoToMessages(ActionEvent actionEvent) {
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/org/example/labjavafx/message-window.fxml"));
            Parent root = loader.load();
            Stage stage = new Stage();
            MessageWindow messageWindow = loader.getController();
            messageWindow.setService(service, user);
            stage.setTitle("Messages");
            stage.setScene(new Scene(root));
            stage.show();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void handleGoToFriends(ActionEvent actionEvent) {
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/org/example/labjavafx/main-window.fxml"));
            Parent root = loader.load();
            Stage stage = new Stage();
            MainWindow mainWindow = loader.getController();
            mainWindow.setServiceAndUser(service, user);
            stage.setTitle("Friends");
            stage.setScene(new Scene(root));
            stage.show();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }
}
