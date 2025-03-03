"""
Acest modul contine validatorul pentru inscrieri
"""

class RegisterValidator:
    def ValidateRegister(self,register):
        erori = ""
        registered_person = register.get_registered_person()
        registered_event = register.get_registered_event()
        if registered_person.get_person_ID() < 0:
            erori += "ID persoana invalid!"
        if registered_person.get_person_name() == "":
            erori += "Nume persoana invalid!"
        if registered_person.get_person_adress() == "":
            erori += "Adresa persoana invalida!"
        if registered_event.get_event_ID() < 0:
            erori += "ID eveniment invalid!"
        date = registered_event.get_event_date()
        date_split = date.split("/")
        if date == "":
            erori += "data invalida!\n"
        elif len(date_split) != 3:
            erori += "data invalida!\n"
        else:
            try:
                date_split[0] = int(date_split[0])
                if date_split[0] > 31:
                    assert False
                date_split[1] = int(date_split[1])
                if date_split[1] > 12:
                    assert False
                date_split[2] = int(date_split[2])
            except:
                erori += "data invalida!\n"
        if registered_event.get_event_length() < 0:
            erori += "durata invalida!\n"
        if registered_event.get_event_description() == "":
            erori += "descriere invalida!\n"
        if len(erori) > 0:
            raise Exception(erori)

