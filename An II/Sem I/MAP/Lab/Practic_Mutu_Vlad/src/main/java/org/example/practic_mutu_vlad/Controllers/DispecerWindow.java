package org.example.practic_mutu_vlad.Controllers;

import javafx.event.ActionEvent;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import org.example.practic_mutu_vlad.Domain.Order;
import org.example.practic_mutu_vlad.Service.Service;

public class DispecerWindow {
    public TextField adresaPlecare;
    public TextField adresaDestinatie;
    public TextField numeClient;
    public Button addOrderButton;
    private Service service;

    public void setService(Service service) {
        this.service = service;
    }

    public void addOrder(ActionEvent actionEvent) {
        String adresaPlecareText = adresaPlecare.getText();
        String adresaDestinatieText = adresaDestinatie.getText();
        String numeClientText = numeClient.getText();
        Order order = service.addOrder(adresaPlecareText, adresaDestinatieText, numeClientText);
        service.notifyObservers(order);
    }
}
