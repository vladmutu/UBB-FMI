#include "domain.h"

int Tractor::validate()
{
	if (id < 1)
		throw TractorException("Id invalid!");
	if (denumire.empty())
		throw TractorException("denumire invalida!");
	if (tip.empty())
		throw TractorException("tip invalid!");
	if ((roti < 2 || roti > 16) || roti % 2 != 0)
		throw TractorException("nr roti invalid!");
	return 0;
}