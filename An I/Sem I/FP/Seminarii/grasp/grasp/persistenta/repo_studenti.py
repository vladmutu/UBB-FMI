
class RepoStudenti:
    def __init__(self):
        self._studenti ={

        }

    def adauga_student(self,student):
        id_student = student.get_id_student()
        if id_student in self._studenti:
            raise RepoError("student existent!")
        self._studenti[id_student] = student


    def get_all(self):
        return [self._studenti[x] for x in self._studenti]


class FileRepoStudenti(RepoStudenti):
    def __init__(self,cale_fisier):
        RepoStudenti.__init__(self)
        self.__cale_fisier = cale_fisier

    def __read_all_studenti_from_file(self):
        with open(self.__cale_fisier,"r") as f:
            self._studenti.clear()
            lines = f.readlines()
            for line in lines:
                if line != "":
                    parts = line.split(",")
                    id_student = int(parts[0])
                    nume = parts[1]
                    valoare = float(parts[2])
                    student = Student(id_student,nume,valoare)
                    self._studenti[id_student]=student

    def __write_all_studenti_to_file(self):
        with open(self.__cale_fisier,"w") as f:
            for id_student in self._studenti:
                f.write(str(self._studenti[id_student])+"\n")

    def adauga_student(self,student):
        self.__read_all_studenti_from_file()
        RepoStudenti.adauga_student(self,student)
        self.__write_all_studenti_to_file()

    def get_all(self):
        self.__read_all_studenti_from_file()
        return RepoStudenti.get_all(self)