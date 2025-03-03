package org.example.labjavafx.Controllers;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.stage.Stage;
import org.example.labjavafx.Domain.FriendRequest;
import org.example.labjavafx.Domain.Friendship;
import org.example.labjavafx.Domain.User;
import org.example.labjavafx.Service.Service;
import org.example.labjavafx.Utils.Events.UserEntityChangeEvent;
import org.example.labjavafx.Utils.Observer.Observer;
import org.example.labjavafx.Utils.Pageable.Page;
import org.example.labjavafx.Utils.Pageable.Pageable;
import org.example.labjavafx.Validators.ServiceException;

import java.io.IOException;
import java.time.LocalDateTime;
import java.util.List;
import java.util.Optional;
import java.util.stream.StreamSupport;

public class MainWindow implements Observer<UserEntityChangeEvent> {

    public TableView<FriendRequest> tableViewFriendRequests;

    public TableColumn<FriendRequest, String> tableColumnFirstName;

    public TableColumn<FriendRequest, String> tableColumnLastName;

    public TableColumn<FriendRequest, String> tableColumnEmail;

    public TableColumn<FriendRequest, LocalDateTime> tableColumnSendDate;

    public TableView<FriendRequest> tableViewFriends;

    public TableColumn<FriendRequest, String> tableColumnFirstNameFriend;

    public TableColumn<FriendRequest, String> tableColumnLastNameFriend;

    public TableColumn<FriendRequest, String> tableColumnEmailFriend;

    public TableColumn<FriendRequest, LocalDateTime> tableColumnFriendsFrom;

    public Label friendRequestStatus;
    public Button prevButton;
    public Button nextButton;
    public Label pageNumber;

    private Service service;

    ObservableList<FriendRequest> modelFriends = FXCollections.observableArrayList();
    ObservableList<FriendRequest> modelFriendRequests = FXCollections.observableArrayList();

    private User user;

    private int currentPage = 0;
    private int pageSize = 1;

    public void setServiceAndUser(Service service, User user) {
        this.service = service;
        this.user = user;
        service.addObserver(this);
        initModelFriendsForPage();
        initModelFriendRequests();
        initializeTableViews();
    }

    private void initializeTableViews() {
        if(!service.getFriendRequests(user.getId()).isEmpty()) {
            friendRequestStatus.setManaged(true);
            friendRequestStatus.setVisible(true);
            friendRequestStatus.setText("New friend requests!");
        } else {
            friendRequestStatus.setManaged(false);
            friendRequestStatus.setVisible(false);

            friendRequestStatus.setText("");
        }
        tableColumnFirstName.setCellValueFactory(new PropertyValueFactory<>("firstName"));
        tableColumnLastName.setCellValueFactory(new PropertyValueFactory<>("lastName"));
        tableColumnEmail.setCellValueFactory(new PropertyValueFactory<>("email"));
        tableColumnSendDate.setCellValueFactory(new PropertyValueFactory<>("friendsSince"));
        tableViewFriendRequests.setItems(modelFriendRequests);

        tableColumnFirstNameFriend.setCellValueFactory(new PropertyValueFactory<>("firstName"));
        tableColumnLastNameFriend.setCellValueFactory(new PropertyValueFactory<>("lastName"));
        tableColumnEmailFriend.setCellValueFactory(new PropertyValueFactory<>("email"));
        tableColumnFriendsFrom.setCellValueFactory(new PropertyValueFactory<>("friendsSince"));
        tableViewFriends.setItems(modelFriends);
    }

    private void initModelFriends() {
        List<FriendRequest> friends = service.getUsersFriendsDTO(user.getId());
        modelFriends.setAll(friends);
    }

    private void initModelFriendsForPage() {
        if(currentPage > (int)(Math.ceil((double) service.getUsersFriends(user.getId()).size() / pageSize))) {
            currentPage = 0;
        }
        Page<Friendship> page = service.getUsersFriendsDTOOnPage(new Pageable(currentPage, pageSize), user.getId());
        Iterable<Friendship> aux = page.getElementsOnPage();
        List<FriendRequest> friend = StreamSupport.stream(aux.spliterator(), false).map(friendship -> {
            Optional<User> auxUser = service.findOneUser(friendship.getId2());
            return new FriendRequest(auxUser.get().getId(),auxUser.get().getFirstName(), auxUser.get().getLastName(), auxUser.get().getEmail(), friendship.getDate());
        }).collect(java.util.stream.Collectors.toList());
        modelFriends.setAll(friend);
        prevButton.setDisable(currentPage == 0);
        int noOfPages = (int)(Math.ceil((double) service.getUsersFriends(user.getId()).size() / pageSize));
        nextButton.setDisable(currentPage + 1 == noOfPages);
        pageNumber.setText((currentPage + 1) + " / " + noOfPages);
    }

    private void initModelFriendRequests() {
        List<FriendRequest> friendRequests = service.getFriendRequests(user.getId());
        modelFriendRequests.setAll(friendRequests);
    }

    @Override
    public void update(UserEntityChangeEvent userEntityChangeEvent) {
        initModelFriendRequests();
        initModelFriendsForPage();
        if(!service.getFriendRequests(user.getId()).isEmpty()) {
            friendRequestStatus.setManaged(true);
            friendRequestStatus.setVisible(true);
            friendRequestStatus.setText("New friend requests!");
        } else {
            friendRequestStatus.setManaged(false);
            friendRequestStatus.setVisible(false);

            friendRequestStatus.setText("");
        }
    }


    public void handleAcceptFriendRequest(ActionEvent actionEvent) {
        FriendRequest friend = tableViewFriendRequests.getSelectionModel().getSelectedItem();
        if (friend != null) {
            try {
                service.acceptFriendRequest(user.getId(), service.findOneUserByNameAndEmail(friend.getFirstName(), friend.getLastName(), friend.getEmail()).getId());
                update(null);
            } catch (ServiceException e) {
                Dialog dialog = new Dialog();
                dialog.setContentText(e.getMessage());
                ButtonType closeButton = new ButtonType("Close", ButtonBar.ButtonData.OK_DONE);
                dialog.getDialogPane().getButtonTypes().add(closeButton);
                dialog.showAndWait();

            }
        } else {
            Dialog dialog = new Dialog();
            dialog.setContentText("You must select a friend request!");
            ButtonType closeButton = new ButtonType("Close", ButtonBar.ButtonData.OK_DONE);
            dialog.getDialogPane().getButtonTypes().add(closeButton);
            dialog.showAndWait();
        }
    }

    public void handleDeclineFriendRequest(ActionEvent actionEvent) {
        FriendRequest friend = tableViewFriendRequests.getSelectionModel().getSelectedItem();
        if (friend != null) {
            try {
                service.declineFriendRequest(user.getId(), service.findOneUserByNameAndEmail(friend.getFirstName(), friend.getLastName(), friend.getEmail()).getId());
                update(null);
            } catch (ServiceException e) {
                Dialog dialog = new Dialog();
                dialog.setContentText(e.getMessage());
                ButtonType closeButton = new ButtonType("Close", ButtonBar.ButtonData.OK_DONE);
                dialog.getDialogPane().getButtonTypes().add(closeButton);
                dialog.showAndWait();
            }
        } else {
            Dialog dialog = new Dialog();
            dialog.setContentText("You must select a friend request!");
            ButtonType closeButton = new ButtonType("Close", ButtonBar.ButtonData.OK_DONE);
            dialog.getDialogPane().getButtonTypes().add(closeButton);
            dialog.showAndWait();
        }
    }

    public void handleDeleteFriend(ActionEvent actionEvent) {
        FriendRequest friend = tableViewFriends.getSelectionModel().getSelectedItem();
        if (friend != null) {
            User auxFriend = service.findOneUserByNameAndEmail(friend.getFirstName(), friend.getLastName(), friend.getEmail());
            service.removeFriendship(user.getId(), auxFriend.getId());
            update(null);
        } else {
            Dialog dialog = new Dialog();
            dialog.setContentText("You must select a friend!");
            ButtonType closeButton = new ButtonType("Close", ButtonBar.ButtonData.OK_DONE);
            dialog.getDialogPane().getButtonTypes().add(closeButton);
            dialog.showAndWait();
        }
    }

    public void handleBackToLogin(ActionEvent actionEvent) {
        ((Stage) ((Button) actionEvent.getSource()).getScene().getWindow()).close();
    }

    public void handleUpdateUser(ActionEvent actionEvent) {
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/org/example/labjavafx/update-user.fxml"));
            Parent root = loader.load();
            Stage stage = new Stage();
            UpdateUser updateUser = loader.getController();
            updateUser.setService(service, user);
            stage.setTitle("Update User");
            stage.setScene(new Scene(root));
            stage.show();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void handleDeleteUser(ActionEvent actionEvent) {
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

    public void handleAddFriend(ActionEvent actionEvent) {
        try {
            FXMLLoader loader = new FXMLLoader();
            loader.setLocation(getClass().getResource("/org/example/labjavafx/add-friend-window.fxml"));
            Parent root = loader.load();
            Stage stage = new Stage();
            stage.initModality(javafx.stage.Modality.WINDOW_MODAL);
            Scene scene = new Scene(root);
            stage.setScene(scene);
            stage.show();
            AddFriendWindow addFriendWindow = loader.getController();
            addFriendWindow.setService(service, user);
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void handleChat(ActionEvent actionEvent) {
        try{
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/org/example/labjavafx/message-window.fxml"));
            Parent root = loader.load();
            Stage stage = new Stage();
            MessageWindow messageWindow = loader.getController();
            messageWindow.setService(service, user);
            stage.setTitle("Chat");
            stage.setScene(new Scene(root));
            stage.show();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public void onPreviousPage(ActionEvent actionEvent) {
        currentPage--;
        initModelFriendsForPage();
    }

    public void onNextPage(ActionEvent actionEvent) {
        currentPage++;
        initModelFriendsForPage();
    }
}
