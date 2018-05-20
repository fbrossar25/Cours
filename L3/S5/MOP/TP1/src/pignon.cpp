//
// Created by florian on 16/09/16.
//

#include "pignon.h"

CPignon::CPignon() : CPignon(1.0,1.0)
{
   
}

CPignon::CPignon(float base, float hauteur) : CTriangle(base,hauteur)
{

}

CPignon::~CPignon()
{

}

void CPignon::printStats() const
{
	std::cout << m_hauteur << "m" << std::endl;
}

void CPignon::addFenetre(float largeur, float hauteur)
{
	if(largeur <= 0.0 || hauteur <= 0.0) return;
	m_fenetres.addFenetre(largeur,hauteur);
}