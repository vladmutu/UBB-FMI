package org.example.practic_mutu_vlad.Controllers;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.stage.Stage;
import org.example.practic_mutu_vlad.Domain.Driver;
import org.example.practic_mutu_vlad.Domain.Order;
import org.example.practic_mutu_vlad.Service.Service;
import org.example.practic_mutu_vlad.Utils.Observer;
import org.example.practic_mutu_vlad.Utils.Status;

import java.time.LocalDateTime;
import java.util.*;

public class DriverWindow implements Observer<Order> {


    public Label name;
    public TableColumn<Order, Status> statusColumn;
    public TableColumn<Order, LocalDateTime> startDateColumn;
    public TableColumn<Order, LocalDateTime> endDateColumn;
    public TableColumn<Order, String> pickupAddressColumn;
    public TableColumn<Order, String> destinationAddressColumn;
    public TableColumn<Order, String> clientNameColumn;
    public TableView driverOrdersInProgressTableView;
    public TableColumn<Order, Void> finishedColumn;
    ObservableList<Order> modelOrders = FXCollections.observableArrayList();

    private Service service;
    private Driver driver;
    private Stage stage;
    private Boolean canGetNotified = true;


    public void setServiceAndDriverAndStage(Service service, Driver driver, Stage stage) {
        this.service = service;
        this.driver = driver;
        this.stage = stage;
        name.setText(driver.getName());
        initializeTableViews();
    }

    private void initializeTableViews() {
        List<Order> orders = service.getOrdersForDriver(driver.getId());
        modelOrders.setAll(orders);
        driverOrdersInProgressTableView.setItems(modelOrders);
        statusColumn.setCellValueFactory(new PropertyValueFactory<>("status"));
        statusColumn.setCellFactory(column -> new TableCell<Order, Status>() {
            @Override
            protected void updateItem(Status status, boolean empty) {
                super.updateItem(status, empty);
                if (empty || status == null) {
                    setText(null);
                } else {
                    // Map integer status to corresponding string
                    String statusText = switch (status) {
                        case PENDING -> "Pending";
                        case IN_PROGRESS -> "In Progress";
                        case FINISHED -> "Finished";
                    };
                    setText(statusText);
                }
            }
        });
        finishedColumn.setCellFactory(param -> new TableCell<Order, Void>() {

            private final Button btn = new Button("Finished");

            {
                btn.setOnAction(event -> {
                    Order order = getTableView().getItems().get(getIndex());
                    service.changeOrderStatus(order, Status.FINISHED);

                    // Hide the button for this row
                    btn.setVisible(false);

                    // Force refresh to ensure changes persist
                    getTableView().refresh();
                });
            }

            @Override
            protected void updateItem(Void item, boolean empty) {
                super.updateItem(item, empty);

                if (empty) {
                    setGraphic(null);
                } else {
                    setGraphic(btn);
                    btn.setVisible(true);  // Ensure button is visible for other rows
                }
            }
        });
        startDateColumn.setCellValueFactory(new PropertyValueFactory<>("startDate"));
        endDateColumn.setCellValueFactory(new PropertyValueFactory<>("endDate"));
        pickupAddressColumn.setCellValueFactory(new PropertyValueFactory<>("pickupAddress"));
        destinationAddressColumn.setCellValueFactory(new PropertyValueFactory<>("destinationAddress"));
        clientNameColumn.setCellValueFactory(new PropertyValueFactory<>("clientName"));
    }


    @Override
    public void update(Order order) {
        Integer notbusydriverid = service.getOldestFinishedOrdersForDrivers();
        if(order.getEndDate() != null) {
            initializeTableViews();
        }
        else {
            if(service.getOrdersForDriver(driver.getId()).isEmpty() || Objects.equals(notbusydriverid, driver.getId()) && canGetNotified) {
                Dialog dialog = new Dialog();
                dialog.initOwner(stage);
                dialog.setContentText("New order: " + order.getPickupAddress() + " -> " + order.getDestinationAddress());
                ButtonType yesButton = new ButtonType("Accept", ButtonBar.ButtonData.YES);
                dialog.getDialogPane().getButtonTypes().addAll(yesButton);
                dialog.showAndWait().ifPresent(response -> {
                            if (response == yesButton) {
                                canGetNotified = false;
                                order.setStatus(Status.IN_PROGRESS);
                                order.setDriverId(driver.getId());
                                service.updateOrder(order);
                                initializeTableViews();
                            }
                        }
                );
                initializeTableViews();
            }
        }

    }
}
