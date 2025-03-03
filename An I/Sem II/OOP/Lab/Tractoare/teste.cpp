#include "teste.h"
#include "service.h"
#include "repository.h"
#include "domain.h"
#include <cassert>
void Teste::runAll()
{
	testSaveLoad();
	testAdaugaModifica();
	testSetterModifier();
}

void Teste::testSaveLoad()
{
	RepoTractoare repo{"tests.txt"};
	assert(repo.get_all().size() == 2);
	assert(repo.get_all()[0].get_id() == 1);
}

void Teste::testAdaugaModifica()
{
	RepoTractoare repo{ "tests.txt" };
	ServiceTractoare serv{ repo };
	try {
		serv.adauga_tractor_service(-1, "1", "1", 2);
	}
	catch (ServiceException& e) {
		assert(e.get_msg() == "Id invalid!");
	}
}

void Teste::testSetterModifier()
{
}
