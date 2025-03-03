from Domain.registerDomain import Register
from Domain.personDomain import Person
from Domain.eventDomain import Event


class RegisterRepository:
    def __init__(self):
        """
        functie de initializare a atributelor clasei Repository pentru inscrieri
        """
        self._register_list = {

        }

    def add_register(self, register):
        """
        functie de adaugare a unei inscrieri in lista de inscrieri
        :param register:
        :return:
        """
        self._register_list[register.get_register_id()] = register

    def get_all_registers(self):
        """
        functie de returnare din RegisterRpository a intregului dictionar de inscrieri
        :return:
        """
        return self._register_list


class FileRepoRegister(RegisterRepository):
    def __init__(self, cale_fisier):
        """
        functie de initializare a RegisterRepository din fisier
        :param cale_fisier:
        """
        RegisterRepository.__init__(self)
        self.__cale_fisier = cale_fisier

    def __read_all_registers_from_file(self):
        """
        functie care citeste din fisier atributele lui register
        :return:
        """
        with open(self.__cale_fisier, "r") as f:
            self._register_list.clear()
            lines = f.readlines()
            i = 0
            for line in lines:
                if line != "" and line != "\n" and line != " ":
                    i += 1
                    line.strip()
                    if i % 7 == 1:
                        person_id = int(line)
                    elif i % 7 == 2:
                        nume = line
                    elif i % 7 == 3:
                        adresa = line
                    elif i % 7 == 4:
                        event_id = int(line)
                    elif i % 7 == 5:
                        event_date = line
                    elif i % 7 == 6:
                        event_length = int(line)
                    else:
                        event_description = line
                        person = Person(person_id, nume, adresa)
                        event = Event(event_id, event_date, event_length, event_description)
                        register = Register(person, event)
                        self._register_list[int(i/2)] = register

    def __write_all_registers_to_file(self):
        """
        functie care adauga in fisier atributele lui register
        :return:
        """
        with open(self.__cale_fisier, "w") as f:
            for register_id in self._register_list:
                f.write(str(self._register_list[register_id].get_registered_person().get_person_ID()) + '\n')
                f.write(str(self._register_list[register_id].get_registered_person().get_person_name()) + '\n')
                f.write(str(self._register_list[register_id].get_registered_person().get_person_adress()) + '\n')
                f.write(str(self._register_list[register_id].get_registered_event().get_event_ID()) + '\n')
                f.write(str(self._register_list[register_id].get_registered_event().get_event_date()) + '\n')
                f.write(str(self._register_list[register_id].get_registered_event().get_event_length()) + '\n')
                f.write(str(self._register_list[register_id].get_registered_event().get_event_description()) + '\n')

    def add_register(self, register):
        """
        functie care adauga in RegisterRepo obiectele citite din fisier
        :param register: Register
        :return:
        """
        self.__read_all_registers_from_file()
        RegisterRepository.add_register(self, register)
        self.__write_all_registers_to_file()

    def get_all_registers(self):
        """
        functie care returneaza toate obiectele register din RegisterRepo
        :return:
        """
        self.__read_all_registers_from_file()
        return RegisterRepository.get_all_registers(self)
