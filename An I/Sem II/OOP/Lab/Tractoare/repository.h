#pragma once
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

class RepoTractoare{
private:
	vector<Tractor> tractoare;
	string file_name;
public:
	RepoTractoare(string file_name) : file_name{ file_name } {
		load_from_file();
	}

	void adauga_tractor(const Tractor& t);

	void modifica_tractor(int ID);

	vector<Tractor>& get_all();


	void load_from_file();

	void save_to_file();

	~RepoTractoare() {
		save_to_file();
	}
};