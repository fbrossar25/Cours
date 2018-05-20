//
// Created by florian on 16/09/16.
//

#include "fenetres.h"

CFenetres::CFenetres()
{
    m_fenetres.reserve(5);
}

CFenetres::~CFenetres()
{
	
}

void CFenetres::addFenetre(float largeur, float hauteur)
{
	m_fenetres.push_back(COuverture(largeur,hauteur));
}

unsigned int CFenetres::getSize() const
{
	return m_fenetres.size();
}

COuverture CFenetres::getFenetre(unsigned int n)
{
	assert(n < m_fenetres.size());
	return m_fenetres[n];
}

float CFenetres::getAire() const
{
	unsigned int i,n = m_fenetres.size();
	if(n == 0) return 0.0;
	float res = m_fenetres[0].getAire();
	for(i=1; i<n; i++)
	{
		res += m_fenetres[i].getAire();
	}
	return res;
}

void CFenetres::printStats() const
{
	unsigned int i,n = m_fenetres.size();
    if(n == 0)
    {
        std::cout << "Pas de fenetres" << std::endl;
        return;
    }
	std::cout << n << " fenetres :"<< std::endl;
	for(i=0; i<n; i++)
	{
		m_fenetres[i].printStats();
	}
	std::cout << std::endl;
}