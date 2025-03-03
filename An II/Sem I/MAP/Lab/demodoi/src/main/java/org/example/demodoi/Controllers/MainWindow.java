package org.example.demodoi.Controllers;

import javafx.beans.property.ReadOnlyObjectWrapper;
import javafx.beans.property.SimpleIntegerProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import org.example.demodoi.Domain.Client;
import org.example.demodoi.Domain.Flight;
import org.example.demodoi.Domain.Ticket;
import org.example.demodoi.Service.Service;
import org.example.demodoi.Utils.Observable;
import org.example.demodoi.Utils.Observer;

import javax.swing.table.TableModel;
import java.time.LocalDate;
import java.time.LocalDateTime;
import java.util.*;

public class MainWindow implements Observer<Flight> {
    public Label numeuser;
    public TableView tableViewTicketsBought;
    public TableColumn<Ticket, Long> flightIdColumn;
    public TableColumn<Ticket, LocalDateTime> purchaseTimeColumn;
    public TableView tableViewTicketsDate;
    public TableColumn<Ticket, Long> flightIdDateColumn;
    public TableColumn<Ticket, LocalDateTime> purchaseTimeDateColumn;
    public TableView flightsView;
    public TableColumn<Flight, String> flightFromColumn;
    public TableColumn<Flight, String> flightToColumn;
    public TableColumn<Flight, LocalDateTime> flightDepartureColumn;
    public TableColumn<Flight, LocalDateTime> flightArrivalColumn;
    public TableColumn<Flight, Integer> flightSeatsColumn;
    public ComboBox<String> fromCombo;
    public ComboBox<String> toCombo;
    public DatePicker datePicker;
    public TableColumn<Flight, Void> actionColumn;
    public TableColumn<Flight, Integer> seatsLeftColumn;
    ObservableList<Ticket> ticketsModel = FXCollections.observableArrayList();
    ObservableList<Ticket> ticketsModelDate = FXCollections.observableArrayList();
    ObservableList<Flight> flightsModel = FXCollections.observableArrayList();
    private Service service;
    private Client client;
    private Boolean toIsSelected = false;
    private Boolean fromIsSelected = false;
    private Map<Integer, Integer> clickedButtons = new HashMap<>();


    public void setServiceAndUser(Service service, Client client) {
        this.service = service;
        this.client = client;
        numeuser.setText(client.getName());
        initializeBoughtTickets();
        initializeTableViews();
        initializeDateTickets();
        initializeTableViews2();
        initializeFlights();
        initializeTableViews3();
        intializeComboBoxes();
    }

    private void intializeComboBoxes() {
        Set<String> from = service.getAllFlightFrom();
        Set<String> to = service.getAllFlightTo();
        fromCombo.getItems().addAll(from);
        toCombo.getItems().addAll(to);
        Set<LocalDateTime> dates = service.getAllFlightDates();
        datePicker.setDayCellFactory(picker -> new DateCell() {
            @Override
            public void updateItem(LocalDate date, boolean empty) {
                super.updateItem(date, empty);
                if (dates.contains(date)) {
                    setStyle("-fx-background-color: #ff4444;");
                }
            }
        });
    }

    private void initializeTableViews3() {
        flightFromColumn.setCellValueFactory(new PropertyValueFactory<>("from"));
        flightToColumn.setCellValueFactory(new PropertyValueFactory<>("to"));
        flightDepartureColumn.setCellValueFactory(new PropertyValueFactory<>("departureTime"));
        flightArrivalColumn.setCellValueFactory(new PropertyValueFactory<>("landingTime"));
        flightSeatsColumn.setCellValueFactory(new PropertyValueFactory<>("seats"));
        seatsLeftColumn.setCellValueFactory(cellData -> {
            Flight flight = cellData.getValue();
            int boughtTickets = service.boughtTicketsIndexesAndHowMany.getOrDefault(cellData.getTableView().getItems().indexOf(cellData.getValue()), 0);
            int seatsLeft = flight.getSeats() - boughtTickets;

            return new ReadOnlyObjectWrapper<>(seatsLeft);
        });

        //seats left column will be seats - bought tickets and will be calculated dinamically
        //seatsLeftColumn.setCellValueFactory(new PropertyValueFactory<>("seats"));
        flightsView.setItems(flightsModel);

        actionColumn.setCellFactory(param -> new TableCell<Flight, Void>() {

            private final Button btn = new Button("Cumpara");

            {
                btn.setOnAction(event -> {
                    Flight flight = getTableView().getItems().get(getIndex());

                    //add the current ticket to bought tickets
                    service.addTicket(new Ticket(client.getUsername(), flight.getId(), LocalDateTime.now()));
                    //add the current ticket to a variable that stores all bought tickets
                    clickedButtons.put(getIndex(), clickedButtons.getOrDefault(getIndex(), 0) + 1);
                    service.buyTicket(flight, getIndex());
                    // Hide the button for this row
                    btn.setVisible(false);

                    // Force refresh to ensure changes persist
                    getTableView().refresh();
                });
            }

            @Override
            protected void updateItem(Void item, boolean empty) {
                super.updateItem(item, empty);
                //also check if this client pressed the button for this row
                if (empty || getTableView().getItems().get(getIndex()).getSeats() == 0 || clickedButtons.getOrDefault(getIndex(), 0) > 0) {
                    setGraphic(null);
                } else {
                    setGraphic(btn);
                    btn.setVisible(true);// Ensure button is visible for other rows
                }
            }
        });
    }

    private void initializeFlights() {
        flightsModel.setAll(service.getAllFlights());
        
    }

    private void initializeTableViews2() {
        flightIdDateColumn.setCellValueFactory(new PropertyValueFactory<>("flightId"));
        purchaseTimeDateColumn.setCellValueFactory(new PropertyValueFactory<>("purchaseTime"));
        tableViewTicketsDate.setItems(ticketsModelDate);
    }

    private void initializeDateTickets() {
        ticketsModelDate.setAll(service.getAllTickets());
    }

    private void initializeTableViews() {
        flightIdColumn.setCellValueFactory(new PropertyValueFactory<>("flightId"));
        purchaseTimeColumn.setCellValueFactory(new PropertyValueFactory<>("purchaseTime"));
        tableViewTicketsBought.setItems(ticketsModel);
    }

    private void initializeBoughtTickets() {
        ticketsModel.setAll(service.getAllTicketsForClient(client.getUsername()));

    }

    @Override
    public void update(Flight flight) {
        initializeBoughtTickets();
        initializeTableViews();
        initializeDateTickets();
        initializeTableViews2();
        initializeFlights();
        initializeTableViews3();
        intializeComboBoxes();
    }

    public void fromAction(ActionEvent actionEvent) {
        fromIsSelected = true;
        if(toIsSelected) {
            flightsModel.setAll(service.getFlightsFromTo(fromCombo.getValue(), toCombo.getValue()));
        }
    }

    public void toAction(ActionEvent actionEvent) {
        toIsSelected = true;
        if(fromIsSelected) {
            flightsModel.setAll(service.getFlightsFromTo(fromCombo.getValue(), toCombo.getValue()));
        }
    }

    public void dateAction(ActionEvent actionEvent) {
        LocalDateTime date = datePicker.getValue().atStartOfDay();
        flightsModel.setAll(service.getFlightsOnDate(date));
    }
}
