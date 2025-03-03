"""
Acest modul contine clasa de service a obiectului signing
"""

from Domain.registerDomain import Register
from Domain.personDomain import Person
from Domain.eventDomain import Event
from Domain.topParticipantiDomain import TopParticipanti
from Domain.sorts import *

class RegisterService:
    def __init__(self, repo_person, repo_event, repo_register, register_validator):
        """
        functie de initializare a clasei de service al inscrierilor
        :param repo_person: PersonRepository
        :param repo_event: EventRepository
        :param repo_register: RegisterRepository
        :param register_validator: RegisterValidator
        """
        self.__repo_person = repo_person
        self.__repo_event = repo_event
        self.__repo_register = repo_register
        self.__register_validator = register_validator

    def register_person(self, person_id, event_id):
        """
        functie de inscriere persoana in RegisterPerson
        :param person_id: int
        :param event_id: int
        :return:
        """
        registered_person = 0
        registered_event = 0
        ok = False
        person_list = self.__repo_person.get_allPersons()
        for person in person_list:
            if person.get_person_ID() == person_id:
                ok = True
                registered_person = Person(person.get_person_ID(), person.get_person_name(), person.get_person_adress())
        if not ok:
            raise Exception("persoana inexistenta!")
        event_list = self.__repo_event.get_allEvents()
        ok = False
        for event in event_list:
            if event.get_event_ID() == event_id:
                ok = True
                registered_event = Event(event.get_event_ID(), event.get_event_date(), event.get_event_length(),
                                         event.get_event_description())
        if not ok:
            raise Exception("eveniment inexistent!")
        else:
            register = Register(registered_person, registered_event)
            register_list = self.__repo_register.get_all_registers()
            self.__register_validator.ValidateRegister(register)
            for reg in register_list:
                if (register_list[reg].get_registered_person().get_person_ID() ==
                        register.get_registered_person().get_person_ID() and
                        register_list[reg].get_registered_event().get_event_ID()
                        == register.get_registered_event().get_event_ID()):
                    raise Exception("Persoana deja inscrisa!")
            self.__repo_register.add_register(register)

    def get_all_registers(self):
        """
        functie care returneaza intreaga lista de inscrieri
        :return: list
        """
        return self.__repo_register.get_all_registers()

    def get_top_registers(self):
        """
        afiseaza top 20% evenimente cu cei mai multi participanti
        :return:
        """
        registers = self.__repo_register.get_all_registers()
        nr_participari = {}
        for atendance in registers:
            event_id = registers[atendance].get_registered_event().get_event_ID()
            if event_id not in nr_participari:
                nr_participari[event_id] = 0
            nr_participari[event_id] += 1
        rez = []
        for event_id in nr_participari:
            event_description = self.__repo_event.searchEventID(event_id).get_event_description()
            atendance_nr = nr_participari[event_id]
            event_atendace = TopParticipanti(event_description, atendance_nr)
            rez.append(event_atendace)
        rez.sort(key=lambda x: x.get_register_nr(), reverse=True)
        k = len(rez) / 5
        k = int(k)
        if k < 1 and len(self.__repo_event.get_allEvents()) >= 5:
            return rez
        else:
            if k >= 1:
                return rez[:k]
            else:
                raise Exception("evenimente insuficiente!")

    def get_most_registered(self, k):
        """
        afiseaza k persoane participante la cele mai multe evenimente
        :param k: int
        :return:
        """
        # n = len(registers)
        registers = self.__repo_register.get_all_registers()  # T(n) = n
        nr_participari = {}
        for atendance in registers:  # T(n) = n
            person_id = registers[atendance].get_registered_person().get_person_ID()  # T(n) = 1
            if person_id not in nr_participari:  # T(n) = 1
                nr_participari[person_id] = 0  # T(n) = 1
            nr_participari[person_id] += 1  # T(n) = 1
        rez = []
        for person_id in nr_participari:  # WC(n) = n
            rez.append(self.__repo_person.searchPersonID(person_id))  # T(n) = 1
        if k > len(rez):
            raise Exception("persoane inscrise insuficiente!")
        else:
            return rez[:k]
        # n = len(registers)
        # Worst case scenario = n + n * 3 + n + n - k ~ 6 * n - k
        # Best case Scenario = 2 * n + 1 + n - k = 3 * n - k + 1 pentru cazul in care
        # aceeasi persoana participa la evenimente
        # Average case Scenario = n + n + n/2 + n/2 + n - k ~ 5 * n - k  fiecare persoana participa
        # la cel putin doua evenimente

    def get_events_description(self, person_id):
        """
        functie care returneaza lista de evenimente
        la care participa o persoana ordonata dupa descriere
        :param person_id: int
        :return: list
        """
        registers = self.__repo_register.get_all_registers()
        events_list = []
        for register in registers:
            new_person_id = registers[register].get_registered_person().get_person_ID()
            if person_id == new_person_id:
                event = registers[register].get_registered_event()
                events_list.append(event)
        recursive_selection_sort(events_list, len(events_list))
        return events_list

    def get_events_date(self, person_id):
        """
        functie care returneaza lista de evenimente
        la care participa o persoana ordonata dupa data
        :param person_id: int
        :return:
        """
        registers = self.__repo_register.get_all_registers()
        events_list = []
        for register in registers:
            new_person_id = registers[register].get_registered_person().get_person_ID()
            if person_id == new_person_id:
                event = registers[register].get_registered_event()
                events_list.append(event)
        new_events_list = cocktail_sort(events_list)
        return new_events_list
