package org.example.demo1.Service;

import javafx.beans.InvalidationListener;
import javafx.collections.ObservableArray;
import org.example.demo1.Domain.Show;
import org.example.demo1.Domain.User;
import org.example.demo1.Domain.Validators.ServiceException;
import org.example.demo1.Repository.PagingRepository;
import org.example.demo1.Repository.Repository;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;
import java.util.stream.Stream;
import java.util.stream.StreamSupport;

import org.example.demo1.Repository.ShowDBRepository;
import org.example.demo1.Repository.UserDBRepository;
import org.example.demo1.Utils.*;

public class Service implements Observable<Show> {

    private Repository<Integer, User> userRepository;
    private PagingRepository<Integer, Show> showRepository;
    private List<Observer<Show>> observers = new ArrayList<>();

    public Service(UserDBRepository userDBRepository, ShowDBRepository showDBRepository) {
        this.showRepository = showDBRepository;
        this.userRepository = userDBRepository;
    }

    @Override
    public void addObserver(Observer<Show> observer) {
        observers.add(observer);
    }

    @Override
    public void removeObserver(Observer<Show> observer) {
        observers.remove(observer);
    }

    @Override
    public void notifyObservers(Show event) {
        observers.forEach(o-> o.update(event));
    }

    public void addShow(Show show) {
        List<Show> identicalShows = StreamSupport.stream(showRepository.findAll().spliterator(), false)
                .filter(existingShow -> existingShow.getStartDate().equals(show.getStartDate()))
                .toList();
        if (!identicalShows.isEmpty()) {
            throw new ServiceException("The show cannot be scheduled at the specified time as " + identicalShows.get(0).getName() +
                    " will be playing at that time");
        }
        else{
            showRepository.save(show);
        }
        Show reserved = new Show("", -1, null, -1, null);
        reserved.setId(-1);
        notifyObservers(reserved);
    }

    public List<Show> getShows() {
        return StreamSupport.stream(showRepository.findAll().spliterator(), false)
                .collect(Collectors.toList());
    }

    public Page<Show> getShowsOnPage(Pageable pageable) {
        return showRepository.findAllOnPage(pageable);
    }


    public void reserveSeat(Show s) {
        showRepository.update(s);
        Show reserved = new Show("", -1, null, -1, null);
        reserved.setId(-2);
        notifyObservers(reserved);
    }
}
