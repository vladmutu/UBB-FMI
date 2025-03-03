#include "teste.h"
#include "domain.h"
#include "repository.h"
#include "service.h"
#include <cassert>

using namespace std;

void Teste::runAll()
{
	testAdaugaModificaSterge();
	testGetSet();
	testExceptions();
}

void Teste::testAdaugaModificaSterge()
{
	RepoUtilaje repo{ "tests.txt" };
	ServiceUtilaje serv{ repo };
	try {
		serv.adauga_utilaj_service(1, "1", "1", 1);
	}
	catch (ServiceException& e)
	{
		
		assert(e.get_msg() == "Id deja existent!");
	}
	try {
		serv.adauga_utilaj_service(-1, "1", "1", 1);
	}
	catch (ServiceException& e)
	{
		assert(e.get_msg() == "Id invalid!");
	}
	try {
		serv.sterge_utilaj_service(1);
	}
	catch (ServiceException& e) {
		assert(e.get_msg() == "Ultimul utilaj cu acest numar de cilindrii!");
	}
	serv.adauga_utilaj_service(3, "Tractor1", "mare", 1);
	assert(serv.get_all_service()[0].get_id() == 1);
	assert(serv.get_all_service()[1].get_id() == 3);
	serv.sterge_utilaj_service(3);
	try {
		serv.modifica_utilaj_service(1, "", "a", 1);
	}
	catch (ServiceException& e) {
		assert(e.get_msg() == "Denumire invalida!");
	}
	try {
		serv.modifica_utilaj_service(1, "a", "", 1);
	}
	catch (ServiceException& e) {
		assert(e.get_msg() == "Tip invalid!");
	}
	serv.modifica_utilaj_service(1, "a", "a", 8);
	assert(serv.get_all_service()[0].get_cilindrii() == 8);
	serv.modifica_utilaj_service(1, "Tractor1", "mare", 1);
}

void Teste::testGetSet()
{
	int id = 1, cil = 1;
	string den = "a", tip = "a";
	Utilaj t(id, den, tip, cil);
	assert(t.get_id() == 1);
	assert(t.get_denumire() == "a");
	assert(t.get_tip() == "a");
	assert(t.get_cilindrii() == 1);
	assert(t.validate() == 0);
	id = -1;
	Utilaj t1(id, den, tip, cil);
	try {
		t1.validate();
	}
	catch (UtilajException& e){
		assert(e.get_msg() == "Id invalid!");
	}
	id = 1;
	Utilaj t2(id, "", tip, cil);
	try {
		t2.validate();
	}
	catch (UtilajException& e1) {
		assert(e1.get_msg() == "Denumire invalida!");
	}
	Utilaj t3(id, den, "", cil);
	try {
		t3.validate();
	}
	catch (UtilajException& e2) {
		assert(e2.get_msg() == "Tip invalid!");
	}
	Utilaj t4(id, den, tip, 0);
	try {
		t4.validate();
	}
	catch (UtilajException& e3) {
		assert(e3.get_msg() == "Numar cilindrii invalid!");
	}
}

void Teste::testExceptions()
{
	try {
		throw RepoException("a");
	}
	catch (RepoException& e) {
		assert(e.get_msg() == "a");
	}

	try {
		throw ServiceException("a");
	}
	catch (ServiceException& e) {
		assert(e.get_msg() == "a");
	}

	try {
		throw UtilajException("a");
	}
	catch (UtilajException& e) {
		assert(e.get_msg() == "a");
	}
}
