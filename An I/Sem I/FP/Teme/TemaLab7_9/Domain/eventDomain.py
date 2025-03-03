"""
Acest modul defineste obiectul Event
"""


class Event:
    def __init__(self, event_ID,event_date,event_length,event_description):
        """
        aici se definesc campurile acestui obiect
        :param event_ID: int
        :param event_date: string
        :param event_length: int
        :param event_description: string
        """
        self.__event_ID = event_ID
        self.__event_date = event_date
        self.__event_length = event_length
        self.__event_description = event_description

    def get_event_ID(self):
        """
        functie care returneaza ID-ul obiectului Event
        :return: int
        """
        return self.__event_ID

    def get_event_date(self):
        """
        functie care returneaza data obiectului Event
        :return: string
        """
        return self.__event_date

    def get_event_date_year(self):
        event_date = self.__event_date
        event_date = event_date.split('/')
        return event_date[2]

    def get_event_date_month(self):
        event_date = self.__event_date
        event_date = event_date.split('/')
        return event_date[1]

    def get_event_date_day(self):
        event_date = self.__event_date
        event_date = event_date.split('/')
        return event_date[0]

    def get_event_length(self):
        """
        functie care returneaza durata obiectului Event
        :return: int
        """
        return self.__event_length

    def get_event_description(self):
        """
        functie care returneaza descrierea obiectului Event
        :return: string
        """
        return self.__event_description

    def get_event(self):
        return self

    def __str__(self):
        """
        functie de redefinire a parsarii la str care ajuta la printarea obiectului Event
        """
        #return (f"[{self.__event_ID}] Data: {self.__event_date}, Durata: {self.__event_length} ore, "
                #f"Descriere: {self.__event_description}")
        return f"{self.__event_ID},{self.__event_date},{self.__event_length},{self.__event_description}"