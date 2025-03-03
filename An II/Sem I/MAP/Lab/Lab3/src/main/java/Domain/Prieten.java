package Domain;

import java.util.Objects;

public class Prieten extends Entity<Long>{
    private Long user1ID;
    private Long user2ID;

    public Prieten(Long user1ID, Long user2ID) {
        this.user1ID = user1ID;
        this.user2ID = user2ID;
    }

    public Long getUser1ID() {
        return user1ID;
    }

    public void setUser1ID(Long user1ID) {
        this.user1ID = user1ID;
    }

    public Long getUser2ID() {
        return user2ID;
    }

    public void setUser2ID(Long user2ID) {
        this.user2ID = user2ID;
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (!(o instanceof Prieten prieten)) return false;
        if (!super.equals(o)) return false;
        return Objects.equals(user1ID, prieten.user1ID) && Objects.equals(user2ID, prieten.user2ID);
    }

    @Override
    public int hashCode() {
        return Objects.hash(super.hashCode(), user1ID, user2ID);
    }

    @Override
    public String toString() {
        return "Prieten{"
                + "user1ID="
                + user1ID
                + ", user2ID="
                + user2ID
                + '}';
    }
}
