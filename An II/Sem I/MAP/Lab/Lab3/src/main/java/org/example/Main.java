package org.example;
import Domain.Prieten;
import Domain.Utilizator;
import Domain.Validators.PrietenValidator;
import Domain.Validators.UtilizatorValidator;
import Repository.Repository;
import UI.Console;
import Controller.Service;
import Controller.NetworkService;
import Repository.UtilizatorRepository;
import Repository.InMemoryRepository;
import Repository.PrietenieRepository;
import Repository.UtilizatorDBRepository;
import Repository.PrietenieDBRepository;
//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {


        /*Repository<Long, Utilizator> utilizatorRepository = new UtilizatorRepository(new UtilizatorValidator(), "utilizatori.txt");
        Repository<Long, Prieten> prietenieRepository = new PrietenieRepository(new PrietenValidator(), "prietenii.txt");

        Service service = new Service(utilizatorRepository, prietenieRepository);
        NetworkService net = new NetworkService(service);

        Console console = new Console(service, net);
        console.run();*/
        String username="postgres";
        String password="vldm19";
        String url="jdbc:postgresql://localhost:5432/proiect_map";
        Repository<Long,Utilizator> utilizatorRepository = new UtilizatorDBRepository(url,username, password, new UtilizatorValidator());
        Repository<Long, Prieten> prietenieRepository = new PrietenieDBRepository(url, username, password, new PrietenValidator());

        Service service = new Service(utilizatorRepository, prietenieRepository);
        NetworkService net = new NetworkService(service);

        Console console = new Console(service, net);
        console.run();
    }
}