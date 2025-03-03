#include "domain.h"

/*
functie getter pentru id;
*/
int Utilaj::get_id() const
{
	return id;
}


/*
functie getter petrnu denumire
*/
string Utilaj::get_denumire() const
{
	return denumire;
}


/*
functie getter petnru tip
*/
string Utilaj::get_tip() const
{
	return tip;
}

/*
fucntie getter pentru cilindrii
*/
int Utilaj::get_cilindrii() const
{
	return cilindrii;
}

/*
validator
0 = ok
altfel exceptie
*/
int Utilaj::validate() const
{
	if (id < 1)
		throw(UtilajException("Id invalid!"));
	if(denumire.empty())
		throw(UtilajException("Denumire invalida!"));
	if (tip.empty())
		throw(UtilajException("Tip invalid!"));
	if (cilindrii != 1 && cilindrii != 2 && cilindrii != 4 && cilindrii != 8)
		throw(UtilajException("Numar cilindrii invalid!"));
	return 0;
}
