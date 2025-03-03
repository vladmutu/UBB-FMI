#include "repository.h"
#include <string>
#include <fstream>
#include "domain.h"
#include <algorithm>
using namespace std;

void RepoTractoare::load_from_file()
{
	ifstream fin(file_name);
	while (!fin.eof())
	{
		string id_aux;
		string denumire;
		string tip;
		string roti_aux;
		getline(fin, id_aux, ',');
		getline(fin, denumire, ',');
		getline(fin, tip, ',');
		getline(fin, roti_aux, '\n');
		if (id_aux.empty())
			break;
		int id = stoi(id_aux);
		int roti = stoi(roti_aux);
		Tractor m(id, denumire, tip, roti);
		adauga_tractor(m);
	}
}

void RepoTractoare::save_to_file()
{
	ofstream fout(file_name);
	for (auto& t : tractoare) {
		fout << t.get_id() << ',' << t.get_denumire() << ',' << t.get_tip() << ',' << t.get_roti() << '\n';
	}
}

void RepoTractoare::adauga_tractor(const Tractor& t)
{
	for (auto& tractor : tractoare)
		if (tractor.get_id() == t.get_id())
			throw RepoException("Id deja existent!");
	tractoare.push_back(t);
	sort(tractoare.begin(), tractoare.end(), [](Tractor& t1, Tractor& t2){
			return t1.get_denumire() < t2.get_denumire();
		});
}

void RepoTractoare::modifica_tractor(int ID)
{
	for (auto& tractor : tractoare)
		if (tractor.get_id() == ID)
			tractor.modifica_roti();
}

vector<Tractor>& RepoTractoare::get_all()
{
	return tractoare;
}
