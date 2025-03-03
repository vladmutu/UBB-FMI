"""
Acest modul contine toate functiile care modifica repository-ul
obiectelor Person
"""
from Domain.personDomain import Person


class PersonRepository:
    def __init__(self):
        """
        functie care defineste obiectul PersonRepository ca un dictionar
        """
        self._personList = {

        }

    def addPerson(self,person):
        """
        functie care adauga in dictionar obiectul person
        :param person: de tip Person
        :return:
        """
        personID = person.get_person_ID()
        if personID not in self._personList:
            self._personList[personID] = person
        else:
            raise Exception("ID existent!")

    def deletePerson(self, personID):
        """
        functie care sterge din dictionar obiectul person
        cu ID-ul personID
        :param i:
        :param personID: int
        :return:
        """
        self._personList.pop(personID)


    def updatePerson(self,person):
        """
        functie care actualizeaza in dictionar un obiect
        avand acelasi ID cu person si care va avea in final
        aceleasi date ca si person
        :param person: de tip Person
        :return:
        """
        personID = person.get_person_ID()
        if personID not in self._personList:
            raise Exception("ID persoana inexistent!")
        self._personList[personID] = person


    def searchPerson(self,person_name):
        """
        functie care cauta in dictionar toate persoanele cu
        name person_name
        :param person_name: string
        :return:
        """
        search_list = []
        for person in self.get_allPersons():
            if person.get_person_name() == person_name:
                search_list.append(person)
        if len(search_list) != 0:
            return search_list
        else:
            raise Exception("nume persoana inexistent!")

    def searchPersonID(self,person_id):
        """
        functie de cautare in PersonRepository a unei persoane dupa
        ID-ul sau
        :param person_id:
        :return:
        """
        for person in self.get_allPersons():
            if person.get_person_ID() == person_id:
                return person


    def get_allPersons(self):
        """
        functie care returneaza intreaga lista
        de obiecete person
        :return: [...]
        """
        return [self._personList[x] for x in self._personList.keys()]

    def get_length(self):
        """
        functie care returneaza lungimea liste de persoane
        :return: int
        """
        return len(self._personList)


class FileRepoPerson(PersonRepository):
    def __init__(self, cale_fisier):
        """
        functie de initializare a PersonRepository din fisier
        :param cale_fisier:
        """
        PersonRepository.__init__(self)
        self.__cale_fisier = cale_fisier

    def __read_all_persons_from_file(self):
        """
        functie care citeste din fisier toate atributele si adauga in personList
        :return:
        """
        with open(self.__cale_fisier, "r") as f:
            self._personList.clear()
            i = 0
            lines = f.readlines()
            for line in lines:
                line.strip()
                if line != "" and line != "\n":
                    i += 1
                    if i % 3 == 1:
                        person_id = int(line)
                    elif i % 3 == 2:
                        nume = line
                    else:
                        adresa = line
                        person = Person(person_id, nume, adresa)
                        self._personList[person_id] = person

    def __write_all_persons_to_file(self):
        """
        functie care scrie in fisier lista de persoane
        :return:
        """
        with open(self.__cale_fisier, "w") as f:
            for person_id in self._personList:
                f.write(str(self._personList[person_id].get_person_ID()) + '\n')
                f.write(str(self._personList[person_id].get_person_name()) + '\n')
                f.write(str(self._personList[person_id].get_person_adress()) + '\n')
            f.write('\n')

    def addPerson(self, person):
        """
        functie care adauga in PersonRepo datele citite din fisier
        :param person:
        :return:
        """
        self.__read_all_persons_from_file()
        if person.get_person_ID() not in self._personList:
            PersonRepository.addPerson(self, person)
        else:
            raise Exception("ID persoana existent!")
        self.__write_all_persons_to_file()

    def deletePerson(self,person_id):
        """
        functie care sterge din PersonRepo datele din fisier
        :param person_id: int
        :return:
        """
        self._personList.pop(person_id)
        self.__write_all_persons_to_file()

    def updatePerson(self,person):
        """
        functie care actualizeaza in dictionar un obiect
        avand acelasi ID cu person si care va avea in final
        aceleasi date ca si person
        :param person: de tip Person
        :return:
        """
        personID = person.get_person_ID()
        if personID not in self._personList:
            raise Exception("ID persoana inexistent!")
        self._personList[personID] = person
        self.__write_all_persons_to_file()

    def searchPerson(self,person_name):
        """
        functie care cauta in repo datele citite din fisier
        :param person_name: string
        :return:
        """
        search_list = []
        for person in self.get_allPersons():
            if person.get_person_name() == person_name:
                search_list.append(person)
        if len(search_list) != 0:
            return search_list
        else:
            raise Exception("nume persoana inexistent!")

    def get_allPersons(self):
        """
        functie care returneaza intreaga lista din fisier
        :return:
        """
        self.__read_all_persons_from_file()
        return PersonRepository.get_allPersons(self)