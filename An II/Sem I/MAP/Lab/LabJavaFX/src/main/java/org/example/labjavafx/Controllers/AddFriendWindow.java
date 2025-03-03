package org.example.labjavafx.Controllers;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import org.example.labjavafx.Domain.User;
import org.example.labjavafx.Service.Service;
import org.example.labjavafx.Utils.Events.UserEntityChangeEvent;
import org.example.labjavafx.Utils.Observer.Observer;

import java.util.Objects;

public class AddFriendWindow implements Observer<UserEntityChangeEvent> {
    private Service service;
    private User user;
    ObservableList<User> model = FXCollections.observableArrayList();
    public TableView<User> tableView;
    public TableColumn<User, String> tableColumnFirstName;
    public TableColumn<User, String> tableColumnLastName;
    public TableColumn<User, String> tableColumnEmail;

    public void setService(Service service, User user) {
        this.service = service;
        this.user = user;
        initModel();
        initializeView();
    }

    public void initializeView() {
        tableColumnFirstName.setCellValueFactory(new PropertyValueFactory<>("firstName"));
        tableColumnLastName.setCellValueFactory(new PropertyValueFactory<>("lastName"));
        tableColumnEmail.setCellValueFactory(new PropertyValueFactory<>("email"));
        tableView.setItems(model);
    }
    public void initModel() {
        Iterable<User> users = service.getAllUsers();
        //remove from users the current user
        users.forEach(user -> {
            if(!Objects.equals(user.getId(), this.user.getId())) {
                model.add(user);
            }
        });
    }

    public void handleSendFriendRequest(ActionEvent actionEvent) {
        User selectedUser = (User) tableView.getSelectionModel().getSelectedItem();
        if(selectedUser == null) {
            return;
        }
        try{
            service.sendFriendRequest(user.getId(), selectedUser.getId());
            Dialog dialog = new Dialog();
            dialog.setContentText("Friend request sent");
            ButtonType closeButton = new ButtonType("Close", ButtonBar.ButtonData.OK_DONE);
            dialog.getDialogPane().getButtonTypes().add(closeButton);
            dialog.showAndWait();

        }catch (Exception e) {
            e.printStackTrace();
        }

    }

    @Override
    public void update(UserEntityChangeEvent userEntityChangeEvent) {
        initModel();
    }
}
