"""
Acest modul contine toate functiile care citesc comenzi si date si care afiseaza corespunzator mesaje
in legatura cu datele si comenzile introduse sau prompt uri pentru a comunica cu USER-ul
"""


class UI:
    def __init__(self, service_persons, service_events, service_register):
        """

        :param service_persons: de tip servicePerson
        :param service_events: de tip serviceEvent

        se definesc comenzile care vor apela functii care vor trimite catre
        cele doua obiecte de tip service instructiunile/datele necesare functionarii
        programului

        """
        self.__service_Persons = service_persons
        self.__service_Events = service_events
        self.__service_Register = service_register
        self.__commandz = {
            "adauga_persoana": self.__ui_add_Person,
            "afiseaza_lista_de_persoane": self.__ui_printPersons,
            "adauga_eveniment": self.__ui_add_Event,
            "afiseaza_lista_de_evenimente": self.__ui_printEvents,
            "sterge_persoana": self.__ui_deletePerson,
            "sterge_eveniment": self.__ui_deleteEvent,
            "actualizeaza_persoana": self.__ui_updatePerson,
            "actualizeaza_eveniment": self.__ui_updateEvent,
            "cauta_persoana": self.__ui_searchPersonDescription,
            "cauta_eveniment": self.__ui_searchEvent,
            "genereaza_persoane": self.__ui_generatePersons,
            "inscrie_persoana": self.__ui_registerPerson,
            "afiseaza_lista_de_inscrieri": self.__ui_printRegisters,
            "afiseaza_evenimentele_cu_cei_mai_multi_participanti_20": self.__ui_printTopRegisters,
            "afiseaza_persoanele_inscrise_la_cele_mai_multe_evenimente": self.__ui_printMostRegisteredPersons,
            "afiseaza_evenimentele_sortate_dupa_descriere": self.__ui_printEventsDescription,
            "afiseaza_evenimentele_sortate_dupa_data": self.__ui_printEventsDate,
            "cauta_eveniment_dupa_id": self.__ui_searchEventID,
            "cauta_persoana_dupa_id": self.__ui_searchPersonID,
            "exit": self.__ui_exit,
        }

    def __ui_exit(self, params):
        """

        :param params: nimic
        :return: nimic

        aceasta functie este responsabila pentru iesirea din intreg programul

        """
        if len(params) != 0:
            print("nr parametrii invalid ")
            return
        exit()

    def __ui_printPersons(self, params):
        """

        :param params: nimic
        :return: nimic

        aceasta functie afiseaza lista de persoane

        """
        if len(params) != 0:
            print("nr parametrii invalid!")
            return
        person_list = self.__service_Persons.get_allPersons()
        for person in person_list:
            print(person)

    def __ui_searchEventID(self, params):
        """
        functie care apeleaza functia de cautare a unui
        eveniment dupa ID
        :param params: event_id : int
        :return:
        """
        if len(params) != 1:
            print("nr parametrii invalid!")
            return
        try:
            event_id = int(params[0])
        except ValueError:
            raise Exception("parametrii invalizi!")
        try:
            event = self.__service_Events.search_event_id_recursive(event_id, 0)
            print(event)
        except Exception as ex:
            if ex != "ID eveniment inexistent!":
                raise Exception("ID eveniment inexistent!")


    def __ui_searchPersonID(self, params):
        """
        functie care apeleaza functia de cautare a unui
        eveniment dupa ID
        :param params: event_id : int
        :return:
        """
        if len(params) != 1:
            print("nr parametrii invalid!")
            return
        try:
            person_id = int(params[0])
        except ValueError:
            raise Exception("parametrii invalizi!")
        try:
            person = self.__service_Persons.search_person_id_recursive(person_id, 0)
            print(person)
        except Exception as ex:
            if ex != "ID persoana inexistent!":
                raise Exception("ID persoana inexistent!")

    def __ui_add_Person(self, params):
        """

        :param params:  ID de tip int
                        nume de tip string
                        adresa de tip string
        :return: nimic

        aceasta functie este responsabila pentru transmiterea parametrilor
        ce vor defini obiectul person

        """
        if len(params) != 3:
            print("nr parametrii invalid!")
            return
        try:
            personID = int(params[0])
            person_name = params[1]
            person_adress = params[2]
        except ValueError:
            raise Exception("parametrii invalizi!")
        self.__service_Persons.addPerson(personID,person_name,person_adress)
        print("persoana adaugata cu succes!")

    def __ui_printEvents(self, params):
        """

        :param params: nimic
        :return: nimic

        aceasta functie afiseaza lista de evenimente

        """
        if len(params) != 0:
            print("nr parametrii invalid!")
            return
        event_list = self.__service_Events.get_allEvents()
        for event in event_list:
            print(event)

    def __ui_printRegisters(self,params):
        """
        functie UI pentru afisarea inscrierilor
        :param params:
        :return:
        """
        if len(params) != 0:
            print("nr parametrii invalid!")
            return
        register_list = self.__service_Register.get_all_registers()
        for key in register_list:
            print(register_list[key])

    def __ui_add_Event(self, params):
        """

        :param params:  ID de tip int
                        data de tip string
                        durata de tip int
                        descriere de tip string
        :return: nimic

        aceasta functie este responsabila pentru transmiterea parametrilor
        ce vor defini obiectul event

        """
        if len(params) != 4:
            print("nr parametrii invalid!")
            return
        try:
            event_id = int(params[0])
            event_date = params[1]
            event_length = int(params[2])
            event_description = params[3]
        except ValueError:
            raise Exception("parametrii invalizi!")
        self.__service_Events.addEvent(event_id, event_date, event_length, event_description)
        print("eveniment adaugat cu succes")

    def __ui_deletePerson(self, params):
        """

        :param params: ID de tip int
        :return: nimic

        aceasta functie este responsabila pentru transmiterea parametrului
        ce va ajuta la stergerea persoanei cu un anumit ID

        """
        if len(params) != 1:
            print("nr parametrii invalid!")
            return
        try:
            person_id = int(params[0])
        except ValueError:
            raise Exception("parametrii invalizi!")
        self.__service_Persons.deletePerson(person_id)
        print("persoana stearsa cu succes!")

    def __ui_deleteEvent(self, params):
        """

        :param params: ID de tip int
        :return: nimic

        aceasta functie este responsabila pentru transmiterea parametrului
        ce va ajuta la stergerea evenimentului cu un anumit ID

        """
        if len(params) != 1:
            print("nr parametrii invalid!")
            return
        try:
            event_id = int(params[0])
        except:
            raise Exception("parametrii invalizi!")
        self.__service_Events.deleteEvent(event_id)
        print("eveniment sters cu succes!")

    def __ui_updatePerson(self,params):
        """

        :param params:lista cu:     ID de tip int
                                    nume de tip string
                                    adresa de tip string
        :return: nimic

        aceasta functie este responsabila pentru transmiterea parametrilor
        ce vor defini noul obiect persoana ce va actualiza o persoana
        din lista de persoane

        """
        if len(params) != 3:
            print("nr parametrii invalid!")
            return
        try:
            personID = int(params[0])
            person_name = params[1]
            person_adress = params[2]
        except:
            raise Exception("parametrii invalizi!")
        self.__service_Persons.updatePerson(personID,person_name,person_adress)
        print("date persoana actualizate cu succes!")

    def __ui_generatePersons(self,params):
        """
        functie care genereaza params persoane cu
        atribute random
        :param params: int
        :return:
        """
        if len(params) != 1:
            print("nr parametrii invalid!")
            return
        try:
            personNumber = int(params[0])
        except:
            raise Exception("parametru invalid!")
        self.__service_Persons.generatePersons(personNumber)
        print("Persoane generate cu succes!")

    def __ui_updateEvent(self,params):
        """

        :param params:  lista cu:   ID de tip int
                                    data de tip string
                                    durata de tip int
                                    descriere de tip string
        :return: nimic

        aceasta functie este responsabila pentru transmiterea parametrilor
        ce vor defini noul obiect eveniment ce va actualiza un eveniment
        din lista de evenimente

        """
        if len(params) != 4:
            print("nr parametrii invalid!")
            return
        try:
            eventID = int(params[0])
            event_date = params[1]
            event_length = int(params[2])
            event_description = params[3]
        except:
            raise Exception("parametrii invalizi!")
        self.__service_Events.updateEvent(eventID,event_date,event_length,event_description)
        print("date eveniment actualizate cu succes!")

    def __ui_searchPersonDescription(self,params):
        """
        functie care cauta o persoana din lista de persoane dupa nume
        :param params: string
        :return:
        """
        if len(params) != 1:
            print("nr parametrii invalid!")
            return
        try:
            person_name = params[0]
        except:
            raise Exception("parametru invalid!")
        search_persons = self.__service_Persons.searchPerson(person_name)
        for person in search_persons:
            print(person)

    def __ui_searchEvent(self,params):
        """
        functie care cauta un eveniment din lista de evenimente dupa descriere
        :param params: string
        :return:
        """
        if len(params) != 1:
            print("nr parametrii invalid!")
            return
        try:
            event_description = params[0]
        except ValueError:
            raise Exception("parametru invalid!")
        search_event = self.__service_Events.searchEvent(event_description)
        for event in search_event:
            print(event)

    def __ui_registerPerson(self, params):
        """
        functie de pregatire a parametrilor pentru
        procesul de inscriere a unei persoane la un eveniment
        :param params: person_id -> int event_id -> int
        :return: None
        """
        if len(params) != 2:
            print("nr parametrii invalid!")
            return
        try:
            person_id = int(params[0])
            event_id = int(params[1])
        except ValueError:
            raise Exception("parametrii invalizi!")
        self.__service_Register.register_person(person_id, event_id)
        print("persoana inscrisa!")

    def __ui_printTopRegisters(self,params):
        """
        functie de afisare a top evenimente cu cei mai multi participanti inscrisi
        :param params:
        :return:
        """
        if len(params) != 0:
            print("nr parametrii invalid!")
            return
        top_booked_list = self.__service_Register.get_top_registers()
        for x in top_booked_list:
            print(x)

    def __ui_printMostRegisteredPersons(self, params):
        """
        functie de afisare a top k persoane inscrise la cele mai multe evenimente
        :param params:
        :return:
        """
        if len(params) != 1:
            print("nr parametrii invalid!")
            return
        try:
            k = int(params[0])
        except ValueError:
            raise Exception("parametru invalid!")
        top_most_registered_list = self.__service_Register.get_most_registered(k)
        for x in top_most_registered_list:
            print(x)

    def __ui_printEventsDescription(self, params):
        """
        functie de afisare a evenimentelor la care participa
        o persoana sortate dupa descriere
        :param params: person_id ->int
        :return:
        """
        if len(params) != 1:
            print("nr parametrii invalid!")
            return
        try:
            person_id = int(params[0])
        except ValueError:
            raise Exception("parametru invalid!")
        events_description_list = self.__service_Register.get_events_description(person_id)
        for x in events_description_list:
            print(x)

    def __ui_printEventsDate(self,params):
        """
        functie de afisare a evenimentelor la care participa o persoana
        ordonate dupa data
        :param params: person_id -> int
        :return:
        """
        if len(params) != 1:
            print("numar parametrii invalid!")
            return
        try:
            person_id = int(params[0])
        except ValueError:
            raise Exception("parametru invalid!")
        events_date_list = self.__service_Register.get_events_date(person_id)
        for x in events_date_list:
            print(x)

    def run(self):
        """

        :return: None

        aceasta functie este functia care separa input-ul USER-ului in comenzi si parametrii acestora

        """
        print("...Toate testele au fost efectuate cu succes!")
        while True:
            cmd = input(">>>")
            cmd = cmd.strip()
            if cmd == "exit":
                return
            parts = cmd.split(",")
            cmd_name = parts[0]
            params = parts[1:]
            if cmd_name in self.__commandz:
                try:
                    self.__commandz[cmd_name](params)
                except Exception as ex:
                    print(ex)
            else:
                print("comanda invalida!")

