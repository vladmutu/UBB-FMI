package org.example.demodoi.Domain;

import java.time.LocalDateTime;

public class Ticket extends Entity<Long> {
    private String username;
    private Long flightId;
    private LocalDateTime purchaseTime;

    public Ticket(String username, Long flightId, LocalDateTime purchaseTime) {
        this.username = username;
        this.flightId = flightId;
        this.purchaseTime = purchaseTime;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public Long getFlightId() {
        return flightId;
    }

    public void setFlightId(Long flightId) {
        this.flightId = flightId;
    }

    public LocalDateTime getPurchaseTime() {
        return purchaseTime;
    }

    public void setPurchaseTime(LocalDateTime purchaseTime) {
        this.purchaseTime = purchaseTime;
    }

    @Override
    public String toString() {
        return "Ticket{"
                + "id="
                + getId()
                + ", username='"
                + username
                + '\''
                + ", flightId="
                + flightId
                + ", purchaseTime="
                + purchaseTime
                + '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Ticket ticket)) return false;
        if (!super.equals(o)) return false;
        return username.equals(ticket.username) && flightId.equals(ticket.flightId) && purchaseTime.equals(ticket.purchaseTime);
    }

    @Override
    public int hashCode() {
        return super.hashCode();
    }
}
