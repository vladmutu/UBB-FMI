package Controller;

import Domain.Utilizator;
import Domain.Prieten;
import Domain.Validators.ServiceException;
import Domain.Validators.ValidationException;
import Repository.Repository;

import java.util.List;
import java.util.ArrayList;
import java.util.Objects;
import java.util.Optional;

public class Service {
    private Repository<Long, Utilizator> utilizatorRepository;
    private Repository<Long, Prieten> prietenieRepository;
    private Long lastUserId = 0L;
    private Long lastFriendshipId = 0L;

    public Service(Repository<Long, Utilizator> utilizatorRepo, Repository<Long, Prieten> prietenieRepo) {
        this.utilizatorRepository = utilizatorRepo;
        this.prietenieRepository = prietenieRepo;
        initializeLastIds();
    }

    private void initializeLastIds() {
        utilizatorRepository.findAll().forEach(utilizator -> {
            if (utilizator.getId() > lastUserId) {
                lastUserId = utilizator.getId();
            }
        });
        prietenieRepository.findAll().forEach(prietenie -> {
            if (prietenie.getId() > lastFriendshipId) {
                lastFriendshipId = prietenie.getId();
            }
        });
    }

    public Utilizator addUtilizator(String firstName, String lastName) {
        Utilizator user = new Utilizator(firstName, lastName);
        user.setId(++lastUserId);
        utilizatorRepository.save(user);
        return user;
    }

    public Utilizator removeUtilizator(Long userId) {
        Optional<Utilizator> userOpt = utilizatorRepository.findOne(userId);
        if (userOpt.isEmpty()) {
            throw new ValidationException("No user");
        }

        Utilizator user = userOpt.get();
        try {
            List<Prieten> prietenii = new ArrayList<Prieten>();
            prietenieRepository.findAll().forEach(prietenii::add);
            prietenii.forEach(friendship -> {
                if (friendship.getUser1ID().equals(userId) || friendship.getUser2ID().equals(userId)) {
                    removePrietenie(friendship.getId());
                }
            });
            utilizatorRepository.delete(userId);
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
        return user;
    }

    public Prieten addPrietenie(Long userId1, Long userId2) {
        Utilizator u1 = utilizatorRepository.findOne(userId1).orElseThrow(() -> new ValidationException("No user"));
        Utilizator u2 = utilizatorRepository.findOne(userId2).orElseThrow(() -> new ValidationException("No user"));
        Prieten friendship = new Prieten(userId1, userId2);
        friendship.setId(++lastFriendshipId);
        if (prietenieRepository.save(friendship).isEmpty()) {
            u1.addFriend(u2);
            u2.addFriend(u1);
            return friendship;
        } else {
            throw new ServiceException("Eroare la adaugarea prieteniei!");
        }
    }

    public Utilizator findUser(Long userId) {
        return utilizatorRepository.findOne(userId).orElse(null);
    }

    public Prieten removePrietenie(Long friendshipId) {
        Prieten friendship = prietenieRepository.findOne(friendshipId).orElseThrow(() -> new ServiceException("Prietenia nu exista!"));
        Optional<Utilizator> u1 = utilizatorRepository.findOne(friendship.getUser1ID());
        Optional<Utilizator> u2 = utilizatorRepository.findOne(friendship.getUser2ID());
        u1.ifPresent(user1 -> u2.ifPresent(user2 -> {
            user1.removeFriend(user2);
            user2.removeFriend(user1);
        }));
        prietenieRepository.delete(friendshipId);
        return friendship;
    }

    public Iterable<Utilizator> getUtilizatori() {
        return utilizatorRepository.findAll();
    }

    public Iterable<Prieten> getPrietenii() {
        return prietenieRepository.findAll();
    }
}
