"""
Acest modul contine clasa de service a obiectului person
"""

from Domain.personDomain import Person
import random
import string


class Personservice:
    def __init__(self, person_repo, person_validator):
        """
        functie care defineste obiectul personService
        :param person_repo: de tip PersonRepository
        :param person_validator: de tip PersonValidator
        """
        self.__personRepo = person_repo
        self.__validatePerson = person_validator

    def addPerson(self, personID, person_name, person_adress):
        """
        functie care apeleaza metoda de adaugare in PersonRepository un obiect de tip person
        care este validat de PersonValidator
        :param personID: int
        :param person_name: string
        :param person_adress: string
        :return:
        """
        person = Person(personID, person_name, person_adress)
        self.__validatePerson.validatePerson(person)
        self.__personRepo.addPerson(person)

    def deletePerson(self,personID):
        """
        functie care apeleaza metoda de stergere din PersonRepository obiectul cu ID-ul primit
        ca parametru
        :param personID: int
        :return:
        """
        self.__personRepo.deletePerson(personID)

    def updatePerson(self, personID,person_name,person_adress):
        """
        functie care apeleaza metoda de actualizare in PersonRepository obiectul person
        validat cu PersonValidator
        :param personID: int
        :param person_name: string
        :param person_adress: string
        :return:
        """
        person = Person(personID,person_name,person_adress)
        self.__validatePerson.validatePerson(person)
        self.__personRepo.updatePerson(person)

    def searchPerson(self,person_name):
        """
        functie care apeleaza metoda de cautare in PersonRepository a
        obiectelor person cu name = person_name
        :param person_name: string
        :return:
        """
        return self.__personRepo.searchPerson(person_name)

    def generateID(self):
        return random.randint(0,100000)

    def generateName(self):
        person_name = "".join(random.choices(string.ascii_uppercase, k=1))
        person_name += "".join(random.choices(string.ascii_lowercase, k=random.randint(3, 8)))
        person_name += " "
        person_name += "".join(random.choices(string.ascii_uppercase, k=1))
        person_name += "".join(random.choices(string.ascii_lowercase, k=random.randint(5, 9)))
        return person_name

    def generateAdress(self):
        person_adress = "".join(random.choices(string.ascii_uppercase, k=1))
        person_adress += "".join(random.choices(string.ascii_lowercase, k=random.randint(6, 14)))
        person_adress += " "
        person_adress += "".join(random.choices(string.digits, k=random.randint(1, 2)))
        return person_adress

    def generatePersons(self, personNumber):
        """
        functie care apeleaza metoda de adaugare in
        PersonRepository a unor obiecte random cu
        date aleatorii care sunt validate cu un PersonValidator
        :param personNumber: int
        :return:
        """
        random.seed(random.randint(0,100))
        for x in range(0,personNumber):
            personID = self.generateID()
            person_name = self.generateName()
            person_adress = self.generateAdress()
            person = Person(personID,person_name,person_adress)
            self.__validatePerson.validatePerson(person)
            self.__personRepo.addPerson(person)

    def search_person_id_recursive(self, person_id, i):

        """
        functie recursiva de cautare a unui eveniment
        dupa id
        :param i: int
        :param person_id: int
        :return: event
        """
        persons = self.get_allPersons()
        if i > len(persons):
            raise Exception("ID persoana inexistent!")
        if persons[i].get_person_ID() == person_id:
            return persons[i]
        i = i + 1
        return self.search_person_id_recursive(person_id, i)

    def get_allPersons(self):
        """
        functie care apeleaza metoda de obtinere a tuturor obiectelor
        din PersonRepository
        :return: dictionar ce contine toate obiectele Person
        """
        return self.__personRepo.get_allPersons()


