"""
Acest modul contine clasa de service a obiectului event
"""

from Domain.eventDomain import Event


class Eventservice:
    def __init__(self, event_repo, event_validator):
        """
        functie care defineste obiectul eventService
        :param event_repo: de tip EventRepository
        :param event_validator: de tip EventValidator
        """
        self.__eventRepo = event_repo
        self.__eventValidator = event_validator

    def addEvent(self, eventID, event_date, event_length, event_description):
        """
        functie care apeleaza metoda de adaugare a obiectului
        event validat cu EventValidator in EventRepository
        :param eventID: int
        :param event_date: string
        :param event_length: int
        :param event_description: string
        :return:
        """
        event = Event(eventID, event_date, event_length, event_description)
        self.__eventValidator.validateEvent(event)
        self.__eventRepo.addEvent(event)

    def deleteEvent(self, eventID):
        """
        functie care apeleaza metoda de stergere a obiectului event cu ID-ul eventID
        din EventRepository
        :param eventID: int
        :return:
        """
        self.__eventRepo.deleteEvent(eventID)

    def updateEvent(self,eventID,event_date,event_length,event_description):
        """
        functie de apelare a metodei de actualizare a unui obiect event din EventRepositoru avand ID-ul eventID
        prin inlocuirea cu noul obiect event validat cu EventValidator
        :param eventID: int
        :param event_date: string
        :param event_length: int
        :param event_description: string
        :return:
        """
        event = Event(eventID,event_date,event_length,event_description)
        self.__eventValidator.validateEvent(event)
        self.__eventRepo.updateEvent(event)

    def searchEvent(self,event_description):
        """
        functie care apeleaza metoda de cautare a unui eveniment dupa nume
        :param event_description: string
        :return:
        """
        return self.__eventRepo.searchEvent(event_description)

    def search_event_id_recursive(self, event_id, i):

        """
        functie recursiva de cautare a unui eveniment
        dupa id
        :param i: int
        :param event_id: int
        :return: event
        """
        events = self.get_allEvents()
        if i > len(events):
            raise Exception("ID eveniment inexistent!")
        if events[i].get_event_ID() == event_id:
            return events[i]
        i = i + 1
        return self.search_event_id_recursive(event_id, i)


    def get_allEvents(self):
        """
        functie care apeleaza metoda de obtinere a tuturor elementelor din
        EventRepository
        :return: dictionar ce contine toate obiectele Event
        """
        return self.__eventRepo.get_allEvents()
