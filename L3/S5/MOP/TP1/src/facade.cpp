#include "facade.h"

CFacade::CFacade() : CFacade(false)
{

}

CFacade::CFacade(bool hasPignon)
: m_hasPignon(hasPignon)
{
	if(!m_hasPignon) CPignon m_pignon(0.0,0.0);
}

CFacade::CFacade(float largeur, float hauteur)
: m_rectangle(largeur,hauteur)
, m_hasPignon(false)
, m_pignon(0.0,0.0)
{
	if(largeur <= 0.0 && hauteur <= 0.0)
		throw std::invalid_argument("Dimensions incorrectes"); 
}

CFacade::CFacade(float RLargeur, float RHauteur, float PHauteur)
: m_rectangle(RLargeur,RHauteur)
, m_hasPignon(PHauteur > 0.0)
, m_pignon( m_hasPignon ? RLargeur : 0.0, PHauteur)
{
	if(RLargeur <= 0.0 || RHauteur <= 0.0 || PHauteur <= 0.0)
		throw std::invalid_argument("Dimensions de facade ou de pignon incorrectes");
	
}

CFacade::~CFacade()
{

}

void CFacade::addPorte(float largeur, float hauteur)
{
	if(largeur <= 0.0 && hauteur <= 0.0) return;
	m_portes.addPorte(largeur,hauteur);
}
void CFacade::addFenetre(float largeur, float hauteur)
{
	if(largeur <= 0.0 && hauteur <= 0.0) return;
	m_fenetres.addFenetre(largeur,hauteur);
}

float CFacade::getAire() const
{
	float res = m_rectangle.getAire();
	res -= m_portes.getAire();
	res -= m_fenetres.getAire();
	if(m_hasPignon) res += m_pignon.getAire();
	return res;
}

void CFacade::printStats() const
{
	m_rectangle.printStats();
	if(m_hasPignon)
	{
		std::cout << "\nPignon de ";
		m_pignon.printStats();
		std::cout << std::endl;
	}
	else
	{
		std::cout << "\nPas de pignon\n" << std::endl;
	}
	m_fenetres.printStats();
	m_portes.printStats();
}

void CFacade::addFenetreSurPignon(float largeur, float hauteur)
{
	m_pignon.addFenetre(largeur,hauteur);
}