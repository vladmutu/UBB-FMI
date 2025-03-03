#include "service.h"

void ServiceTractoare::adauga_tractor_service(int id, string denumire, string tip, int roti)
{
	Tractor t(id, denumire, tip, roti);
	try {
		t.validate();
	}
	catch (TractorException& e) {
		throw ServiceException(e.get_msg());
	}

	try {
		repo.adauga_tractor(t);
	}
	catch (RepoException& e) {
		throw ServiceException(e.get_msg());
	}
}

void ServiceTractoare::modifica_tractor_service(int id)
{
	try {
		repo.modifica_tractor(id);
	}
	catch (RepoException& e) {
		throw ServiceException(e.get_msg());
	}
}

vector<Tractor>& ServiceTractoare::get_all_service()
{
	return repo.get_all();
}
