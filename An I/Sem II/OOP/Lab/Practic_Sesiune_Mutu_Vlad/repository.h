#pragma once
#include <exception>
#include <vector>
#include <string>
#include "domain.h"
using namespace std;

class RepoException : public exception {
private:
	string msg;
public:
	RepoException(string msg) : msg{ msg } {

	}
	string get_msg() {
		return msg;
	}
};

class RepoUtilaje {
private:
	string file_name;
	vector<Utilaj> utilaje;
public:
	RepoUtilaje(string file_name) : file_name(file_name) {
		load_from_file();
	}

	void load_from_file();

	void save_to_file();

	void adauga_utilaj(const Utilaj& u);

	void sterge_utilaj(const int& id);

	void modifica_utilaj(const int& id, const string& denumire, const string& tip, const int& nr_cilindrii);

	vector<Utilaj>& get_all() {
		return utilaje;
	}
	
	~RepoUtilaje() {
		save_to_file();
	}
};