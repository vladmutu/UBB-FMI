from Tests.teste import *


teste = Teste()
teste.run_all_tests()
repo_person = PersonRepository()
repo_event = EventRepository()
repo_register = RegisterRepository()
validator_person = PersonValidator()
validator_event = EventValidator()
validator_register = RegisterValidator()
person_service = Personservice(repo_person, validator_person)
event_service = Eventservice(repo_event, validator_event)
register_service = RegisterService(repo_person, repo_event, repo_register, validator_register)
console = UI(person_service, event_service, register_service)
console.run()
