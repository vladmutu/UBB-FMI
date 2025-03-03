package org.example.labjavafx.Service;


import java.util.*;
import org.example.labjavafx.Domain.User;
import org.example.labjavafx.Domain.Friendship;
import org.example.labjavafx.Repository.*;

public class NetworkService {
    Service service;
    HashMap<Long, List<Long>> adjList;

    public NetworkService(Service service) {
        this.service = service;
    }

    void DFS(Long v, HashMap<Long, Boolean> visited) {
        visited.put(v, true);
        Optional<User> user = service.findOneUser(v);
        user.ifPresent(value -> System.out.println(v + " " + value.getFirstName() + " " + value.getLastName()));
        if (adjList.containsKey(v)) {
            for (Long x : adjList.get(v)) {
                if (!visited.containsKey(x))
                    DFS(x, visited);
            }
        }
    }

    public int connectedCommunities() {
        adjList = new HashMap<Long, List<Long>>();
        service.getAllUsers().forEach(user -> {
            List<Long> friends = new ArrayList<>();
            service.getFrienships().forEach(friendship -> {
                if (friendship.getId1().equals(user.getId()))
                    friends.add(friendship.getId2());
                if (friendship.getId2().equals(user.getId()))
                    friends.add(friendship.getId1());
            });
            if (!friends.isEmpty())
                this.adjList.put(user.getId(), friends);
        });

        // list of ids of users
        List<Long> ids = new ArrayList<>();
        service.getAllUsers().forEach(user -> ids.add(user.getId()));

        int nrOfCommunities = 0;
        HashMap<Long, Boolean> visited = new HashMap<Long, Boolean>();
        for (Long v : ids) {
            if (!visited.containsKey(v)) {
                DFS(v, visited);
                nrOfCommunities++;
                System.out.println();
            }
        }
        return nrOfCommunities;
    }

    public List<Long> mostSocialCommunity() {
        adjList = new HashMap<>();
        List<Long> max = new ArrayList<>();
        for (User user : service.getAllUsers()) {
            List<Long> friends = new ArrayList<>();
            for (Friendship friendship : service.getFrienships()) {
                if (friendship.getId1().equals(user.getId()))
                    friends.add(friendship.getId2());
                if (friendship.getId2().equals(user.getId()))
                    friends.add(friendship.getId1());
            }
            if (!friends.isEmpty()) {
                this.adjList.put(user.getId(), friends);
                if (max.size() < friends.size() + 1) {
                    max = friends;
                    max.add(user.getId());
                }
            }
        }
        return max;
    }
}
