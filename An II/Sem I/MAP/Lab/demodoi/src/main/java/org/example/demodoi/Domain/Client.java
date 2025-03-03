package org.example.demodoi.Domain;

import java.util.Objects;

public class Client extends Entity<Long>{
    private String username;
    private String name;

    public Client(String username, String name) {
        this.username = username;
        this.name = name;
    }

    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    @Override
    public String toString() {
        return "Client{"
                + "id="
                + getId()
                + ", username='"
                + username
                + '\''
                + ", name='"
                + name
                + '\''
                + '}';
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Client client)) return false;
        if (!super.equals(o)) return false;
        return Objects.equals(username, client.username) && Objects.equals(name, client.name);
    }

    @Override
    public int hashCode() {
        return Objects.hash(super.hashCode(), username, name);
    }
}
