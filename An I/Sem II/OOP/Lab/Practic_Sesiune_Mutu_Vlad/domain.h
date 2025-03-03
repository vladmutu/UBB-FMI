#pragma once
#include <string>
using namespace std;

class UtilajException : public exception {
private:
	string msg;
public:
	UtilajException(string msg) : msg(msg) {

	}
	string get_msg() {
		return msg;
	}
};

class Utilaj {
private:
	int id;
	string denumire;
	string tip;
	int cilindrii;
public:
	Utilaj(int id, string denumire, string tip, int cilindrii) : id(id), denumire(denumire), tip(tip), cilindrii(cilindrii) {

	}

	int get_id() const;
	
	string get_denumire() const;

	string get_tip() const;

	int get_cilindrii() const;

	int validate() const;

	~Utilaj() = default;
};