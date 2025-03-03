from domeniu.dtos import TopGDTO


class ServiceNote:
    def __init__(self,repo_note,repo_materii,repo_studenti,valid_nota):
        self.__repo_note = repo_note
        self.__repo_materii = repo_materii
        self.__repo_studenti = repo_studenti
        self.__valid_nota = valid_nota


    def get_top_gs(self,k):
        note = self.__repo_note.get_all_note()
        medii = {}
        for nota in note:
            id_student = nota.get_student().get_id_student()
            if id_student not in medii:
                medii[id_student] = [0,0]
            medii[id_student][0]+= nota.get_valoare_nota()
            medii[id_student][1] += 1
        rez = []
        for id_student_medie in medii:
            nume_student = self.__repo_studenti.cauta_student_dupa_id(id_student_medie).get_name()
            medie =medii[id_student_medie][0]/medii[id_student_medie][1]
            dto = TopGDTO(nume_student,medie)
            rez.append(dto)
        rez.sort(key=lambda x:x.get_medie(),reverse=True)
        return rez[:k]
