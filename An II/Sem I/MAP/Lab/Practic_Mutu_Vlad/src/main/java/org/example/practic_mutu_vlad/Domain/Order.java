package org.example.practic_mutu_vlad.Domain;

import org.example.practic_mutu_vlad.Utils.Status;

import java.time.LocalDateTime;
import java.util.Objects;

public class Order extends Entity<Integer>{
    private int driverId;
    private Status status;
    private LocalDateTime startDate;
    private LocalDateTime endDate;
    private String pickupAddress;
    private String destinationAddress;
    private String clientName;

    public Order(int driverId, Status status, LocalDateTime startDate, LocalDateTime endDate, String pickupAddress, String destinationAddress, String clientName) {
        this.driverId = driverId;
        this.status = status;
        this.startDate = startDate;
        this.endDate = endDate;
        this.pickupAddress = pickupAddress;
        this.destinationAddress = destinationAddress;
        this.clientName = clientName;
    }

    public int getDriverId() {
        return driverId;
    }

    public void setDriverId(int driverId) {
        this.driverId = driverId;
    }

    public Status getStatus() {
        return status;
    }

    public void setStatus(Status status) {
        this.status = status;
    }

    public LocalDateTime getStartDate() {
        return startDate;
    }

    public void setStartDate(LocalDateTime startDate) {
        this.startDate = startDate;
    }

    public LocalDateTime getEndDate() {
        return endDate;
    }

    public void setEndDate(LocalDateTime endDate) {
        this.endDate = endDate;
    }

    public String getPickupAddress() {
        return pickupAddress;
    }

    public void setPickupAddress(String pickupAddress) {
        this.pickupAddress = pickupAddress;
    }

    public String getDestinationAddress() {
        return destinationAddress;
    }

    public void setDestinationAddress(String destinationAddress) {
        this.destinationAddress = destinationAddress;
    }

    public String getClientName() {
        return clientName;
    }

    public void setClientName(String clientName) {
        this.clientName = clientName;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Order order)) return false;
        if (!super.equals(o)) return false;
        return driverId == order.driverId && status == order.status && Objects.equals(startDate, order.startDate) && Objects.equals(endDate, order.endDate) && Objects.equals(pickupAddress, order.pickupAddress) && Objects.equals(destinationAddress, order.destinationAddress) && Objects.equals(clientName, order.clientName);
    }

    @Override
    public int hashCode() {
        return Objects.hash(super.hashCode(), driverId, status, startDate, endDate, pickupAddress, destinationAddress, clientName);
    }

    @Override
    public String toString() {
        return "Order{" +
                "driverId=" + driverId +
                ", status=" + status +
                ", startDate=" + startDate +
                ", endDate=" + endDate +
                ", pickupAddress='" + pickupAddress + '\'' +
                ", destinationAddress='" + destinationAddress + '\'' +
                ", clientName='" + clientName + '\'' +
                '}';
    }
}
