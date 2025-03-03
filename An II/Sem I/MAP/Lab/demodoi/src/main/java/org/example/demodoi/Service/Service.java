package org.example.demodoi.Service;

import org.example.demodoi.Domain.Client;
import org.example.demodoi.Domain.Flight;
import org.example.demodoi.Domain.Ticket;
import org.example.demodoi.Repository.*;
import org.example.demodoi.Utils.Observable;
import org.example.demodoi.Utils.Observer;

import java.time.LocalDateTime;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.StreamSupport;

public class Service implements Observable<Flight> {
    private TicketRepository<Long, Ticket> ticketDBRepository;
    private ClientRepository<Long, Client> clientDBRepository;
    private Repository<Long, Flight> flightDBRepository;
    private List<Observer<Flight>> observers = new ArrayList<>();
    public Map<Integer, Integer> boughtTicketsIndexesAndHowMany = new HashMap<>();

    public Service(TicketDBRepository ticketDBRepository, ClientDBRepository clientDBRepository, FlightDBRepository flightDBRepository) {
        this.ticketDBRepository = ticketDBRepository;
        this.clientDBRepository = clientDBRepository;
        this.flightDBRepository = flightDBRepository;
    }

    public Client login(String text) {
        Client client = clientDBRepository.getOneByUsername(text);
        return client;
    }

    @Override
    public void addObserver(Observer<Flight> observer) {
        observers.add(observer);
    }

    @Override
    public void removeObserver(Observer<Flight> observer) {
        observers.remove(observer);
    }

    @Override
    public void notifyObservers(Flight event) {
        observers.forEach(o -> o.update(event));
    }

    public List<Ticket> getAllTicketsForClient(String username) {
        return StreamSupport.stream(ticketDBRepository.findByClient(username).spliterator(), false)
                .toList();
    }

    public List<Ticket> getAllTickets() {
        return StreamSupport.stream(ticketDBRepository.findAll().spliterator(), false)
                .filter(ticket -> Objects.equals(ticket.getPurchaseTime().toLocalDate(), LocalDateTime.of(2024, 1, 24, 12, 12).toLocalDate()))
                .collect(Collectors.toList());
    }

    public Set<String> getAllFlightFrom() {
        return StreamSupport.stream(flightDBRepository.findAll().spliterator(), false)
                .map(Flight::getFrom)
                .collect(Collectors.toSet());
    }

    public Set<String> getAllFlightTo() {
        return StreamSupport.stream(flightDBRepository.findAll().spliterator(), false)
                .map(Flight::getTo)
                .collect(Collectors.toSet());
    }

    public List<Flight> getAllFlights() {
        return StreamSupport.stream(flightDBRepository.findAll().spliterator(), false)
                .collect(Collectors.toList());
    }

    public List<Flight> getFlightsFromTo(String value, String value1) {
        return StreamSupport.stream(flightDBRepository.findAll().spliterator(), false)
                .filter(flight -> flight.getFrom().equals(value) && flight.getTo().equals(value1))
                .collect(Collectors.toList());
    }

    public Set<LocalDateTime> getAllFlightDates() {
        return StreamSupport.stream(flightDBRepository.findAll().spliterator(), false)
                .map(Flight::getDepartureTime)
                .collect(Collectors.toSet());
    }

    public List<Flight> getFlightsOnDate(LocalDateTime date) {
        return StreamSupport.stream(flightDBRepository.findAll().spliterator(), false)
                .filter(flight -> flight.getDepartureTime().toLocalDate().equals(date.toLocalDate()))
                .collect(Collectors.toList());
    }

    public void buyTicket(Flight flight, int index) {
        this.boughtTicketsIndexesAndHowMany.put(index, this.boughtTicketsIndexesAndHowMany.getOrDefault(index, 0) + 1);
        this.notifyObservers(flight);
    }

    public void addTicket(Ticket ticket) {
        ticketDBRepository.save(ticket);
    }
}
