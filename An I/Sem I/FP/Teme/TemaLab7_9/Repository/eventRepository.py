"""
Acest modul contine toate functiile care modifica repository-ul
obiectelor Event
"""
from Domain.eventDomain import Event


class EventRepository:
    def __init__(self):
        """
        functie care defineste entitatea EventRepository
        ca un dictionar
        """
        self._eventList = {}

    def addEvent(self,event):
        """
        functie care adauga in lista de evenimente
        evenimentul event
        :param event: de tip Event
        :return:
        """
        eventID = event.get_event_ID()
        if eventID in self._eventList:
            raise Exception("ID eveniment existent!")
        self._eventList[eventID] = event

    def deleteEvent(self,eventID):
        """
        functie care sterge din lista de eveniment
        evenimentul cu ID = eventID
        :param eventID: int
        :return:
        """
        if eventID not in self._eventList:
            raise Exception("ID eveniment inexistent!")
        del self._eventList[eventID]

    def updateEvent(self,event):
        """
        functie care actualizeaza obiectul event
        din lista de evenimente cu un nou eveniment
        event cu acelasi ID, dar poate avea alte date
        :param event: de tip Event
        :return:
        """
        eventID = event.get_event_ID()
        if eventID not in self._eventList:
            raise Exception("ID eveniment inexistent!")
        self._eventList[eventID] = event

    def searchEvent(self,event_description):
        """
        functie care cauta in dictionarul de evenimente
        evenimentul cu description = event_description
        :param event_description: string
        :return:
        """
        search_list = []
        for event in self.get_allEvents():
            if event.get_event_description() == event_description:
                search_list.append(event)
        if len(search_list)!=0:
            return search_list
        else:
            raise Exception("descriere inexistenta!")

    def searchEventID(self,event_id):
        """
        functie de cautare a unui eveniment dupa ID
        :param event_id: int event_ID
        :return:
        """
        for event in self.get_allEvents():
            if event_id == event.get_event_ID():
                return event
        raise Exception("ID inexistent!")

    def get_allEvents(self):
        """
        functie care returneaza intreaga lista de evenimente
        ca dictionar
        :return: {...}
        """
        return [self._eventList[x] for x in self._eventList.keys()]

    def get_length(self):
        """
        functie care returneaza lungimea liste de evenimente
        :return: int
        """
        return len(self._eventList)


class FileRepoEvent(EventRepository):
    def __init__(self, cale_fisier):
        """
        functie de initializare a Repository ului din fisier
        :param cale_fisier:
        """
        EventRepository.__init__(self)
        self.__cale_fisier = cale_fisier

    def __read_all_events_from_file(self):
        """
        functie care citeste din fisier toate atributele
        lui event
        :return:
        """
        with open(self.__cale_fisier,"r") as f:
            self._eventList.clear()
            i = 0
            lines = f.readlines()
            for line in lines:
                line.strip()
                if line != "" and line != "\n":
                    i += 1
                    if i % 4 == 1:
                        event_id = int(line)
                    elif i % 4 == 2:
                        event_date = line
                    elif i % 4 == 3:
                        event_length = int(line)
                    else:
                        event_description = line
                        event = Event(event_id, event_date, event_length, event_description)
                        self._eventList[event_id] = event

    def __write_all_events_to_file(self):
        """
        functie de scriere in fisier a evenimentelor din lista de
        evenimente
        :return:
        """
        with open(self.__cale_fisier, "w") as f:
            for event_id in self._eventList:
                f.write(str(self._eventList[event_id].get_event_ID())+"\n")
                f.write(str(self._eventList[event_id].get_event_date())+"\n")
                f.write(str(self._eventList[event_id].get_event_length())+"\n")
                f.write(str(self._eventList[event_id].get_event_description())+"\n")
            f.write('\n')

    def addEvent(self, event):
        """
        functie de adaugare a unui eveniment citit din fisier in dictionarul de evenimente
        :param event: Event
        :return:
        """
        self.__read_all_events_from_file()
        if event.get_event_ID() not in self._eventList:
            EventRepository.addEvent(self, event)
        else:
            raise Exception("ID eveniment existent!")
        self.__write_all_events_to_file()

    def deleteEvent(self,event_id):
        """
        functie de stergere a unui eveniment din dictionarul de evenimente
        care este afisat mai apoi in fisier
        :param event_id:
        :return:
        """
        self._eventList.pop(event_id)
        self.__write_all_events_to_file()

    def searchEvent(self, event_description):
        """
        functie de cautare a unui eveniment
        :param event_description:
        :return:
        """
        search_list = []
        for event in self.get_allEvents():
            if event.get_event_description() == event_description:
                search_list.append(event)
        if len(search_list) != 0:
            return search_list
        else:
            raise Exception("nume eveniment inexistent!")

    def get_all_events(self):
        """
        functie care citeste din fisier intreaga lista de evenimente si o returneaza
        :return:
        """
        self.__read_all_events_from_file()
        return EventRepository.get_allEvents(self)