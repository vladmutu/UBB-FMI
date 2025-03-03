class Student:
    def __init__(self,id_student,nume,medie):
        self.__id_student = id_student
        self.__nume = nume
        self.__medie = medie

    def get_id_student(self):
        return self.__id_student

    def get_nume(self):
        return self.__nume

    def get_medie(self):
        return self.__medie

    def __str__(self):
        return f"{self.__id_student},{self.__nume},{self.__medie}"