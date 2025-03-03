package org.example.demo1.Domain;

import java.time.LocalDateTime;
import java.util.Objects;

public class Show extends Entity<Integer>{
    private String name;
    private int durationMinutes;
    private LocalDateTime startDate;
    private int numberOfSeats;
    private LocalDateTime creationDate;

    public Show(String name, int durationMinutes, LocalDateTime startDate, int numberOfSeats, LocalDateTime creationDate) {
        this.name = name;
        this.durationMinutes = durationMinutes;
        this.startDate = startDate;
        this.numberOfSeats = numberOfSeats;
        this.creationDate = creationDate;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getDurationMinutes() {
        return durationMinutes;
    }

    public void setDurationMinutes(int durationMinutes) {
        this.durationMinutes = durationMinutes;
    }

    public LocalDateTime getStartDate() {
        return startDate;
    }

    public void setStartDate(LocalDateTime startDate) {
        this.startDate = startDate;
    }

    public int getNumberOfSeats() {
        return numberOfSeats;
    }

    public void setNumberOfSeats(int numberOfSeats) {
        this.numberOfSeats = numberOfSeats;
    }

    public LocalDateTime getCreationDate() {
        return creationDate;
    }

    public void setCreationDate(LocalDateTime creationDate) {
        this.creationDate = creationDate;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Show show)) return false;
        return getId().equals(((Show) o).getId()) && durationMinutes == show.durationMinutes && numberOfSeats == show.numberOfSeats && Objects.equals(name, show.name) && Objects.equals(startDate, show.startDate) && Objects.equals(creationDate, show.creationDate);
    }

    @Override
    public int hashCode() {
        return super.hashCode();
    }

    @Override
    public String toString() {
        return "Show{" +
                "id=" + getId() +
                ", name='" + name + '\'' +
                ", durationMinutes=" + durationMinutes +
                ", startDate=" + startDate +
                ", numberOfSeats=" + numberOfSeats +
                ", creationDate=" + creationDate +
                '}';
    }
}
