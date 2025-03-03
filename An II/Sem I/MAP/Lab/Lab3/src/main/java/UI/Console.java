package UI;

import Domain.Utilizator;
import Domain.Prieten;
import Domain.Validators.ServiceException;
import Domain.Validators.ValidationException;
import Controller.NetworkService;
import Controller.Service;
import java.util.Scanner;

public class Console {
    private Service service;
    private NetworkService networkService;

    public Console(Service service, NetworkService networkService) {
        this.service = service;
        this.networkService = networkService;
    }

    public void run() {
        Scanner scanner = new Scanner(System.in);
        while (true) {
            displayMenu();
            System.out.print("Alege o optiune: ");
            String option = scanner.nextLine();
            switch (option) {
                case "1":
                    addUser(scanner);
                    break;
                case "2":
                    removeUser(scanner);
                    break;
                case "3":
                    addFriendship(scanner);
                    break;
                case "4":
                    removeFriendship(scanner);
                    break;
                case "5":
                    showCommunities();
                    break;
                case "6":
                    showMostSociableCommunity();
                    break;
                case "7":
                    afiseazaUtilizatori();
                    break;
                case "8":
                    afiseazaPrietenii();
                    break;
                case "0":
                    return;
                default:
                    System.out.println("Optiune invalida!\n");
            }
        }
    }

    private void displayMenu() {
        System.out.println("\nMeniu Principal");
        System.out.println("1. Adauga utilizator");
        System.out.println("2. Sterge utilizator");
        System.out.println("3. Adauga prietenie");
        System.out.println("4. Sterge prietenie");
        System.out.println("5. Numarul de comunitati");
        System.out.println("6. Cea mai sociabila comunitate");
        System.out.println("7. Afiseaza utilizatorii");
        System.out.println("8. Afiseaza prieteniile");
        System.out.println("0. Exit");
    }

    private void addUser(Scanner scanner) {
        System.out.println("Introdu prenumele:");
        String firstName = scanner.nextLine();
        System.out.println("Introdu numele:");
        String lastName = scanner.nextLine();
        try
        {
            service.addUtilizator(firstName, lastName);
            System.out.println("Utilizator adaugat cu succes.");
        }
        catch (ValidationException e) {
            System.out.println(e.getMessage());
        }
    }

    private void removeUser(Scanner scanner) {
        System.out.println("Introdu ID-ul utilizatorului:");
        Long userId = Long.parseLong(scanner.nextLine());
        Utilizator user = service.removeUtilizator(userId);
        if (user != null) {
            System.out.println("Utilizator sters.");
        } else {
            System.out.println("Utilizatorul nu a fost gasit.");
        }
    }

    private void addFriendship(Scanner scanner) {
        System.out.println("ID utilizator 1:");
        Long userId1 = Long.parseLong(scanner.nextLine());
        System.out.println("ID utilizator 2:");
        Long userId2 = Long.parseLong(scanner.nextLine());
        try {
            service.addPrietenie(userId1, userId2);
            System.out.println("Prietenie adaugata cu succes");
        }
        catch (ValidationException e) {
            System.out.println(e.getMessage());
        }
        catch (ServiceException e) {
            System.out.println(e.getMessage());
        }
    }

    private void removeFriendship(Scanner scanner) {
        System.out.println("Introdu ID-ul prieteniei:");
        Long friendshipId = Long.parseLong(scanner.nextLine());
        Prieten friendship = service.removePrietenie(friendshipId);
        if (friendship != null) {
            System.out.println("Prietenie stearsa.");
        } else {
            System.out.println("Prietenia nu a fost gasita.");
        }
    }

    private void showCommunities() {
        int numberOfCommunities = networkService.connectedCommunities();
        System.out.println("Nr comunitati: " + numberOfCommunities);
    }

    private void afiseazaUtilizatori() {
        System.out.println("Utilizatorii sunt:");
        for (Utilizator user : service.getUtilizatori()) {
            System.out.println(user.getId() + ": " + user + " prieteni: ");
            for(Prieten u: service.getPrietenii()) {
                if(u.getUser1ID().equals(user.getId())) {
                    System.out.println(service.findUser(u.getUser2ID()).getFirstName() + " " + service.findUser(u.getUser2ID()).getLastName());
                }
                if(u.getUser2ID().equals(user.getId())) {
                    System.out.println(service.findUser(u.getUser1ID()).getFirstName() + " " + service.findUser(u.getUser1ID()).getLastName());
                }
            }
        }
    }

    private void afiseazaPrietenii() {
        System.out.println("Prieteniile existente sunt:");
        for (Prieten friendship : service.getPrietenii()) {
            System.out.println(friendship.getId() + ": " + friendship);
        }
    }

    private void showMostSociableCommunity() {
        System.out.println("Cea mai sociabila comunitate este:");
        for (Long user : networkService.mostSocialCommunity()) {
            System.out.println(user + ": " + service.findUser(user).getFirstName() + " " + service.findUser(user).getLastName());
        }
    }

}
