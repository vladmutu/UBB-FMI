#pragma once
#include <string>

using namespace std;

class TractorException :public std::exception
{
private:
	string msg;
public:
	TractorException(const string& msg) : msg{ msg } {

	}

	string get_msg() {
		return msg;
	}
};

class Tractor {
private:
	int id;
	string denumire;
	string tip;
	int roti;
public:
	Tractor(int i, string& d, string& t, int r) : id{ i }, denumire{ d }, tip{ t }, roti{ r } {

	}

	Tractor(const Tractor& ot) : id{ ot.id }, denumire{ ot.denumire }, tip{ ot.tip }, roti{ ot.roti } {

	}

	int get_id() const {
		return id;
	}

	string get_denumire() const{
		return denumire;
	}

	string get_tip() const {
		return tip;
	}

	int get_roti() const {
		return roti;
	}

	void modifica_roti()
	{
		roti -= 2;
	}

	int validate();

	~Tractor() = default;
};
