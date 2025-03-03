#pragma once
#include "domain.h"
#include "repository.h"
#include <vector>
#include <exception>
#include <string>

using namespace std;

class ServiceException : public exception {
private:
	string msg;
public:
	ServiceException(string msg) : msg(msg) {

	}
	string get_msg() {
		return msg;
	}
};

class ServiceUtilaje {
private:
	RepoUtilaje& repo;
public:
	ServiceUtilaje(RepoUtilaje& r) : repo{ r } {

	}

	void adauga_utilaj_service(int id, string denumire, string tip, int cilindrii);

	void sterge_utilaj_service(int id);

	void modifica_utilaj_service(int id, string denumire, string ip, int nr_cilindrii);


	vector<Utilaj>& get_all_service() {
		return repo.get_all();
	}
};