"""
Acest modul defineste obiectul Person
"""


class Person:
    def __init__(self,person_ID,person_name,person_adress):
        """
        aici se definesc campurile acestui obiect
        :param person_ID: int
        :param person_name: string
        :param person_adress: string
        """
        self.__person_ID = person_ID
        self.__person_name = person_name
        self.__person_adress = person_adress

    def get_person_ID(self):
        """
        functie care returneaza ID-ul obiectului Person
        :return: int
        """
        return self.__person_ID

    def get_person_name(self):
        """
        functie care returneaza numele obiectului Person
        :return: string
        """
        return self.__person_name

    def get_person_adress(self):
       """
       functie care returneaza adresa obiectului Person
       :return:
       """
       return self.__person_adress

    def get_person(self):
        return self

    def __str__(self):
        """
        functie de redefinire a parsarii la str care ajuta la printarea obiectului Person
        """
        #return f"[{self.__person_ID}] Nume: {self.__person_name}, Adresa:{self.__person_adress}"
        return f"{self.__person_ID},{self.__person_name},{self.__person_adress}"


