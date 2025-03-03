class TopParticipanti:
    def __init__(self, event_description, nr_participanti):
        """
        functie de initializare a atributelor clasei TopParticipanti
        :param event_description:
        :param nr_participanti:
        """
        self.__event_description = event_description
        self.__register_nr = nr_participanti

    def get_register_nr(self):
        """
        functie getter pentru numarul inscrierilor
        :return:
        """
        return self.__register_nr

    def __str__(self):
        return f"Descriere: {self.__event_description} , Numar participanti: {self.__register_nr}"