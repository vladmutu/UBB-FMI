package Domain;

import java.util.ArrayList;
import java.util.List;
import java.util.Objects;

public class Utilizator extends Entity<Long>{
    private String firstName;
    private String lastName;
    final private List<Utilizator> prieteni;

    public Utilizator(String firstName, String lastName) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.prieteni = new ArrayList<>();
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public List<Utilizator> getPrieteni() {
        return prieteni;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    public void addFriend(Utilizator friend) {
        this.prieteni.add(friend);
    }

    public void removeFriend(Utilizator friend) {
        this.prieteni.remove(friend);
    }


    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Utilizator that)) return false;
        if (!super.equals(o)) return false;
        return Objects.equals(firstName, that.firstName) && Objects.equals(lastName, that.lastName);
    }

    @Override
    public int hashCode() {
        return Objects.hash(super.hashCode(), firstName, lastName);
    }

    @Override
    public String toString() {
        return "Utilizator{"
                + "id = "
                + getId()
                + ", firstName='"
                + firstName
                + ", lastName='"
                + lastName
                + '}';
    }
}
