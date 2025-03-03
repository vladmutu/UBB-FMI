package org.example.labjavafx.Controllers;

import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.stage.Stage;
import org.example.labjavafx.Domain.User;
import org.example.labjavafx.Service.Service;
import org.example.labjavafx.Validators.ServiceException;
import org.example.labjavafx.Validators.ValidationException;

import javax.crypto.SecretKeyFactory;
import javax.crypto.spec.PBEKeySpec;
import java.util.Base64;

public class SignUpWindow {


    private static final int ITERATIONS = 65536;
    private static final int KEY_LENGTH = 256;

    public TextField passwordFieldVisible;public CheckBox showPassword;private Service service;

    public TextField firstNameField;

    public TextField lastNameField;

    public TextField emailField;

    public PasswordField passwordField;

    public void setService(Service service) {
        this.service = service;
    }

    public static String hashPassword(String password, byte[] salt) throws Exception {
        PBEKeySpec spec = new PBEKeySpec(password.toCharArray(), salt, ITERATIONS, KEY_LENGTH);
        SecretKeyFactory factory = SecretKeyFactory.getInstance("PBKDF2WithHmacSHA256");
        byte[] hashedPassword = factory.generateSecret(spec).getEncoded();
        return Base64.getEncoder().encodeToString(hashedPassword);
    }

    public void registerAction(ActionEvent actionEvent) {
        String firstName = firstNameField.getText();
        String lastName = lastNameField.getText();
        String email = emailField.getText();
        String password = passwordField.getText();
        if(firstName.isEmpty() || lastName.isEmpty() || email.isEmpty() || password.isEmpty()){
            Dialog dialog = new Dialog();
            dialog.setContentText("Please fill in all the fields");
            ButtonType closeButton = new ButtonType("Close", ButtonBar.ButtonData.OK_DONE);
            dialog.getDialogPane().getButtonTypes().add(closeButton);
            dialog.showAndWait();
        }
        if(!email.contains("@gmail.com") && !email.contains("@yahoo.com") && !email.contains("@hotmail.com")) {
            Dialog dialog = new Dialog();
            dialog.setContentText("Invalid email");
            ButtonType closeButton = new ButtonType("Close", ButtonBar.ButtonData.OK_DONE);
            dialog.getDialogPane().getButtonTypes().add(closeButton);
            dialog.showAndWait();
        }

        if(password.length() < 6) {
            Dialog dialog = new Dialog();
            dialog.setContentText("Password must be at least 6 characters long");
            ButtonType closeButton = new ButtonType("Close", ButtonBar.ButtonData.OK_DONE);
            dialog.getDialogPane().getButtonTypes().add(closeButton);
            dialog.showAndWait();
        }
        Iterable<User> users = service.getAllUsers();
        for(User user : users) {
            if(user.getEmail().equals(email)) {
                Dialog dialog = new Dialog();
                dialog.setContentText("Email already in use");
                ButtonType closeButton = new ButtonType("Close", ButtonBar.ButtonData.OK_DONE);
                dialog.getDialogPane().getButtonTypes().add(closeButton);
                dialog.showAndWait();
                return;
            }
        }
        try {
            String pass = hashPassword(password, email.getBytes());
            User user = new User(firstName, lastName, email, password);
            service.addUser(user);
            Dialog dialog = new Dialog();
            dialog.setContentText("Account created successfully");
            ButtonType closeButton = new ButtonType("Close", ButtonBar.ButtonData.OK_DONE);
            dialog.getDialogPane().getButtonTypes().add(closeButton);
            dialog.showAndWait();
                ((Stage) ((Button) actionEvent.getSource()).getScene().getWindow()).close();
        }catch (ValidationException |ServiceException e) {
            Dialog dialog = new Dialog();
            dialog.setContentText(e.getMessage());
            ButtonType closeButton = new ButtonType("Close", ButtonBar.ButtonData.OK_DONE);
            dialog.getDialogPane().getButtonTypes().add(closeButton);
            dialog.showAndWait();
        } catch (Exception e) {
            throw new RuntimeException(e);
        }

    }

    public void backToLogin(ActionEvent actionEvent) {
        ((Stage) ((Button) actionEvent.getSource()).getScene().getWindow()).close();
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
