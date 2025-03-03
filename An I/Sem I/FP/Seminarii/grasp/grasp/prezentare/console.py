from exceptii.ui_error import UIError
class Consola:

    def __init__(self,srv_studenti,srv_materii,srv_note):
        self.__srv_studenti = srv_studenti
        self.__srv_materii = srv_materii
        self.__srv_note = srv_note
        self.__comenzi = {
            "add_student":self.__ui_add_student,
            "print_studenti":self.__ui_print_students,
            "top_gs":self.__ui_top_gs
        }

    def __ui_top_gs(self,params):
        top_gs = self.__srv_note.get_top_gs()
        for top_g in top_gs:
            print(top_g)
    def __ui_print_students(self,params):
        if len(params)!=0:
            print("nr params invalid!")
            return
        students = self.__srv_studenti.get_all_students()
        for student in students:
            print(student)
    def __ui_add_student(self,params):
        if len(params)!= 3:
            print("nr params invalid!")
            return
        try:
            id_student = int(params[0])
            nume = params[1]
            medie = float(params[2])
            self.__srv_studenti.adauga_student(id_student,nume,medie)
        except ValueError:
            raise UIError("valoare numerica invalida!")

    def run(self):
        while True:
            cmd = input(">>>")
            cmd = cmd.strip()
            if cmd == "":
                continue
            if cmd == "exit":
                return
            parts = cmd.split()
            cmd_name = parts[0]
            params = parts[1:]
            if cmd_name in self.__comenzi:
                try:
                    self.__comenzi[cmd_name](params)
                except UIError as ex:
                    print(f"ui error:{ex}")
            else:
                print("comanda invalida!")
