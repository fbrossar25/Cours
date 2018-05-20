#include "maison.h"

CMaison::CMaison()
{
	m_facades.reserve(4);
}

CMaison::~CMaison()
{

}

void CMaison::addFacade()
{
	m_facades.push_back(CFacade());
}

void CMaison::addFacade(bool hasPignon)
{
	m_facades.push_back(CFacade(hasPignon));
}

void CMaison::addFacade(float largeur, float hauteur)
{
	m_facades.push_back(CFacade(largeur,hauteur));
}

void CMaison::addFacade(float RLargeur, float RHauteur, float PHauteur)
{
	m_facades.push_back(CFacade(RLargeur,RHauteur,PHauteur));
}

float CMaison::getAireACrepir() const
{
	float res = m_facades[0].getAire();
	for(unsigned int i=1; i<m_facades.size(); i++)
	{
		res += m_facades[i].getAire();
	}
	return res;
}

void CMaison::printStats() const
{
	unsigned int i,n = m_facades.size();
    std::cout << "\n\n=========DISPLAYING STATS========\n\n";
	for (i = 0; i < n; ++i)
	{
		std::cout << "\n\n=========FACADE " << i+1 << "========\n\n";
		m_facades[i].printStats();
        std::cout << "\n\n=========================\n\n";
	}
    std::cout << "\n\n========END OF DISPLAY========\n\n";
}