from validare.validator_nota import ValidatorNota
from validare.validator_materie import ValidatorMaterie
from validare.validator_student import ValidatorStudent
from persistenta.repo_note import RepoNote
from persistenta.repo_materii import RepoMaterii
from persistenta.repo_studenti import RepoStudenti, FileRepoStudenti
from business.service_studenti import ServiceStudenti
from business.service_note import ServiceNote
from business.service_materii import ServiceMaterii
from prezentare.console import Consola
from teste.teste import Teste
teste = Teste()
teste.run_all_tests()

valid_student = ValidatorStudent()
valid_materie = ValidatorMaterie()
valid_nota = ValidatorNota()
repo_studenti = FileRepoStudenti("D:\\UBB-FMI\\FP\\Seminarii\\grasp\\grasp\\persistenta\\studenti.txt")
repo_materii = RepoMaterii()
repo_note = RepoNote()
srv_studenti = ServiceStudenti(repo_studenti,valid_student)
srv_materii = ServiceMaterii(repo_materii,valid_materie)
srv_note = ServiceNote(repo_note,repo_materii,repo_studenti,valid_nota)
ui = Consola(srv_studenti,srv_materii,srv_note)
ui.run()
