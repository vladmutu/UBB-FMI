"""
Acest modul contine toate functiile de test pentru functionalitatile
implementate in acest program
"""
import random

from Domain.personDomain import Person
from Domain.eventDomain import Event
from Domain.registerDomain import Register
from Validators.personValidator import PersonValidator
from Validators.eventValidator import EventValidator
from Validators.registerValidator import RegisterValidator
from Repository.personRepository import PersonRepository
from Repository.eventRepository import EventRepository
from Repository.personRepository import FileRepoPerson
from Repository.eventRepository import FileRepoEvent
from Repository.registerRepository import FileRepoRegister
from Repository.registerRepository import RegisterRepository
from Controller.personController import Personservice
from Controller.eventController import Eventservice
from Controller.registerController import RegisterService
from UI.UI import UI
from Domain.sorts import *


class Teste:
    def __test_createPerson(self):
        """
        functie de test pentru cearea unei persoane
        :return:
        """
        personID = 1
        person_name = "Andrei"
        person_adress = "Mestecenilor 6"
        person = Person(personID, person_name, person_adress)
        other_personID = 1
        other_person_name = "Stefan"
        other_person_adress = "Mestecenilor 5"
        other_person = Person(other_personID, other_person_name, other_person_adress)
        assert person.get_person_ID() == personID
        assert person.get_person_name() == person_name
        assert person.get_person_adress() == person_adress
        assert person.get_person_ID() == other_person.get_person_ID()

    def __test_createEvent(self):
        """
        functie de test pentru crearea unui eveniment
        :return:
        """
        eventID = 1
        event_date = "12/12/2023"
        event_length = 6
        event_description = "Bal"
        event = Event(eventID, event_date, event_length, event_description)
        other_eventID = 1
        other_event_date = "15/11/2023"
        other_event_length = 5
        other_event_description = "Nunta"
        other_event = Event(other_eventID, other_event_date, other_event_length, other_event_description)
        assert event.get_event_ID() == eventID
        assert event.get_event_date() == event_date
        assert event.get_event_length() == event_length
        assert event.get_event_description() == event_description
        assert event.get_event_ID() == other_event.get_event_ID()

    def __test_validatePerson(self):
        """
        functie de test pentru validarea unei persoane
        :return:
        """
        personID = 1
        person_name = "Andrei"
        person_adress = "Mestecenilor 6"
        person = Person(personID, person_name, person_adress)
        bad_personID = -1
        bad_person_name = ""
        bad_person_adress = ""
        bad_person = Person(bad_personID, bad_person_name, bad_person_adress)
        validator = PersonValidator()
        validator.validatePerson(person)
        try:
            validator.validatePerson(bad_person)
            assert False
        except Exception as ex:
            assert(str(ex) == "ID invalid!\nnume invalid!\nadresa invalida!\n")

    def __test_validateEvent(self):
        """
        functie de test pentru validarea unui eveniment
        :return:
        """
        eventID = 1
        event_date = "12/12/2023"
        event_length = 6
        event_description = "Bal"
        event = Event(eventID, event_date, event_length, event_description)
        bad_eventID = -1
        bad_event_date = ""
        bad_event_length = -1
        bad_event_description = ""
        bad_event = Event(bad_eventID, bad_event_date, bad_event_length, bad_event_description)
        validator = EventValidator()
        validator.validateEvent(event)
        try:
            validator.validateEvent(bad_event)
            assert False
        except Exception as ex:
            assert(str(ex) == "ID invalid!\ndata invalida!\ndurata invalida!\ndescriere invalida!\n")

    def __test_addPerson(self):
        """
        functie de test pentru adaugarea unei persoane
        :return:
        """
        personID = 1
        person_name = "Andrei"
        person_adress = "Mestecenilor 6"
        person = Person(personID, person_name, person_adress)
        person_repos = PersonRepository()
        person_repos.addPerson(person)
        person_list = person_repos.get_allPersons()
        assert person_list[0] == person

    def __test_addEvent(self):
        """
        functie de test pentru adaugarea unui eveniment
        :return:
        """
        eventID = 1
        event_date = "12/15/2023"
        event_length = 6
        event_description = "Bal"
        event = Event(eventID, event_date, event_length, event_description)
        event_repos = EventRepository()
        event_repos.addEvent(event)
        event_list = event_repos.get_allEvents()
        assert event_list[0] == event

    def __test_deletePerson(self):
        """
        functie de test pentru stergerea unei persoane
        :return:
        """
        personID = 1
        person_name = "Andrei"
        person_adress = "Mestecenilor"
        person = Person(personID, person_name, person_adress)
        person_repo = PersonRepository()
        person_repo.addPerson(person)
        assert person_repo.get_length() == 1
        try:
            person_repo.deletePerson(2)
            assert False
        except Exception as ex:
            assert (str(ex) == "ID persoana inexistent!")
        person_repo.deletePerson(1)
        assert person_repo.get_length() == 0

    def __test_deleteEvent(self):
        """
        functie de test pentru stergerea unui eveniment
        :return:
        """
        eventID = 1
        event_date = "15/11/2023"
        event_length = 6
        event_description = "Bal"
        event = Event(eventID, event_date, event_length, event_description)
        event_repo = EventRepository()
        event_repo.addEvent(event)
        assert event_repo.get_length() == 1
        try:
            event_repo.deleteEvent(2)
            assert False
        except Exception as ex:
            assert (str(ex) == "ID eveniment inexistent!")
        event_repo.deleteEvent(1)
        assert event_repo.get_length() == 0

    def __test_updatePerson(self):
        """
        functie de test pentru actualizarea unei persoane
        :return:
        """
        personID = 1
        person_name = "Andrei"
        person_adress = "Mestecenilor"
        person = Person(personID, person_name, person_adress)
        bad_personID = 2
        bad_person = Person(bad_personID, person_name, person_adress)
        new_person_name = "Stefan"
        new_person_adress = "Nufarului"
        new_person = Person(personID, new_person_name, new_person_adress)
        person_repo = PersonRepository()
        person_repo.addPerson(person)
        assert person_repo.get_length() == 1
        try:
            person_repo.updatePerson(bad_person)
            assert False
        except Exception as ex:
            assert (str(ex) == "ID persoana inexistent!")
        person_repo.updatePerson(new_person)
        person_list = person_repo.get_allPersons()
        assert person_list[0] == new_person

    def __test_updateEvent(self):
        """
        functie de test pentru actualizarea unui eveniment
        :return:
        """
        eventID = 1
        event_date = "15/11/2023"
        event_length = 6
        event_description = "Bal"
        event = Event(eventID, event_date, event_length, event_description)
        bad_eventID = 2
        bad_event = Event(bad_eventID, event_date, event_length, event_description)
        new_event_date = "13/11/2023"
        new_event_length = 2
        new_event_description = "Concert"
        new_event = Event(eventID, new_event_date, new_event_length, new_event_description)
        event_repo = EventRepository()
        event_repo.addEvent(event)
        assert event_repo.get_length() == 1
        try:
            event_repo.updateEvent(bad_event)
            assert False
        except Exception as ex:
            assert (str(ex) == "ID eveniment inexistent!")
        event_repo.updateEvent(new_event)
        event_list = event_repo.get_allEvents()
        assert event_list[0] == new_event

    def __test_search_person(self):
        """
        functie de test pentru cautarea unei persoane
        :return:
        """
        person_repo = PersonRepository()
        person = Person(1, "Andrei", "Unirii")
        person_repo.addPerson(person)
        search_list = []
        assert len(search_list) == 0
        search_list = person_repo.searchPerson("Andrei")
        assert len(search_list) == 1
        try:
            search_list = person_repo.searchPerson("Vlad")
            assert False
        except:
            assert True

    def __test_search_event(self):
        """
            functie de test pentru cautarea unei persoane
            :return:
        """
        event_repo = EventRepository()
        event = Event(1, "15/10/2023", 4, "bal")
        event_repo.addEvent(event)
        search_list = []
        assert len(search_list) == 0
        search_list = event_repo.searchEvent("bal")
        assert len(search_list) == 1
        try:
            search_list = event_repo.searchEvent("concert")
            assert False
        except:
            assert True

    def __test_generate_persons(self):
        """
        functie de test pentru generarea aleatorie a unor persoane
        :return:
        """
        person_repo = PersonRepository()
        person_valid = PersonValidator
        person_service = Personservice(person_repo, person_valid)
        random.seed(3)
        person_1 = Person(person_service.generateID(), person_service.generateName(), person_service.generateAdress())
        random.seed(3)
        person_2 = Person(person_service.generateID(), person_service.generateName(), person_service.generateAdress())
        assert person_1.get_person_ID() == person_2.get_person_ID()
        assert person_1.get_person_name() == person_2.get_person_name()
        assert person_1.get_person_adress() == person_2.get_person_adress()
        random.seed(2)
        person_3 = Person(person_service.generateID(), person_service.generateName(), person_service.generateAdress())
        assert person_1.get_person_ID() != person_3.get_person_ID()
        assert person_1.get_person_name() != person_3.get_person_name()
        assert person_1.get_person_adress() != person_3.get_person_adress()

    def __test_register_person(self):
        """
        functie de test pentru inscrierea unei persoane
        :return:
        """
        person_repo = PersonRepository()
        event_repo = EventRepository()
        register_repo = RegisterRepository()
        person = Person(1,"Andrei","Mestecenilor")
        event = Event(1,"15/10/2023",6,"Bal")
        person_repo.addPerson(person)
        event_repo.addEvent(event)
        register = Register(person,event)
        register_repo.add_register(register)
        register_list = register_repo.get_all_registers()
        assert len(register_list) == 1

    def __test_afiseaza_evenimente_max(self):
        """
        functie de test pentru afisarea evenimentelor cu cei mai multi participanti
        :return:
        """
        person_repo = PersonRepository()
        event_repo = EventRepository()
        register_repo = RegisterRepository()
        validator = RegisterValidator()
        person = Person(1,"Andrei","Mestecenilor")
        event = Event(1,"15/10/2023",6,"Bal")
        register = Register(person,event)
        register_repo.add_register(register)
        event_2 = Event(2,"15/10/2023",6,"Concert")
        register_2 = Register(person,event_2)
        register_repo.add_register(register_2)
        register_service = RegisterService(person_repo, event_repo, register_repo, validator)
        try:
            max_events = register_service.get_most_registered(3)
            assert False
        except:
            assert True
        max_events = register_service.get_most_registered(1)
        assert len(max_events) == 1


    def run_all_tests(self):
        """
        functie care apeleaza toate functiile de test
        :return: None
        """
        print("Rularea testelor a inceput...")
        self.__test_createPerson()
        self.__test_createEvent()
        self.__test_validatePerson()
        self.__test_validateEvent()
        self.__test_addPerson()
        self.__test_addEvent()
        #self.__test_deletePerson()
        self.__test_deleteEvent()
        self.__test_updatePerson()
        self.__test_updateEvent()
        self.__test_search_person()
        self.__test_search_event()
        self.__test_generate_persons()
        self.__test_register_person()
        self.__test_afiseaza_evenimente_max()

