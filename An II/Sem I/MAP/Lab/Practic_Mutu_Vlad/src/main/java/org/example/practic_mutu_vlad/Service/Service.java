package org.example.practic_mutu_vlad.Service;

import javafx.collections.ObservableList;
import org.example.practic_mutu_vlad.Domain.Driver;
import org.example.practic_mutu_vlad.Domain.Order;
import org.example.practic_mutu_vlad.Repository.Repository;
import org.example.practic_mutu_vlad.Utils.Observable;
import org.example.practic_mutu_vlad.Utils.Observer;
import org.example.practic_mutu_vlad.Utils.Status;

import java.time.LocalDateTime;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;
import java.util.stream.StreamSupport;

public class Service implements Observable<Order> {
    private Repository<Integer, Order> orderRepository;
    private Repository<Integer, Driver> driverRepository;
    private List<Observer<Order>> observers = new ArrayList<>();

    public Service(Repository<Integer, Order> orderRepository, Repository<Integer, Driver> driverRepository) {
        this.orderRepository = orderRepository;
        this.driverRepository = driverRepository;
    }

    @Override
    public void addObserver(Observer<Order> observer) {
        observers.add(observer);
    }

    @Override
    public void removeObserver(Observer<Order> observer) {
        observers.remove(observer);
    }

    @Override
    public void notifyObservers(Order event) {
        observers.forEach(o -> o.update(event));

    }

    public List<Order> getOrdersForDriver(Integer id) {
        return StreamSupport.stream(orderRepository.findAll().spliterator(), false)
                .filter(order -> order.getDriverId() == id && order.getStatus().equals(Status.IN_PROGRESS))
                .toList();
    }

    public void changeOrderStatus(Order order, Status status) {
        order.setStatus(status);
        order.setEndDate(LocalDateTime.now());
        orderRepository.update(order);
        notifyObservers(order);
    }

    public Order addOrder(String adresaPlecareText, String adresaDestinatieText, String numeClientText) {
        Order order = new Order(-1, Status.PENDING, LocalDateTime.now(), null, adresaPlecareText, adresaDestinatieText, numeClientText);
        Optional<Order> aux = orderRepository.save(order);
        if(aux.isPresent()) {
            order.setId(aux.get().getId());
        }
        return order;
    }




    public Integer getOldestFinishedOrdersForDrivers() {
        return StreamSupport.stream(orderRepository.findAll().spliterator(), false)
                .filter(order -> order.getStatus().equals(Status.FINISHED))
                .collect(Collectors.groupingBy(Order::getDriverId, Collectors.counting()))
                .entrySet().stream()
                .min((entry1, entry2) -> {
                    if (entry1.getValue().equals(entry2.getValue())) {
                        return entry1.getKey().compareTo(entry2.getKey());
                    }
                    return entry1.getValue().compareTo(entry2.getValue());
                })
                .map(Map.Entry::getKey)
                .orElse(-1);
    }

    public void updateOrder(Order order) {
        orderRepository.update(order);
        notifyObservers(order);
    }
}
