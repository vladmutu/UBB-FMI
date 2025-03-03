"""
Acest modul contine clasa cu functia de validare a obiectului person
"""

class PersonValidator:
    def validatePerson(self,person):
        """

        :param person: de tip Person
        :return:
        functie de validarea a obiectului person
        """
        erori = ""
        if person.get_person_ID() < 0:
            erori += "ID invalid!\n"
        if person.get_person_name() == "":
            erori += "nume invalid!\n"
        if person.get_person_adress() == "":
            erori += "adresa invalida!\n"
        if len(erori) > 0:
            raise Exception(erori)