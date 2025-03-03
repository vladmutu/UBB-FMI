from domeniu.student import Student
class ServiceStudenti:
    def __init__(self,repo_studenti,valid_student):
        self.__repo_studenti = repo_studenti
        self.__valid_student = valid_student

    def adauga_student(self,id_student,nume,medie):
        student = Student(id_student,nume,medie)
        self.__valid_student.valideaza(student)
        self.__repo_studenti.adauga_student(student)

    def get_all_students(self):
        return self.__repo_studenti.get_all()