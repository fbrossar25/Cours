#include "Maison.h"

Maison::Maison()
: Bien(0.0)
, m_nombrePieces(0)
{

}

Maison::Maison(float surface, unsigned int nombrePieces)
: Bien(surface)
, m_nombrePieces(nombrePieces)
{

}

Maison::~Maison()
{

}

void Maison::addPiece(float surface)
{
	m_surface += surface;
	m_nombrePieces++;
}