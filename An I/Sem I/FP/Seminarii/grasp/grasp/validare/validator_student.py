from exceptii.valid_error import ValidError

class ValidatorStudent:

    def valideaza(self,student):
        erori = ""

        if student.get_id_student()<0:
            erori+="id student invalid!\n"
        if student.get_nume()=="":
            erori+="nume student invalid!\n"
        if student.get_medie()<=0.0:
            erori+="medie student invalida!\n"
        if len(erori)>0:
            raise ValidError(erori)