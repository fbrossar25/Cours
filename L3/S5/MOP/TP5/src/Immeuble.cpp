#include "Immeuble.h"

Immeuble::Immeuble()
{

}

Immeuble::~Immeuble()
{
	for(unsigned int i(0); i<m_appartements.size(); i++)
	{
		delete m_appartements[i];
	}
}

void Immeuble::addAppartement(Appartement *appartement)
{
	m_appartements.push_back(appartement);
	m_surface += appartement->getSurface();
}