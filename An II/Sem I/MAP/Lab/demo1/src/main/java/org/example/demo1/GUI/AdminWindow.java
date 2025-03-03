package org.example.demo1.GUI;

import javafx.event.ActionEvent;
import javafx.scene.control.ButtonBar;
import javafx.scene.control.ButtonType;
import javafx.scene.control.Dialog;
import javafx.scene.control.TextField;
import org.example.demo1.Domain.Show;
import org.example.demo1.Domain.Validators.ServiceException;
import org.example.demo1.Service.Service;

import java.time.DateTimeException;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;

public class AdminWindow {
    private Service service;

    public TextField name;
    public TextField durationMinutes;
    public TextField startDate;
    public TextField numberOfSeats;


    public void addNewShow(ActionEvent actionEvent) {
        if(name.getText().isEmpty() || durationMinutes.getText().isEmpty() || startDate.getText().isEmpty() ||
        numberOfSeats.getText().isEmpty()) {
            Dialog dialog = new Dialog();
            dialog.setContentText("Field urile trebuie sa fie completate");
            ButtonType closeButton = new ButtonType("Close", ButtonBar.ButtonData.OK_DONE);
            dialog.getDialogPane().getButtonTypes().add(closeButton);
            dialog.showAndWait();
        }
        try{
            Integer.parseInt(durationMinutes.getText());
            Integer.parseInt(numberOfSeats.getText());
            LocalDateTime.parse(startDate.getText(), DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss"));
            Show show = new Show(name.getText(), Integer.parseInt(durationMinutes.getText()), LocalDateTime.parse(startDate.getText(), DateTimeFormatter.ofPattern("yyyy-MM-dd HH:mm:ss")),
                    Integer.parseInt(numberOfSeats.getText()), LocalDateTime.now());
            try{
                service.addShow(show);
            }catch (ServiceException e){
                Dialog dialog = new Dialog();
                dialog.setContentText(e.getMessage());
                ButtonType closeButton = new ButtonType("Close", ButtonBar.ButtonData.OK_DONE);
                dialog.getDialogPane().getButtonTypes().add(closeButton);
                dialog.showAndWait();
            }

        }catch (NumberFormatException | DateTimeException e) {
            Dialog dialog = new Dialog();
            dialog.setContentText("Date invalide");
            ButtonType closeButton = new ButtonType("Close", ButtonBar.ButtonData.OK_DONE);
            dialog.getDialogPane().getButtonTypes().add(closeButton);
            dialog.showAndWait();
        }


    }

    public void setService(Service service) {
        this.service = service;
    }
}
