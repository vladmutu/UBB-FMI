#include "service.h"
#include "domain.h"
#include <vector>

using namespace std;

/*
functie de service pentru adaugarea in repo
*/
void ServiceUtilaje::adauga_utilaj_service(int id, string denumire, string tip, int cilindrii)
{
	Utilaj t(id, denumire, tip, cilindrii);
	try {
		t.validate();
	}
	catch (UtilajException& e) {
		throw(ServiceException(e.get_msg()));}
	try {
		repo.adauga_utilaj(t);
	}
	catch (RepoException& e)
	{
		throw(ServiceException(e.get_msg()));}}


/*
functie service pentru stergerea unui utilaj
*/
void ServiceUtilaje::sterge_utilaj_service(int id)
{
	try {
		repo.sterge_utilaj(id);
	}
	catch (RepoException& e) {
		throw ServiceException(e.get_msg());}
	
}

/*
functie
service pentru modificarea unui utilaj
*/
void ServiceUtilaje::modifica_utilaj_service(int id, string denumire, string tip, int nr_cilindrii)
{
	if (denumire.empty())
		throw ServiceException("Denumire invalida!");
	if (tip.empty())
		throw ServiceException("Tip invalid!");
	repo.modifica_utilaj(id, denumire, tip, nr_cilindrii);
}
