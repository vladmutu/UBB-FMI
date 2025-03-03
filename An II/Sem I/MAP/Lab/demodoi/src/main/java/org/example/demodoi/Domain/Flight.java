package org.example.demodoi.Domain;

import java.time.LocalDateTime;

public class Flight extends Entity<Long>{
    private String from;
    private String to;
    private LocalDateTime departureTime;
    private LocalDateTime landingTime;
    private int seats;

    public Flight(String from, String to, LocalDateTime departureTime, LocalDateTime landingTime, int seats) {
        this.from = from;
        this.to = to;
        this.departureTime = departureTime;
        this.landingTime = landingTime;
        this.seats = seats;
    }

    public String getFrom() {
        return from;
    }

    public void setFrom(String from) {
        this.from = from;
    }

    public String getTo() {
        return to;
    }

    public void setTo(String to) {
        this.to = to;
    }

    public LocalDateTime getDepartureTime() {
        return departureTime;
    }

    public void setDepartureTime(LocalDateTime departureTime) {
        this.departureTime = departureTime;
    }

    public LocalDateTime getLandingTime() {
        return landingTime;
    }

    public void setLandingTime(LocalDateTime landingTime) {
        this.landingTime = landingTime;
    }

    public int getSeats() {
        return seats;
    }

    public void setSeats(int seats) {
        this.seats = seats;
    }

    @Override
    public String toString() {
        return "Flight{"
                + "id="
                + getId()
                + ", from='"
                + from
                + '\''
                + ", to='"
                + to
                + '\''
                + ", departureTime="
                + departureTime
                + ", landingTime="
                + landingTime
                + ", seats="
                + seats
                + '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Flight flight)) return false;
        if (!super.equals(o)) return false;
        return seats == flight.seats && from.equals(flight.from) && to.equals(flight.to) && departureTime.equals(flight.departureTime) && landingTime.equals(flight.landingTime);
    }

    @Override
    public int hashCode() {
        return super.hashCode();
    }
}
