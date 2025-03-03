package Controller;

import Domain.Prieten;
import Domain.Utilizator;
import Repository.Repository;

import java.util.*;

public class NetworkService {
    Service service;
    HashMap<Long, List<Long>> adjList;

    public NetworkService(Service service) {
        this.service = service;
    }

    void DFS(Long v, HashMap<Long, Boolean> visited) {
        visited.put(v, true);
        System.out.println(v + " " + this.service.findUser(v).getFirstName() + " " + this.service.findUser(v).getLastName());
        if (adjList.containsKey(v)) {
            for (Long x : adjList.get(v)) {
                if (!visited.containsKey(x))
                    DFS(x, visited);
            }
        }
    }

    public int connectedCommunities() {
        adjList = new HashMap<Long, List<Long>>();
        service.getUtilizatori().forEach(user -> {
            List<Long> friends = new ArrayList<>();
            service.getPrietenii().forEach(friendship -> {
                if (friendship.getUser1ID().equals(user.getId()))
                    friends.add(friendship.getUser2ID());
                if (friendship.getUser2ID().equals(user.getId()))
                    friends.add(friendship.getUser1ID());
            });
            if (!friends.isEmpty())
                this.adjList.put(user.getId(), friends);
        });

        // list of ids of users
        List<Long> ids = new ArrayList<>();
        service.getUtilizatori().forEach(user -> ids.add(user.getId()));

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
        for (Utilizator user : service.getUtilizatori()) {
            List<Long> friends = new ArrayList<>();
            for (Prieten friendship : service.getPrietenii()) {
                if (friendship.getUser1ID().equals(user.getId()))
                    friends.add(friendship.getUser2ID());
                if (friendship.getUser2ID().equals(user.getId()))
                    friends.add(friendship.getUser1ID());
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
