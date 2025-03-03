package org.example.labjavafx.Controllers;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import org.example.labjavafx.Domain.User;
import org.example.labjavafx.Service.Service;

import java.io.IOException;
import java.io.InputStream;
import java.net.URL;
import java.util.ArrayList;
import java.util.List;
import java.util.Objects;
import java.util.stream.Collectors;
import java.util.stream.StreamSupport;

import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.PBEKeySpec;
import java.security.SecureRandom;
import java.util.Base64;


public class StartWindow {

    private static final int ITERATIONS = 65536;
    private static final int KEY_LENGTH = 256;

    private Service service;

    public TextField emailField;

    public PasswordField passwordField;

    public TextField passwordFieldVisible;

    public CheckBox showPassword;

    public void setService(Service service) {
        this.service = service;
    }

    public static String hashPassword(String password, byte[] salt) throws Exception {
        PBEKeySpec spec = new PBEKeySpec(password.toCharArray(), salt, ITERATIONS, KEY_LENGTH);
        SecretKeyFactory factory = SecretKeyFactory.getInstance("PBKDF2WithHmacSHA256");
        byte[] hashedPassword = factory.generateSecret(spec).getEncoded();
        return Base64.getEncoder().encodeToString(hashedPassword);
    }


    public void SignIn(ActionEvent actionEvent) throws Exception {
        String email = emailField.getText();
        String password = hashPassword(passwordField.getText(), email.getBytes());
        if(email.isEmpty() || password.isEmpty()) {
            Dialog<String> dialog = new Dialog<>();
            dialog.setTitle("Error");
            dialog.setHeaderText("Error");
            dialog.setContentText("Please fill in all the fields");
        }
        if(!email.contains("@gmail.com") && !email.contains("@yahoo.com")) {
            Dialog<String> dialog = new Dialog<>();
            dialog.setTitle("Error");
            dialog.setHeaderText("Error");
            dialog.setContentText("Invalid email");
        }
        if(password.length() < 6) {
            Dialog<String> dialog = new Dialog<>();
            dialog.setTitle("Error");
            dialog.setHeaderText("Error");
            dialog.setContentText("Password must be at least 6 characters long");
        }
        List<User> users = StreamSupport.stream(service.getAllUsers().spliterator(), false).collect(Collectors.toList())
                .stream().filter(user -> user.getEmail().equals(email) && user.getPassword().equals(password)).collect(Collectors.toList());
        if(users.isEmpty()) {
            Dialog<String> dialog = new Dialog<>();
            dialog.setTitle("Error");
            dialog.setHeaderText("Error");
            dialog.setContentText("Invalid email or password");
            ButtonType closeButton = new ButtonType("Close", ButtonBar.ButtonData.OK_DONE);
            dialog.getDialogPane().getButtonTypes().add(closeButton);
            dialog.showAndWait();
        }
        else {
            try {
                FXMLLoader loader = new FXMLLoader(getClass().getResource("/org/example/labjavafx/profile-view.fxml"));
                Parent root = loader.load();
                Stage stage = new Stage();
                ProfileView profileView = loader.getController();
                profileView.setServiceAndUser(service, users.get(0));
                stage.setTitle("Main Window");
                stage.setScene(new Scene(root));
                stage.show();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }

    public void goToSignUp(ActionEvent actionEvent) throws IOException {
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/org/example/labjavafx/sign-up-window.fxml"));
            Parent root = loader.load();
            Stage stage = new Stage();
            SignUpWindow signUpWindow = loader.getController();
            signUpWindow.setService(service);
            stage.setTitle("Sign Up");
            stage.setScene(new Scene(root));
            stage.show();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }

    public void showHidePassword(ActionEvent actionEvent) {
        if(showPassword.isSelected()) {
            passwordFieldVisible.setText(passwordField.getText());
            passwordFieldVisible.setManaged(true);
            passwordFieldVisible.setVisible(true);
            passwordField.setManaged(false);
            passwordField.setVisible(false);
        }
        else {
            passwordField.setManaged(true);
            passwordField.setVisible(true);
            passwordField.setText(passwordField.getText());
        }
    }
}
