#include "repository.h"
#include <fstream>
#include <string>
#include <vector>
#include "domain.h"
#include <algorithm>
#include <unordered_map>
using namespace std;

/*
functie de incarcare a elementelor din fisier
*/
void RepoUtilaje::load_from_file()
{
	ifstream fin(file_name);
	while (!fin.eof())
	{
		string id_aux;
		string denumire;
		string tip;
		string cilindrii_aux;
		getline(fin, id_aux, ',');
		getline(fin, denumire, ',');
		getline(fin, tip, ',');
		getline(fin, cilindrii_aux, '\n');
		if (id_aux.empty())
			break;
		int id = stoi(id_aux);
		int cilindrii = stoi(cilindrii_aux);
		Utilaj u(id, denumire, tip, cilindrii);
		adauga_utilaj(u);
	}
}
/*
functie de salvare in fisier
*/
void RepoUtilaje::save_to_file()
{
	ofstream fout(file_name);
	for (auto& u : utilaje) {
		fout << u.get_id() << ',' << u.get_denumire() << ',' << u.get_tip() << ',' << u.get_cilindrii() << '\n';
	}
}

/*
* functie de adaugare utilaj in repo
* u:Utilaj valid
*/
void RepoUtilaje::adauga_utilaj(const Utilaj& u)
{
	for (auto& utilaj : utilaje)
		if (utilaj.get_id() == u.get_id())
			throw RepoException("Id deja existent!");
	utilaje.push_back(u);
	sort(utilaje.begin(), utilaje.end(), [](Utilaj& u1, Utilaj& u2) {
		if (u1.get_tip() == u2.get_tip())
			return u1.get_denumire() < u2.get_denumire();
		else
			return u1.get_tip() < u2.get_tip();
		});
	save_to_file();
}
/*
functie de stergere_utilaj din repo
id = valid;
*/
void RepoUtilaje::sterge_utilaj(const int& id)
{
	for (auto utilaj = utilaje.begin(); utilaj != utilaje.end();) {
		if (utilaj->get_id() == id) 
		{
			unordered_map<int, int> nrC = { {1,0}, {2,0}, {4,0}, {8,0} };
			for (auto& u : utilaje) {
				nrC[u.get_cilindrii()]++;
			}
			if (nrC[utilaj->get_cilindrii()] == 1)
				throw(RepoException("Ultimul utilaj cu acest numar de cilindrii!"));
			utilaje.erase(utilaj);
			break;}
		else {
			++utilaj;
		}
	}
	sort(utilaje.begin(), utilaje.end(), [](Utilaj& u1, Utilaj& u2) {
		if (u1.get_tip() == u2.get_tip()) return u1.get_denumire() < u2.get_denumire();
		else
			return u1.get_tip() < u2.get_tip();
		});
	save_to_file();
}

/*
* functie de modificare a unui utilaj din repo
* id = int
* denumire = string
* denumire.empty() = false;
* tip = string
* tip.empty() = false;
* 
*/
void RepoUtilaje::modifica_utilaj(const int& id, const string& denumire, const string& tip, const int& nr_cilindrii)
{
	Utilaj u(id, denumire, tip, nr_cilindrii);
	for (auto& utilaj : utilaje)
		if (u.get_id() == utilaj.get_id())
			utilaj = u;
	sort(utilaje.begin(), utilaje.end(), [](Utilaj& u1, Utilaj& u2) {
		if (u1.get_tip() == u2.get_tip()) return u1.get_denumire() < u2.get_denumire();
		else
			return u1.get_tip() < u2.get_tip();
		});
	save_to_file();
}
