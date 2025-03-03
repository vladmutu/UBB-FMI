class TopGDTO:
    def __init__(self,nume_student, medie):
        self.__nume_student = nume_student
        self.__medie = medie

    def get_medie(self):
        return self.__medie
    def __str__(self):
        return f"{self.__nume_student} {self.__medie}"