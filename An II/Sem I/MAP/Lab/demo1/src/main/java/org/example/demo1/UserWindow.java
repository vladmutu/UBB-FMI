package org.example.demo1;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.stage.Stage;
import javafx.stage.Window;
import javafx.util.Callback;
import org.example.demo1.Domain.Show;
import org.example.demo1.Domain.User;
import org.example.demo1.Service.Service;
import org.example.demo1.Utils.Observer;
import org.example.demo1.Utils.Page;
import org.example.demo1.Utils.Pageable;

import java.time.LocalDateTime;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.StreamSupport;

public class UserWindow extends Window implements Observer<Show> {
    public TableView<Show> tableViewShows;
    public TableColumn<Show, String> showNameColumn;
    public TableColumn<Show, Integer> durationMinutesColumn;
    public TableColumn<Show, LocalDateTime> startDateColumn;
    public TableColumn<Show, Integer> numberOfSeatsColumn;
    public TableColumn<Show, LocalDateTime> createdAtColumn;
    public Label email;
    public Button prevButton;
    public Button nextButton;
    public TableColumn<Show, Void> actionColumn;
    private Service service;
    private User user;
    ObservableList<Show> modelShows = FXCollections.observableArrayList();
    private int currentPage = 0;
    private int pageSize = 3;
    private Map<Integer, List<Integer>> hiddenButtons = new HashMap<>();
    private Boolean canGetNotified;
    private Stage stage;

    public void setServiceAndUserAndStage(Service service, User u, Stage stage) {
        this.service = service;
        this.user = u;
        this.canGetNotified = true;
        this.stage = stage;
        email.setText("Email" + user.getEmail());
        initializeShowsForPage();
        initializeTableViews();
    }

    private void initializeTableViews() {
        showNameColumn.setCellValueFactory(new PropertyValueFactory<>("name"));
        durationMinutesColumn.setCellValueFactory(new PropertyValueFactory<>("durationMinutes"));
        startDateColumn.setCellValueFactory(new PropertyValueFactory<>("startDate"));
        numberOfSeatsColumn.setCellValueFactory(new PropertyValueFactory<>("numberOfSeats"));
        createdAtColumn.setCellValueFactory(new PropertyValueFactory<>("creationDate"));

        tableViewShows.setItems(modelShows);
    //also check if numberofseats is not 0

        actionColumn.setCellFactory(param -> new TableCell<Show, Void>() {

            private final Button btn = new Button("Reserve seat");

            {
                btn.setOnAction(event -> {
                    Show show = getTableView().getItems().get(getIndex());
                    service.reserveSeat(show);
                    int rowIndex = getIndex();

                    // Track reserved row for the current page
                    hiddenButtons.computeIfAbsent(currentPage, k -> new ArrayList<>()).add(rowIndex);

                    // Hide the button for this row
                    btn.setVisible(false);

                    // Force refresh to ensure changes persist
                    getTableView().refresh();
                });
            }

            @Override
            protected void updateItem(Void item, boolean empty) {
                super.updateItem(item, empty);

                if (empty || hiddenButtons.getOrDefault(currentPage, Collections.emptyList()).contains(getIndex()) || getTableView().getItems().get(getIndex()).getNumberOfSeats() == 0) {
                    setGraphic(null);
                } else {
                    setGraphic(btn);
                    btn.setVisible(true);  // Ensure button is visible for other rows
                }
            }
        });





    }

    private void initializeShowsForPage() {
        if(currentPage > (int)(Math.ceil((double) service.getShows().size() / pageSize))) {
            currentPage = 0;
        }
        Page<Show> page = service.getShowsOnPage(new Pageable(currentPage, pageSize));
        Iterable<Show> aux = page.getElementsOnPage();
        List<Show> shows = StreamSupport.stream(aux.spliterator(), false).collect(Collectors.toList());
        modelShows.setAll(shows);
        int noOfPages = (int)(Math.ceil((double) service.getShows().size() / pageSize));
        nextButton.setDisable(currentPage + 1 == noOfPages);
        prevButton.setDisable(currentPage == 0);
    }


    @Override
    public void update(Show show) {
        if(show.getId() == -1 && canGetNotified) {
            initializeTableViews();
            initializeShowsForPage();
            Dialog dialog = new Dialog();
            dialog.initOwner(stage);
            dialog.setContentText("New shows have been scheduled. Do you want to see them?");
            ButtonType yesButton = new ButtonType("Yes", ButtonBar.ButtonData.YES);
            ButtonType noButton = new ButtonType("No", ButtonBar.ButtonData.NO);
            dialog.getDialogPane().getButtonTypes().addAll(yesButton, noButton);
            dialog.showAndWait().ifPresent(response -> {
                        if (response == yesButton) {
                            canGetNotified = true;

                        } else if (response == noButton) {
                            canGetNotified = false;
                        }
                    }
                    );
        }
        if(show.getId() == -2) {
            currentPage = 0;
            initializeShowsForPage();
        }

    }

    public void onPreviousPage(ActionEvent actionEvent) {
        currentPage--;
        initializeShowsForPage();
    }

    public void onNextPage(ActionEvent actionEvent) {
        currentPage++;
        initializeShowsForPage();
    }


}
