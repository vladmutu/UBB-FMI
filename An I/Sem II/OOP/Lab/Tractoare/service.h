#pragma once
#include "repository.h"
#include <vector>
#include <string>
using namespace std;
class ServiceException : public exception {
private:
	string msg;
public:
	ServiceException(string msg) : msg{ msg } {

	}

	string get_msg() {
		return msg;
	}
};

class ServiceTractoare {
private:
	RepoTractoare& repo;
public:
	ServiceTractoare(RepoTractoare& repo) : repo{ repo } {

	}

	void adauga_tractor_service(int id, string denumire, string tip, int roti);

	void modifica_tractor_service(int id);

	vector<Tractor>& get_all_service();
};