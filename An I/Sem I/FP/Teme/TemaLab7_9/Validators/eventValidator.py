"""
Acest modul contine clasa cu functia de validare a obiectului event
"""


class EventValidator:
    def validateEvent(self,event):
        """

        :param event: de tip Event
        :return:

        functie de validare a obiectului Event

        """
        erori = ""
        if event.get_event_ID() < 0:
            erori += "ID invalid!\n"
        date = event.get_event_date()
        date_split = date.split("/")
        if event.get_event_date() == "":
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
        if event.get_event_length() < 0:
            erori += "durata invalida!\n"
        if event.get_event_description() == "":
            erori += "descriere invalida!\n"
        if len(erori) > 0:
            raise Exception(erori)
