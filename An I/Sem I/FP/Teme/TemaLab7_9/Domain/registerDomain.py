"""
acest modul va folosi la generarea clasei de inscrieri la evenimente
"""


class Register:
    __register_id = 0

    def __init__(self, person, event):
        """
        functie de initalizare a clasei Register
        :param person:
        :param event:
        """
        Register.__register_id += 1
        self.__registered_person = person
        self.__registered_event = event

    def get_register_id(self):
        """
        functie getter pentru ID built in a fiecarui register
        :return:
        """
        return self.__register_id

    def get_registered_person(self):
        """
        functie getter pentru persoana inscrisa
        :return:
        """
        return self.__registered_person

    def get_registered_event(self):
        """
        functie getter pentru evenimentul la care este inscris persoana
        :return:
        """
        return self.__registered_event

    def __str__(self):
        """return (f"[{self.__registered_person.get_person_ID()}] Nume: {self.__registered_person.get_person_name()}, "
                f"Adresa: {self.__registered_person.get_person_adress()} inscris la evenimentul "
                f"[{self.__registered_event.get_event_ID()}], Data: {self.__registered_event.get_event_date()}, "
                f"Durata: {self.__registered_event.get_event_length()} ore, Descriere: "
                f"{self.__registered_event.get_event_description()}")"""
        return (f"{self.__registered_person.get_person_ID()},{self.__registered_person.get_person_name()},"
                f"{self.__registered_person.get_person_adress()}{self.__registered_event.get_event_ID()},"
                f"{self.__registered_event.get_event_date()},{self.__registered_event.get_event_length()},"
                f"{self.__registered_event.get_event_description()}")

